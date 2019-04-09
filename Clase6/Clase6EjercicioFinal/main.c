#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> //isspace()0 si no es espacio

void pedirCadena(char[] , char[] , int);
void validarCadena(char[] , char[] , int);

int main()
{
    char nombre[20];
    char apellido[20];
    char apellidoNombre[41] = "";
    int i = 0;
    //char auxCadena0[100];
    //char auxCadena1[100];

    pedirCadena("nombre: " , nombre , 20);
    //strcpy(auxCadena0, apellidoNombre);
    pedirCadena("apellido: " , apellido, 20);
    //strcpy(auxCadena1, apellidoNombre);

    strcat(apellidoNombre , apellido);
    strcat(apellidoNombre , ", ");
    strcat(apellidoNombre , nombre);

    strlwr(apellidoNombre);

    apellidoNombre[0] = toupper(apellidoNombre[0]);

    while(apellidoNombre[i] != '\0')//tmb con for()
    {
        if(apellidoNombre[i] == ' ')
        {
            apellidoNombre[i + 1] = toupper(apellidoNombre[i + 1]);
        }
        i++;
    }
    //strcpy(auxCadena, apellidoNombre);
    /*no va*/
    puts(apellidoNombre);
    return 0;
}
void pedirCadena(char mensaje[] , char cadena[] , int tam)
{
    printf("%s" , mensaje);
    fflush(stdin);
    scanf("%[^\n]" , cadena);
    validarCadena(mensaje , cadena , tam);
}
void validarCadena(char mensajeError[] , char cadena [] , int tam)
{
    while(strlen(cadena)>tam)
    {
        printf("Reingrese %s" , mensajeError);
        fflush(stdin);
        scanf("%[^\n]" , cadena);
    }
}
//ERROR CUANDO SOBRECARGO NOMBRE Ó APELLIDO;
