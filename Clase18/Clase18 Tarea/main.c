#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int legajo;
    char nombre[30];
    float sueldo;
}eEmpleado;

eEmpleado* constructorEmpleado();
eEmpleado* cargaEmpleado(eEmpleado*);

int main()
{
    eEmpleado* unEmpleado;
    unEmpleado = cargaEmpleado(unEmpleado);
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

eEmpleado* constructorEmpleado()
{
    eEmpleado* unEmpleado;
    unEmpleado = (eEmpleado*) malloc(sizeof(eEmpleado));
    return unEmpleado;
}

eEmpleado* cargaEmpleado(eEmpleado* unEmpleado)
{
    unEmpleado = constructorEmpleado();
    unEmpleado->legajo = 15;
    strcpy(unEmpleado->nombre, "Jonathan");
    unEmpleado->sueldo = 15100.14;
    return unEmpleado;
}


