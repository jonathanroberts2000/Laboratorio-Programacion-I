#include <stdio.h>
#define OCUPADO 1
#define LIBRE 0

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

void inicializarEmpleados(Employee[], int);
int buscarId(Employee[], int, int);
int buscarLibre(Employee[], int);
void cargarEmpleado(Employee[], int);
void modificarEmpleado(Employee[], int);
void borrarEmpleado(Employee[], int);
void mostrarEmpleado(Employee);
void mostrarListaEmpleados(Employee[], int);
void ordenarListaEmpleados(Employee[], int);
void utilizandoStrings(Employee[], int);
void ordenarAlfabeticamente(Employee[], int);
void pasarMayusculas(Employee[], int);
void mostrarListaSectores(Employee[], int);


//informes
float totalSalarios(Employee[], int);
float promedioSalarios(Employee[], int, float);


//funciones pedir datos
int pedirEntero(char[]);
char pedirCaracter(char[]);
int generarNumeroRandom(void);


//revisar funcion para que no se repita el printf
void mostrarSectorEmpleados(Employee);
