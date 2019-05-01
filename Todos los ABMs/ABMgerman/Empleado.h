#include <stdio.h>

#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct
{
    int idSector;
    int cantEmp;
}sectorAUX;//probar con el ultimo punto de la tarea del txt

typedef struct
{
    int idSector;

    char descripcion[20];
    float valor;

}eSector;

typedef struct
{
    int legajo;
    char nombre[20];
    char sexo;
    int cantidadHoras;
    int idSector;
    float sueldoBruto;
    float sueldoNeto;
    int estado;
} eEmpleado;

void mostrarEmpleado(eEmpleado, eSector[], int);
void cargarEmpleado(eEmpleado[], int, eSector[], int);
void mostrarListaEmpleados(eEmpleado[], int, eSector[], int);

int buscarLibre(eEmpleado[], int);
void inicializarEmpleados(eEmpleado[], int);
void hardcodearDatosEmpleados(eEmpleado[], int, eSector[]);
void modificar(eEmpleado[], int, int);
int buscarLegajo(eEmpleado[], int, int);
void borrarEmpleado(eEmpleado[], int, int);


void mostrarEmpleadoPorSector(eEmpleado[], int, eSector);//check
void mostrarListaEmpleadosPorSector(eEmpleado[], int, eSector[], int ts);//check

void mostrarSector_(eSector);//check
void mostrarListaSectores(eSector[], int);//check

//void totalSueldosPorSector(eSector[], int, eEmpleado[], int);
void mostrarSectores(eSector[],int,eEmpleado[],int);//funcion de nico
void mostrarSector(eSector,eEmpleado[],int);//funcion de nico

void mostrarSectorMasEmpleados(eSector[],int,eEmpleado[],int);//funcion de nico
void mostrarSueldoSector(eSector,eEmpleado[],int);//funcion de nico
void mostrarSueldosSectores(eSector[], int, eEmpleado[], int);//funcion de nico

float buscarSueldoMaximo(eEmpleado[],int);//check
void mostrarEmpleadosSueldoMaximo(eEmpleado[],int);//check
int contarCarlos(eEmpleado[],int);//check






