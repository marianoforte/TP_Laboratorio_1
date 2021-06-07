#include "Employee.h"

static int lastId = 0;

int employee_setLastId(int id){
		lastId = id;
	return lastId;
}

int employee_getLastId(void){
	return lastId;
}

int employee_increaseLastId(void){
	lastId++;
	return lastId;
}

int employee_decreaseLastId(void){
	lastId--;
	return lastId;
}

/** \brief Almacena un espacio en memoria dinamica para un empleado
 *
 * \param -
 * \param -
 * \return allocated memmory for the new employee
 */
Employee* employee_new()
{
    return (Employee*)calloc(1, sizeof(Employee));
}

/** \brief Creo nuevos empleados con parametros
 *
 * \param char* idStr Id generado
 * \param char* nombreStr Nombre generado
 * \param char* horasTrabajadasStr Horas trabajadas generadas
 * \param char* sueldoStr Sueldo
 * \return retorna la direccion del empleado
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* auxiliarEmpleado = employee_new();

    int id;
    int salary;
    int workedHours;
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


/** \brief Libera espacio de un empleado eliminado
 *
 * \param Employee* this Puntero del array de empleados
 * \return -
 *
 */
void employee_delete(Employee* this)
{   ///LIBERA ESPACIO EN CADA EMPLEADO
    if(this!=NULL){
    	free(this);
    }
}


/** \brief Valida el id
 *
 * \param Employee* this Puntero del array de empleados
 * \param int id recibe una cantidad de id
 * \return rtn, si esta bien es 1, si esta mal es 0
 *
 */
int employee_setId(Employee* this,int id)
{
    int rtn = 0;
    if(this!=NULL && id>0){
            this->id = id;
            rtn = 1;
    }
    return rtn;
}


/** \brief Valida el Nombre
 *
 * \param Employee* this Puntero del array de empleados
 * \param char* nombre recibe un nombre
 * \return rtn, si esta bien es 1, si esta mal es 0
 *
 */
int employee_setNombre(Employee* this,char* nombre) ///MODIFICAR
{
    int rtn = 0;
    if(this!=NULL  && strlen(nombre) != 0){
        strcpy(this->nombre, nombre);
        rtn = 1;
    }
    return rtn;
}


/** \brief Valida las horas de trabajo
 *
 * \param Employee* this Puntero del array de empleados
 * \param int horasTrabajadas Recibe una cantidad de horas de trabajo
 * \return rtn, si esta bien es 1, si esta mal es 0
 *
 */

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int rtn = 0;
    if(this!=NULL){
        if(horasTrabajadas > 0 || horasTrabajadas <24){
            this->horasTrabajadas = horasTrabajadas;
            rtn = 1;
        }
    }
    return rtn;
}


/** \brief Valida el sueldo
 *
 * \param Employee* this Puntero del array de empleados
 * \param float sueldo Recibe una cantidad de sueldo
 * \return rtn, si esta bien es 1, si esta mal es 0
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    int rtn = 0;
    if(this!=NULL){
        if(sueldo > 1000 || sueldo <90000){
            this->sueldo = sueldo;
            rtn = 1;
        }
    }
    return rtn;
}


/** \brief Me escribe el parametro del nombre en el argumento pasado
 *
 * \param Employee* this Puntero del array de empleados
 * \param char* nombre Recibe un nombre
 * \return rtn, si esta bien es 1, si esta mal es 0
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
    int rtn = 0;
    if(this!=NULL && nombre != NULL){
        strcpy ( nombre, this->nombre); //
        rtn = 1;
    }
    return rtn;
}


/** \brief Me escribe el parametro del id en el argumento pasado
 *
 * \param Employee* this Puntero del array de empleados
 * \param int* id recibe un puntero al id
 * \return rtn, si esta bien es 1, si esta mal es 0
 *
 */

int employee_getId(Employee* this,int* id)
{
    int rtn = 0;
    if(this!=NULL && id != NULL){
        *id = this->id;
        rtn = 1;
    }
    return rtn;
}

/** \brief Me escribe el parametro de las horas trabajadas en el argumento pasado
 *
 * \param Employee* this Puntero del array de empleados
 * \param int* horasTrabajadas Recibe un puntero a las horas trabajadas
 * \return retorno, si esta bien es 1, si esta mal es 0
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int rtn = 0;
    if(this!=NULL && horasTrabajadas != NULL){
        *horasTrabajadas = this->horasTrabajadas;
        rtn = 1;
    }
    return rtn;
}


/** \brief Me escribe el parametro del sueldo en el argumento pasado
 *
 * \param Employee* this Puntero del array de empleados
 * \param float* sueldo recibe un puntero del sueldo
 * \return rtn, si esta bien es 1, si esta mal es 0
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    int rtn = 0;

    if(this!=NULL && sueldo != NULL){
        *sueldo = this->sueldo;
        rtn = 1;
    }
    return rtn;
}


/** \brief Valida el id
 *
 * \param Employee* empleado Puntero del array de empleados
 * \return -
 *
 */
void employee_showEmployee(Employee* this)
{
	if(this != NULL ){
		int idAuxiliar;
		char nombreAuxiliar[50];
		int horasAuxiliar;
		int sueldoAuxiliar;

		employee_getId(this, &idAuxiliar);
		employee_getNombre(this,nombreAuxiliar);
		employee_getHorasTrabajadas(this,&horasAuxiliar);
		employee_getSueldo(this,&sueldoAuxiliar);
		printf("%5d  %10s %10d  %15.2d\n",idAuxiliar, nombreAuxiliar, horasAuxiliar, sueldoAuxiliar);
	}
}

/** \brief Compara dos parametros que serian int (por el id)
 *
 * \param void* employeeA
 * \param void* employeeB
 * \return rtn Devuelve 1 si el employeeA es igual a empleado B, devuelve -1 si el employeeA es mayor al empleado B y devuelve 1 si el employeeA es menor al empleado B
 *
 */
int employeeSortById(void* employeeA, void* employeeB)
{
    int rtn;
    Employee* empA;
    Employee*empB;

    if(employeeA != NULL && employeeB != NULL){
        empA = (Employee*) employeeA;
        empB = (Employee*) employeeB;
        if(empA->id == empB->id){
        	rtn = 1;
        }
        if(empA->id > empB->id){
        	rtn = -1;
        }
        if(empA->id < empB->id){
        	rtn = 0;
        }
    }

    return rtn;
}


/** \brief Compara dos parametros que serian string (por el nombre)
 *
 * \param void* employeeA
 * \param void* employeeB
 * \return rtn Devuelve la comparacion de los dos parametros, o devuelve 0 si falla
 *
 */
int employeeSortByName(void* employeeA, void* employeeB)
{
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


/** \brief Compara dos parametros que serian int (por las horas trabajadas)
 *
 * \param void* employeeA
 * \param void* employeeB
 * \return rtn Devuelve 1 si el employeeA es igual a empleado B, devuelve -1 si el employeeA es mayor al empleado B y devuelve 1 si el employeeA es menor al empleado B
 *
 */
int employeeSortByWorkHours(void* employeeA, void* employeeB)
{
    int rtn;
    Employee* empA;
    Employee*empB;

    if(employeeA != NULL && employeeB != NULL){
        empA = (Employee*) employeeA;
        empB = (Employee*) employeeB;
        if(empA->horasTrabajadas == empB->horasTrabajadas){
        	rtn = 1;
        }
        if(empA->horasTrabajadas> empB->horasTrabajadas){
        	rtn = -1;
        }
        if(empA->horasTrabajadas < empB->horasTrabajadas){
        	rtn = 0;
        }
    }

    return rtn;
}


/** \brief Compara dos parametros que serian float (por el salario)
 *
 * \param void* employeeA
 * \param void* employeeB
 * \return rtn Devuelve 1 si el employeeA es igual a empleado B, devuelve -1 si el employeeA es mayor al empleado B y devuelve 1 si el employeeA es menor al empleado B
 *
 */
int employeeSortBySalary(void* employeeA, void* employeeB)
{
    int rtn;
    Employee* empA;
    Employee*empB;

    if(employeeA != NULL && employeeB != NULL){
        empA = (Employee*) employeeA;
        empB = (Employee*) employeeB;
        if(empA->sueldo == empB->sueldo){
        	rtn = 1;
        }
        if(empA->sueldo > empB->sueldo){
        	rtn = -1;
        }
        if(empA->sueldo < empB->sueldo){
        	rtn = 0;
        }
    }

    return rtn;
}


