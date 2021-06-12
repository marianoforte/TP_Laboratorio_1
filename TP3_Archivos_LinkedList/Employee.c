#include "Employee.h"

int employee_setLastId(int id){
	int lastId = id;
	return lastId;
}

int employee_getLastId(int id){
	int lastId = id;
	return lastId;
}

int employee_increaseLastId(int id){
	int lastId = id;
	lastId++;
	return lastId;
}

int employee_decreaseLastId(int id){
	int lastId = id;
	lastId--;
	return lastId;
}

Employee* employee_new(){
    return (Employee*)calloc(1, sizeof(Employee));
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){
    Employee* auxiliarEmpleado;
    int id;
    int salary;
    int workedHours;
    auxiliarEmpleado = employee_new();
    if( auxiliarEmpleado != NULL ){

    	if(idStr != NULL){
    		id = atoi(idStr);
    		employee_setId(auxiliarEmpleado, id);
    	}
        if(nombreStr != NULL){
        	employee_setNombre(auxiliarEmpleado, nombreStr);
        }
        if(horasTrabajadasStr != NULL){
        	workedHours = atoi(horasTrabajadasStr);
        	employee_setHorasTrabajadas(auxiliarEmpleado, workedHours);
        }
        if(sueldoStr != NULL){
        	salary = atoi(sueldoStr);
        	employee_setSueldo(auxiliarEmpleado, salary);
        }
    }
    return auxiliarEmpleado;

}

void employee_delete(Employee* this){
    if(this!=NULL){
    	free(this);
    }
}

int employee_setId(Employee* this,int id){
    int rtn = 0;
    if(this!=NULL && id>0){
            this->id = id;
            rtn = 1;
    }
    return rtn;
}

int employee_setNombre(Employee* this,char* nombre){
    int rtn = 0;
    if(this!=NULL  && strlen(nombre) != 0){
        strcpy(this->nombre, nombre);
        rtn = 1;
    }
    return rtn;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
    int rtn = 0;
    if(this!=NULL){
        if(horasTrabajadas > 0 || horasTrabajadas <24){
            this->horasTrabajadas = horasTrabajadas;
            rtn = 1;
        }
    }
    return rtn;
}

int employee_setSueldo(Employee* this,int sueldo){
    int rtn = 0;
    if(this!=NULL){
        if(sueldo > 0){
            this->sueldo = sueldo;
            rtn = 1;
        }
    }
    return rtn;
}

int employee_getId(Employee* this,int* id){
    int rtn = 0;
    if(this!=NULL && id != NULL){
        *id = this->id;
        rtn = 1;
    }
    return rtn;
}

int employee_getNombre(Employee* this,char* nombre){
    int rtn = 0;
    if(this!=NULL && nombre != NULL){
        strcpy(nombre, this->nombre); //
        rtn = 1;
    }
    return rtn;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
    int rtn = 0;
    if(this!=NULL && horasTrabajadas != NULL){
        *horasTrabajadas = this->horasTrabajadas;
        rtn = 1;
    }
    return rtn;
}

int employee_getSueldo(Employee* this,int* sueldo){
    int rtn = 0;

    if(this!=NULL && sueldo != NULL){
        *sueldo = this->sueldo;
        rtn = 1;
    }
    return rtn;
}

void employee_showEmployee(Employee* this){
	if(this != NULL ){
		int idAuxiliar;
		char nombreAuxiliar[50];
		int horasAuxiliar;
		int sueldoAuxiliar;

		employee_getId(this, &idAuxiliar);
		employee_getNombre(this,nombreAuxiliar);
		employee_getHorasTrabajadas(this,&horasAuxiliar);
		employee_getSueldo(this,&sueldoAuxiliar);
		printf("%5d  %16s %12d  %15.2d\n",idAuxiliar, nombreAuxiliar, horasAuxiliar, sueldoAuxiliar);
	}
}

int employee_SortById(void* employeeA, void* employeeB){
    int rtn;
    Employee* empA;
    Employee*empB;

    if(employeeA != NULL && employeeB != NULL){
        empA = (Employee*) employeeA;
        empB = (Employee*) employeeB;
        if(empA->id == empB->id){
        	rtn = 0;
        }
        if(empA->id > empB->id){
        	rtn = -1;
        }
        if(empA->id < empB->id){
        	rtn = 1;
        }
    }

    return rtn;
}

int employee_SortByName(void* employeeA, void* employeeB){
    int rtn = 0;
    Employee* empA;
    Employee* empB;

    if(employeeA != NULL && employeeB != NULL){
        empA = (Employee*) employeeA;
        empB = (Employee*) employeeB;
        rtn = strcmp(empB->nombre, empA->nombre);
    }

    return rtn;
}

int employee_SortByWorkHours(void* employeeA, void* employeeB){
    int rtn;
    Employee* empA;
    Employee*empB;

    if(employeeA != NULL && employeeB != NULL){
        empA = (Employee*) employeeA;
        empB = (Employee*) employeeB;
        if(empA->horasTrabajadas == empB->horasTrabajadas){
        	rtn = 0;
        }
        if(empA->horasTrabajadas> empB->horasTrabajadas){
        	rtn = -1;
        }
        if(empA->horasTrabajadas < empB->horasTrabajadas){
        	rtn = 1;
        }
    }

    return rtn;
}

int employee_SortBySalary(void* employeeA, void* employeeB){
    int rtn;
    Employee* empA;
    Employee*empB;

    if(employeeA != NULL && employeeB != NULL){
        empA = (Employee*) employeeA;
        empB = (Employee*) employeeB;
        if(empA->sueldo == empB->sueldo){
        	rtn = 0;
        }
        if(empA->sueldo > empB->sueldo){
        	rtn = -1;
        }
        if(empA->sueldo < empB->sueldo){
        	rtn = 1;
        }
    }

    return rtn;
}
