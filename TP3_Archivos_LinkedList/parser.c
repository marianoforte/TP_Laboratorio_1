#include "parser.h"

int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
	//int r;
	int rtn = 0;
	int counter = 0;
	char idAux[50], nameAux[50], workedHoursAux[50], salaryAux[50];
	Employee* auxEmployee = employee_new();

	if(pFile != NULL && pArrayListEmployee != NULL){
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nameAux,workedHoursAux,salaryAux); // Hago una falsa lectura para quitar la cabecera de archivo y guardo la cantidad de variables que encontró el fscanf
		while(!feof(pFile)){
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idAux, nameAux,workedHoursAux, salaryAux);
			//if(r==4){
				auxEmployee = employee_newParametros(idAux ,nameAux, workedHoursAux, salaryAux);

				ll_add(pArrayListEmployee, auxEmployee);
				counter++;
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
	Employee empleadoAux;

	fread(&empleadoAux, sizeof(Employee), 1, pFile); // Hago una falsa lectura para quitar la cabecera de archivo

	if(pFile != NULL && pArrayListEmployee != NULL){

		while(!feof(pFile)){
			Employee* employee = employee_new();
			employee_setId(employee,empleadoAux.id);
			employee_setHorasTrabajadas(employee,empleadoAux.horasTrabajadas);
			employee_setNombre(employee,empleadoAux.nombre);
			employee_setSueldo(employee,empleadoAux.sueldo);
			counter++; //Cuento los empleados que se cargaron
			ll_add(pArrayListEmployee, employee); //Los añado
			fread(&empleadoAux, sizeof(Employee), 1, pFile);
		}
		rtn = counter;
		printf("\nSe cargaron %d empleados a la lista con exito !\n\n", counter);
	}
	return rtn;
}
