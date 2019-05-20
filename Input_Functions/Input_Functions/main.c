#include <stdio.h>
#include <stdlib.h>
#include "bPointers.h"
#define T 5
int main()
{
    /*int numInt;
    float numFloat;
    char carac_1;
    char cadena[61];*/
    int vec[T];
    int* pVector = vec;
    /*int estadoEntero;
    int estadoFloat;
    int estadoChar;
    int estadoString;*/
    int estadoVec_0;
    int estadoVec_1;
    /*estadoEntero = getInt(&numInt, "Ingrese un numero: ", "No se ha podido cargar el numero!", 0, 100);
    printf("Numero: %d\nEstado: %d\n", numInt, estadoEntero);
    estadoFloat = getFloat(&numFloat, "Ingrese un numero: ", "No se ha podido cargar el numero!", 0, 100);
    printf("Numero: %f\nEstado: %d\n", numFloat, estadoFloat);
    estadoChar = getChar(&carac_1, "Ingrese un caracter: ", "No se ha podido cargar el numero!", 's', 'n');
    printf("Caracter: %c\nEstado: %d\n", carac_1, estadoChar);
    estadoString = getString(cadena, "Ingrese una cadena de texto: ", "No se ha podido cargar el numero!", 61);
    printf("Cadena: %s\nEstado: %d\n", cadena, estadoString);*/
    estadoVec_0 = loadVector(pVector, "Ingrese un numero: ", "No se ha podido cargar el vector!", T);
    estadoVec_1 = showVector(pVector, "Los datos cargados son: ", "No se ha podido mostrar el vector!", T);
    printf("Estado carga: %d\nEstado muestra: %d\n", estadoVec_0, estadoVec_1);

    return 0;
}
