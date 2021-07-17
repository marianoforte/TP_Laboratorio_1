#include "Controller.h"
#define HEADER "id,nombre,horasTrabajadas,sueldo"

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee){
    int gotData = ll_isEmpty(pArrayListEmployee);
    FILE* pFile;

    if(gotData != -1 && path != NULL)
    {
        if(!gotData)
        {
            printf("\nYa existen elementos cargados en la lista. Si continua, se perderan los datos no guardados");
            if(Input_Confirmation("\nDesea continuar? s/n: ", "Esta opcion no es valida", 's', 'n'))
            {
                ll_clear(pArrayListEmployee);
                gotData = 1;
            }
        }
        if(gotData == 1)
        {

            pFile = fopen(path,"r");
            if(pFile != NULL)
            {
                gotData = parser_EmployeeFromText(pFile, pArrayListEmployee);
                fclose(pFile);
            }
        }

    }
    return gotData;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee){
    int gotData = -1;
    FILE* pFile;
    int tempInt = ll_isEmpty(pArrayListEmployee);

    if(path != NULL && tempInt != -1)
    {
        if(!tempInt)
        {
            printf("\nYa existen elementos cargados en la lista. Si continua, se perderan los datos no guardados");
            if(Input_Confirmation("\nDesea continuar? s/n: ", "Esta opcion no es valida", 's', 'n'))
            {
                ll_clear(pArrayListEmployee);
                tempInt = 1;
            }
        }
        if(tempInt == 1)
        {
            pFile = fopen(path, "rb");
            if(pFile != NULL)
            {
                gotData = parser_EmployeeFromBinary(pFile, pArrayListEmployee);
                fclose(pFile);
            }
        }
    }
    return gotData;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee){
	Employee* auxEmployee;
	int listState;
	int rtn = -1;
	listState = ll_isEmpty(pArrayListEmployee);
	if(listState != -1){
		int listLength = ll_len(pArrayListEmployee);
		if(listState == 0){
			puts("\n-------------------------------------------------------------------------------");
			puts("\nListado de Empleados:");
			printf("\n   Id |          Nombre |   Hs trabajadas   |  Sueldo\n");
			for(int i=0; i<listLength; i++){
					auxEmployee = (Employee*)ll_get(pArrayListEmployee, i);
					employee_showEmployee(auxEmployee);
			}
			printf("\n");
			rtn = 1;
		}
		else{
			puts("\nNo hay empleados para mostrar\n");
			rtn = 0;
		}
	}
    return rtn;
}

int controller_addEmployee(LinkedList* pArrayListEmployee){
	int rtn = -3;
	Employee* newEmployee;
	char idAux[50];
	char nameAux[50];
	char workedHoursAux[50];
	char salaryAux[50];
	int idAuxAux;
	if(ll_isEmpty(pArrayListEmployee) != -1){
		newEmployee = employee_new();
		idAuxAux = employee_getLastId();
		idAuxAux = employee_increaseLastId();
		employee_setLastId(idAuxAux);
		employee_setId(newEmployee, idAuxAux);
		itoa(idAuxAux, idAux, 10);
		getValidStringEspaciosYLetras("Ingrese el nombre del empleado: ", "Error, nombre no valido.", nameAux);
		getValidStringNumeros("Ingrese las horas trabajadas del empleado: ","Error, horas no validas", workedHoursAux);
		getValidStringNumeros("Ingrese el sueldo del empleado: ","Error, sueldo no valido", salaryAux);
		newEmployee = employee_newParametros(idAux, nameAux, workedHoursAux, salaryAux);
		if(Input_Confirmation("\nDesea confirmar este ingreso? s/n: ", "\nOpcion invalida", 's', 'n')){
			ll_add(pArrayListEmployee, newEmployee);
			rtn = 0;
			printf("\nNuevo empleado cargado exitosamente");
		}
		else{
			printf("\nSe ha cancelado el ingreso de este empleado");
			free(newEmployee);
			employee_decreaseLastId();
			rtn = -1;
		}
	}
	else{
		printf("\nSe produjo un error al añadir un empleado");
		rtn = -2;
	}
	return rtn;
}

int controller_editEmployee(LinkedList* pArrayListEmployee){
	Employee* auxEmployee;
	int rtn = -1;
	int listLength ;
	char nameAux[50];
	char workedHoursAux[50];
	char salaryAux[50];
	int idAux;
	int workedHoursAuxAux;
	int salaryAuxAux;
	int option;
	int option2;
	int listState = ll_isEmpty(pArrayListEmployee);
	int idExists = 0;
	char confirmation = 'n';
	char confirmation2 = 'n';
	int dontEdit = 1;

	if(listState != -1){
		if(listState == 0){
			do{
				printf("\n1. Mostrar listado de empleados\n2. Ingresar ID de empleado\n3. Salir\n");
				printf("\nOpcion elegida: ");
				scanf("%d", &option);
				switch(option){
					case 1:
						controller_ListEmployee(pArrayListEmployee);
						break;
					case 2:
						idAux = getValidInt("\nIngrese el ID que desea modificar:  ", "Error, no es valido el id.", 1, 5000);
						dontEdit = 0;
						confirmation = 'y';
						break;
					case 3:
						printf("\nVolviendo al menu anterior!\n");
						system("pause");
						confirmation = 'y';
						break;
					default:
						puts("\nOpcion invalida");
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
									getValidString("\nIngrese nuevo nombre: ", "Error al ingresar nombre", nameAux);
									employee_setNombre(auxEmployee, nameAux);
									break;
								case 2:
									if(getStringNumeros("\nIngrese nuevas horas trabajadas: ", workedHoursAux)!=1){
										printf("\nError, ingrese solo numeros.\n");
									}
									workedHoursAuxAux = atoi(workedHoursAux);
									employee_setHorasTrabajadas(auxEmployee, workedHoursAuxAux);
									break;
								case 3:
									if(getStringNumeros("\nIngrese nuevo sueldo: ", salaryAux)!=1){
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
									puts("\nOpcion invalida");
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

int controller_removeEmployee(LinkedList* pArrayListEmployee){
	Employee* auxEmployee;
	int listLength;
	int auxId;
	int option;
	int confirmation;
	int listState = ll_isEmpty(pArrayListEmployee);
	int idExists = 0;
	int dontDelete = 1;
	int rtn = -1;
	if(listState != -1){
		if(listState == 0){
			do{
				printf("\n1. Mostrar listado de empleados\n2. Ingresar ID de empleado a eliminar\n3. Salir\n");
				printf("Opcion elegida: ");
				scanf("%d", &option);
				switch(option){
					case 1:
						controller_ListEmployee(pArrayListEmployee);
						break;
					case 2:
						auxId = getValidInt("\nIngrese el id que desea eliminar: ", "Error, no es valido el id.", 1, 5000);
						dontDelete = 0;
						confirmation = 'y';
						break;
					case 3:
						printf("\nVolviendo al menu anterior!\n");
						system("pause");
						confirmation = 'y';
						break;
					default:
						puts("\nOpcion invalida");
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
		else{
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

int controller_sortEmployee(LinkedList* pArrayListEmployee){
    int rtn = -1;
    int listState = ll_isEmpty(pArrayListEmployee);
    int option;
    int sortOption;
    int sortCriteria;
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
					puts("Opcion invalida\n");
					break;
			}
			rtn = 1;
    	}
    	if(listState == 1){
    		puts("\nNo hay empleados en la lista para ordenar\n\n");
    		rtn = 0;
    	}
    }

    return rtn;
}

int controller_saveAsText(char* path, LinkedList* pArrayListEmployee){
	int savedData = ll_isEmpty(pArrayListEmployee);
	Employee* current;
	int id;
	int hoursWorked;
	int salary;
	char name[128];
	FILE* pFile;

	puts("HOLA 1\n");
	if(path != NULL && savedData != -1){
		savedData = 0;
		pFile = fopen(path, "w");
		puts("HOLA 2\n");
		if(pFile != NULL){
			puts("HOLA 3\n");
			fprintf(pFile, "%s\n", HEADER);
			for(int i=0;i<ll_len(pArrayListEmployee);i++){
				current = ll_get(pArrayListEmployee, i);
				if(!employee_getHorasTrabajadas(current, &hoursWorked)){
					if(!employee_getId(current, &id)){
						if(!employee_getNombre(current, name)){
							if(!employee_getSueldo(current, &salary)){
								fprintf(pFile, "%d,%s,%d,%d\n", id, name, hoursWorked, salary);
								savedData++;
							}
						}
					}
				}
			}
			fclose(pFile);
			printf("\nListado guardado exitosamente. %d elementos registrados\n\n", savedData);
		}
	}
	return savedData;
}

int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee){
	int savedData = ll_isEmpty(pArrayListEmployee);
	Employee* current;
	FILE* pFile;

	if(path != NULL && savedData != -1){
		savedData = 0;
		pFile = fopen(path, "wb");
		if(pFile != NULL){
			//fprintf(pFile, "%s\n", HEADER);
			for(int i=0;i<ll_len(pArrayListEmployee);i++){
				current = ll_get(pArrayListEmployee, i);
				fwrite(current, sizeof(Employee), 1, pFile);
				savedData++;
			}
			fclose(pFile);
			printf("\nListado guardado exitosamente. %d elementos registrados\n\n", savedData);
		}
	}
	return savedData;
}

int controller_loadLastId(char* path){
	FILE* pFile;
	int id = -1;
	int rtn = -1;

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

int controller_saveLastId(char* path, int* id){
	FILE* pFile;
	int rtn = -1;

	if(path != NULL){
		pFile = fopen(path, "wb");
		if(pFile != NULL){
			*id = employee_getLastId();
			fwrite(id, sizeof(int), 1, pFile);
			fclose(pFile);
			rtn = 1;
		}
	}
	return rtn;
}
