#include <stdio.h>
#include <stdlib.h>
#include "funcionVector.h"
#define T 5 //no ocupa memoria, es mejor

int main()
{
    int numeros[T];
    int maximo;
    int posicion;
    int valor;
    cargaVector(numeros, T);
    muestraVector(numeros, T);
    maximo = buscarMaximo(numeros, T);
    printf("El maximo es %d \n" , maximo);
    printf("Ingrese el valor de parametro!\n");
    scanf("%d" , &valor);
    posicion = buscarNumero(numeros, T, valor);
    printf("%d" , posicion);
    return 0;
}
