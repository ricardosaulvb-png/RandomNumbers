#ifndef LIBRERIA_RANDOM_H
#define LIBRERIA_RANDOM_H

#include <ctime> 


inline int aleatorio()
{
    long tiempo = time(0);
    int numbase = (tiempo % 60) + ((tiempo / 60) % 60);

    numbase = numbase + 1;
    numbase = numbase * 5;

    if (numbase >= 10)
    {
        numbase = numbase / 5;
        numbase = numbase * 7;
    }
    else if (numbase <= 10)
    {
        numbase = numbase * 20;
        numbase = numbase * 5;
    }
    else {
        numbase = numbase * 10;
    }

    if (numbase >= 100)
    {
        numbase = numbase / 7;
    }

    return numbase;
}

#endif
