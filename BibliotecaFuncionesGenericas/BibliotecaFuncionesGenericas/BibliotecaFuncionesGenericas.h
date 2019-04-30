#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    char nombre[50];
    char apellido[50];

}eEmpleados;

int pedirEntero(char mensaje[]);
float pedirFlotante(char mensaje[]);
char pedirCaracter(char mensaje[]);
void recorrerVector(int vector_1[], int tam);
int generarNumeroRandom(void);
void buscarMaximo(int vector_1[], int tam);
float sumaNumeros(float num1, float num2);
float restaNumeros(float num1, float num2);
float divisionNumeros(float num1, float num2);
float multiplicacionNumeros(float num1, float num2);
