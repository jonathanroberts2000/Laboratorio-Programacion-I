#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "BibliotecaFuncionesGenericas.h"
int pedirEntero(char mensaje[])
{
    int numeroEntero;
    printf("%s" , mensaje);
    scanf("%d" , &numeroEntero);
    return numeroEntero;
}

float pedirFlotante(char mensaje[])
{
    float numeroFlotante;
    printf("%s" , mensaje);
    scanf("%f" , &numeroFlotante);
    return numeroFlotante;
}

char pedirCaracter(char mensaje[])
{
    char caracter;
    printf("%s" , mensaje);
    scanf("%c" , &caracter);
    return caracter;
}

void recorrerVector(int vector_1[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("%d" , vector_1[i]);
    }
}

int generarNumeroRandom()
{
    int numero;
    srand(time(NULL));
    numero = rand();
    return numero;
}

int buscarMaximo(int vector_1[], int tam)
{
    int i;
    int maximo;
    int flag = 0;
    for(i=0;i<tam;i++)
    {
        if(vector_1[i]>maximo || flag == 0)
        {
            maximo = vector_1[i];
            flag = 1;
        }
    }
    return maximo;
}

float sumaNumeros(float num1, float num2)
{
    float resultado;
    resultado = num1 + num2;
    return resultado;
}

float restaNumeros(float num1, float num2)
{
    float resultado;
    resultado = num1 - num2;
    return resultado;
}

float divisionNumeros(float num1, float num2)
{
    float resultado;
    resultado = num1 / num2;
    return resultado;
}

float multiplicacionNumeros(float num1, float num2)
{
    float resultado;
    resultado = num1 * num2;
    return resultado;
}

int factorialNumero(int num1)
{
    int resultado;
    if(num1 == 0 || num1 == 1)
    {
        resultado = 1;
    }else
    {
        resultado = num1 * factorialNumero(num1 -1);
    }
    return resultado;
}

int buscarEntero(int vector_1[], int tam, int numero)
{
    int i;
    int index = -1;
    numero = pedirEntero("Ingrese el numero que desea buscar: ");
    for(i=0;i<tam;i++)
    {
        if(vector_1[i] == index)
        {
            index = i;
        }
    }
    return index;
}

