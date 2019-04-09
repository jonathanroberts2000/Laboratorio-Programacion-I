#include <stdio.h>
#include <stdlib.h>
#define T 3

void pedirCadena(char[] , char[] , int);

int main()
{
    int legajos[T];
    float sueldos[T];
    float sueldoNeto[T];
    float sueldoBruto[T];
    char sexos[T];
    char nombres[T/*filas*/][20/*columnas*/];//matrices
    int i,j;
    int auxEnteros;
    float auxFlotantes;
    char auxCaracter;
    char auxCadena[100];
    for(i=0; i<T; i++)
    {
        printf("Ingrese legajo: ");
        scanf("%d" , &legajos[i]);
        printf("Ingrese sueldo: ");
        scanf("%f" , &sueldos[i]);
        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c" , &sexos[i]);
        pedirCadena("Nombre: " , nombres[i] , 20);

        sueldoNeto[i] = sueldoBruto[i]*0.85;
    }

    for(i=0; i<T-1;i++)
    {
        for(j=i+1;j<T;j++)
        {
            if(legajos[i]>legajos[j])
            {
                auxEnteros = legajos[i];
                legajos[i] = legajos[j];
                legajos[j] = auxEnteros;

                auxFlotantes = sueldos[i];
                sueldos[i] = sueldos[j];
                sueldos[j] = auxFlotantes;

                auxCaracter = sexos[i];
                sexos[i] = sexos[j];
                sexos[j] = auxCaracter;

                //auxCadena = nombres[]
            }
        }
    }

    for(i=0;i<T;i++)
    {
        printf("%d--%s--%f--%c\n" , legajos[i] , nombres[i] , sueldos[i] , sexos[i]);
    }
    return 0;
}
void pedirCadena(char mensaje[] , char cadena[] , int tam)
{
    printf("%s" , mensaje);
    fflush(stdin);
    scanf("%[^\n]" , cadena);
}
