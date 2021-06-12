#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* - Recibe el puntero al archivo
 * \param pArrayListEmployee LinkedList* - Recibe el puntero a la linkedlist
 * \return int Retorna 1 si la carga fue exitosa, 0 si no lo fue
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee);

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* - Recibe el puntero al archivo
 * \param pArrayListEmployee LinkedList* - Recibe el puntero a la linkedlist
 * \return int Retorna 1 si la carga fue exitosa, 0 si no lo fue
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* - Recibe el puntero a la linkedlist
 * \return int Retorna 1 si hay empleados para listar, 0 si no hay empleados en la lista, -1 si el listado no existe
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee);

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList* - Recibe el puntero a la linkedlist
 * \param id int* - Recibe la variable local de la ultima ID desde el main
 * \return int Retorna 1 si el alta fue exitosa, 0 si no lo fue
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id);

/** \brief Modificar datos de un empleado
 *
 * \param pArrayListEmployee LinkedList* - Recibe el puntero a la linkedlist
 * \return int Retorna 1 si la edición fue exitosa, 0 si no hay empleados en el listado, -1 si el listado no existe
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee);

/** \brief Baja de un empleado
 *
 * \param pArrayListEmployee LinkedList* - Recibe la linkedlist
 * \return int Retorna 1 si la eliminación fue exitosa, 0 si no hay empleados en el listado, -1 si el listado no existe
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee);

/** \brief Ordenar los empleados del listado
 *
 * \param pArrayListEmployee LinkedList* - Recibe el puntero a la linkedlist
 * \return int Retorna 1 si el ordenamiento fue exitoso, 0 si no hay empleados en el listado, -1 si el listado no existe
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* - Recibe el puntero al archivo
 * \param pArrayListEmployee LinkedList* - Recibe el puntero a la linkedlist
 * \return int Retorna 1 si se puedieron guardar los datos en el archivo, 0 si no se pudo
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* - Recibe el puntero al archivo
 * \param pArrayListEmployee LinkedList* - Recibe el puntero a la linkedlist
 * \return int Retorna 1 si se puedieron guardar los datos en el archivo, 0 si no se pudo
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* - Recibe el puntero al archivo
 * \return int Retorna el ID si se pudo acceder al archivo, -1 si no existe el archivo
 *
 */
int controller_loadLastId(char* path);

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* - Recibe el puntero al archivo
 * \param id int* - Recibe el ultimo ID a guardar en el archivo
 * \return int Retorna 1 si se pudo acceder al archivo y guardar el ID, -1 si no existe el archivo
 *
 */
int controller_saveLastId(char* path, int* id);


