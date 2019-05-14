#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*int *x = NULL;
    int v = 10;
    x = &v;
    printf("%d \n", v);
    printf("%p \n", &v);//direccion de memoria de v
    printf("%p \n", &x);//direccion de memoria de x
    printf("%p \n", x);//el valor de x
    printf("%d \n", *x);//el valor al que apunta*/

    //pedir un char y cargarlo por puntero

    /*char letra;
    char* pLetra = NULL;
    pLetra = &letra;
    printf("Ingrese caracter: ");
    fflush(stdin);
    scanf("%c", pLetra);
    //printf("%c",*pLetra);
    printf("%c \n", letra);*/

    int p;
    int* q;
    int* r;
    p = 10;
    q = &p;
    r = q;
    //los dos punteros apuntan al mismo lugar
    //cuando muestro su contenido apuntan a la misma direccion de memoria
    printf("%p \n", q);
    printf("%p \n", r);
    printf("%d \n", *q);
    printf("%d \n", *r);
    printf("%p", &p);
    return 0;
}
