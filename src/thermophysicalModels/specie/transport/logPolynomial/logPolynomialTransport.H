/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | OpenFOAM: The Open Source CFD Toolbox
   \\    /   O peration     | Website:  https://openfoam.org
    \\  /    A nd           | Copyright (C) 2016-2025 OpenFOAM Foundation
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
    Foam::logPolynomialTransport

Description
    Transport package using polynomial functions of the natural logarithm of
    temperature for the natural logarithm of dynamic viscosity and thermal
    conductivity:

    \verbatim
        log(mu) = muLogCoeffs[0] + muLogCoeffs[1]*log(T)
           + muLogCoeffs[2]*sqr(log(T)) + muLogCoeffs[3]*pow3(log(T))
           + muLogCoeffs[4]*pow4(log(T)) + muLogCoeffs[5]*pow(log(T), 5)
           + muLogCoeffs[6]*pow(log(T), 6) + muLogCoeffs[7]*pow(log(T), 7)

        log(kappa) = kappaLogCoeffs[0] + kappaLogCoeffs[1]*log(T)
           + kappaLogCoeffs[2]*sqr(log(T)) + kappaLogCoeffs[3]*pow3(log(T))
           + kappaLogCoeffs[4]*pow4(log(T)) + kappaLogCoeffs[5]*pow(log(T), 5)
           + kappaLogCoeffs[6]*pow(log(T), 6) + kappaLogCoeffs[7]*pow(log(T), 7)
    \endverbatim

    The polynomial function is templated on the order of the polynomial which
    defaults to 8.

Usage
    \table
        Property           | Description
        muLogCoeffs<8>     | Dynamic viscosity polynomial coefficients
        kappaLogCoeffs<8>  | Thermal conductivity polynomial coefficients
    \endtable

    Example of the specification of the transport properties:
    \verbatim
    transport
    {
        muLogCoeffs<8>     (1000 -0.05 0.003 0 0 0 0 0);
        kappaLogCoeffs<8>  (2000 -0.15 0.023 0 0 0 0 0);
    }
    \endverbatim

SourceFiles
    logPolynomialTransportI.H
    logPolynomialTransport.C

See also
    Foam::Polynomial

\*---------------------------------------------------------------------------*/

#ifndef logPolynomialTransport_H
#define logPolynomialTransport_H

#include "Polynomial.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// Forward declaration of friend functions and operators

template<class Thermo, int PolySize> class logPolynomialTransport;

template<class Thermo, int PolySize>
inline logPolynomialTransport<Thermo, PolySize> operator+
(
    const logPolynomialTransport<Thermo, PolySize>&,
    const logPolynomialTransport<Thermo, PolySize>&
);

template<class Thermo, int PolySize>
inline logPolynomialTransport<Thermo, PolySize> operator*
(
    const scalar,
    const logPolynomialTransport<Thermo, PolySize>&
);

template<class Thermo, int PolySize>
Ostream& operator<<
(
    Ostream&,
    const logPolynomialTransport<Thermo, PolySize>&
);


/*---------------------------------------------------------------------------*\
                   Class logPolynomialTransport Declaration
\*---------------------------------------------------------------------------*/

template<class Thermo, int PolySize=8>
class logPolynomialTransport
:
    public Thermo
{
    // Private Data

        //- Dynamic viscosity polynomial coefficients [Pa.s/K^i]
        Polynomial<PolySize> muLogCoeffs_;

        //- Thermal conductivity polynomial coefficients [W/m/K/K^i]
        Polynomial<PolySize> kappaLogCoeffs_;


public:

    // Constructors

        //- Construct from components
        inline logPolynomialTransport
        (
            const Thermo& t,
            const Polynomial<PolySize>& muPoly,
            const Polynomial<PolySize>& kappaPoly
        );

        //- Construct as named copy
        inline logPolynomialTransport
        (
            const word&,
            const logPolynomialTransport&
        );

        //- Construct from name and dictionary
        logPolynomialTransport(const word& name, const dictionary& dict);

        //- Construct and return a clone
        inline autoPtr<logPolynomialTransport> clone() const;


    // Member Functions

        //- Return the instantiated type name
        static word typeName()
        {
            return "logPolynomial<" + Thermo::typeName() + '>';
        }

        //- Dynamic viscosity [kg/m/s]
        inline scalar mu(const scalar p, const scalar T) const;

        //- Thermal conductivity [W/m/K]
        inline scalar kappa(const scalar p, const scalar T) const;

        //- Write to Ostream
        void write(Ostream& os) const;


    // Member Operators

        inline void operator+=(const logPolynomialTransport&);
        inline void operator*=(const scalar);


    // Friend operators

        friend logPolynomialTransport operator+ <Thermo, PolySize>
        (
            const logPolynomialTransport&,
            const logPolynomialTransport&
        );

        friend logPolynomialTransport operator* <Thermo, PolySize>
        (
            const scalar,
            const logPolynomialTransport&
        );


    // Ostream Operator

        friend Ostream& operator<< <Thermo, PolySize>
        (
            Ostream&,
            const logPolynomialTransport&
        );
};


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "logPolynomialTransportI.H"

#ifdef NoRepository
    #include "logPolynomialTransport.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
