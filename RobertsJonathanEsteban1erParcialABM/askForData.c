#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include "askForData.h"

int pedirEntero(char mensaje[])
{
    int numeroEntero;
    printf("%s" , mensaje);
    scanf("%d" , &numeroEntero);
    numeroEntero = validacionDeEnterosPositivos(numeroEntero);
    return numeroEntero;
}

int validacionDeEnterosPositivos(int num1)
{
    int auxNum = num1;
    while(auxNum < 0)
    {
        auxNum = pedirEntero("Error! Reingrese un numero positivo: ");
    }
    return auxNum;
}

int generarNumeroRandom(void)
{
    int numero;
    srand(time(NULL));
    numero = rand();
    while(numero <1000)
    {
        numero = generarNumeroRandom();
    }
    return numero;
}

void pedirCadena(char mensaje[], char cadena[], int tamCadena)
{
    printf("%s" , mensaje);
    fflush(stdin);
    scanf("%[^\n]" , cadena);
    validarCadena("cadena: " , cadena , tamCadena);
}

void validarCadena(char mensajeError[], char cadena[], int tamCadena)
{
     char auxCadena[100];
    strcpy(auxCadena, cadena);
    while(strlen(auxCadena)>tamCadena)
    {
        printf("Reingrese %s" , mensajeError);
        fflush(stdin);
        scanf("%[^\n]" , auxCadena);
        pedirCadena("Reingrese nombre: ", auxCadena, 21);
    }
    strcpy(cadena, auxCadena);
}

int validarRangoPositivos(int num,int numMin,int numMax)
{
     while(num < numMin || num > numMax)
    {
        num = pedirEntero("No esta en el rango solicitado. Reingrese el numero: ");
    }
    return num;
}

