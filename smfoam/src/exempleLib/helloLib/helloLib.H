#ifndef helloLib_H
#define helloLib_H

#include "string.H"

namespace Foam
{
    const char* targetString = "Hello FOAM!";

    int amazingGuess(int currentIndex);
    char getHello(int length);
}

#endif