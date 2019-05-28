#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int legajo;
    char nombre[30];
    float sueldo;
}eEmpleado;


int main()
{
    eEmpleado* unEmpleado = (eEmpleado*) malloc(sizeof(eEmpleado));
    unEmpleado->legajo = 15;
    strcpy(unEmpleado->nombre, "Jonathan");
    unEmpleado->sueldo = 15.00;
    FILE* miArchivo_1;
    FILE* miArchivo_2;
    miArchivo_1 = fopen("miArchivo_1.txt", "w");
    fprintf(miArchivo_1, "%d--%s--%f",unEmpleado->legajo, unEmpleado->nombre, unEmpleado->sueldo);
    fclose(miArchivo_1);
    miArchivo_2 = fopen("miArchivo_2", "rb");
    fwrite(unEmpleado->nombre, sizeof(eEmpleado), 1, miArchivo_2);
    fread(unEmpleado, sizeof(eEmpleado), 1, miArchivo_2);
    fgets(unEmpleado->nombre, 10, miArchivo_2);
    fclose(miArchivo_2);
    return 0;
}


