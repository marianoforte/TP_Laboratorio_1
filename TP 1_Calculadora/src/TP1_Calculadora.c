/*
 ============================================================================
 Name        : TP1_Calculadora.c
 Author      : Mariano Forte
 Version     :
 Copyright   : GNU Public License v3.0
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <inttypes.h>
#include "CalculosAritmeticos.h"

int main()
{
    float primerNumero;
    float segundoNumero;
    int opcion;
    float suma;
    float resta;
    float division;
    float producto;
    unsigned long long int factorialUno;
    unsigned long long int factorialDos;
    char salir;
    primerNumero = 0;
    segundoNumero = 0;
    salir = 'n';

    setbuf(stdout,NULL);
    do{
        printf("\n1- Ingresar 1er operando (A = %.2f)\n",primerNumero);
        printf("2- Ingresar 2do operando (B = %.2f)\n",segundoNumero);
        printf("3- Calcular todas las operaciones\n");
        printf("4- Informar resultadoss\n");
        printf("5- Salir\n\n");
        printf("Opcion: ");
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                do
                {
                    printf("\nIngrese el 1er operando: ");
                }while(ValidarDato("%f", &primerNumero));
                break;
            case 2:
                do
                {
                    printf("\nIngrese el 2do operando: ");
                }while(ValidarDato("%f", &segundoNumero));
                break;
            case 3:
                SumaOperandos(primerNumero,segundoNumero, &suma);
                RestaOperandos(primerNumero,segundoNumero, &resta);
                MultiplicacionOperandos(primerNumero,segundoNumero, &producto);
                DivisionOperandos(primerNumero,segundoNumero, &division);
                Factorial(primerNumero, &factorialUno);
                Factorial(segundoNumero, &factorialDos);
                printf("-------------------------------------------------------------------------------\n");
                break;
            case 4:
            	printf("-------------------------------------------------------------------------------\n\n");
				printf("1er operando: %.2f\n",primerNumero);
				printf("2do operando: %.2f\n\n",segundoNumero);
				printf("Resultados: \n");
				printf("El resultado de %.2f + %.2f es: %.2f\n",primerNumero, segundoNumero, suma);
				printf("El resultado de %.2f - %.2f es: %.2f\n",primerNumero, segundoNumero, resta);
				if(segundoNumero == 0){
					printf("No es posible dividir por 0.\n");
				}
				else{
					printf("El resultado de %.2f / %.2f es: %.2f\n",primerNumero, segundoNumero, division);
				}
				printf("El resultado de %.2f * %.2f es: %.2f\n",primerNumero, segundoNumero, producto);
				MostrarFactorial(primerNumero, factorialUno);
				MostrarFactorial(segundoNumero, factorialDos);
				printf("-------------------------------------------------------------------------------\n");
				primerNumero = 0;
				segundoNumero = 0;
            	break;
            case 5:
                salir = 's';
                break;
        }
    }while(salir == 'n');

    printf("\n-------------------------------------------------------------------------------\n");
    printf("\nGracias por utlizar la aplicacion.\n");
    printf("\nEscrita y diseniada por Mariano Forte.\n");
    printf("\nVersion 2.1\n\n");
    printf("-------------------------------------------------------------------------------\n\n");
	return EXIT_SUCCESS;
}
