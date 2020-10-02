#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "ConsoleOutputStyle.h"

void Color(int background, int text){ // Función para cambiar el color del fondo y/o pantalla

    HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE); // Tomamos la consola.

    // Para cambiar el color, se utilizan números desde el 0 hasta el 255.
    // Pero, para convertir los colores a un valor adecuado, se realiza el siguiente cálculo.

    int New_Color= text + (background * 16);

    SetConsoleTextAttribute(Console, New_Color); // Guardamos los cambios en la Consola.

}

