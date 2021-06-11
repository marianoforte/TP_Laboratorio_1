#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* - Recibe el puntero al archivo
 * \param pArrayListEmployee LinkedList* - Recibe el puntero a la linkedlist
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int rtn = 0;

	pFile = fopen(path, "r");
	if(pFile != NULL && ll_isEmpty(pArrayListEmployee) != -1){
		parser_EmployeeFromText(pFile, pArrayListEmployee);
		fclose(pFile);
		controller_loadLastId("id.dat");
		rtn = 1;
	}
	else{
		puts("\nEl archivo no se pudo cargar\n");
	}
    return rtn;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* - Recibe el puntero al archivo
 * \param pArrayListEmployee LinkedList* - Recibe el puntero a la linkedlist
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int rtn = 0;

	pFile = fopen(path, "rb");
	if(pFile != NULL && ll_isEmpty(pArrayListEmployee) != -1){
		parser_EmployeeFromBinary(pFile, pArrayListEmployee);
		fclose(pFile);
		controller_loadLastId("id.dat");
		rtn = 1;
	}
	else{
		puts("\nEl archivo no se pudo cargar\n");
	}
	return rtn;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList* - Recibe el puntero a la linkedlist
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;
	int listState;
	int rtn = -1;
	listState = ll_isEmpty(pArrayListEmployee);
	if(listState != -1){
		int listLength = ll_len(pArrayListEmployee);
		if(listState == 0){
			printf("\n-------------------------------------------------------------------------------\n");
			printf("\nListado de Empleados:\n");
			printf("\n   Id |          Nombre |   Hs trabajadas   |  Sueldo\n");
			for(int i=0; i<listLength; i++){
					auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
					employee_showEmployee(auxEmployee);
			}
			printf("\n");
			rtn = 1;
		}
		if(listState == 1){
			puts("\nNo hay empleados para mostrar\n");
			rtn = 0;
		}
	}
    return rtn;
}

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee LinkedList* - Recibe el puntero a la linkedlist
 * \param id int* - Recibe la variable local de la ultima id desde el main
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee, int* id)
{
	int rtn = 0;
	Employee* newEmployee;
	char idAux[50], nameAux[50], workedHoursAux[50], salaryAux[50];
	int idAuxAux;
	if(ll_isEmpty(pArrayListEmployee) != -1){
		newEmployee = employee_new();
		controller_loadLastId("id.dat");
		idAuxAux = employee_getLastId(*id);
		idAuxAux = employee_increaseLastId(idAuxAux);
		*id = employee_setLastId(idAuxAux);
		itoa(idAuxAux, idAux, 10);
		getValidStringEspaciosYLetras("Ingrese el nombre del empleado: ", "Error, nombre no valido.", nameAux);
		getValidStringNumeros("Ingrese las horas trabajadas del empleado: ","Error, horas no validas", workedHoursAux);
		getValidStringNumeros("Ingrese el sueldo del empleado: ","Error, sueldo no valido", salaryAux);
		newEmployee = employee_newParametros(idAux, nameAux, workedHoursAux, salaryAux);
		ll_add(pArrayListEmployee, newEmployee);
		controller_saveLastId("id.dat", &idAuxAux);
		rtn = 1;
	}
	return rtn;
}

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee LinkedList* - Recibe el puntero a la linkedlist
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;
	int rtn = -1;
	int listLength ;
	char nameAux[50], workedHoursAux[50], salaryAux[50];
	int idAux, workedHoursAuxAux, salaryAuxAux, option, option2;
	int listState = ll_isEmpty(pArrayListEmployee);
	int idExists = 0;
	char confirmation = 'n';
	char confirmation2 = 'n';
	int dontEdit = 1;

	if(listState == -1){
		if(listState == 0){
			do{
				printf("1. Mostrar listado de empleados\n2. Ingresar ID de empleado\n3. Salir\n");
				printf("\nOpcion elegida: ");
				scanf("%d", &option);
				switch(option){
					case 1:
						controller_ListEmployee(pArrayListEmployee);
						break;
					case 2:
						idAux = getValidInt("Ingrese el ID que desea modificar:  ", "Error, no es valido el id.", 1, 5000);
						dontEdit = 0;
						confirmation = 'y';
						break;
					case 3:
						printf("\nVolviendo al menu anterior!\n");
						system("pause");
						confirmation = 'y';
						break;
					default:
						puts("Opcion invalida");
						break;
				}
			}while(confirmation != 'y');

			if(dontEdit != 1){
				listLength = ll_len(pArrayListEmployee);
				for(int i=0; i<listLength ; i++){
					auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
					if(employee_getId(auxEmployee, &idAux)){
						do{
							system("cls");
							employee_showEmployee(auxEmployee);
							printf("\nElija la opcion que desea modificar: \n1. Nombre\n2. Horas trabajadas\n3. Sueldo\n4. Salir\n");
							printf("Opcion elegida: ");
							scanf("%d", &option2);
							switch(option2){
								case 1:
									getValidString("Ingrese nuevo nombre: ", "Error al ingresar nombre", nameAux);
									employee_setNombre(auxEmployee, nameAux);
									break;
								case 2:
									if(getStringNumeros("Ingrese horas trabajadas: ", workedHoursAux)!=1){
										printf("'nError, ingrese solo numeros.\n");
									}
									workedHoursAuxAux = atoi(workedHoursAux);
									employee_setHorasTrabajadas(auxEmployee, workedHoursAuxAux);
									break;
								case 3:
									if(getStringNumeros("Ingrese sueldo nuevo: ", salaryAux)!=1){
										printf("\nError, ingrese solo numeros.\n");
									}
									salaryAuxAux = atoi(salaryAux);
									employee_setSueldo(auxEmployee, salaryAuxAux);
									break;
								case 4:
									printf("\nVolviendo al menu anterior!\n");
									system("pause");
									confirmation2 = 'y';
									break;
								default:
									puts("Opcion invalida");
									break;
							}
						}
						while(confirmation2 != 'y');
						idExists = 1;
						rtn = 1;
						break;
					}
				}
			}
		}
		if(listState == 1){
			puts("\nNo hay empleados en la lista para modificar\n");
			rtn = 0;
		}

		if(idExists == 0){
			printf("\nNo existe ese ID!\n\n");
			rtn = 0;
		}
	}
	return rtn;
}

/** \brief Baja de empleado
 *
 * \param pArrayListEmployee LinkedList* - Recibe la linkedlist
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;
	int listLength, auxId, option, confirmation;
	int listState = ll_isEmpty(pArrayListEmployee);
	int idExists = 0;
	int dontDelete = 1;
	int rtn = -1;

	if(listState == -1){
		system("cls");
		if(listState == 0){
			do{
				printf("1. Mostrar listado de empleados\n2. Ingresar ID de empleado a eliminar\n3. Salir\n");
				printf("Opcion elegida: ");
				scanf("%d", &option);
				switch(option){
					case 1:
						controller_ListEmployee(pArrayListEmployee);
						break;
					case 2:
						auxId = getValidInt("Ingrese el id que desea eliminar: ", "Error, no es valido el id.", 1, 5000);
						dontDelete = 0;
						confirmation = 'y';
						break;
					case 3:
						printf("\nVolviendo al menu anterior!\n");
						system("pause");
						confirmation = 'y';
						break;
					default:
						puts("Opcion invalida");
						break;
				}
			}while(confirmation != 'y');

			if(dontDelete != 1){
				listLength = ll_len(pArrayListEmployee);
				for(int i=0; i<listLength; i++){
					auxEmployee = (Employee*)ll_get(pArrayListEmployee, i); //

					if(employee_getId(auxEmployee, &auxId)){
						ll_remove(pArrayListEmployee, i);
						employee_showEmployee(auxEmployee);
						printf("\nEmpleado eliminado exitosamente!\n");
						employee_delete(auxEmployee);
						idExists = 1;
						rtn = 1;
					}
				}
			}
		}
		if(listState == 1){
			puts("\nNo hay empleados en la lista para eliminar\n");
			rtn = 0;
		}


		if(idExists == 0){
			printf("\nEl Id no existe.\n");
			rtn = 0;
		}
	}
	return rtn;
}



/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList* - Recibe el puntero a la linkedlist
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int rtn = -1;
    int listState = ll_isEmpty(pArrayListEmployee);
    int option, sortOption, sortCriteria;
    if(listState != -1){
    	if(listState == 0){
    		puts("\nSeleccione la manera en que quiere ordenar los empleados:");
    		puts("1. Ordenar por Id");
    		puts("2. Ordenar por nombre");
    		puts("3. Ordenar por horas trabajadas");
    		puts("4. Ordenar por sueldo");
    		puts("5. Salir");
			printf("\nOpcion elegida: ");
			scanf("%d", &option);

			puts("\n\nSeleccione el criterio de ordenamiento:");
			puts("1. Ascendente");
			puts("2. Descendente");
			printf("\nOpcion elegida: ");
			scanf("%d", &sortOption);

			while(sortOption != 1 && sortOption != 2){
				puts("\n\nOpcion invalida");
				puts("\nSeleccione el criterio de ordenamiento:");
				puts("1. Ascendente");
				puts("2. Descendente");
				printf("\nOpcion elegida: ");
				scanf("%d", &sortOption);
			}
			if(sortOption == 1){
				sortCriteria = 0;
			}
			if(sortOption == 2){
				sortCriteria = 1;
			}

			switch(option){
				case 1:
					ll_sort(pArrayListEmployee, employee_SortById,sortCriteria);
					printf("\nOrdenamiento por ID exitoso!!\n\n");
					break;
				case 2:
					ll_sort(pArrayListEmployee, employee_SortByName,sortCriteria);
					printf("\nOrdenamiento por nombre exitoso!!\n\n");
					break;
				case 3:
					ll_sort(pArrayListEmployee, employee_SortByWorkHours,sortCriteria);
					printf("\nOrdenamiento por horas trabajadas exitoso!!\n\n");
					break;
				case 4:
					ll_sort(pArrayListEmployee, employee_SortBySalary,sortCriteria);
					printf("\nOrdenamiento por salario exitoso!!\n\n");
					break;
				case 5:
					printf("\nVolviendo al menu anterior!\n");
					system("pause");
					break;
				default :
					puts("Opcion invalida");
					break;
			}
			rtn = 1;
    	}
    	if(listState == 1){
    		puts("\nNo hay empleados en la lista para ordenar");
    		rtn = 0;
    	}
    }

    return rtn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* - Recibe el puntero al archivo
 * \param pArrayListEmployee LinkedList* - Recibe el puntero a la linkedlist
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int idAuxiliar;
	char nombreAuxiliar[50];
	int horasAuxiliar;
	int sueldoAuxiliar;
    int listLength;
    int rtn = 0;
    Employee* pAuxEmployee;
    FILE* pFile = fopen(path, "w");
    if(pFile != NULL && ll_isEmpty(pArrayListEmployee) != -1){
    	listLength = ll_len(pArrayListEmployee);
    	fprintf(pFile, "ID,Nombre,HorasTrabajadas,Sueldo\n");
			for(int i=0; i<listLength; i++){
				pAuxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
				employee_getId(pAuxEmployee, &idAuxiliar);
				employee_getNombre(pAuxEmployee,nombreAuxiliar);
				employee_getHorasTrabajadas(pAuxEmployee,&horasAuxiliar);
				employee_getSueldo(pAuxEmployee,&sueldoAuxiliar);
				fprintf(pFile, "%d,%s,%d,%d\n", idAuxiliar, nombreAuxiliar, horasAuxiliar, sueldoAuxiliar);
			}
		fclose(pFile);
		printf("Se ha realizado el guardado del archivo con exito !\n");
		rtn = 1;
	}
    else{
    	puts("Error al abrir el archivo para guardar los datos");
    }
    return rtn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* - Recibe el puntero al archivo
 * \param pArrayListEmployee LinkedList* - Recibe el puntero a la linkedlist
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int rtn = 0;
    int listLength;
    Employee* pAuxEmployee;
    FILE* pFile = fopen(path, "wb");
    if(pFile != NULL && ll_isEmpty(pArrayListEmployee) != -1){
    	listLength = ll_len(pArrayListEmployee);
        for(int i=0; i<listLength; i++){
        	pAuxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
            fwrite(pAuxEmployee, sizeof(Employee), 1, pFile);
        }
        fclose(pFile);
        printf("Se ha realizado el guardado del archivo con exito !\n");
        rtn = 1;
    }
    else{
		puts("Error al abrir el archivo para guardar los datos");
	}
    return rtn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* - Recibe el puntero al archivo
 * \return int
 *
 */
int controller_loadLastId(char* path){
	FILE* pFile;
	int id = -1;
	int rtn = 0;

	if(path != NULL){
		pFile = fopen(path, "rb");
		if(pFile != NULL){
			fread(&id, sizeof(int), 1, pFile);
			employee_setLastId(id);
			fclose(pFile);
			rtn = id;
		}
	}
	return rtn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char* - Recibe el puntero al archivo
 * \return int
 *
 */
int controller_saveLastId(char* path, int* id){
	FILE* pFile;
	int rtn = 0;

	if(path != NULL){
		pFile = fopen(path, "wb");
		if(pFile != NULL){
			*id = employee_getLastId(*id);
			fwrite(id, sizeof(int), 1, pFile);
			fclose(pFile);
			rtn = 1;
		}
	}
	return rtn;
}
