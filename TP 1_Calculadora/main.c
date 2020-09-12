#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
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
    float producto;
    float division;
    double factorialPrimerNumero;
    double factorialSegundoNumero;
    int flagPrimerNumero;
    int flagSegundoNumero;
    int flagCalcularOperaciones;
    char salir;
    flagPrimerNumero = 0;
    flagSegundoNumero = 0;
    flagCalcularOperaciones = 0;
    salir = 'n';

    do{
        system("cls");
        printf("\n ______________________________________________");
        printf("\n|                                              |");
        printf("\n|**************CALCULADORA*********************|");
        printf("\n|______________________________________________|\n\n");
        if(flagPrimerNumero == 0)
        {
            printf("\n1- Ingresar 1er operando (A)\n");
        }
        else
        {
            printf("\n1- Ingresar 1er operando (A = %.2f)\n",primerNumero);
        }
        if(flagSegundoNumero == 0)
        {
            printf("2- Ingresar 2do operando (B)\n");
        }
        else
        {
            printf("2- Ingresar 2do operando (B = %.2f)\n",segundoNumero);
        }
        printf("3- Calcular todas las operaciones\n");
        printf("    a) Calcular la suma (A+B)\n");
        printf("    b) Calcular la resta (A-B)\n");
        printf("    c) Calcular la multiplicaci%cn (A*B)\n",162);
        printf("    d) Calcular la divisi%cn (A/B)\n",162);
        printf("    e) Calcular factoriales (A!) y (B!)\n");
        printf("4- Mostrar resultados\n");
        printf("5- Salir\n\n");
        printf("Opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
            case 1:
                do
                {
                    printf("\nIngrese el 1er operando: ");
                    flagPrimerNumero = 1;
                }while(ValidarDato("%f", &primerNumero));
                break;
            case 2:
                do
                {
                    printf("\nIngrese el 2do operando: ");
                    flagSegundoNumero = 1;
                }while(ValidarDato("%f", &segundoNumero));
                break;
            case 3:
                if(flagPrimerNumero == 0 && flagSegundoNumero == 0)
                {
                    printf("\nNo es posible calcular las operaciones. Ingrese alg%cn n%cmero.\n",163,163);
                }
                else
                {
                    flagCalcularOperaciones = 1;
                    suma = SumaOperandos(primerNumero,segundoNumero);
                    resta = RestaOperandos(primerNumero,segundoNumero);
                    producto = MultiplicacionOperandos(primerNumero,segundoNumero);
                    division = DivisionOperandos(primerNumero,segundoNumero);
                    factorialPrimerNumero = FactorialPrimerNumero(primerNumero);
                    factorialSegundoNumero = FactorialSegundoNumero(segundoNumero);
                    AnimacionCalculos(primerNumero, segundoNumero);
                }
                printf("\n");
                system("pause");
                break;
            case 4:
                printf("\n-------------------------------------------------------------------------------\n\n");
                if(flagCalcularOperaciones == 0)
                {
                    printf("No se han calculado las operaciones.");
                }
                else
                {
                    if(flagPrimerNumero == 0)
                    {
                        printf("No se han cargado n%cmeros en el 1er operando.\n",163);
                    }
                    else
                    {
                        printf("1er operando: %.2f\n",primerNumero);
                    }
                    if(flagSegundoNumero == 0)
                    {
                        printf("\nNo se han cargado n%cmeros en el 2do operando.\n",163);
                    }
                    else
                    {
                        printf("\n2do operando: %.2f\n\n",segundoNumero);
                    }
                    printf("\nResultados: \n\n");
                    if(flagPrimerNumero == 0 || flagSegundoNumero == 0)
                    {
                        printf("No pudo realizarse la suma ya que no se han cargado ambos n%cmeros.\n",163);
                        printf("No pudo realizarse la resta ya que no se han cargado ambos n%cmeros.\n",163);
                        printf("No pudo realizarse la multiplicaci%cn ya que no se han cargado ambos n%cmeros.\n",162,163);
                        printf("No pudo realizarse la divisi%cn ya que no se han cargado ambos n%cmeros.\n",162,163);
                    }
                    else
                    {
                        printf("La suma es %.2f\n",suma);
                        printf("La resta es %.2f\n",resta);
                        printf("El producto es %.2f\n",producto);
                        if(segundoNumero == 0)
                        {
                            printf("Error. No es posible dividir por 0.\n");
                        }
                        else
                        {
                            printf("El cociente es %.2f\n",division);
                        }
                    }
                    if(flagPrimerNumero == 0)
                    {
                        printf("No pudo realizarse la factorizaci%cn ya que no se ha cargado el 1er n%cmero.\n",162,163);
                    }
                    else
                    {
                        if(primerNumero < 0)
                        {
                            printf("El factorial de un numero negativo (%.0f) es indefinido\n", primerNumero);
                        }
                        else if(ValidacionFactorialPrimerNumero(primerNumero) != 0)
                        {
                            printf("El factorial de %.0f es %.0f\n",primerNumero,factorialPrimerNumero);
                        }
                        else
                        {
                            printf("Error. %.2f no puede factorizarse porque es decimal.\n",primerNumero);
                        }
                    }
                    if(flagSegundoNumero == 0)
                    {
                        printf("No pudo realizarse la factorizaci%cn ya que no se ha cargado el 2do n%cmero.\n",162,163);
                    }
                    else
                    {
                        if(segundoNumero < 0)
                        {
                            printf("El factorial de un numero negativo (%.0f) es indefinido\n", segundoNumero);
                        }
                        else if(ValidacionFactorialSegundoNumero(segundoNumero) != 0)
                        {
                            printf("El factorial de %.0f es %.0f\n",segundoNumero,factorialSegundoNumero);
                        }
                        else
                        {
                            printf("Error. %.2f no puede factorizarse porque es decimal.\n",segundoNumero);
                        }
                    }
                }

                printf("\n-------------------------------------------------------------------------------\n");
                printf("\n");
                system("pause");
                break;
            case 5:
                salir = 's';
                break;
            default:
                printf("\nOpci%cn inv%clida.\n",162,160);
                printf("\n");
                system("pause");
                break;
        }
    }while(salir == 'n');
    printf("\n-------------------------------------------------------------------------------\n");
    printf("\nGracias por utlizar la aplicaci%cn.\n",162);
    printf("\nEscrita y dise%cada por Mariano Forte.\n",164);
    printf("\nVersi%cn 3.6\n\n",162);
    printf("-------------------------------------------------------------------------------\n\n");
    return 0;
}
