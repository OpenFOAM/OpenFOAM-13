#include "helloLib.H"
#include <random> 
#include <cmath>
#include <algorithm>

#include <thread>   // Required for std::this_thread::sleep_for
#include <chrono>   // Required for time units

namespace Foam
{
    static std::random_device hardwareEntropy; 
    static std::mt19937 rndGen(hardwareEntropy()); 
    static std::normal_distribution<double> gaussDist(0.0, 1.0);

    int amazingGuess(int currentIndex)
    {
        double weighted_rand = gaussDist(rndGen);
        double desvioPadrao = 1; 
        
        int selectedIndex = currentIndex + static_cast<int>(
            std::round(weighted_rand * desvioPadrao)
        );

        int sleepMs = static_cast<int>(std::round(300.0 + gaussDist(rndGen) * 50.0));
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepMs));
        
        return selectedIndex % 11;
    }

    char getHello(int length){

        int luckyIndex = amazingGuess(length);
        
        return targetString[luckyIndex];
    }
}