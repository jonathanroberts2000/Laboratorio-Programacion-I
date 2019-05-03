#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIBRE 0
#define OCUPADO 1
//#include "ValidationFunctions.h"

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

int buscarId(Employee[], int, int);
void cargarEmpleado(Employee[], int);
void modificarEmpleado(Employee[], int);
void borrarEmpleado(Employee[], int);
void mostrarEmpleado(Employee);
void mostrarListaEmpleados(Employee[], int);
void ordenarListaEmpleados(Employee[], int);
