#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char id[100], nombre[100], horasTrabajadas[100], sueldo[100];
    while(!feof(pFile))
    {
        Employee* aux = (Employee*)malloc(sizeof(Employee));

        fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);

        aux->id = atoi(id);
        strcpy(aux->nombre, nombre);
        aux->horasTrabajadas = atoi(horasTrabajadas);
        aux->sueldo = atoi(sueldo);

        ll_add(pArrayListEmployee, aux);
    }
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{


    return 1;
}
