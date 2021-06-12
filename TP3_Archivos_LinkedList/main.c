#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.dat (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.dat (modo binario).
    10. Salir
*****************************************************/



int main(){
	setbuf(stdout,NULL);
    int option, id;
    LinkedList* listaEmpleados = ll_newLinkedList();
    id = controller_loadLastId("id.dat");
    do{
    	puts("\n\t\t ******MENU DE OPERACIONES******\n");
    	puts("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)");
    	puts("2. Cargar los datos de los empleados desde el archivo data.dat (modo binario)");
    	puts("3. Alta de empleado");
    	puts("4. Modificar datos de empleado");
    	puts("5. Baja de empleado");
    	puts("6. Listar empleados");
    	puts("7. Ordenar empleados");
    	puts("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)");
    	puts("9. Guardar los datos de los empleados en el archivo data.dat (modo binario)");
    	puts("10. Salir");
    	printf("\nOpcion elegida: ");
    	scanf("%d", &option);
        switch(option){
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
            	controller_loadFromBinary("data.dat",listaEmpleados);
            	break;
            case 3:
            	controller_addEmployee(listaEmpleados, &id);
            	break;
            case 4:
            	if(listaEmpleados != NULL){
            		controller_editEmployee(listaEmpleados);
            	}
            	break;
            case 5:
            	if(listaEmpleados != NULL){
            		controller_removeEmployee(listaEmpleados);
            	}
            	break;
            case 6:
            	if(listaEmpleados != NULL){
            		controller_ListEmployee(listaEmpleados);
            	}
            	break;
            case 7:
            	if(listaEmpleados != NULL){
            		controller_sortEmployee(listaEmpleados);
            	}
            	break;
            case 8:
            	if(listaEmpleados != NULL){
            		controller_saveAsText("data.csv", listaEmpleados);
            		controller_saveLastId("id.dat", &id);
            	}
            	break;
            case 9:
            	if(listaEmpleados != NULL){
            		controller_saveAsBinary("data.dat", listaEmpleados);
            		controller_saveLastId("id.dat", &id);
            	}
            	break;
            case 10:
            	if(listaEmpleados != NULL){
            		free(listaEmpleados);
            	}
            	printf("\n-------------------------------------------------------------------------------\n");
            	puts("\nGracias por utilizar la aplicacion.\nEscrita y desarrollada por Mariano Forte.\n");
            	system("pause");
            	break;
            default:
            	puts("Opcion invalida\n");
            	break;
        }
        printf("-------------------------------------------------------------------------------\n");
    }while(option != 10);
    return 0;
}

