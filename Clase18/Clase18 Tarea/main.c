#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int legajo;
    char nombre[30];
    float sueldo;
}eEmpleado;

eEmpleado* constructorEmpleado();
int setLegajo(eEmpleado*, int);
int setNombre(eEmpleado*, char*);
int setSueldo(eEmpleado*, float);
int getLegajo(eEmpleado*);
char* getNombre(eEmpleado*);
float getSueldo(eEmpleado*);
int writeArchiveText(FILE*, eEmpleado*);
int readArchiveText(FILE*, eEmpleado*);
int writeArchiveBinary(FILE*, eEmpleado*);
int readArchiveBinary(FILE*, eEmpleado*);

int main()
{
    eEmpleado* unEmpleado = constructorEmpleado();
    setLegajo(unEmpleado, 12);
    setNombre(unEmpleado, "PEPe");
    setSueldo(unEmpleado, 15000);
    //printf("%d---%s---%f", getLegajo(unEmpleado), getNombre(unEmpleado), getSueldo(unEmpleado));
    FILE* miArchivo_1;
    //miArchivo_1 = fopen("MisDatos.txt", "w");
    //fprintf(miArchivo_1, "%d--%s--%f", unEmpleado->legajo, unEmpleado->nombre, unEmpleado->sueldo);
    //fclose(miArchivo_1);
    writeArchiveText(miArchivo_1, unEmpleado);
    readArchiveText(miArchivo_1, unEmpleado);
    FILE* miArchivo_2;

    writeArchiveBinary(miArchivo_2, unEmpleado);
    readArchiveBinary(miArchivo_2, unEmpleado);
    //fprintf(miArchivo_1, "%d--%s--%f",unEmpleado->legajo, unEmpleado->nombre, unEmpleado->sueldo);
    //fscanf(miArchivo_1,  todo);
    //fgets(todo, 500, miArchivo_1);
    //printf("%s",todo);
    //fclose(miArchivo_1);
    //miArchivo_2 = fopen("miArchivo_2.csv", "wb");
    //fwrite(unEmpleado->nombre, sizeof(eEmpleado), 1, miArchivo_2);
    //fread(unEmpleado, sizeof(eEmpleado), 1, miArchivo_2);
    //fgets(unEmpleado->nombre, 10, miArchivo_2);
    //fclose(miArchivo_2);
    return 0;
}

eEmpleado* constructorEmpleado()
{
    eEmpleado* unEmpleado;
    unEmpleado = (eEmpleado*) malloc(sizeof(eEmpleado));
    return unEmpleado;
}

int setLegajo(eEmpleado* unEmpleado, int valor)
{
    int status = 0;
    if(unEmpleado != NULL && valor > 0)
    {
        unEmpleado->legajo = valor;
        status = 1;
    }
    return status;
}

int setNombre(eEmpleado* unEmpleado, char* valor)
{
    int status = 0;
    if(unEmpleado != NULL && valor != NULL)
    {
        strcpy(unEmpleado->nombre, valor);
        status = 1;
    }
    return status;
}

int setSueldo(eEmpleado* unEmpleado, float valor)
{
    int status = 0;
    if(unEmpleado != NULL && valor > 0)
    {
        unEmpleado->sueldo = valor;
        status = 1;
    }
    return status;
}

int getLegajo(eEmpleado* unEmpleado)
{
    int valor = 0;
    if(unEmpleado != NULL)
    {
        valor = unEmpleado->legajo;
    }
    return valor;
}

char* getNombre(eEmpleado* unEmpleado)
{
    char* valor;

    if(unEmpleado != NULL)
    {
        valor = unEmpleado->nombre;
    }
    return valor;
}

float getSueldo(eEmpleado* unEmpleado)
{
    float valor = 0;
    if(unEmpleado != NULL)
    {
        valor = unEmpleado->sueldo;
    }
    return valor;
}

int writeArchiveText(FILE* unArchivo, eEmpleado* unEmpleado)
{
    int status = 0;
    if(unArchivo != NULL && unEmpleado != NULL)
    {
        unArchivo = fopen("MisDatos.txt", "w");
        fprintf(unArchivo, "%d,%s,%f\n", getLegajo(unEmpleado), getNombre(unEmpleado), getSueldo(unEmpleado));
        fclose(unArchivo);
        status = 1;
    }
    return status;
}

int readArchiveText(FILE* unArchivo, eEmpleado* unEmpleado)
{
    int status = 0;
    char inf[100];
    if(unArchivo != NULL && unEmpleado != NULL)
    {
        unArchivo = fopen("MisDatos.txt", "r");
        while(!(feof(unArchivo)))
              {
                    fgets(inf, 100, unArchivo);
                    printf("%s", inf);
              }
    fclose(unArchivo);
    status = 1;
    }
    return status;
}

int writeArchiveBinary(FILE* unArchivo, eEmpleado* unEmpleado)
{
    int status = 0;
    if(unArchivo != NULL && unEmpleado != NULL)
    {
        unArchivo = fopen("MisDatos", "wb");
        fwrite(unEmpleado,sizeof(eEmpleado),1,unArchivo);
        fclose(unArchivo);
        status = 1;
    }
    return status;
}

int readArchiveBinary(FILE* unArchivo, eEmpleado* unEmpleado)
{
    int status = 0;
    char legajo[100], nombre[100], sueldo[100];
    if(unArchivo != NULL && unEmpleado != NULL)
    {
        unArchivo = fopen("MisDatos", "rb");
        while(!(feof(unArchivo)))
        {
            fscanf(unArchivo, "%[^,],%[^,],%[^\n]\n", legajo, nombre, sueldo);
            /*setLegajo(unEmpleado, atoi(legajo));
            setNombre(unEmpleado, nombre);
            setSueldo(unEmpleado, atof(sueldo));*/
        }
        fclose(unArchivo);
        status = 1;
    }
    return status;
}

