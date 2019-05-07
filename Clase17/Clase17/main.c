#include <stdio.h>
#include <stdlib.h>



int main()
{
    int* pNumeros;
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
    pNumeros = (int*) malloc(sizeof(int) * 5);

    if(pNumeros != NULL)
    {
        for(i=0;i<5;i++)
        {
            printf("Ingrese un numero: ");
            scanf("%d", pNumeros+i);
            //*(pNumeros+i) = i+1; hardcodeo
        }
        for(j=0;j<5;j++)
        {
            printf("%d\n", *(pNumeros+j));
        }
    }

    return 0;
}
