#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "eEmpleado.h"

eEmpleado* employee_new()
{
    eEmpleado* empleado = (eEmpleado*)malloc(sizeof(eEmpleado));
    return empleado;
}

eEmpleado* employee_newParametros(char* idStr, char* nombreStr, char* empleo, char* edad, char* horasTrabajadasStr)
{
    eEmpleado* empleado = employee_new();
    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && edad != NULL && empleado != NULL && empleo != NULL)
    {
        employee_setId(empleado, atoi(idStr));
        employee_setEmpleo(empleado, empleo);
        employee_setNombre(empleado, nombreStr);
        employee_setHorasTrabajadas(empleado, atoi(horasTrabajadasStr));
        employee_setEdad(empleado, atoi(edad));
        return empleado;
    }else
    {
        return NULL;
    }
}

int employee_setId(eEmpleado* this, int id)
{
    int status = 0;
    if(this != NULL)
    {
        this->id = id;
        status = 1;
    }
    return status;
}

int employee_getId(eEmpleado* this)
{
    int returnAux;
    if(this != NULL)
    {
        returnAux = (this->id);
    }
    return returnAux;
}

int employee_setNombre(eEmpleado* this, char* nombre)
{
    int status = 0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        status = 1;
    }
    return status;
}

char* employee_getNombre(eEmpleado* this)
{
    char* returnAux = NULL;
    if(this != NULL)
    {
        returnAux = this->nombre;
    }
    return returnAux;
}

int employee_setHorasTrabajadas(eEmpleado* this, int horasTrabajadas)
{
    int status = 0;
    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        status = 1;
    }
    return status;
}

int employee_getHorasTrabajadas(eEmpleado* this)
{
    int returnAux;
    if(this != NULL)
    {
        returnAux = (this->horasTrabajadas);
    }
    return returnAux;
}

int employee_compareByName(eEmpleado* e1, eEmpleado* e2)
{
    return strcmp(e1->nombre,e2->nombre);
}

int employee_setEdad(eEmpleado* this, int edad)
{
    int status = 0;
    if(this != NULL)
    {
        this->edad = edad;
        status = 1;
    }
    return status;
}

int employee_setEmpleo(eEmpleado* this, char* empleo)
{
    int status = 0;
    if(this!= NULL && empleo != NULL)
    {
        strcpy(this->empleo, empleo);
        status = 1;
    }
    return status;
}

char* employee_getEmpleo(eEmpleado* this)
{
    char* returnAux = NULL;
    if(this != NULL)
    {
        returnAux = this->empleo;
    }
    return returnAux;
}

int employee_getEdad(eEmpleado* this)
{
    int returnAux;
    if(this != NULL)
    {
        returnAux = (this->edad);
    }
    return returnAux;
}

int laQueMapea(void* pElement)
{
    int returnAux = -1;
    if(pElement != NULL)
    {
        returnAux = employee_getHorasTrabajadas(pElement) * 300;
    }
    return returnAux;
}

int employee_getSueldo(eEmpleado* this)
{
    int returnAux;
    if(this != NULL)
    {
        returnAux = (this->sueldo);
    }
    return returnAux;
}
