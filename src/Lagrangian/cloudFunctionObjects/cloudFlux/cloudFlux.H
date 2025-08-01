/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2025 OpenFOAM Foundation
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

Class
    Foam::functionObjects::cloudFlux

Description
    Base class for functions which generate the flux of a cloud

SourceFiles
    cloudFlux.C

\*---------------------------------------------------------------------------*/

#ifndef cloudFlux_functionObject_H
#define cloudFlux_functionObject_H

#include "LagrangianPatchField.H"
#include "cloudFvMeshFunctionObject.H"
#include "surfaceFields.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{
namespace functionObjects
{

/*---------------------------------------------------------------------------*\
                       Class cloudFlux Declaration
\*---------------------------------------------------------------------------*/

class cloudFlux
:
    public cloudFvMeshFunctionObject
{
private:

    // Private Data

        //- Flux field
        surfaceScalarField phi_;


    // Private Member Functions

        //- Return the property for which to compute the flux
        virtual tmp<LagrangianSubScalarSubField> q
        (
            const LagrangianSubScalarSubField& fraction
        ) const = 0;

        //- Helper for crossing patch faces in either direction
        void crossPatchFaces
        (
            const LagrangianSubScalarSubField& fraction,
            const label sign
        );


public:

    //- Runtime type information
    TypeName("cloudFlux");


    // Constructors

        //- Construct from Time and dictionary
        cloudFlux
        (
            const word& name,
            const Time& runTime,
            const dictionary& dict,
            const word& phiName,
            const dimensionSet& qDims
        );

        //- Disallow default bitwise copy construction
        cloudFlux(const cloudFlux&) = delete;


    //- Destructor
    virtual ~cloudFlux();


    // Member Functions

        //- Return the list of fields required
        virtual wordList fields() const;

        //- Return false so this function does not execute at the start
        virtual bool executeAtStart() const;

        //- Do nothing. Everything happens in faces crossing hooks.
        virtual bool execute();

        //- Hook before solution steps
        virtual void preSolve();

        //- Hook before face crossings of a specific sub-mesh
        virtual void preCrossFaces
        (
            const LagrangianSubScalarSubField& fraction
        );

        //- Hook following face crossings of a specific sub-mesh
        virtual void postCrossFaces
        (
            const LagrangianSubScalarSubField& fraction
        );

        //- Write the number flux
        virtual bool write();

        //- Clear the number flux
        virtual bool clear();


    // Member Operators

        //- Disallow default bitwise assignment
        void operator=(const cloudFlux&) = delete;
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace functionObjects
} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
