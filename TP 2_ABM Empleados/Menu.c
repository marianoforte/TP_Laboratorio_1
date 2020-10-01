#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"
#include "ArrayEmployees.h"
#include "Input&Validation.h"
#define SIZE 3


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
        printf("\n ______________________________________________");
        printf("\n|                                              |");
        printf("\n|**********ADMINISTRACION DE EMPLEADOS*********|");
        printf("\n|______________________________________________|\n\n");
        option = getInt("\nSelecciona una opcion\n 1. ALTA\n 2. MODIFICAR\n 3. BAJA\n 4. INFORMAR\n 0. SALIR\n\nIngrese una opcion: ");
        switch(option)
        {
        case 1://ALTA
            freeRowEmployeesList = searchListingFirstEmptyPlace(employeesListing, SIZE);
            if(freeRowEmployeesList == -1 || freeRowEmployeesList == SIZE)
            {
                printf("\n\n------------------------------------------------------------------------------------\n\n");
                printf("\n\nEl listado esta lleno. Elimina alg%cn empleado para ingresar uno nuevo\n\n",163);
                printf("\n\n------------------------------------------------------------------------------------\n\n");
            }
            else
            {
                lastId = createId(employeesListing,lastId,freeRowEmployeesList);
                employeesListing[freeRowEmployeesList] = getEmployee(employeesListing[freeRowEmployeesList]);
                employeesListing[freeRowEmployeesList].isEmpty = changeIsEmptyState(employeesListing[freeRowEmployeesList]);
                employeesListing[freeRowEmployeesList].id = lastId;
                printf("\n\n------------------------------------------------------------------------------------\n\n");
                printf("Se le ha asignado la ID %04d.",lastId);
                printf("\n\n------------------------------------------------------------------------------------\n\n");
            }
            system("pause");
            system("cls");
            break;
        case 2://MODIFICAR
            if(lastId == 0)
            {
                printf("\n\n------------------------------------------------------------------------------------\n\n");
                printf("\nNo se han ingresado empleados hasta el momento.\n");
                printf("\n\n------------------------------------------------------------------------------------\n\n");
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
                printf("\n\n------------------------------------------------------------------------------------\n\n");
                printf("\nNo se han ingresado empleados hasta el momento.\n");
                printf("\n\n------------------------------------------------------------------------------------\n\n");
            }
            else
            {
                deleteEmployee(employeesListing, SIZE);
            }
            system("pause");
            system("cls");
            break;
        case 4://MOSTRAR
            sortEmployees(employeesListing,SIZE);
            printList(employeesListing,SIZE);
        case 0: //SALIR
            break;
        default:
            printf("Opci%cn inv%clida. Elija nuevamente.\n\n",162,160);
            system("pause");
            system("cls");
            break;
        }
        printf("\n\n");
    }
    while(option!=0);
    printf("\n\n------------------------------------------------------------------------------------\n\n");
    printf("\nGracias por utilizar la aplicaci%cn. Desarrollada por Mariano Forte. Version 3.0\n",162);
    printf("\n\n------------------------------------------------------------------------------------\n\n");
}
