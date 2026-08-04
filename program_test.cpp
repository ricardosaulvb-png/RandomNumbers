#include <iostream>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <vector>
#include <fstream>
using namespace std;

inline int random()
{
    long tiempo = std::chrono::steady_clock::now().time_since_epoch().count();
    int numbase = static_cast<int>(tiempo);

    numbase = ((numbase >> 16) ^ numbase) * 0x45d9f3b;
    numbase = ((numbase >> 16) ^ numbase) * 0x45d9f3b;
    numbase = (numbase >> 16) ^ numbase;

    static std::vector<std::vector<int>> historial;


    return numbase;
}



int main()
{
    // Ruta directa al escritorio del usuario Acer
    std::ofstream archivo("YOU CAN WRITE YOUR RUTE");

    if (!archivo.is_open()) {
        std::cout << "Error al crear el archivo en el Escritorio." << std::endl;
        return 1;
    }

    std::cout << "Generando 100,000 numeros en tu Escritorio..." << std::endl;

    for (int i = 0; i < 100000; ++i)
    {
        archivo << random() << "\n";
    }

    archivo.close();
    std::cout << "¡Listo! El archivo 'datos_random.txt' aparecio en tu Escritorio." << std::endl;
    return 0;
}
