#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "Input&Validation.h"
#include "ConsoleOutputStyle.h"

int initArrayAsEmpty(sEmployee employeeData[], int quant)
{
    int i;
    int result = 0;

    for(i = 0 ; i < quant; i++)
    {
        employeeData[i].isEmpty = 1;
        result = 1;
    }
    return result;
}

int searchListingFirstEmptyPlace(sEmployee employeeData[], int quant)
{
    int i;
    int index = -1;

    for(i = 0; i< quant; i++)
    {
        if(employeeData[i].isEmpty == 1)
        {
            index = i;
            break;
        }
    }
    return index;
}

int changeIsEmptyState(sEmployee employeeData)
{
    int isEmptyStatus;

    if(employeeData.isEmpty == 0)
    {
        isEmptyStatus = 1;
    }
    else
    {
        isEmptyStatus = 0;
    }
    return isEmptyStatus;
}

int createId(sEmployee employeeData[],int lastId, int quant)
{
    int i;
    int actualId;

    actualId = lastId + 1;
    for(i=0;i==quant;i++)
    {
        employeeData[i].id = actualId;
        break;
    }
    return actualId;
}

int modifyEmployee(sEmployee employeeData[], int quant)
{
    int i;
    int employeeIdToModify;
    sEmployee auxiliarMod;
    int confirmation;
    int successReturn;
    int flagId = 0;

    employeeIdToModify = getInt("\nIngrese el ID del empleado a modificar: ");
    printf("\n");

    if(employeeData != NULL && quant > 0)
    {
        for(i=0;i<quant;i++)
        {
            if(employeeData[i].id == employeeIdToModify)
            {
                flagId = 1;
                auxiliarMod = getEmployee(employeeData[i]);
                Colour(WHITE,RED);
                confirmation = getInt("\nEsta seguro que quiere modificar los datos? Ingrese 1 para si, cualquier tecla para no: ");
                Colour(WHITE,BLACK);
                if(confirmation != 1)
                {
                    printf("\n\nNo se aplicar%cn las modificaciones.",159);
                    successReturn = 0;
                    break;
                }
                else
                {
                    employeeData[i] = auxiliarMod;
                    successReturn = 1;
                    break;
                }
            }
        }
        if(flagId == 0)
        {
            Colour(WHITE,RED);
            printf("\nNo existe un/a empleado/a con la id %04d.\n ",employeeIdToModify);
            Colour(WHITE,BLACK);
            successReturn = 0;
        }
    }
    printf("\n");
    return successReturn;
}

int deleteEmployee(sEmployee employeeData[], int quant)
{
    int i;
    int employeeIdToDelete;
    int confirmation;
    int deletionResult;
    int flagId = 0;

    employeeIdToDelete = getInt("\nIngresa el ID del empleado a eliminar: ");

    if(employeeData != NULL && quant > 0)
    {
        for(i = 0; i < quant; i++)
        {
            if(employeeIdToDelete == employeeData[i].id && employeeData[i].isEmpty == 0)
            {
                flagId = 1;
                Colour(WHITE,RED);
                confirmation = getInt("\nEsta seguro que quiere eliminar el/la empleado/a?\n\nIngrese 1 para si, cualquier tecla para no: ");
                Colour(WHITE,BLACK);
                if(confirmation == 1)
                {
                    employeeData[i].isEmpty = changeIsEmptyState(employeeData[i]);
                    printf("\nEl/la empleado/a %s, %s (ID: %04d) ha sido eliminado del sistema.\n",employeeData[i].lastName,employeeData[i].name,employeeIdToDelete);
                    deletionResult = 1;
                    break;
                }
                else
                {
                    printf("No se eliminar%c el/la empleado/a.",160);
                    deletionResult = 0;
                    break;
                }
            }
            else
            {
                Colour(WHITE,RED);
                printf("No existe un/a empleado/a con la id %04d\n\n", employeeIdToDelete);
                Colour(WHITE,BLACK);
                deletionResult = 0;
                break;
            }
        }
        if(flagId == 0)
        {
            Colour(WHITE,RED);
            printf("\nNo existe un/a empleado/a con la id %04d.\n ",employeeIdToDelete);
            Colour(WHITE,BLACK);
            deletionResult = 0;
        }
    }
    return deletionResult;
}

int sortEmployees(sEmployee employeeData[], int quant)
{
    int i;
    int j;
    int result;
    sEmployee auxLastName;
    sEmployee auxSector;

    for(i = 0; i < quant; i++)
    {
        for(j = i+1; j < quant; j++)
        {
            if(strcmp(employeeData[i].lastName, employeeData[j].lastName) > 0)//ordenamiento ascendente por apellido
            {
                auxLastName = employeeData[i];
                employeeData[i] = employeeData[j];
                employeeData[j] = auxLastName;
                result = 1;
            }
            if(((strcmp(employeeData[i].lastName, employeeData[j].lastName) == 0) && ((employeeData[i].sector > employeeData[j].sector) > 0)))//ordenamiento ascendente por sector
            {                                                                                                                                      //si el apellido es el mismo
                auxSector = employeeData[i];
                employeeData[i] = employeeData[j];
                employeeData[j] = auxSector;
                result = 1;
            }
        }
    }
    return result;
}

float averageWage(sEmployee employeeData[], int quant)
{
    int i;
    float sum;
    float finalAverage;
    int salaryCounter = 0;

    if(employeeData != NULL && quant > 0)
    {
        for(i=0; i<quant; i++)
        {
            if(employeeData[i].isEmpty == 0)
            {
                sum = sum + employeeData[i].salary;
                salaryCounter++;
            }
        }
    }
    finalAverage = sum / salaryCounter;
    return finalAverage;
}

int printList(sEmployee employeeData[],int quant)
{
    int retorno = 0;
    int i;
    float employeesAverageWage;
    employeesAverageWage = averageWage(employeeData,quant);

    if(employeeData != NULL && quant > 0)
    {
        Colour(WHITE,BLUE);
        printf("\n\n------------------------------------------------------------------------------------\n");
        Colour(WHITE,MAGENTA);
        printf("|ID      |APELLIDO            |NOMBRE              |SALARIO             |SECTOR");
        Colour(WHITE,BLUE);
        printf("\n------------------------------------------------------------------------------------\n");
        Colour(WHITE,BLACK);

        for(i=0; i < quant; i++)
        {
            if(employeeData[i].isEmpty == 0)
            {
                printf("|%-8d|%-20s|%-20s|%-20.2f|%-5d\n",employeeData[i].id,employeeData[i].lastName,employeeData[i].name,employeeData[i].salary,employeeData[i].sector);
            }
        }
        Colour(WHITE,BLUE);
        printf("------------------------------------------------------------------------------------\n\n");
        printf("\n------------------------------------------------------------------------------------\n");
        Colour(WHITE,BLACK);
        printf("El promedio de los salarios es %.2f",employeesAverageWage);
        Colour(WHITE,BLUE);
        printf("\n------------------------------------------------------------------------------------\n\n\n");
        Colour(WHITE,BLACK);
        retorno = 1;
    }

    return retorno;
}
