#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "Input&Validation.h"

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

    employeeIdToModify = getInt("\nIngrese el ID del empleado a modificar: ");
    printf("\n");

    for(i=0;i<quant;i++)
    {   printf("ID empleado: %d\n",employeeData[i].id);

        if(employeeData[i].id == employeeIdToModify)
        {
            auxiliarMod = getEmployee(employeeData[i]);
            confirmation = getInt("\nEsta seguro que quiere modificar los datos? Ingrese 1 para si, cualquier tecla para no: ");
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
        else
        {
            printf("\nNo existe un/a empleado/a con la id %04d.\n ",employeeIdToModify);
            successReturn = 0;
            break;
        }
    }
    return successReturn;
}

int deleteEmployee(sEmployee employeeData[], int quant)
{
    int i;
    int employeeIdToDelete;
    int confirmation;
    int modifyingResult;

    employeeIdToDelete = getInt("\nIngresa el ID del empleado a eliminar: ");

    for(i = 0; i < quant; i++)
    {
        confirmation = getInt("\nEsta seguro que quiere eliminar el/la empleado/a? Ingrese 1 para si, cualquier tecla para no: ");
        if(confirmation != 1)
        {
            printf("No se eliminar%c el/la empleado/a.",160);
            modifyingResult = 0;
            break;
        }
        else
        {
            if(employeeData[i].id == employeeIdToDelete && employeeData[i].isEmpty == 0)
            {
                employeeData[i].isEmpty = changeIsEmptyState(employeeData[i]);
                printf("\nEl/la empleado/a %s, %s (ID: %04d) ha sido eliminado del sistema.\n",employeeData[i].lastName,employeeData[i].name,employeeIdToDelete);
                modifyingResult = 1;
                break;
            }
            else
            {
                printf("No existe un/a empleado/a con la id %04d\n\n", employeeIdToDelete);
                modifyingResult = 0;
                break;
            }
        }
    }
    return modifyingResult;
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
            if(((strcmp(employeeData[i].lastName, employeeData[j].lastName) == 0) && (strcmp(employeeData[i].sector, employeeData[j].sector) > 0)))//ordenamiento ascendente por sector
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
    int i, j;
    float employeesAverageWage;
    employeesAverageWage = averageWage(employeeData,quant);

    for(i=0;i<quant;i++)
    {
        if(employeeData != NULL && quant > 0)
        {
            retorno = 1;
            printf("\n\n------------------------------------------------------------------------------------\n");
            printf("ID \tNOMBRE \t\tAPELLIDO \t\tSALARIO  \tSECTOR");
            printf("\n------------------------------------------------------------------------------------\n\n");

            for(j=0; j < quant; j++)
            {
                if(employeeData[j].isEmpty == 0)
                {
                    printf("%04d %4s %10s %15.2f %20s\n",employeeData[j].id,employeeData[j].name,employeeData[j].lastName,employeeData[j].salary,employeeData[j].sector);
                }
            }
            printf("\n------------------------------------------------------------------------------------\n");
            printf("El promedio de los salarios es %.2f",employeesAverageWage);
            printf("\n------------------------------------------------------------------------------------\n\n");
            retorno = 1;
            system("pause");
            system("cls");
        }
        if(employeeData[i].isEmpty == 1)
        {
            printf("\n\n------------------------------------------------------------------------------------\n\n");
            printf("\nNo hay empleados para mostrar.\n");
            printf("\n\n------------------------------------------------------------------------------------\n\n");
            system("pause");
            system("cls");
            retorno = 0;
        }
    }
    return retorno;
}
