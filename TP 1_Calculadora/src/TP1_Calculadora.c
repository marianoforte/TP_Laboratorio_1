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
    char salir;
    primerNumero = 0;
    segundoNumero = 0;
    salir = 'n';

    setbuf(stdout,NULL);
    do{
        printf("\n1- Ingresar 1er operando (A = %.2f)\n",primerNumero);
        printf("2- Ingresar 2do operando (B = %.2f)\n",segundoNumero);
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n\n");
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
                suma = SumaOperandos(primerNumero,segundoNumero);
                printf("-------------------------------------------------------------------------------\n\n");
                printf("1er operando: %.2f\n",primerNumero);
                printf("2do operando: %.2f\n\n",segundoNumero);
                printf("Resultado: \n");
                printf("La suma es %.2f\n\n",suma);
                printf("-------------------------------------------------------------------------------\n");
                break;
            case 4:
                resta = RestaOperandos(primerNumero,segundoNumero);
                printf("1er operando: %.2f\n",primerNumero);
                printf("2do operando: %.2f\n\n",segundoNumero);
                printf("-------------------------------------------------------------------------------\n\n");
                printf("Resultado: \n");
                printf("La resta es %.2f\n\n",resta);
                printf("-------------------------------------------------------------------------------\n");
                break;
            case 5:
                printf("-------------------------------------------------------------------------------\n\n");
                printf("1er operando: %.2f\n",primerNumero);
                printf("2do operando: %.2f\n\n",segundoNumero);
                if(segundoNumero == 0){
                    printf("Error. No se puede dividir por 0.\n\n");
                }
                else{
                    division = DivisionOperandos(primerNumero,segundoNumero);
                    printf("Resultado: \n");
                    printf("El cociente es %.2f\n\n",division);
                }
                printf("-------------------------------------------------------------------------------\n");
                break;
            case 6:
                producto = MultiplicacionOperandos(primerNumero,segundoNumero);
                printf("-------------------------------------------------------------------------------\n\n");
                printf("1er operando: %.2f\n",primerNumero);
                printf("2do operando: %.2f\n\n",segundoNumero);
                printf("Resultado: \n");
                printf("El producto es %.2f\n\n",producto);
                printf("-------------------------------------------------------------------------------\n");
                break;
            case 7:
                printf("-------------------------------------------------------------------------------\n\n");
                printf("Resultado: \n");
                ValidacionFactorial(primerNumero);
                printf("-------------------------------------------------------------------------------\n");
                break;
            case 8:
                suma = SumaOperandos(primerNumero,segundoNumero);
                resta = RestaOperandos(primerNumero,segundoNumero);
                producto = MultiplicacionOperandos(primerNumero,segundoNumero);
                printf("-------------------------------------------------------------------------------\n\n");
                printf("1er operando: %.2f\n",primerNumero);
                printf("2do operando: %.2f\n\n",segundoNumero);
                printf("Resultados: \n");
                printf("La suma es %.2f\n",suma);
                printf("La resta es %.2f\n",resta);
                if(segundoNumero == 0){
                    printf("Error. No se puede dividir por 0.\n");
                }
                else{
                    division = DivisionOperandos(primerNumero,segundoNumero);
                    printf("El cociente es %.2f\n",division);
                }
                printf("El producto es %.2f\n",producto);
                ValidacionFactorial(primerNumero);
                printf("-------------------------------------------------------------------------------\n");
                break;
            case 9:
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
