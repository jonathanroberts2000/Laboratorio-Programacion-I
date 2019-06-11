#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "pInput.h"
#define PATHT "data.csv"
#define PATHB "data.dat"
#define MAT miArchivoT
#define MAB miArchivoB

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int status = 0;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        FILE* MAT;
        MAT = fopen(path, "r");
        parser_EmployeeFromText(MAT, pArrayListEmployee);
        fclose(MAT);
        status = 1;
    }
    return status;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int status = 0;
    int i;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        FILE* MAB;
        FILE* MAT;
        MAT = fopen(PATHT, "r");
        parser_EmployeeFromText(MAT, pArrayListEmployee);
        fclose(MAT);

        MAB = fopen(PATHB, "wb");
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            Employee* aux;
            aux = ll_get(pArrayListEmployee, i);
            fwrite(aux, sizeof(Employee),1,miArchivoB);
        }
        fclose(MAB);

        MAB = fopen(PATHB, "rb");
        parser_EmployeeFromBinary(MAB, pArrayListEmployee);
        fclose(MAB);
        status = 1;
    }
    return status;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int status = 0;
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    Employee* e1 = employee_new();
    if(pArrayListEmployee != NULL)
    {
        printf("Id generado correctamente!\n");
        id = (ll_len(pArrayListEmployee) + 1);
        printf("Ingrese nombre: ");
        fflush(stdin);
        scanf("%s", nombre);
        printf("Ingrese cantidad de horas trabajadas: ");
        scanf("%d", &horasTrabajadas);
        printf("Ingrese sueldo: ");
        scanf("%d", &sueldo);

        employee_setId(e1, id);
        employee_setNombre(e1, nombre);
        employee_setHorasTrabajadas(e1, horasTrabajadas);
        employee_setSueldo(e1, sueldo);
        ll_add(pArrayListEmployee, e1);
        status = 1;
    }
    return status;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int status = 0;
    int id;
    int option;
    char seguir = 's';
    Employee* aux;
    printf("Ingrese el id del empleado que desea modificar: ");
    scanf("%d", &id);
    aux = ll_get(pArrayListEmployee, id);
    if(aux != NULL && pArrayListEmployee != NULL)
    {
        do
        {
            printf("1.Nombre\n2.Horas trabajadas\n3.Sueldo\n4.Salir\nIngrese una opcion: ");
            scanf("%d", &option);

            switch(option)
            {
            case 1:
                printf("Ingrese el nuevo nombre: ");
                fflush(stdin);
                scanf("%s", aux->nombre);
                break;
            case 2:
                printf("Ingrese la nueva cantidad de horas trabajadas: ");
                scanf("%d", &(aux->horasTrabajadas));
                break;

            case 3:
                printf("Ingrese el nuevo sueldo: ");
                scanf("%d", &(aux->sueldo));
                break;
            case 4:
                return 1;
                break;
            default:
                printf("Opcion invalida! Reingrese\n");
                break;
            }
        }
        while(seguir == 's');
        status = 1;
    }
    else{
        status = 2;
    }
    return status;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int status = 0;
    int id;
    if(pArrayListEmployee != NULL)
    {
        printf("Ingrese el id del empleado que desea borrar: ");
        scanf("%d", &id);
        ll_remove(pArrayListEmployee, id);
        //antes de borrar mostrar los datos del empleado a borrar y preguntar si es ese el que quiere borrar!
        printf("Operacion exitosa!\n");
        status = 1;
    }
    return status;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int status = 0;
    int i;
    Employee* aux;
    if(pArrayListEmployee != NULL)
    {
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            aux = ll_get(pArrayListEmployee, i);
            printf("%d--%s--%d--%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
            status = 1;
        }
    }
    return status;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int status = 0;
    int (*pFunc)(Employee*,Employee*);
    pFunc = employee_compareByName;
    if(pArrayListEmployee != NULL)
    {
        ll_sort(pArrayListEmployee, pFunc, 1);
        status = 1;
    }
    return status;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int status = 0;
    int i;
    Employee* aux;
    FILE* MAT;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        MAT = fopen(path, "w");
        fprintf(MAT, "id,nombre,horasTrabajadas,sueldo\n");
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            aux = ll_get(pArrayListEmployee,i);
            fprintf(MAT, "%d,%s,%d,%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
        }
        fclose(MAT);
        status = 1;
    }
    return status;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int status = 0;
    int i;
    Employee* aux;
    FILE* MAB;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        MAB = fopen(path, "wb");
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            aux = ll_get(pArrayListEmployee, i);
            fwrite(aux, sizeof(Employee), 1, MAB);
        }
        fclose(MAB);
        status = 1;
    }
    return status;
}

