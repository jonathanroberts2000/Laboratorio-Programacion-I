#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "ValidationFunctions.h"
int pedirEntero(char mensaje[])
{
    int numeroEntero;
    printf("%s" , mensaje);
    scanf("%d" , &numeroEntero);
    return numeroEntero;
}
char pedirCaracter(char mensaje[])
{
    char respuesta;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &respuesta);
    return respuesta;
}
int generarNumeroRandom(void)
{
    int numero;
    srand(time(NULL));
    numero = rand();
    return numero;
}
void utilizandoStrings(Employee lista[], int tamEmployees)
{
    int i;
    for(i=0;i<tamEmployees;i++)
    {
        strlwr(lista[i].name);
        strlwr(lista[i].lastName);
    }
    pasarMayusculas(lista, tamEmployees);
}
void ordenarAlfabeticamente(Employee lista[], int tamEmployees)
{
     int i,j;

    int auxEnteroId;
    int auxEnteroSector;
    float auxFlotanteSalary;
    char auxCadenaLastName[100];
    char auxCadenaName[100];
    for(i=0;i<tamEmployees-1;i++)
    {
        for(j=i+1;j<tamEmployees;j++)
        {
            if(strcmp(lista[i].lastName,lista[j].lastName)>0)
            {
                strcpy(auxCadenaLastName, lista[i].lastName);
                strcpy(lista[i].lastName, lista[j].lastName);
                strcpy(lista[j].lastName, auxCadenaLastName);

                strcpy(auxCadenaName, lista[i].name);
                strcpy(lista[i].name, lista[j].name);
                strcpy(lista[j].name, auxCadenaName);

                auxEnteroSector = lista[i].sector;
                lista[i].sector = lista[j].sector;
                lista[j].sector = auxEnteroSector;

                auxEnteroId = lista[i].id;
                lista[i].id = lista[j].id;
                lista[j].id = auxEnteroId;

                auxFlotanteSalary = lista[i].salary;
                lista[i].salary = lista[j].salary;
                lista[j].salary = auxFlotanteSalary;
            }
        }
    }
}
void pasarMayusculas(Employee lista[], int tamEmployees)
{
    int i;
    int j;
    for(i=0;i<tamEmployees;i++)
    {
        for(j=0;j<tamEmployees;j++)
        {
            if(j==0)
            {
                lista[i].name[j] = toupper(lista[i].name[j]);
                lista[i].lastName[j] = toupper(lista[i].lastName[j]);
            }
        }
    }
}

