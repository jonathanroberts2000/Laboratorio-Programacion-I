#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIBRE 0
#define OCUPADO 1
typedef struct
{
    char nombre[51];
    char apellido[51];
    char sexo;
    int legajo;
    int estado;
    int cantHoras;
    int idSector;
    float sueldoBruto;
    float sueldoNeto;
}eEmpleados;

typedef struct
{
    int idSector;
    char descripcion[20];
    float valor;
}eSectores;

int pedirEntero(char mensaje[]);
int validacionDeEnterosPositivos(int num1);
float pedirFlotante(char mensaje[]);
float validacionDeFlotantesPositivos(float num1);
char pedirCaracter(char mensaje[]);
char validacionCaracterSexo(char caracter);
void recorrerVector(int vector_1[], int tamEmpleados);
int generarNumeroRandom(void);
int buscarMaximo(int vector_1[], int tamEmpleados);
float sumaNumeros(float num1, float num2);
float restaNumeros(float num1, float num2);
float divisionNumeros(float num1, float num2);
float multiplicacionNumeros(float num1, float num2);
int buscarEntero(eEmpleados lista[], int tamEmpleados);
void pedirCadena(char mensaje[], char cadena[], int tamCadena);//a veces anda, a veces no
void validarCadena(char mensajeError[], char cadena[], int tamCadena);// a veces anda, a veces no
void cargarEmpleado(eEmpleados lista[], int tamEmpleados);
void ordenarMenorMayor(eEmpleados lista[], int tamEmpleados);
void mostrarEmpleado(eEmpleados unEmpleado);
void mostrarListaEmpleados(eEmpleados lista[], int tamEmpleados);
int buscarLibre(eEmpleados lista[], int tamEmpleados);
void inicializarEmpleados(eEmpleados lista[], int tamEmpleados);
void hardcodearDatos(eEmpleados lista[], int tamEmpleados);
void borrarEmpleado(eEmpleados lista[], int tamEmpleados);
void modificarEmpleado(eEmpleados lista[], int tamEmpleados);
int buscarEmpleadoPorLegajo(eEmpleados lista[], int tamEmpleados, int legajo);
int buscarEmpleadoEspecifico(eEmpleados lista[], int tamEmpleados);
int validarSectores(eEmpleados listaEmpleados[], eSectores listaSectores[], int tamEmpleados, int tamSectores);
