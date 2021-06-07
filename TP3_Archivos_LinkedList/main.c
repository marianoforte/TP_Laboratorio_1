#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	puts("\t ******MENU DE OPERACIONES******");
    	puts("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)");
    	puts("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario)");
    	puts("3. Alta de empleado");
    	puts("4. Modificar datos de empleado");
    	puts("5. Baja de empleado");
    	puts("6. Listar empleados");
    	puts("7. Ordenar empleados");
    	puts("8. Guardar los datos de los empleados en el archivo data.csv (modo texto)");
    	puts("9. Guardar los datos de los empleados en el archivo data.csv (modo binario)");
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
            	controller_addEmployee(listaEmpleados);
            	break;
            case 4:
            	controller_editEmployee(listaEmpleados);
            	break;
            case 5:
            	controller_removeEmployee(listaEmpleados);
            	break;
            case 6:
            	controller_ListEmployee(listaEmpleados);
            	break;
            case 7:
            	controller_sortEmployee(listaEmpleados);
            	break;
            case 8:
            	controller_saveAsText("data.csv", listaEmpleados);
            	break;
            case 9:
            	controller_saveAsBinary("data.dat", listaEmpleados);
            	break;
            case 10:
            	puts("Gracias por utilizar la aplicacion.\nEscrita y desarrollada por Mariano Forte.");
            	system("pause");
            	break;
            default:
            	puts("Opcion invalida\n");
            	break;
        }
        system("cls");
    }while(option != 10);
    return 0;
}

