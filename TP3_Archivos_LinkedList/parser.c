#include "parser.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee){
    int elementsAdded = -1;
    int returnAux;
    char parsedId[9];
    char parsedHours[5];
    char parsedSalary[9];
    char parsedName[128];
    Employee* new;

    if(pFile != NULL && pArrayListEmployee != NULL){
        elementsAdded = 0;
        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", parsedId, parsedName, parsedHours, parsedSalary);
        while(!feof(pFile)){
            returnAux = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", parsedId, parsedName, parsedHours, parsedSalary);
            if(returnAux == 4){
                new = employee_newParametros(parsedId, parsedName, parsedHours, parsedSalary);
                if(new != NULL && !ll_contains(pArrayListEmployee, new)){
                    ll_add(pArrayListEmployee, new);
                    elementsAdded++;
                }
            }
        }
    }
    return elementsAdded;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee){
    int elementsAdded = -1;
    int returnAux;
    Employee* new;

    if(pFile != NULL && pArrayListEmployee != NULL){
        elementsAdded = 0;
        while(!feof(pFile)){
            new = employee_new();
            if(new != NULL){
                returnAux = fread(new, sizeof(Employee), 1, pFile);
                if(returnAux == 1 && !ll_contains(pArrayListEmployee, new)){
                    ll_add(pArrayListEmployee, new);
                    elementsAdded++;
                }
            }
        }
    }
    return elementsAdded;
}
