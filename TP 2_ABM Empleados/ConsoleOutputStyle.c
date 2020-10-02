#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "ConsoleOutputStyle.h"

void Colour(int background, int text){ // Funci�n para cambiar el color del fondo y/o pantalla

    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.

    // Para cambiar el color, se utilizan n�meros desde el 0 hasta el 255.
    // Pero, para convertir los colores a un valor adecuado, se realiza el siguiente c�lculo.

    int New_Colour= text + (background * 16);

    SetConsoleTextAttribute(Console, New_Colour); // Guardamos los cambios en la Consola.

}

