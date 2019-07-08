#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eEmpleado.h"

eEmpleado* employee_new()/*...LISTO...*/
{
    eEmpleado* empleado = (eEmpleado*)malloc(sizeof(eEmpleado));
    return empleado;
}

eEmpleado* employee_newParametros(char* idStr, char* nombreStr, char* empleoStr, char* edadStr, char* horasTrabajadasStr)/*...LISTO...*/
{
    eEmpleado* empleado = employee_new();
    if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && edadStr != NULL && empleoStr != NULL && empleado != NULL)
    {
        employee_setId(empleado, atoi(idStr));
        employee_setEmpleo(empleado, empleoStr);
        employee_setNombre(empleado, nombreStr);
        employee_setHorasTrabajadas(empleado, atoi(horasTrabajadasStr));
        employee_setEdad(empleado, atoi(edadStr));
        return empleado;
    }else
    {
        return NULL;
    }
}

int employee_setId(eEmpleado* this, int id)/*...LISTO...*/
{
    int status = 0;
    if(this != NULL && id > 0)
    {
        this->id = id;
        status = 1;
    }
    return status;
}

int employee_getId(eEmpleado* this)/*...LISTO...*/
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = (this->id);
    }
    return returnAux;
}

int employee_setNombre(eEmpleado* this, char* nombre)/*...LISTO...*/
{
    int status = 0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        status = 1;
    }
    return status;
}

char* employee_getNombre(eEmpleado* this)/*...LISTO...*/
{
    char* returnAux = NULL;
    if(this != NULL)
    {
        returnAux = this->nombre;
    }
    return returnAux;
}

int employee_setEmpleo(eEmpleado* this, char* empleo)/*...LISTO...*/
{
    int status = 0;
    if(this!= NULL && empleo != NULL)
    {
        strcpy(this->empleo, empleo);
        status = 1;
    }
    return status;
}

char* employee_getEmpleo(eEmpleado* this)/*...LISTO...*/
{
    char* returnAux = NULL;
    if(this != NULL)
    {
        returnAux = this->empleo;
    }
    return returnAux;
}

int employee_setHorasTrabajadas(eEmpleado* this, int horasTrabajadas)/*...LISTO...*/
{
    int status = 0;
    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        status = 1;
    }
    return status;
}

int employee_getHorasTrabajadas(eEmpleado* this)/*...LISTO...*/
{
    int returnAux;
    if(this != NULL)
    {
        returnAux = (this->horasTrabajadas);
    }
    return returnAux;
}

int employee_setEdad(eEmpleado* this, int edad)/*...LISTO...*/
{
    int status = 0;
    if(this != NULL)
    {
        this->edad = edad;
        status = 1;
    }
    return status;
}

int employee_getEdad(eEmpleado* this)/*...LISTO...*/
{
    int returnAux;
    if(this != NULL)
    {
        returnAux = (this->edad);
    }
    return returnAux;
}

int employee_setSueldo(eEmpleado* this, float sueldo)/*...LISTO...*/
{
    int status = 0;
    if(this != NULL)
    {
        this->sueldo = sueldo;
        status = 1;
    }
    return status;
}

float employee_getSueldo(eEmpleado* this)/*...LISTO...*/
{
    float returnAux = -1;
    if(this != NULL)
    {
        returnAux = (this->sueldo);
    }
    return returnAux;
}

int employee_compareByName(eEmpleado* this1, eEmpleado* this2)/*...LISTO...*/
{
    return strcmp(this1->nombre,this2->nombre);
}

int laQueMapea(eEmpleado* this)/*...LISTO...*/
{
    int returnAux;
    float sueldo;
    if(this != NULL)
    {
        sueldo = employee_getHorasTrabajadas(this) * 300;
        returnAux = employee_setSueldo(this, sueldo);
    }
    return returnAux;
}

int laQuefiltra(eEmpleado* this)/*...LISTO...*/
{
    int returnAux = -1;
    if(this != NULL)
    {
        if(stricmp(employee_getEmpleo(this), "programador") == 0 && employee_getEdad(this) > 20)
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

