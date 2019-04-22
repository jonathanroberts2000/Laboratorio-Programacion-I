#include <stdio.h>
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldoBruto;
    float sueldoNeto;
    int estado;
} eEmpleado;

typedef struct
{
    int idSector;
    char descSector[50];
    int estado;
} eSectores;

void mostrarEmpleado(eEmpleado);
void cargarEmpleado(eEmpleado[], int);
void mostrarListaEmpleados(eEmpleado[], int);

int buscarLibre(eEmpleado[], int);
void inicializarEmpleados(eEmpleado[], int);
void hardcodearDatosEmpleados(eEmpleado[], int);

int buscarLegajo(eEmpleado[], int, int);
void modificarDatos(eEmpleado[], int);
void borrarDatos(eEmpleado[], int, int);
int pedirOpcion(char[]);

void hardcodearDatosSectores(eSectores[], int);
void mostrarListaSectores(eSectores[], int);
void mostrarSectorEmpleado(eSectores);
float buscarMaximo(eEmpleado[], int);
void buscarMaximoEmpleados(eEmpleado[], int);
int buscarEmpleado(eEmpleado[], int);
