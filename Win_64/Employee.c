#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "Controller.h"
#include "LinkedList.h"
#define R_OK 1
#define R_ERROR 0


Employee* employee_new()
{
    Employee* empleado;
    empleado = (Employee*)malloc(sizeof(Employee));
    empleado->id = 0;
    strcpy(empleado->nombre, "");
    empleado->horasTrabajadas;
    empleado->sueldo;

    return empleado;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{
    Employee* empleado;
    empleado = (Employee*)malloc(sizeof(Employee));
    empleado->id = idStr;
    strcpy(empleado->nombre, nombreStr);
    empleado->horasTrabajadas = horasTrabajadasStr;
    empleado->sueldo = 0;

    return empleado;
}

void employee_delete()
{

}

int employee_setId(Employee* this,int id)
{
    int r=R_ERROR;


    if(id > 0 && this != NULL)
    {
        this->id = id;
        r = R_OK;
    }
    return r;
}
int employee_getId(Employee* this,int* id)
{
    int r=R_ERROR;

    if(this != NULL)
    {
        *id = this->id;
        r = R_OK;
    }

    return r;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int r=R_ERROR;

    if(this != NULL)
    {
        strcpy(this->nombre,nombre);
        r = R_OK;
    }

    return r;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int r=R_ERROR;

    if(this != NULL)
    {
        strcpy(nombre,this->nombre);
        r = R_OK;
    }

    return r;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int r=R_ERROR;

    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        r = R_OK;
    }

    return r;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int r=R_ERROR;

    if(this != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        r = R_OK;
    }

    return r;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int r=R_ERROR;

    if(this != NULL)
    {
        this->sueldo = sueldo;
        r = R_OK;
    }

    return r;
}
int employee_getSueldo(Employee* this,int* sueldo)
{
    int r=R_ERROR;

    if(this != NULL)
    {
        *sueldo = this->sueldo;
        r = R_OK;
    }

    return r;
}

void  employee_showOneEmployee(Employee* this)
{
    if(this != NULL )
    {
        printf ( " %4d  %s  %d  %d \n\n ", this->id, this->nombre, this->horasTrabajadas, this->sueldo);
    }
}

void  employee_showAllEmployees(Employee* this)
{
    Employee* empleado;

    if(this != NULL )
    {
        for(int i=0; i<ll_len(this); i++)
        {
            empleado = (Employee*)ll_get(this, i);
            employee_showOneEmployee(empleado);
        }
    }
    else
    {
        printf("No se han cargado empleados\n\n");
    }

}

int employee_ordByName(void* empleadoA, void* empleadoB)
{
    int r=R_ERROR;


    Employee* employeeA;
    Employee* employeeB;

    if(empleadoA != NULL && empleadoB != NULL)
    {
        employeeA = (Employee*) empleadoA;
        employeeB = (Employee*) empleadoB;
        r = strcmp(employeeA->nombre, employeeB->nombre);
    }
    return r;
}

int employee_ordById(void* employeeA, void* employeeB)
{
    int r=R_ERROR;


    Employee* empleadoA;
    Employee* empleadoB;

    if(employeeA != NULL && employeeB != NULL)
    {
        empleadoA = (Employee*) employeeA;
        empleadoB = (Employee*) employeeB;
        r = empleadoA->id, empleadoB->id;
    }
    return r;
}

int employee_ordByHorasTrabajadas(void* employeeA, void* employeeB)
{
    int r=R_ERROR;


    Employee* empleadoA;
    Employee* empleadoB;

    if(employeeA != NULL && employeeB != NULL)
    {
        empleadoA = (Employee*) employeeA;
        empleadoB = (Employee*) employeeB;
        r = empleadoA->horasTrabajadas, empleadoB->horasTrabajadas;
    }
    return r;
}

int employee_ordBySueldo(void* employeeA, void* employeeB)
{
    int r=R_ERROR;

    Employee* empleadoA;
    Employee* empleadoB;

    if(employeeA != NULL && employeeB != NULL)
    {
        empleadoA = (Employee*) employeeA;
        empleadoB = (Employee*) employeeB;
        r = empleadoA->sueldo, empleadoB->sueldo;
    }
    return r;
}



