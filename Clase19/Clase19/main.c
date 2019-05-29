#include <stdio.h>
#include <stdlib.h>
//caracter delimitador...siempre el mismo , ; - / un split para leer datos
//linkedlist, funciones listas, ll_remove();etc
#include <string.h>
#define OCUPADO 1
#define LIBRE 0

typedef struct{
    int legajo;
    char nombre[50];
    float sueldo;
    int estado;
}eEmpleado;

int main()
{
    eEmpleado* e1 = (eEmpleado*)malloc(sizeof(eEmpleado));
    eEmpleado* e2 = (eEmpleado*)malloc(sizeof(eEmpleado));
    eEmpleado* e3 = (eEmpleado*)malloc(sizeof(eEmpleado));

    e1->estado = OCUPADO;
    e1->legajo = 1;
    strcpy(e1->nombre, "TITO");
    e1->sueldo = 1000;

    e2->estado = OCUPADO;
    e2->legajo = 2;
    strcpy(e2->nombre, "PEPA");
    e2->sueldo = 2000;

    e3->estado = OCUPADO;
    e3->legajo = 3;
    strcpy(e3->nombre, "BRUNO");
    e3->sueldo = 3000;

    FILE* miArchivo;
    miArchivo = fopen("MISDATOS.csv", "w");
    fprintf(miArchivo, "%d, %d, %s, %f\n", e1->estado, e1->legajo, e1->nombre, e1->sueldo);
    fprintf(miArchivo, "%d, %d, %s, %f\n", e2->estado, e2->legajo, e2->nombre, e2->sueldo);
    fprintf(miArchivo, "%d, %d, %s, %f\n", e3->estado, e3->legajo, e3->nombre, e3->sueldo);

    fclose(miArchivo);
    miArchivo = fopen("MISDATOS.csv", "r");
    char estado[100],legajo[100], nombre[100], sueldo[100];
    int i = 0;
    eEmpleado* lista[i]; //= (eEmpleado*)malloc(sizeof(eEmpleado));
    while(!feof(miArchivo))
    {
        eEmpleado* aux = (eEmpleado*)malloc(sizeof(eEmpleado));

        fscanf(miArchivo, "%[^,],%[^,],%[^,],%[^\n]\n", estado, legajo, nombre, sueldo);

       //fscanf(miArchivo, "%[^,]")

       aux->estado = atoi(estado);
       aux->legajo = atoi(legajo);
       strcpy(aux->nombre, nombre);
       aux->sueldo = atof(sueldo);

        lista[i] = aux;
        i++;
        //printf("%s - %s - %s - %s\n", estado, legajo, nombre, sueldo);
    }
    fclose(miArchivo);
    int j;
    for(j=0;j<i;j++)
    {
        /*funciona*/printf("%d\t %d\t %s\t %f\n", lista[j]->estado, lista[j]->legajo, lista[j]->nombre, lista[j]->sueldo);
        /*funciona-mejor practica*/printf("%d\t %d\t %s\t %f\n", (*(lista+j))->estado, (*(lista+j))->legajo, (*(lista+j))->nombre, (*(lista+j))->sueldo);
    }

    return 0;
}

