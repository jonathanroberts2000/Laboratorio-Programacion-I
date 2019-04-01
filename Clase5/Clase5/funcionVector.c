#include "funcionVector.h"
void cargaVector(int numerosEnteros[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d" , &numerosEnteros[i]);
    }
}
void muestraVector(int numerosEnteros[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("%d \n" , numerosEnteros[i]);
    }
}
int buscarMaximo(int numerosEnteros[], int tam)
{
    int i;
    int flag = 0;
    int numMax;
    for(i=0;i<tam;i++)
    {
        if(numerosEnteros[i] > numMax || flag == 0)
        {
        numMax = numerosEnteros[i];
        flag = 1;
        }
    }
    return numMax;
}
int buscarNumero(int numerosEnteros[], int tam, int numero)
{
    int i;
    int posicion;

    for(i=0;i<tam;i++)
    {
        if(numerosEnteros[i] == numero)
        {
            posicion = i;
        }
    }
    return posicion;
}
