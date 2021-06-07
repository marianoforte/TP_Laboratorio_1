#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
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
 * \param path char*
 * \param pArrayListEmployee LinkedList*
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
 * \param path char*
 * \param pArrayListEmployee LinkedList*
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
			printf("   Id       Nombre   Horas trabajadas   Sueldo\n");
			for(int i=0; i<listLength; i++){
				if(auxEmployee != NULL){
					auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
					employee_showEmployee(auxEmployee);
				}
			}
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
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int rtn = 0;
	Employee* newEmployee;
	char idAux[50], nameAux[50], workedHoursAux[50], salaryAux[50];
	int idAuxAux;
	if(ll_isEmpty(pArrayListEmployee) != -1){
		newEmployee = employee_new();
		if(newEmployee != NULL){
			idAuxAux = employee_getLastId();
			idAuxAux = employee_increaseLastId();
			employee_setLastId(idAuxAux);
			itoa(idAuxAux, idAux, 10);
			getValidStringEspaciosYLetras("Ingrese el nombre del empleado: ", "Error, nombre no valido.", nameAux);
			getValidStringNumeros("Ingrese las horas trabajadas del empleado: ","Error, horas no validas", workedHoursAux);
			getValidStringNumeros("Ingrese el sueldo del empleado: ","Error, sueldo no valido", salaryAux);
			newEmployee = employee_newParametros(idAux, nameAux, workedHoursAux, salaryAux);
			ll_add(pArrayListEmployee, newEmployee);
		}
		rtn = 1;
	}
	return rtn;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;
	int rtn = -1;
	int listLength ;
	char nameAux[50], workedHoursAux[50], salaryAux[50];
	int idAuxAux, workedHoursAuxAux, salaryAuxAux, option, option2;
	int listState = ll_isEmpty(pArrayListEmployee);
	char confirmation = 'n';
	char confirmation2 = 'n';
	int dontEdit = 1;

	if(listState == -1){
		if(listState == 0){
			do{
				printf("1. Mostrar listado de empleados\n2. Ingresar ID de empleado\n3. Salir\n");
				printf("Opcion elegida: ");
				scanf("%d", &option);
				switch(option){
				case 1:
					controller_ListEmployee(pArrayListEmployee);
					break;
				case 2:
					idAuxAux = getValidInt("Ingrese el ID que desea modificar:  ", "Error, no es valido el id.", 1, 5000);
					dontEdit = 0;
					confirmation = 'y';
					break;
				case 3:
					printf("\nVolviendo al menu anterior!\n");
					system("pause");
					confirmation = 'y';
					break;
				}
			}while(confirmation != 'y');

			if(dontEdit != 1){
				listLength = ll_len(pArrayListEmployee);
				for(int i=0; i<listLength ; i++){
					auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
					if(idAuxAux == auxEmployee->id){
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
								printf("Error, opcion invalida\n");
							}
						}
						while(confirmation2 != 'y');
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

		if(idAuxAux != auxEmployee->id){
			printf("\nNo existe ese ID!\n\n");
			rtn = 0;
		}
	}
	return rtn;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	Employee* auxEmployee;
	int listLength, auxId, option, confirmation;
	int listState = ll_isEmpty(pArrayListEmployee);
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
				}
			}while(confirmation != 'y');

			if(dontDelete != 1){
				listLength = ll_len(pArrayListEmployee);
				for(int i=0; i<listLength; i++){
					auxEmployee = (Employee*)ll_get(pArrayListEmployee, i); //

					if(auxEmployee->id == auxId){
						ll_remove(pArrayListEmployee, i);
						employee_showEmployee(auxEmployee);
						printf("\nEmpleado eliminado exitosamente!\n");
						employee_delete(auxEmployee);
						rtn = 1;
					}
				}
			}
		}
		if(listState == 1){
			puts("\nNo hay empleados en la lista para eliminar\n");
			rtn = 0;
		}


		if(auxEmployee->id != auxId){
			printf("\nEl Id no existe.\n");
			rtn = 0;
		}
	}
	return rtn;
}



/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int rtn = -1;
    int listState = ll_isEmpty(pArrayListEmployee);
    int option;
    if(listState != -1){
    	if(listState == 0){
    		printf("Ingrese la manera en que quiere ordenar los empleados : \n");
			printf("1. Ordenar por Id\n");
			printf("2. Ordenar por nombre\n");
			printf("3. Ordenar por horas trabajadas\n");
			printf("4. Ordenar por sueldo\n");
			printf("5. Salir\n");
			scanf("%d", &option);
			switch(option){
			case 1:
				ll_sort(pArrayListEmployee, employeeSortById,0);
				printf("Ordenamiento por ID exitoso!!\n\n");
				break;
			case 2:
				ll_sort(pArrayListEmployee, employeeSortByName,0);
				printf("Ordenamiento por nombre exitoso!!\n\n");
				break;
			case 3:
				ll_sort(pArrayListEmployee, employeeSortByWorkHours,0);
				printf("Ordenamiento por horas trabajadas exitoso!!\n\n");
				break;
			case 4:
				ll_sort(pArrayListEmployee, employeeSortBySalary,0);
				printf("Ordenamiento por salario exitoso!!\n\n");
				break;
			case 5:
				printf("Volviendo al menu anterior!\n");
				system("pause");
				break;
			default :
				printf("Opcion incorrecta\n");
			}
			rtn = 1;
    	}
    	if(listState == 1){
    		puts("No hay empleados en la lista para ordenar");
    		rtn = 0;
    	}
    }

    return rtn;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
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
		controller_saveLastId("id.dat");
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
 * \param path char*
 * \param pArrayListEmployee LinkedList*
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
        controller_saveLastId("id.dat");
        printf("Se ha realizado el guardado del archivo con exito !\n");
        rtn = 1;
    }
    else{
		puts("Error al abrir el archivo para guardar los datos");
	}
    return rtn;
}

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
			rtn = 1;
		}
	}
	return rtn;
}

int controller_saveLastId(char* path){
	FILE* pFile;
	int id = -1;
	int rtn = 0;

	if(path != NULL){
		pFile = fopen(path, "wb");
		if(pFile != NULL){
			id = employee_getLastId();
			fwrite(&id, sizeof(int), 1, pFile);
			fclose(pFile);
			rtn = 1;
		}
	}
	return rtn;
}
