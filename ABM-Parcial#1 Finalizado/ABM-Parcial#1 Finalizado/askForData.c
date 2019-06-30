#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
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

int validarRangoPositivos(int num,int numMin,int numMax)
{
     while(num < numMin || num > numMax)
    {
        num = pedirEntero("No esta en el rango solicitado. Reingrese el numero: ");
    }
    return num;
}

int cargarFechaEstreno(char mensaje[], char mensajeError[], int lowLimit, int highLimit)
{
    int fecha;
    printf("%s", mensaje);
    scanf("%d", &fecha);
    while(fecha < lowLimit || fecha > highLimit)
    {
        printf("%s", mensajeError);
        scanf("%d", &fecha);
    }
    return fecha;
}

char pedirCaracterConfirmacion(char mensaje[], char mensajeError[])
{
    char caracter;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &caracter);
    caracter = tolower(caracter);
    while(caracter != 's' && caracter != 'n')
    {
        printf("%s", mensajeError);
        fflush(stdin);
        scanf("%c", &caracter);
    }
    return caracter;
}

int cargarValidarEntidad(char mensaje[], char mensajeError[], int lowLimit, int highLimit)
{
    int id;
    id = pedirEntero(mensaje);
    while(id < lowLimit || id > highLimit)
    {
        id = pedirEntero(mensajeError);
    }
    return id;
}

void pedirCadena(char mensaje[], char mensajeError[], char auxCadena[], char cadenaFinal[], int tamCadena)
{
    if(strlen(mensaje) != 0)
    {
        printf("%s\n", mensaje);
    }else
    {
        printf("%s\n", mensajeError);
    }
    fflush(stdin);
    scanf("%[^\n]", auxCadena);
    validarCadena(mensajeError, auxCadena, cadenaFinal, tamCadena);
}

void validarCadena(char mensajeError[], char auxCadena[], char cadenaFinal[], int tamCadena)
{
    while(strlen(auxCadena)>tamCadena)
    {
        pedirCadena("", mensajeError, auxCadena, cadenaFinal,tamCadena);
        if(strlen(auxCadena)<tamCadena)
        {
            strcpy(cadenaFinal, auxCadena);
            break;
        }
    }
}

