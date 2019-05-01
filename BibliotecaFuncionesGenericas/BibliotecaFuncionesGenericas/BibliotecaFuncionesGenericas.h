#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIBRE 0
#define OCUPADO 1
typedef struct
{
    char nombre[51];
    char apellido[51];
    int estado;
    int idSector;
    float sueldoBruto;
    float sueldoNeto;
}eEmpleados;

int pedirEntero(char mensaje[]);
float pedirFlotante(char mensaje[]);
char pedirCaracter(char mensaje[]);
void recorrerVector(int vector_1[], int tam);
int generarNumeroRandom(void);
int buscarMaximo(int vector_1[], int tam);
float sumaNumeros(float num1, float num2);
float restaNumeros(float num1, float num2);
float divisionNumeros(float num1, float num2);
float multiplicacionNumeros(float num1, float num2);
int buscarEntero(int vector_1[], int tam, int numero);
void pedirCadena(char mensaje[] , char cadena[] , int tamCadena);//a veces anda, a veces no
void validarCadena(char mensajeError[] , char cadena [] , int tamCadena);// a veces anda, a veces no
void cargarEstructura(eEmpleados lista[], int tam);
void ordenarMenorMayor(eEmpleados lista[], int tam);
void mostrarEmpleado(eEmpleados unEmpleado);
void mostrarListaEmpleados(eEmpleados lista[], int tam);
