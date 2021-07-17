#include "Employee.h"

static int lastId;

int employee_setLastId(int id){
	lastId = id;
	return lastId;
}

int employee_getLastId(){
	return lastId;
}

int employee_increaseLastId(){
	lastId++;
	return lastId;
}

int employee_decreaseLastId(){
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
    int rtn = -1;
    if(this!=NULL && id>0){
            this->id = id;
            rtn = 0;
    }
    return rtn;
}

int employee_setNombre(Employee* this,char* nombre){
    int rtn = -1;
    if(this!=NULL  && strlen(nombre) != 0){
        strcpy(this->nombre, nombre);
        rtn = 0;
    }
    return rtn;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
    int rtn = -1;
    if(this!=NULL){
        if(horasTrabajadas > 0 || horasTrabajadas <24){
            this->horasTrabajadas = horasTrabajadas;
            rtn = 0;
        }
    }
    return rtn;
}

int employee_setSueldo(Employee* this,int sueldo){
    int rtn = -1;
    if(this!=NULL){
        if(sueldo > 0){
            this->sueldo = sueldo;
            rtn = 0;
        }
    }
    return rtn;
}

int employee_getId(Employee* this,int* id){
    int rtn = -1;
    if(this!=NULL && id != NULL){
        *id = this->id;
        rtn = 0;
    }
    return rtn;
}

int employee_getNombre(Employee* this,char* nombre){
    int rtn = -1;
    if(this!=NULL && nombre != NULL){
        strcpy(nombre, this->nombre); //
        rtn = 0;
    }
    return rtn;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
    int rtn = -1;
    if(this!=NULL && horasTrabajadas != NULL){
        *horasTrabajadas = this->horasTrabajadas;
        rtn = 0;
    }
    return rtn;
}

int employee_getSueldo(Employee* this,int* sueldo){
    int rtn = -1;

    if(this!=NULL && sueldo != NULL){
        *sueldo = this->sueldo;
        rtn = 0;
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

int employee_compareById(void* firstEmployee, void* secondEmployee){
    Employee* e1;
    Employee* e2;
    int comparison = -2;
    int id1;
    int id2;

    if(firstEmployee != NULL && secondEmployee != NULL){
        e1 = (Employee*)firstEmployee;
        e2 = (Employee*)secondEmployee;

        if(!employee_getId(e1, &id1)){
            if(!employee_getId(e2, &id2)){
                if(id1 < id2){
                    comparison = -1;
                }
                else{
                    comparison = 0;
                    if(id1 > id2){
                        comparison = 1;
                    }
                }
            }
        }
    }
    return comparison;
}

int employee_compareByName(void* firstEmployee, void* secondEmployee){
    Employee* e1;
    Employee* e2;
    int comparison = -2;
    char name1[128];
    char name2[128];

    if(firstEmployee != NULL && secondEmployee != NULL){
        e1 = (Employee*)firstEmployee;
        e2 = (Employee*)secondEmployee;

        if(!employee_getNombre(e1, name1)){
            if(!employee_getNombre(e2, name2)){
                comparison = strcmp(name1, name2);
                if(comparison < -1){
                    comparison = -1;
                }
                else{
                    if(comparison>1){
                        comparison = 1;
                    }
                }
            }
        }
    }
    return comparison;
}

int employee_compareByHoursWorked(void* firstEmployee, void* secondEmployee){
    Employee* e1;
    Employee* e2;
    int comparison = -2;
    int hours1;
    int hours2;

    if(firstEmployee != NULL && secondEmployee != NULL){
        e1 = (Employee*)firstEmployee;
        e2 = (Employee*)secondEmployee;

        if(!employee_getHorasTrabajadas(e1, &hours1)){
            if(!employee_getHorasTrabajadas(e2, &hours2)){
                if(hours1 < hours2){
                    comparison = -1;
                }
                else{
                    comparison = 0;
                    if(hours1 > hours2){
                        comparison = 1;
                    }
                }
            }
        }
    }
    return comparison;
}

int employee_compareBySalary(void* firstEmployee, void* secondEmployee){
    Employee* e1;
    Employee* e2;
    int comparison = 2;
    int salary1;
    int salary2;

    if(firstEmployee != NULL && secondEmployee != NULL){
        e1 = (Employee*)firstEmployee;
        e2 = (Employee*)secondEmployee;

        if(!employee_getSueldo(e1, &salary1)){
            if(!employee_getSueldo(e2, &salary2)){
                if(salary1 < salary2){
                    comparison = -1;
                }
                else{
                    comparison = 0;
                    if(salary1 > salary2){
                        comparison = 1;
                    }
                }
            }
        }
    }
    return comparison;
}
