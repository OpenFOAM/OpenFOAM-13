#include "helloSolver.H"
#include "helloLib.H" // The powerful core function
#include "IOstreams.H"

namespace Foam
{
    helloSolver::helloSolver()
    {
        Info<< "[helloSolver] Creating helloSolver" << endl;
    }

    helloSolver::~helloSolver()
    {}

    void helloSolver::evolve(int step)
    {
        Info << "[helloSolver] Calculating hello " << endl;

        char expected = targetString[step];
        char guess = '?';

        int chances = 5;
        while (chances-- > 0){
            
            guess = getHello(step);

            Info << "Guess: " << guess << endl;

            if (guess == expected){
                currentHello += guess;
                return;
            }
        }
        currentHello += guess;
    }

}
