/*
 * parser.h
 *
 *  Created on: 3 jun. 2021
 *      Author: maria
 */

#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

#ifndef PARSER_H_
#define PARSER_H_

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param pFile FILE* - Puntero al archivo
 * \param pArrayListEmployee LinkedList* - Puntero a la linkedlist
 * \return int - Retorna la cantidad de empleados parseados, 0 si no se encontró ninguno
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);

/** \brief Parsea los datos de los empleados desde el archivo data.dat (modo binario).
 *
 * \param pFile FILE* - Puntero al archivo
 * \param pArrayListEmployee LinkedList* - Puntero a la linkedlist
 * \return int - Retorna la cantidad de empleados parseados, 0 si no se encontró ninguno
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);

#endif /* PARSER_H_ */
