/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2011-2025 OpenFOAM Foundation
     \\/     M anipulation  |
-------------------------------------------------------------------------------
License
    This file is part of OpenFOAM.

    OpenFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    OpenFOAM is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with OpenFOAM.  If not, see <http://www.gnu.org/licenses/>.

Application
    extrude2DMesh

Description
    Takes 2D mesh (all faces 2 points only, no front and back faces) and
    creates a 3D mesh by extruding with specified thickness.

    Note:
        Not sure about the walking of the faces to create the front and
        back faces.

\*---------------------------------------------------------------------------*/

#include "argList.H"
#include "Time.H"
#include "polyMesh.H"
#include "extrude2DMesh.H"
#include "extrudeModel.H"
#include "polyTopoChange.H"
#include "MeshedSurface.H"
#include "edgeCollapser.H"
#include "patchToPoly2DMesh.H"
#include "globalIndex.H"
#include "IOdictionary.H"

using namespace Foam;

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

enum class extrudeSurfaceType
{
    polyMesh2D,
    meshedSurface
};

static const NamedEnum<extrudeSurfaceType, 2> extrudeSurfaceTypeNames
{
    "polyMesh2D",
    "MeshedSurface"
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

int main(int argc, char *argv[])
{
    argList::validArgs.append("surfaceFormat");

    #include "addNoOverwriteOption.H"

    #include "setRootCase.H"

    Info<< "Create time\n" << endl;

    Time runTimeExtruded
    (
        Time::controlDictName,
        args.rootPath(),
        args.caseName(),
        false
    );

    const extrudeSurfaceType surfaceFormat = extrudeSurfaceTypeNames[args[1]];
    #include "setNoOverwrite.H"

    Info<< "Extruding from " << extrudeSurfaceTypeNames[surfaceFormat]
        << " at time " << runTimeExtruded.name() << endl;

    IOdictionary extrude2DMeshDict
    (
        IOobject
        (
            "extrude2DMeshDict",
            runTimeExtruded.system(),
            runTimeExtruded,
            IOobject::MUST_READ,
            IOobject::NO_WRITE,
            false
        )
    );

    // Point generator
    autoPtr<extrudeModel> model(extrudeModel::New(extrude2DMeshDict));

    autoPtr<MeshedSurface<face>> fMesh;

    autoPtr<polyMesh> mesh;

    autoPtr<polyTopoChange> meshMod;

    labelListList extrudeEdgePatches;

    if (surfaceFormat == extrudeSurfaceType::meshedSurface)
    {
        fMesh.set(new MeshedSurface<face>("MeshedSurface.obj"));

        EdgeMap<label> edgeRegionMap;
        wordList patchNames(1, "default");
        labelList patchSizes(1, fMesh().nEdges() - fMesh().nInternalEdges());

        const edgeList& edges = fMesh().edges();
        forAll(edges, edgeI)
        {
            if (!fMesh().isInternalEdge(edgeI))
            {
                edgeRegionMap.insert(edges[edgeI], 0);
            }
        }

        patchToPoly2DMesh poly2DMesh
        (
            fMesh(),
            patchNames,
            patchSizes,
            edgeRegionMap
        );

        poly2DMesh.createMesh();

        mesh.set
        (
            new polyMesh
            (
                IOobject
                (
                    polyMesh::defaultRegion,
                    runTimeExtruded.constant(),
                    runTimeExtruded,
                    IOobject::NO_READ,
                    IOobject::NO_WRITE,
                    false
                ),
                move(poly2DMesh.points()),
                move(poly2DMesh.faces()),
                move(poly2DMesh.owner()),
                move(poly2DMesh.neighbour())
            )
        );

        Info<< "Constructing patches." << endl;
        List<polyPatch*> patches(poly2DMesh.patchNames().size());

        forAll(patches, patchi)
        {
            patches[patchi] = new polyPatch
            (
                poly2DMesh.patchNames()[patchi],
                poly2DMesh.patchSizes()[patchi],
                poly2DMesh.patchStarts()[patchi],
                patchi,
                mesh().boundaryMesh(),
                polyPatch::typeName
            );
        }

        mesh().addPatches(patches);
    }
    else if (surfaceFormat == extrudeSurfaceType::polyMesh2D)
    {
        mesh.set
        (
            new polyMesh
            (
                Foam::IOobject
                (
                    Foam::polyMesh::defaultRegion,
                    runTimeExtruded.name(),
                    runTimeExtruded,
                    Foam::IOobject::MUST_READ
                )
            )
        );
    }

    // Engine to extrude mesh
    extrude2DMesh extruder(mesh(), extrude2DMeshDict, model());

    extruder.addFrontBackPatches();

    meshMod.set(new polyTopoChange(mesh().boundaryMesh().size()));

    extruder.setRefinement(meshMod());

    // Create a mesh from topo changes.
    autoPtr<polyTopoChangeMap> map = meshMod().changeMesh(mesh());

    extruder.updateZones();

    mesh().topoChange(map);

    {
        edgeCollapser collapser(mesh());

        const edgeList& edges = mesh().edges();
        const pointField& points = mesh().points();

        const boundBox& bb = mesh().bounds();
        const scalar mergeDim = 1e-4 * bb.minDim();

        PackedBoolList collapseEdge(mesh().nEdges());
        Map<point> collapsePointToLocation(mesh().nPoints());

        forAll(edges, edgeI)
        {
            const edge& e = edges[edgeI];

            scalar d = e.mag(points);

            if (d < mergeDim)
            {
                Info<< "Merging edge " << e << " since length " << d
                    << " << " << mergeDim << nl;

                collapseEdge[edgeI] = true;
                collapsePointToLocation.set(e[1], points[e[0]]);
            }
        }

        List<pointEdgeCollapse> allPointInfo;
        const globalIndex globalPoints(mesh().nPoints());
        labelList pointPriority(mesh().nPoints(), 0);

        collapser.consistentCollapse
        (
            globalPoints,
            pointPriority,
            collapsePointToLocation,
            collapseEdge,
            allPointInfo
        );

        polyTopoChange meshModCollapse(mesh());

        collapser.setRefinement(allPointInfo, meshModCollapse);

        // Create a mesh from topo changes.
        autoPtr<polyTopoChangeMap> map = meshModCollapse.changeMesh(mesh());

        mesh().topoChange(map);
    }

    if (!overwrite)
    {
        runTimeExtruded++;
    }
    else
    {
        mesh().setInstance("constant");
    }

    // Take over refinement levels and write to new time directory.
    Info<< "\nWriting extruded mesh to time = " << runTimeExtruded.name()
        << nl << endl;

    mesh().write();

    Info<< "End\n" << endl;

    return 0;
}


// ************************************************************************* //
