#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
//#include "eEntidad.h"

int parser_FileFromText(FILE* pFile , LinkedList* pArrayList)/*LISTO Y USADO...*/
{
    int status = 0;
    //char id[100], nombre[100], horasTrabajadas[100], edad[100], empleo[100];
    if(pFile != NULL && pArrayList != NULL)
    {
        while(!feof(pFile))
        {
            //eEntidad* aux = entidad_new();
            //fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, empleo, edad, horasTrabajadas);
            //aux = Entidad_newParametros(id, nombre, empleo, edad, horasTrabajadas);
            //ll_add(pArrayList, aux);
        }
        status = 1;
    }
    return status;
}

