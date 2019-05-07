#include <stdio.h>
#include <stdlib.h>
#define T 5


int main()
{
    int* pNumeros;
    int* pAux;
    /*pNumero = (int*) malloc(sizeof(int));
    *pNumero = 99;
    printf("Heap-> pNumero: %p\n", pNumero);//direccion de memoria del heap
    printf("Stack-> &pNumero: %d\n", &pNumero);//direccion de memoria de pNumero en el stack/pila


    //pNumero = (int*)calloc(sizeof(int), 1);//por lo general igual se usa malloc

    if(pNumero != NULL)
    {
        pNumero = 54;
        printf("Valor-> *pNumero: %d\n", *pNumero);//el contenido que esta en el heap
        free(pNumero);
        printf("Luego de hacer un free: \n");
        printf("Heap-> pNumero: %p\n", pNumero);
        printf("Stack-> &pNumero: %d\n", &pNumero);
        printf("Valor-> *pNumero: %d\n", *pNumero);
    }*/
    int i,j;
    pNumeros = (int*) malloc(sizeof(int) * T);

    if(pNumeros != NULL)
    {
        for(i=0;i<T;i++)
        {
            printf("Ingrese un numero: ");
            scanf("%d", pNumeros+i);
            //*(pNumeros+i) = i+1; hardcodeo
        }
        for(j=0;j<T;j++)
        {
            printf("%d\n", *(pNumeros+j));
        }
    }


    pAux = (int*) realloc(pNumeros, sizeof(int) * T+5);
    pAux = NULL;

    if(pAux != NULL)
    {
        for(i=T;i<T+5;i++)
        {
            printf("Ingrese mas numeros: ");
            scanf("%d", pNumeros+i);
        }
        for(j=0;j<T+5;j++)
        {
            printf("%d\n", *(pNumeros+j));
        }
    }else
    {
        printf("No hay mas espacio");
    }


    return 0;
}

