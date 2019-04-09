#include <stdio.h>
#include <stdlib.h>
#define T 2

void pedirCadena(char[] , char[] , int);

int main()
{
    int legajos[T];
    float sueldos[T];
    char sexos[T];
    char nombres[T/*filas*/][20/*columnas*/];//matrices
    int i;

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
