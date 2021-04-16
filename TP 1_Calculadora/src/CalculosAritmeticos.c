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

/** \brief Recibe los datos ingresado y los valida para reconocer si es de tipo num�rico o caracter
 * \param If condiciona el ingreso de caracteres obtenidos por el scanf a s�lo n�meros, si devuelve 1 no se cumpli� con
        el formato especificado y muestra un mensaje al usuario aclarando lo que sucede y luego limpia el b�fer del teclado
        para que la pr�xima llamada del scanf pause el programa
 * \param If verifica si el b�fer del teclado qued� sucio y luego lo limpia
 * \return Retorna 0 en caso que no ingrese en la iteraci�n, validando que el dato ingresado es de tipo num�rico
 */

int ValidarDato(const char* floatMask, void* variable)
{
    int caracter;
    if(!scanf(floatMask, variable))
    {
        while((caracter = getchar()) != '\n' && caracter != EOF);
        printf("\nError. Eso no es un numero.\n");
        return 1;
    }
    if(getchar() != '\n')
    {
        while((caracter = getchar()) != '\n' && caracter != EOF);
        printf("\nError. Eso no es un numero.\n");
        return 1;
    }
    return 0;
}

/**
 * \brief Recibe los n�meros ingresados por el usuario y los suma
 * \param Suma es la variable que adquiere la adici�n de ambos n�meros
 * \return Retorna el resultado de la suma
 */
float SumaOperandos(float primerNumero, float segundoNumero)
{
    float suma;
    suma = primerNumero + segundoNumero;
    return suma;
}

/**
 * \brief Recibe los n�meros ingresados por el usuario y los resta
 * \param Resta es la variable que adquiere la sustracci�n del segundo n�mero al primero
 * \return Retorna el resultado de la resta
 */
float RestaOperandos(float primerNumero, float segundoNumero)
{
    float resta;
    resta = primerNumero - segundoNumero;
    return resta;
}

/**
 * \brief Recibe los n�meros ingresados por el usuario y los divide
 * \param Cociente es la variable que adquiere el resultado de la divisi�n entre el cociente y el divisor
 * \return Retorna el resultado de la divisi�n
 */
float DivisionOperandos(float dividendo, float divisor)
{
    float cociente;
    cociente = dividendo / divisor;
    return cociente;
}

/**
 * \brief Recibe los n�meros ingresados por el usuario y los multiplica
 * \param Producto es la variable que adquiere el resultado de la multiplicaci�n entre los dos n�meros
 * \return Retorna el resultado de la multiplicaci�n
 */
float MultiplicacionOperandos(float primerNumero, float segundoNumero)
{
    float producto;
    producto = primerNumero * segundoNumero;
    return producto;
}

/**
 * \brief Recibe el primer n�mero ingresado por el usuario y lo factorea
 * \param If comprobrueba que el n�mero ingresado sea distinto de 0, dentro contiene un for que realiza una
          iteraci�n multiplicando el n�mero ingresado por el �ndice de repeticiones
          retornando el resultado factorial
 * \param Else retorna 1 en caso que el n�mero ingresado sea 0, ya que por definici�n el factorial de 0 es 1
 * \return Retorna el resultado validado de la operaci�n factorial
 */
unsigned long long int Factorial(double primerNumero)
{
    unsigned long long int resultado;
    int i;
    resultado = 1;
    if(primerNumero != 0)
    {
        for(i=2; i<=primerNumero; i++){
            resultado *= i;
        }
        return (resultado);
    }
    else
    {
        return 1;
    }
}

/**
 * \brief Recibe los datos de la funcion Factorial y verifica si el n�mero ingresado es un entero
 * \param Entero es la variable de comprobaci�n que se le es asignada la variable de entrada float y toma s�lo
 *        la parte entera
 * \param Resultado recibe la funci�n Factorial
 * \param Se asigna el n�mero float ingresado por el usuario a la variable entero para quitarle los decimales
 * \param If quita la parte entera del n�mero dejando s�lo la parte decimal
 * \param En caso de que haya parte decimal se imprime un mensaje de error, caso contrario se asigna
          a la variable resultado la funci�n Factorial
 * \return Imprime en pantalla el resultado de la factorizaci�n
 */
void ValidacionFactorial(float numero)
{
    int entero;
    unsigned long long int resultado;
    entero = numero;
    if(numero - entero)
    {
        printf("Error. Los numeros decimales no pueden factorizarse.\n\n");
    }
    else
    {
        resultado = Factorial(numero);
        printf("El factorial de %.0f es %llu\n\n",numero,resultado);
    }
}

