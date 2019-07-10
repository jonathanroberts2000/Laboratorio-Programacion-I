#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
//#include "eEntidad.h"
#include "Controller.h"
#include "Parser.h"
#include "pInput.h"
#define PATHT "datos.csv"
#define PATHTR "resultados.csv"

int controller_loadFromText(char* path, LinkedList* pArrayList)
{
    int status = 0;
    if(path != NULL && pArrayList != NULL)
    {
        FILE* MAT;
        MAT = fopen(path, "r");
        parser_FileFromText(MAT, pArrayList);
        fclose(MAT);
        status = 1;
    }
    return status;
}

int controller_addEntidad(LinkedList* pArrayList)
{
    int status = 0;

    return status;
}

int controller_editEntidad(LinkedList* pArrayList)
{
    int status = 0;
    int id;
    int option;
    char seguir = 's';
    get_Int(&id, "Ingrese el id del empleado que desea modificar: ");
    //aux = ll_get(pArrayList, (id-1));
    if(pArrayList != NULL)
    {
        do
        {
            get_Int(&option, "1.Nombre\n2.Empleo\n3.Edad\n4.Horas trabajadas\n5.Salir\nIngrese una opcion: ");
            switch(option)
            {
            case 1:
                //get_String(aux->nombre, "Ingrese el nuevo nombre: ");
                break;
            case 2:
                //get_String(aux->empleo, "Ingrese el nuevo empleo: ");
                break;
            case 3:
                //get_Int(&(aux->edad), "Ingrese la nueva edad: ");
                break;
            case 4:
                //get_Int(&(aux->horasTrabajadas), "Ingrese la nueva cantidad de horas trabajadas: ");
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

int controller_removeEntidad(LinkedList* pArrayList)
{
    int status = 0;
    //int id;
    //char respuesta;
    if(pArrayList != NULL)
    {
        /*get_Int(&id, "Ingrese el id del empleado que desea borrar: ");
        //aux = ll_get(pArrayList, (id-1));
        if(aux != NULL)
        {
            printf("%d %10s %15s %4d %13d\n", Entidad_getId(aux), Entidad_getNombre(aux), Entidad_getEmpleo(aux), Entidad_getEdad(aux), Entidad_getHorasTrabajadas(aux));
            get_Char(&respuesta, "Desea eliminar el empleado mostrado anteriormente?");
            if(respuesta == 's')
            {
                ll_remove(pArrayList, (id-1));
                status = 1;
            }else
            {
                status = 2;
            }
        }else
        {
            status = 3;
        }*/

    }
    return status;
}

int controller_ListEntidad(LinkedList* pArrayList)
{
    int status = 0;
    //int i;
    if(pArrayList != NULL)
    {
        controller_sortEntidad(pArrayList);
        printf("ID    NOMBRE        EMPLEO    EDAD    HORAS TRABAJADAS\n");
        /*for(i=0;i<ll_len(pArrayList);i++)
        {
            aux = ll_get(pArrayList, i);
            printf("%d %10s %15s %4d %13d\n", Entidad_getId(aux), Entidad_getNombre(aux), Entidad_getEmpleo(aux), Entidad_getEdad(aux), Entidad_getHorasTrabajadas(aux));
            status = 1;
        }*/
    }
    return status;
}

int controller_sortEntidad(LinkedList* pArrayList)
{
    int status = 0;
    if(pArrayList != NULL)
    {
        //ll_sort(pArrayList, &Entidad_compareByName, 1);
        status = 1;
    }
    return status;
}

int controller_saveAsText(char* path , LinkedList* pArrayList)
{
    int status = 0;
    //int i;
    //char respuesta;
    //FILE* MAT;
    if(path != NULL && pArrayList != NULL)
    {
        /*get_Char(&respuesta, "Desea guardar los resultados de la busqueda?...");
        if(respuesta == 's')
        {
            MAT = fopen(path, "w");
            for(i=0;i<ll_len(pArrayList);i++)
            {
                aux = ll_get(pArrayList,i);
                fprintf(MAT, "%d,%s,%s,%d,%d,%.3f\n", Entidad_getId(aux), Entidad_getNombre(aux), Entidad_getEmpleo(aux), Entidad_getEdad(aux), Entidad_getHorasTrabajadas(aux), Entidad_getSueldo(aux));
            }
            fclose(MAT);
            status = 1;
        }else
        {
            status = 3;
        }*/
    }
    return status;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayList)
{
    int status = 0;
    //int i;
    //char respuesta;
    //FILE* MAB;
    if(path != NULL && pArrayList != NULL)
    {
        /*get_Char(&respuesta, "Desea guardar los cambios realizados?...");
        if(respuesta == 's')
        {
            MAB = fopen(path, "wb");
            for(i=0;i<ll_len(pArrayList);i++)
            {
                aux = ll_get(pArrayList, i);
                fwrite(aux, sizeof(eEmpleado), 1, MAB);
            }
            fclose(MAB);
            status = 1;
        }else
        {
            status = 3;
        }*/
    }
    return status;
}

int controller_ListEntidadSueldos(LinkedList* pArrayList)
{
    int status = 0;
    //int i;
    if(pArrayList != NULL)
    {
        printf("ID    NOMBRE        EMPLEO    EDAD    HORAS TRABAJADAS    SUELDO\n");
        /*for(i=0;i<ll_len(pArrayList);i++)
        {
            aux = ll_get(pArrayList, i);
            printf("%d %10s %15s %4d %13d %18.3f\n", Entidad_getId(aux), Entidad_getNombre(aux), Entidad_getEmpleo(aux), Entidad_getEdad(aux), Entidad_getHorasTrabajadas(aux), Entidad_getSueldo(aux));
        }
        status = 1;*/
    }
    return status;
}
