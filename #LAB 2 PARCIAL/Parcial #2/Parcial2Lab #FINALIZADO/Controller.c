#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "eEmpleado.h"
#include "Controller.h"
#include "Parser.h"
#include "pInput.h"
#define PATHT "datos.csv"
#define PATHTR "resultados.csv"

int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)/*LISTO Y USADO...*/
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

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int status = 0;
    int id;
    char nombre[128];
    char empleo[128];
    int horasTrabajadas;
    int edad;
    eEmpleado* e1 = employee_new();
    if(pArrayListEmployee != NULL)
    {
        id = (ll_len(pArrayListEmployee) + 1);
        puts("Id generado correctamente!");
        get_String(nombre, "Ingrese nombre: ");
        get_String(empleo, "Ingrese un empleo: ");
        fflush(stdin);
        get_Int(&horasTrabajadas, "Ingrese cantidad de horas trabajadas: ");
        get_Int(&edad, "Ingrese edad: ");
        employee_setId(e1, id);
        employee_setNombre(e1, nombre);
        employee_setHorasTrabajadas(e1, horasTrabajadas);
        employee_setEdad(e1, edad);
        employee_setEmpleo(e1, empleo);
        ll_add(pArrayListEmployee, e1);
        status = 1;
    }
    return status;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int status = 0;
    int id;
    int option;
    char seguir = 's';
    eEmpleado* aux;
    get_Int(&id, "Ingrese el id del empleado que desea modificar: ");
    aux = ll_get(pArrayListEmployee, (id-1));
    if(aux != NULL && pArrayListEmployee != NULL)
    {
        do
        {
            get_Int(&option, "1.Nombre\n2.Empleo\n3.Edad\n4.Horas trabajadas\n5.Salir\nIngrese una opcion: ");
            switch(option)
            {
            case 1:
                get_String(aux->nombre, "Ingrese el nuevo nombre: ");
                break;
            case 2:
                get_String(aux->empleo, "Ingrese el nuevo empleo: ");
                break;
            case 3:
                get_Int(&(aux->edad), "Ingrese la nueva edad: ");
                break;
            case 4:
                get_Int(&(aux->horasTrabajadas), "Ingrese la nueva cantidad de horas trabajadas: ");
                break;
            case 5:
                return 1;
                break;
            default:
                puts("Opcion invalida! Reingrese");
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

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int status = 0;
    int id;
    char respuesta;
    eEmpleado* aux;
    if(pArrayListEmployee != NULL)
    {
        get_Int(&id, "Ingrese el id del empleado que desea borrar: ");
        aux = ll_get(pArrayListEmployee, (id-1));
        if(aux != NULL)
        {
            printf("%d %10s %15s %4d %13d\n", employee_getId(aux), employee_getNombre(aux), employee_getEmpleo(aux), employee_getEdad(aux), employee_getHorasTrabajadas(aux));
            get_Char(&respuesta, "Desea eliminar el empleado mostrado anteriormente?");
            if(respuesta == 's')
            {
                ll_remove(pArrayListEmployee, (id-1));
                status = 1;
            }else
            {
                status = 2;
            }
        }else
        {
            status = 3;
        }

    }
    return status;
}

int controller_ListEmployee(LinkedList* pArrayListEmployee)/*LISTO Y USADO...*/
{
    int status = 0;
    int i;
    eEmpleado* aux;
    if(pArrayListEmployee != NULL)
    {
        controller_sortEmployee(pArrayListEmployee);
        printf("ID    NOMBRE        EMPLEO    EDAD    HORAS TRABAJADAS\n");
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            aux = ll_get(pArrayListEmployee, i);
            printf("%d %10s %15s %4d %13d\n", employee_getId(aux), employee_getNombre(aux), employee_getEmpleo(aux), employee_getEdad(aux), employee_getHorasTrabajadas(aux));
            status = 1;
        }
    }
    return status;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)/*LISTO Y USADO...*/
{
    int status = 0;
    if(pArrayListEmployee != NULL)
    {
        ll_sort(pArrayListEmployee, &employee_compareByName, 1);
        status = 1;
    }
    return status;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)/*LISTO Y USADO...*/
{
    int status = 0;
    int i;
    char respuesta;
    eEmpleado* aux;
    FILE* MAT;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        get_Char(&respuesta, "Desea guardar los resultados de la busqueda?...");
        if(respuesta == 's')
        {
            MAT = fopen(path, "w");
            for(i=0;i<ll_len(pArrayListEmployee);i++)
            {
                aux = ll_get(pArrayListEmployee,i);
                fprintf(MAT, "%d,%s,%s,%d,%d,%.3f\n", employee_getId(aux), employee_getNombre(aux), employee_getEmpleo(aux), employee_getEdad(aux), employee_getHorasTrabajadas(aux), employee_getSueldo(aux));
            }
            fclose(MAT);
            status = 1;
        }else
        {
            status = 3;
        }
    }
    return status;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int status = 0;
    int i;
    char respuesta;
    eEmpleado* aux;
    FILE* MAB;
    if(path != NULL && pArrayListEmployee != NULL)
    {
        get_Char(&respuesta, "Desea guardar los cambios realizados?...");
        if(respuesta == 's')
        {
            MAB = fopen(path, "wb");
            for(i=0;i<ll_len(pArrayListEmployee);i++)
            {
                aux = ll_get(pArrayListEmployee, i);
                fwrite(aux, sizeof(eEmpleado), 1, MAB);
            }
            fclose(MAB);
            status = 1;
        }else
        {
            status = 3;
        }
    }
    return status;
}

int controller_sueldoAllEmployee(LinkedList* pArrayListEmployee)/*LISTO Y USADO...*/
{
    int status = 0;
    if(pArrayListEmployee != NULL)
    {
        ll_map(pArrayListEmployee, &laQueMapea);
        status = 1;
    }
    return status;
}

int controller_ListEmployeeSueldos(LinkedList* pArrayListEmployee)/*LISTO Y USADO...*/
{
    int status = 0;
    int i;
    eEmpleado* aux;
    if(pArrayListEmployee != NULL)
    {
        printf("ID    NOMBRE        EMPLEO    EDAD    HORAS TRABAJADAS    SUELDO\n");
        for(i=0;i<ll_len(pArrayListEmployee);i++)
        {
            aux = ll_get(pArrayListEmployee, i);
            printf("%d %10s %15s %4d %13d %18.3f\n", employee_getId(aux), employee_getNombre(aux), employee_getEmpleo(aux), employee_getEdad(aux), employee_getHorasTrabajadas(aux), employee_getSueldo(aux));
        }
        status = 1;
    }
    return status;
}

LinkedList* controller_ListEmployeeFilter(LinkedList* pArrayListEmployee)/*ARREGLAR...*/
{
    LinkedList* listFilter;
    if(pArrayListEmployee != NULL)
    {
        listFilter = ll_filter(pArrayListEmployee, &laQuefiltra);
    }
    return listFilter;
}

