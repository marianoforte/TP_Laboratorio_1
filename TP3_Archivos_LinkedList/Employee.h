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

/** \brief Setea el último ID
 *
 * \param int id - Recibe la variable local donde está almacenado el último ID
 * \return int - Retorna el último ID obtenido
 */
int employee_setLastId(int id);

/** \brief Obtiene el último ID
 *
 * \param int id - Recibe la variable local donde está almacenado el último ID
 * \return int - Retorna el último ID obtenido
 */
int employee_getLastId();

/** \brief Incrementa el último ID
 *
 * \param int id - Recibe la variable local donde está almacenado el último ID
 * \return int - Retorna el último ID incrementado
 */
int employee_increaseLastId();

/** \brief Decrementa el último ID
 *
 * \param int id - Recibe la variable local donde está almacenado el último ID
 * \return int - Retorna el último ID decrementado
 */
int employee_decreaseLastId();

/** \brief Almacena un espacio en memoria dinamica para un empleado
 *
 * \param -
 * \param -
 * \return allocated memmory for the new employee
 */
Employee* employee_new();

/** \brief Creo nuevos empleados con parametros
 *
 * \param char* idStr Id generado
 * \param char* nombreStr Nombre generado
 * \param char* horasTrabajadasStr Horas trabajadas generadas
 * \param char* sueldoStr Sueldo
 * \return retorna la direccion del empleado
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldo);

/** \brief Libera espacio de un empleado eliminado
 *
 * \param Employee* this Puntero del array de empleados
 * \return -
 *
 */
void employee_delete(Employee*);

/** \brief Setea el ID
 *
 * \param Employee* this Puntero del array de empleados
 * \param int id recibe una cantidad de id
 * \return rtn, si esta bien es 1, si esta mal es 0
 *
 */
int employee_setId(Employee* this,int id);

/** \brief Obtiene el ID de un empleado
 *
 * \param Employee* this Puntero del array de empleados
 * \param char* nombre Puntero a la variable donde almacenar el ID obtenido
 * \return int rtn 1 si la obtención del ID fue exitosa, 0 si no lo fue
 *
 */
int employee_getId(Employee* this,int* id);

/** \brief Setea el Nombre
 *
 * \param Employee* this Puntero del array de empleados
 * \param char* nombre recibe un nombre
 * \return rtn, si esta bien es 1, si esta mal es 0
 *
 */
int employee_setNombre(Employee* this,char* nombre);

/** \brief Obtiene el nombre de un empleado
 *
 * \param Employee* this Puntero del array de empleados
 * \param char* nombre Puntero a la variable donde almacenar el nombre obtenido
 * \return int rtn 1 si la obtención del nombre fue exitosa, 0 si no lo fue
 *
 */
int employee_getNombre(Employee* this,char* nombre);

/** \brief Setea las horas trabajadas
 *
 * \param Employee* this Puntero del array de empleados
 * \param int horasTrabajadas Recibe una cantidad de horas de trabajo
 * \return rtn, si esta bien es 1, si esta mal es 0
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);

/** \brief Obtiene las horas trabajadas de un empleado
 *
 * \param Employee* this Puntero del array de empleados
 * \param char* nombre Puntero a la variable donde almacenar las horas trabajadas obtenido
 * \return int rtn 1 si la obtención de las horas trabajadas fue exitosa, 0 si no lo fue
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

/** \brief Setea el sueldo
 *
 * \param Employee* this Puntero del array de empleados
 * \param float sueldo Recibe una cantidad de sueldo
 * \return rtn, si esta bien es 1, si esta mal es 0
 *
 */
int employee_setSueldo(Employee* this,int sueldo);

/** \brief Obtiene el sueldo de un empleado
 *
 * \param Employee* this Puntero del array de empleados
 * \param char* nombre Puntero a la variable donde almacenar el sueldo obtenido
 * \return int rtn 1 si la obtención del sueldo fue exitosa, 0 si no lo fue
 *
 */
int employee_getSueldo(Employee* this,int* sueldo);

/** \brief Muestra un empleado
 *
 * \param Employee* empleado Puntero del array de empleados
 * \return -
 *
 */
void employee_showEmployee(Employee* this);

/** \brief Compara dos parametros que serian int (por el id)
 *
 * \param void* employeeA - Primer empleado a comparar
 * \param void* employeeB - Segundo empleado a comparar
 * \return rtn Retorna 0 si el employeeA es igual a empleado B, devuelve -1 si el employeeA es mayor al empleado B y devuelve 1 si el employeeA es menor al empleado B
 *
 */
int employee_SortById(void* employeeA, void* employeeB);

/** \brief Compara dos parametros que serian string (por el nombre)
 *
 * \param void* employeeA - Primer empleado a comparar
 * \param void* employeeB - Segundo empleado a comparar
 * \return rtn Retorna la comparacion de los dos parametros, 0 si falla
 *
 */
int employee_SortByName(void* employeeA, void* employeeB);

/** \brief Compara dos parametros que serian int (por las horas trabajadas)
 *
 * \param void* employeeA - Primer empleado a comparar
 * \param void* employeeB - Segundo empleado a comparar
 * \return rtn Retorna 0 si el employeeA es igual a empleado B, devuelve -1 si el employeeA es mayor al empleado B y devuelve 1 si el employeeA es menor al empleado B
 *
 */
int employee_SortByWorkHours(void* employeeA, void* employeeB);

/** \brief Compara dos parametros que serian int (por el salario)
 *
 * \param void* employeeA - Primer empleado a comparar
 * \param void* employeeB - Segundo empleado a comparar
 * \return rtn Retorna 0 si el employeeA es igual a empleado B, devuelve -1 si el employeeA es mayor al empleado B y devuelve 1 si el employeeA es menor al empleado B
 *
 */
int employee_SortBySalary(void* employeeA, void* employeeB);

#endif // employee_H_INCLUDED
