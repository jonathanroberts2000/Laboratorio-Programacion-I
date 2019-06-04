#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "pInput.h"
#define PATHT "data.csv"
#define PATHB "data.dat"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* miArchivoT;
    miArchivoT = fopen(path, "r");
    parser_EmployeeFromText(miArchivoT, pArrayListEmployee);
    fclose(miArchivoT);
    return 1;
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
    FILE* miArchivoB;
    FILE* miArchivoT;
    miArchivoT = fopen("data.csv", "r");
    parser_EmployeeFromText(miArchivoT, pArrayListEmployee);

    fclose(miArchivoT);
    int i;
    miArchivoB = fopen("data.dat", "wb");
    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        Employee* aux = (Employee*)malloc(sizeof(Employee));
        aux = ll_get(pArrayListEmployee, i);
        fwrite(aux, sizeof(Employee),1,miArchivoB);
    }
    fclose(miArchivoB);



    miArchivoB = fopen(PATHB, "rb");
    parser_EmployeeFromBinary(miArchivoB, pArrayListEmployee);
    fclose(miArchivoB);
    return 1;
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
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
    Employee* e1 = employee_new();
    printf("Ingrese id: ");
    scanf("%d", &id);
    printf("Ingrese nombre: ");
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
    return 1;
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
    int id;
    int option;
    char seguir = 's';
    Employee* aux;
    printf("Ingrese el id del empleado que desea modificar: ");
    scanf("%d", &id);
    aux = ll_get(pArrayListEmployee, id);
    if(aux != NULL)
    {
        do
        {
            printf("1.Nombre\n2.Horas trabajadas\n3.Sueldo\n4.Salir\nIngrese una opcion: ");
            scanf("%d",&option);

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
    }
    else{
        printf("Id no registrado en el sistema!\n");
    }
    return 1;
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
    int id;
    printf("Ingrese el id del empleado que desea borrar: ");
    scanf("%d", &id);
    ll_remove(pArrayListEmployee, id);
    //antes de borrar mostrar los datos del empleado a borrar y preguntar si es ese el que quiere borrar!
    printf("Operacion exitosa!\n");
    return 1;
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
    int i;
    Employee* aux = employee_new();
    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        aux = ll_get(pArrayListEmployee, i);
        printf("%d--%s--%d--%d\n", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
    }
    return 1;
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
    int (*pFunc)(Employee*,Employee*);
    pFunc = employee_compareByName;
    ll_sort(pArrayListEmployee, pFunc, 1);
    return 1;
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
    int i;
    Employee* aux;
    FILE* miArchivoT;

    miArchivoT = fopen(path, "w");
    fprintf(miArchivoT,"id,nombre,horasTrabajadas,sueldo\n");
    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        aux=ll_get(pArrayListEmployee,i);

        fprintf(miArchivoT,"%d,%s,%d,%d\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
    }
    fclose(miArchivoT);
    return 1;
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
    int i;
    Employee* aux;
    FILE* miArchivoB;
    miArchivoB = fopen(path, "wb");
    for(i=0;i<ll_len(pArrayListEmployee);i++)
    {
        aux = ll_get(pArrayListEmployee, i);
        fwrite(aux, sizeof(Employee), 1, miArchivoB);
    }
    return 1;
}

