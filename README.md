=============================================================================
                       NUMERIC ORACLE - RANDOM LIBRARY
===============================================================================

This is a lightweight "Header-Only" library for C++. It generates random 
numbers based on system time through a custom mathematical formula. 

Created specifically for those looking for a simple, direct alternative 
without the annoying and complex setups of the standard <random> library.

-------------------------------------------------------------------------------
HOW TO INSTALL IT:
-------------------------------------------------------------------------------
1. Download the "main.h" file from this repository.
2. Place it in the same folder where your project's source code is located.
3. In Visual Studio, right-click on "Header Files" -> Add -> Existing Item, 
   and select "main.h".

-------------------------------------------------------------------------------
HOW TO USE IT (CODE EXAMPLE):
-------------------------------------------------------------------------------
To call the random number, just include the header at the top of your main 
file and trigger the aleatorio() function by assigning it to a variable.

Here is an example based on the "Numeric Oracle" game:

#include <iostream>
#include <string>
#include "main.h" // <-- Connect the downloaded library here

using namespace std;

int main()
{
    // Call the function directly and save the number into a variable
    int finalnum = aleatorio(); 
    
    // Now you can use that variable to calculate your mathematical clues
    int antesnum = finalnum - 5;
    int despuesnum = finalnum + 5;
    int mitadnum = finalnum / 2;
    int doblenum = finalnum * 2;
    int playernum = 0;

    cout << "The number you want is between " << antesnum << " and " << despuesnum << ".\n";
    cout << "What do you think the number is?: ";
    cin >> playernum;

    if (playernum == finalnum) {
        cout << "Congratulations, you got it right!\n";
    } else {
        cout << "Incorrect, the number was: " << finalnum << "\n";
    }

    return 0;
}

-------------------------------------------------------------------------------
BENEFITS:
- Zero complex configurations with engines or seeders.
- Does not require extra .cpp files to compile.
- Call it and use it instantly.
===============================================================================



===============================================================================
                       ORACULO NUMERICO - LIBRERIA RANDOM
===============================================================================

Esta es una libreria ligera del tipo "Header-Only" para C++. Genera numeros 
aleatorios basados en el tiempo del sistema mediante una formula matematica 
propia. 

Creada especificamente para quienes buscan una alternativa simple, directa y
sin las molestas configuraciones de la libreria estandar <random>.

-------------------------------------------------------------------------------
COMO INSTALARLA:
-------------------------------------------------------------------------------
1. Descarga el archivo "main.h" de este repositorio.
2. Ponlo en la misma carpeta donde tienes el codigo fuente de tu proyecto.
3. En Visual Studio, haz clic derecho en "Archivos de encabezado" -> Agregar 
   -> Elemento existente, y selecciona "main.h".

-------------------------------------------------------------------------------
COMO UTILIZARLA (EJEMPLO DE USO):
-------------------------------------------------------------------------------
Para convocar el numero aleatorio, solo debes incluir la cabecera al inicio 
de tu archivo principal y llamar a la funcion aleatorio() asignandola a una 
variable. 

Aqui tienes un ejemplo basado en el juego del "Oraculo Numerico":

#include <iostream>
#include <string>
#include "main.h" // <-- Aqui conectas la libreria descargada

using namespace std;

int main()
{
    // Convocas la funcion directamente y guardas el numero en una variable
    int finalnum = aleatorio(); 
    
    // Ahora puedes usar esa variable para calcular tus pistas matematicas
    int antesnum = finalnum - 5;
    int despuesnum = finalnum + 5;
    int mitadnum = finalnum / 2;
    int doblenum = finalnum * 2;
    int playernum = 0;

    cout << "El numero que quieres esta entre el " << antesnum << " y el " << despuesnum << ".\n";
    cout << "Cual crees que es el numero?: ";
    cin >> playernum;

    if (playernum == finalnum) {
        cout << "Felicidades, acertaste!\n";
    } else {
        cout << "Incorrecto, el numero era: " << finalnum << "\n";
    }

    return 0;
}

-------------------------------------------------------------------------------
VENTAJAS:
- Cero configuraciones complejas de motores o semillas (seeders).
- No requiere archivos .cpp adicionales para compilar.
- Invocar y usar al instante.
===============================================================================
