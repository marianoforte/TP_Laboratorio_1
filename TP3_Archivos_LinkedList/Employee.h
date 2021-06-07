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
int employee_getLastId(void);
int employee_increaseLastId(void);
int employee_decreaseLastId(void);

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

int employeeSortByName(void* employeeA, void* employeeB);
int employeeSortById(void* employeeA, void* employeeB);
int employeeSortByWorkHours(void* employeeA, void* employeeB);
int employeeSortBySalary(void* employeeA, void* employeeB);

#endif // employee_H_INCLUDED
