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
	LinkedList* listaEmpleados = ll_newLinkedList();
    int option;
    int id;
    int returnAux;

    do{
    	puts("\n\t\t ******MENU DE OPERACIONES******\n");
    	puts("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)");
    	puts("2. Cargar los datos de los empleados desde el archivo data.bin (modo binario)");
    	puts("3. Alta de empleado");
    	puts("4. Modificar datos de empleado");
    	puts("5. Baja de empleado");
    	puts("6. Listar empleados");
    	puts("7. Ordenar empleados");
    	puts("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)");
    	puts("9. Guardar los datos de los empleados en el archivo data.bin (modo binario)");
    	puts("10. Salir");
    	printf("\nOpcion elegida: ");
    	scanf("%d", &option);
        switch(option){
            case 1:
            	returnAux = controller_loadFromText("data.csv",listaEmpleados);
            	if(returnAux >= 0)
				{
					printf("\nDatos cargados exitosamente. %d elementos agregados\n\n", returnAux);
					id= controller_loadLastId("id.bin");
				}
                break;
            case 2:
            	returnAux = controller_loadFromBinary("data.bin",listaEmpleados);
            	if(returnAux >= 0)
				{
					printf("\nDatos cargados exitosamente. %d elementos agregados\n\n", returnAux);
					id = controller_loadLastId("id.bin");
				}
            	break;
            case 3:
            	controller_addEmployee(listaEmpleados);
            	break;
            case 4:
            	if(listaEmpleados != NULL && ll_isEmpty(listaEmpleados) != 1){
            		controller_editEmployee(listaEmpleados);
            	}
            	else{
					puts("\nNo hay un listado para editar empleados\n");
				}
            	break;
            case 5:
            	if(listaEmpleados != NULL && ll_isEmpty(listaEmpleados) != 1){
            		controller_removeEmployee(listaEmpleados);
            	}
            	else{
					puts("\nNo hay un listado para eliminar empleados\n");
				}
            	break;
            case 6:
            	if(listaEmpleados != NULL && ll_isEmpty(listaEmpleados) != 1){
            		controller_ListEmployee(listaEmpleados);
            	}
            	else{
            		puts("\nNo hay listado para mostrar\n");
            	}
            	break;
            case 7:
            	if(listaEmpleados != NULL && ll_isEmpty(listaEmpleados) != 1){
            		controller_sortEmployee(listaEmpleados);
            	}
            	else{
					puts("\nNo hay listado para ordenar\n");
				}
            	break;
            case 8:
            	if(listaEmpleados != NULL && ll_isEmpty(listaEmpleados) != 1){
            		controller_saveAsText("data.csv", listaEmpleados);
            		controller_saveLastId("id.bin", &id);
            	}
            	else{
					puts("\nNo hay listado para guardar\n");
				}
            	break;
            case 9:
            	if(listaEmpleados != NULL && ll_isEmpty(listaEmpleados) != 1){
            		controller_saveAsBinary("data.bin", listaEmpleados);
            		controller_saveLastId("id.bin", &id);
            	}
            	else{
					puts("\nNo hay listado para guardar\n");
				}
            	break;
            case 10:
            	if(listaEmpleados != NULL){
            		ll_deleteLinkedList(listaEmpleados);
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

