#ifndef helloSolver_H
#define helloSolver_H

#include "string.H"

namespace Foam
{
    class helloSolver
    {
    public:
        // Construtor limpo (nao pede mais o relogio do OpenFOAM)
        helloSolver();

        ~helloSolver();

        
        string currentHello = ""; // Armazena o hello atual
        
        // O metodo principal agora recebe o passo manualmente
        void evolve(int step);
    };
}

#endif  