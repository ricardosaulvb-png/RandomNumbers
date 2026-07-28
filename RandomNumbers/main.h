#ifndef LIBRERIA_RANDOM_H
#define LIBRERIA_RANDOM_H

#include <chrono> 
#include <vector>


inline int aleatorio()
{
    long tiempo = std::chrono::steady_clock::now().time_since_epoch().count();
    int numbase = (tiempo % 60) + ((tiempo / 60) % 60);

    static std::vector<std::vector<int>> historial;

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

    bool yaExiste = false;

    for (size_t i = 0; i < historial.size(); ++i)
    {
        for (size_t j = 0; j < historial[i].size(); ++j)
        {
            if (historial[i][j] == numbase)
            {
                yaExiste = true;
                break; 
            }
        }
        if (yaExiste) break; 
    }

    while (true)
    {
        if (yaExiste)
        {
            numbase = static_cast<int>(numbase / 3.141592653);
            historial.push_back({numbase});
            break;
        }
        else
        {
            historial.push_back({numbase});
            break;
        }
    }

    return numbase;
}

#endif
