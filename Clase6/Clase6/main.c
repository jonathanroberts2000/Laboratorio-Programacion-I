#include <stdio.h>
#include <stdlib.h>
#include "string.h"
int main()
{
    //int ler;
    char palabra[10] = "philipa";
    char palabra2[10] = "lampara";
    //funcion para pasar todo a mayuscula
    //strupr(palabra);
    //printf("%s" , palabra);
    //para concatenar usamos...
    strcat(palabra, palabra2);
    printf("%s" , palabra2);
    //int com;
    /*printf("Ingrese nombre y apellido: ");
    //scanf("%[^\n]" , palabra); //funciona en linux y windows
    //fgets(palabra, 50 , stdin);
    gets(palabra); //acepta los espacios pero solo funciona para windows
    ler = strlen(palabra);*/

    //strcpy(palabra, "Hola");//puede ir una variableo texto literal
    //strncpy(palabra, "Holaaaa", 4);//pastea la cadena de forma segura sin romper el programa por desborde
    //si quiero comparar string uso...
    //com = stricmp(palabra, "philipa");//devuelve 0 cuando las dos son iguales
    //printf("%d" , com);
    //printf("La palabra es: %s" , palabra);
    return 0;
}
