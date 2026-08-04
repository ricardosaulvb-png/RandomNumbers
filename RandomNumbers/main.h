#ifndef LIBRERIA_RANDOM_H
#define LIBRERIA_RANDOM_H

#include <cstdlib>
#include <chrono>


inline int aleatorio()
{
    long tiempo = std::chrono::steady_clock::now().time_since_epoch().count();
    int numbase = static_cast<int>(tiempo);

    numbase = ((numbase >> 16) ^ numbase) * 0x45d9f3b;
    numbase = ((numbase >> 16) ^ numbase) * 0x45d9f3b;
    numbase = (numbase >> 16) ^ numbase;

    return numbase;

}
#endif


