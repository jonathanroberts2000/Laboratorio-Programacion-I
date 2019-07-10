#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "ePelicula.h"
#include "Controller.h"
#include "parser.h"
#include "pInput.h"
#define PATHT "datosMF1.csv"

int controller_loadFromText(char* path, LinkedList* pArrayListPeliculas)
{
    int status = 0;
    if(path != NULL && pArrayListPeliculas != NULL)
    {
        FILE* MAT;
        MAT = fopen(path, "r");
        parser_EmployeeFromText(MAT, pArrayListPeliculas);
        fclose(MAT);
        status = 1;
    }
    return status;
}

int controller_ListPeliculas(LinkedList* pArrayListPeliculas)
{
    int status = 0;
    int i;
    ePelicula* aux;
    if(pArrayListPeliculas != NULL)
    {
        ll_sort(pArrayListPeliculas, &pelicula_compareById, 1);
        printf("ID                     NOMBRE                                         ANIO                     GENERO\n");
        for(i=0;i<ll_len(pArrayListPeliculas);i++)
        {
            aux = ll_get(pArrayListPeliculas, i);
            printf("%2d-%55s %15d%30s\n", pelicula_getId(aux), pelicula_getNombre(aux), pelicula_getAnio(aux), pelicula_getGenero(aux));
            status = 1;
        }
    }
    return status;
}

