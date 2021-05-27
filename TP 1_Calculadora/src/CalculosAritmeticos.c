/*
 * CalculosAritmeticos.c
 *
 *  Created on: Apr 16, 2021
 *      Author: mariano.forte
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "CalculosAritmeticos.h"

/** \brief Recibe los datos ingresado y los valida para reconocer si es de tipo numérico o caracter
 * \param If condiciona el ingreso de caracteres obtenidos por el scanf a sólo números, si devuelve 1 no se cumplió con
        el formato especificado y muestra un mensaje al usuario aclarando lo que sucede y luego limpia el búfer del teclado
        para que la próxima llamada del scanf pause el programa
 * \param If verifica si el búfer del teclado quedó sucio y luego lo limpia
 * \return Retorna 0 en caso que no ingrese en la iteración, validando que el dato ingresado es de tipo numérico
 */

int ValidarDato(const char* floatMask, void* variable)
{
    int caracter;
    int rtn = 0;
    if(!scanf(floatMask, variable))
    {
        while((caracter = getchar()) != '\n' && caracter != EOF);
        printf("\nError. Eso no es un numero.\n");
        rtn = 1;
    }
    if(getchar() != '\n')
    {
        while((caracter = getchar()) != '\n' && caracter != EOF);
        printf("\nError. Eso no es un numero.\n");
        rtn = 1;
    }
    return rtn;
}

/**
 * \brief Recibe los números ingresados por el usuario y los suma
 * \param Suma es la variable que adquiere la adición de ambos números
 * \return Retorna el resultado de la suma
 */
float SumaOperandos(float primerNumero, float segundoNumero, float* suma)
{
    *suma = primerNumero + segundoNumero;
    return *suma;
}

/**
 * \brief Recibe los números ingresados por el usuario y los resta
 * \param Resta es la variable que adquiere la sustracción del segundo número al primero
 * \return Retorna el resultado de la resta
 */
float RestaOperandos(float primerNumero, float segundoNumero, float* resta)
{
    *resta = primerNumero - segundoNumero;
    return *resta;
}

/**
 * \brief Recibe los números ingresados por el usuario y los divide
 * \param Cociente es la variable que adquiere el resultado de la división entre el cociente y el divisor
 * \return Retorna el resultado de la división
 */
float DivisionOperandos(float dividendo, float divisor, float* cociente)
{
    *cociente = dividendo / divisor;
    return *cociente;
}

/**
 * \brief Recibe los números ingresados por el usuario y los multiplica
 * \param Producto es la variable que adquiere el resultado de la multiplicación entre los dos números
 * \return Retorna el resultado de la multiplicación
 */
float MultiplicacionOperandos(float primerNumero, float segundoNumero, float* producto)
{
    *producto = primerNumero * segundoNumero;
    return *producto;
}

void calcularFactorial(float primerNumero, unsigned long long int* factorial){

}

/**
 * \brief Recibe los datos de la funcion Factorial y verifica si el número ingresado es un entero
 * \param Entero es la variable de comprobación que se le es asignada la variable de entrada float y toma sólo
 *        la parte entera
 * \param Resultado recibe la función Factorial
 * \param Se asigna el número float ingresado por el usuario a la variable entero para quitarle los decimales
 * \param If quita la parte entera del número dejando sólo la parte decimal
 * \param En caso de que haya parte decimal se imprime un mensaje de error, caso contrario se asigna
          a la variable resultado la función Factorial
 * \return Imprime en pantalla el resultado de la factorización
 */
void MostrarFactorial(float numero, unsigned long long int factorial)
{

    if(factorial == 0)
    {
        printf("Error. El numero a factorizar debe pertenecer a los enteros y ser mayor a cero.\n\n");
    }
    else
    {
        printf("El factorial de %.0f es %llu\n",numero, factorial);
    }
}

/**
 * \brief Recibe el primer número ingresado por el usuario y lo factorea
 * \param If comprobrueba que el número ingresado sea distinto de 0, dentro contiene un for que realiza una
          iteración multiplicando el número ingresado por el índice de repeticiones
          retornando el resultado factorial
 * \param Else retorna 1 en caso que el número ingresado sea 0, ya que por definición el factorial de 0 es 1
 * \return Retorna el resultado validado de la operación factorial
 */
unsigned long long int Factorial(float numero, unsigned long long int* factorial)
{
    int i, entero;
    entero = numero;
    *factorial = 1;
    if((numero != 0) && !(numero-entero)){
        for(i=2; i<=numero; i++){
        	*factorial *= i;
        }
        return (*factorial);
    }
    else{
        return 0;
    }
}





