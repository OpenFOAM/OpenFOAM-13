#include "argList.H"
#include "helloSolver.H"

using namespace Foam;

int main(int argc, char *argv[])
{
    // Sua tela de boot intocada!
    Info<< "\n========================================================\n";
    Info<< "    __  __  ______  __      __      ____   \n";
    Info<< "   / / / / / ____/ / /     / /     / __ \\  \n";
    Info<< "  / /_/ / / __/   / /     / /     / / / /  \n";
    Info<< " / __  / / /___  / /___  / /___  / /_/ /   \n";
    Info<< "/_/ /_/ /_____/ /_____/ /_____/  \\____/    \n";
    Info<< "                                           \n";
    Info<< "    ______  ____    ___     __  ___        \n";
    Info<< "   / ____/ / __ \\  /   |   /  |/  /        \n";
    Info<< "  / /_    / / / / / /| |  / /|_/ /         \n";
    Info<< " / __/   / /_/ / / ___ | / /  / /          \n";
    Info<< "/_/      \\____/ /_/  |_|/_/  /_/           \n";
    Info<< "                                           \n";
    Info<< "                  from SINMEC              \n";
    Info<< "========================================================\n" << endl;

    Info<< "\n[ helloFoam ] Initializing..." << endl;
    
    // Instancia o objeto livremente
    helloSolver mySolver;

    Info<< "\n[ helloFoam ] Hello solver created!" << endl;

    // Loop simples do C++ em vez do runTime.loop()
    int passo = 0;
    while (mySolver.currentHello.length() < 11)
    {
        Info<< "[ helloFoam ] Iteracao atual = " << passo << endl;

        // Manda o objeto rodar
        mySolver.evolve(passo);
        
        Info<< "[ helloFoam ] Current Hello: " << mySolver.currentHello << endl;
        passo++;
    }

    Info<< "[ helloFoam ] Final Hello: " << mySolver.currentHello << endl;
    return 0;
}