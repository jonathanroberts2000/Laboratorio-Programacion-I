#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"

Employee* employee_new()
{
    Employee* unEmpleado = (Employee*)malloc(sizeof(Employee));
    return unEmpleado;
}
/*Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr)
{

}
void employee_delete()
{

}*/


int employee_setId(Employee* this,int id)
{
    int status = 0;
    if(this != NULL)
    {
        this->id = id;
        status = 1;
    }
    return status;
}
/* employee_getId(Employee* this,int* id)
{

}*/

int employee_setNombre(Employee* this,char* nombre)
{
    int status = 0;
    if(this != NULL)
    {
        strcpy(this->nombre, nombre);
        status = 1;
    }
    return status;
}
/*int employee_getNombre(Employee* this,char* nombre)
{

}*/

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int status = 0;
    if(this != NULL)
    {
        this->horasTrabajadas = horasTrabajadas;
        status = 1;
    }
    return status;
}
/*int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{

}*/

int employee_setSueldo(Employee* this,int sueldo)
{
    int status = 0;
    if(this != NULL)
    {
        this->sueldo = sueldo;
        status = 1;
    }
    return status;
}
/*int employee_getSueldo(Employee* this,int* sueldo)
{

}*/

int employee_compareByName(Employee* e1, Employee* e2)
{
    int r;
    r = strcmp(e1->nombre,e2->nombre);
    return r;
}
