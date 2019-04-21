#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pedirEntero(char mensaje[]);
float pedirFlotante(char mensaje[]);
char pedirCaracter(char mensaje[]);
void recorrerVector(int vector_1[], int tam);
int generarNumeroRandom(void);

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

