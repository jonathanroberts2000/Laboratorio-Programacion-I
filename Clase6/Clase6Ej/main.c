#include <stdio.h>
#include <stdlib.h>
#include "string.h"

void vector(char nombre[], int tam);

int main()
{
    char nombre[75];
    char apellido[75];
    char apellido_nombre[150];
    printf("Ingrese su nombre: \n");
    gets(nombre);
    printf("Ingrese su apellido: \n");
    gets(apellido);
    //vector(nombre, 75);


    strcat(apellido_nombre, apellido);
    strcat(apellido_nombre, ", ");
    strcat(apellido_nombre, nombre);
    printf("%s" , apellido_nombre);
    return 0;
}
void vector(char nombre[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {

    }
}


/*nombre[0] == strlwr(nombre[0]) || nombre[0] == strupr(nombre[0])*/
