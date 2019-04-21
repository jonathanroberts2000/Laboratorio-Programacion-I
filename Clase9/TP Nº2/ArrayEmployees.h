#include <stdio.h>
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} Employee;

int pedirEntero(char[]);
char pedirCaracter(char[]);
int generarNumeroRandom(void);
int buscarId(Employee[], int, int);
void cargarEmpleado(Employee[], int);
void modificarEmpleado(Employee[], int);
void borrarEmpleado(Employee[], int);
void mostrarEmpleado(Employee);
void mostrarListaEmpleados(Employee[], int);
void ordenarListaEmpleados(Employee[], int);
void utilizandoStrings(Employee[], int, char[]);
