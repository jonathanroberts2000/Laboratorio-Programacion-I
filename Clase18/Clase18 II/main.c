#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int legajo;
    char nombre[60];
    float sueldo;
}eEmpleado;
//4 funciones
int main()
{
    /*FILE* miArchivo;
    int x = 4;
    miArchivo = fopen("datosbinarios", "wb");//.dat o .bit o sin extension
    fwrite(&x, sizeof(int), 1, miArchivo);
    fclose(miArchivo);*/

    FILE* miArchivo;
    int* x = (int*) malloc(sizeof(int));
    miArchivo = fopen("datosbinarios", "rb");
    fread(x, sizeof(int), 1, miArchivo);//los mismos parametros que fwrite
    fclose(miArchivo);
    printf("%d", *x);
    return 0;
}
