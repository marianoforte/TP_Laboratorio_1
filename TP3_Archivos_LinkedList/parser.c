#include "parser.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
	int r;
	int rtn = 0;
	int counter = 0;
	char idAux[50], nameAux[50], workedHoursAux[50], salaryAux[50];
	Employee* auxEmployee = employee_new();

	if(pFile != NULL && pArrayListEmployee != NULL){
		r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nameAux,workedHoursAux,salaryAux); // Hago una falsa lectura para quitar la cabecera de archivo y guardo la cantidad de variables que encontró el fscanf
		while(!feof(pFile)){
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idAux, nameAux,workedHoursAux, salaryAux);
			if(r==4){
				auxEmployee = employee_newParametros(idAux ,nameAux, workedHoursAux, salaryAux);

				ll_add(pArrayListEmployee, auxEmployee);
				counter++;
			}
		}
		rtn = counter;
		printf("\nSe cargaron %d empleados a la lista con exito!\n\n", counter);
	}
    return rtn;
}

int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
	int rtn = 0;
	int counter = 0;
	Employee* empleadoAux;

	//fread(&empleadoAux, sizeof(Employee), 1, pFile); // Hago una falsa lectura para quitar la cabecera de archivo

	if(pFile != NULL && pArrayListEmployee != NULL){

		while(!feof(pFile)){
			empleadoAux = employee_new();
			fread(empleadoAux, sizeof(Employee), 1, pFile);
			counter++; //Cuento los empleados que se cargaron
			ll_add(pArrayListEmployee, empleadoAux); //Los añado

		}
		rtn = counter;
		printf("\nSe cargaron %d empleados a la lista con exito !\n\n", counter);
	}
	return rtn;
}
