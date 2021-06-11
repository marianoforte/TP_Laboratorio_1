#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>
#include "LinkedList.h"

#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

int employee_setLastId(int id);
int employee_getLastId(int id);
int employee_increaseLastId(int id);
int employee_decreaseLastId(int id);

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);
void employee_delete(Employee*);

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

void employee_showEmployee(Employee* this);

int employee_SortByName(void* employeeA, void* employeeB);
int employee_SortById(void* employeeA, void* employeeB);
int employee_SortByWorkHours(void* employeeA, void* employeeB);
int employee_SortBySalary(void* employeeA, void* employeeB);

#endif // employee_H_INCLUDED
