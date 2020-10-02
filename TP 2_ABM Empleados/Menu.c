#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Menu.h"
#include "ArrayEmployees.h"
#include "Input&Validation.h"
#include "ConsoleOutputStyle.h"
#define SIZE 1000

void mainMenu(void)
{
    int option;
    sEmployee employeesListing[SIZE];//MODIFY ARRAY SIZE
    int freeRowEmployeesList;
    int lastId;
    lastId = 0;

    initArrayAsEmpty(employeesListing, SIZE);
    do
    {
        Colour(WHITE,BLUE);
        printf("\n                    _____________________________________________");
        printf("\n                   |                                             |");
        printf("\n                   |*********ADMINISTRACION DE EMPLEADOS*********|");
        printf("\n                   |_____________________________________________|\n\n");
        Colour(WHITE,BLACK);
        option = getInt("\nSelecciona una opcion\n\n1. ALTA\n2. MODIFICAR\n3. BAJA\n4. INFORMAR\n   -Lista de empleados por apellido y sector en orden ascendente\n   -Promedio de todos los salarios\n0. SALIR\n\nIngrese una opcion: ");
        switch(option)
        {
        case 1://ALTA
            freeRowEmployeesList = searchListingFirstEmptyPlace(employeesListing, SIZE);
            if(freeRowEmployeesList == -1 || freeRowEmployeesList == SIZE)
            {
                Colour(WHITE,BLUE);
                printf("\n\n------------------------------------------------------------------------------------\n\n");
                Colour(WHITE,RED);
                printf("\n\nEl listado esta lleno. Elimina alg%cn empleado para ingresar uno nuevo\n\n",163);
                Colour(WHITE,BLUE);
                printf("\n\n------------------------------------------------------------------------------------\n\n");
                Colour(WHITE,BLACK);
            }
            else
            {
                lastId = createId(employeesListing,lastId,freeRowEmployeesList);
                employeesListing[freeRowEmployeesList] = getEmployee(employeesListing[freeRowEmployeesList]);
                employeesListing[freeRowEmployeesList].isEmpty = changeIsEmptyState(employeesListing[freeRowEmployeesList]);
                employeesListing[freeRowEmployeesList].id = lastId;
                Colour(WHITE,BLUE);
                printf("\n\n------------------------------------------------------------------------------------\n\n");
                Colour(WHITE,MAGENTA );
                printf("Se le ha asignado la ID %04d.",lastId);
                Colour(WHITE,BLUE);
                printf("\n\n------------------------------------------------------------------------------------\n\n");
                Colour(WHITE,BLACK);
            }
            system("pause");
            system("cls");
            break;
        case 2://MODIFICAR
            if(lastId == 0)
            {
                Colour(WHITE,BLUE);
                printf("\n\n------------------------------------------------------------------------------------\n\n");
                Colour(WHITE,RED);
                printf("\nNo se han ingresado empleados hasta el momento.\n");
                Colour(WHITE,BLUE);
                printf("\n\n------------------------------------------------------------------------------------\n\n");
                Colour(WHITE,BLACK);
            }
            else
            {
                modifyEmployee(employeesListing, SIZE);
            }
            system("pause");
            system("cls");
            break;
        case 3://BAJA
            if(lastId == 0)
            {
                Colour(WHITE,BLUE);
                printf("\n\n------------------------------------------------------------------------------------\n\n");
                Colour(WHITE,RED);
                printf("\nNo se han ingresado empleados hasta el momento.\n");
                Colour(WHITE,BLUE);
                printf("\n\n------------------------------------------------------------------------------------\n\n");
                Colour(WHITE,BLACK);
            }
            else
            {
                deleteEmployee(employeesListing, SIZE);
            }
            system("pause");
            system("cls");
            break;
        case 4://MOSTRAR
            if(lastId == 0)
            {
                Colour(WHITE,BLUE);
                printf("\n\n------------------------------------------------------------------------------------\n\n");
                Colour(WHITE,RED);
                printf("\nNo se han ingresado empleados hasta el momento.\n");
                Colour(WHITE,BLUE);
                printf("\n\n------------------------------------------------------------------------------------\n\n");
                Colour(WHITE,BLACK);
            }
            else
            {
                sortEmployees(employeesListing,SIZE);
                printList(employeesListing,SIZE);
            }
            system("pause");
            system("cls");
        case 0: //SALIR
            printf("\n\n");
            Colour(WHITE,BLUE);
            printf("------------------------------------------------------------------------------------\n");
            Colour(WHITE,GREEN);
            printf("\n                         Gracias por utilizar la aplicaci%cn.\n\n                       Dise%co y desarrollo por Mariano Forte.\n\n                                    Version 4.8.2\n",162,164);
            Colour(WHITE,BLUE);
            printf("\n------------------------------------------------------------------------------------\n");
            Colour(WHITE,BLACK);
            system("pause");
            break;
        default:
            Colour(WHITE,RED);
            printf("Opci%cn inv%clida. Elija nuevamente.\n\n",162,160);
            Colour(WHITE,BLACK);
            system("pause");
            system("cls");
            break;
        }
    }while(option!=0);

}
