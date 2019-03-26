#include "Ingresos.h"
#include <stdio.h>
#include <stdlib.h>
int pedirEntero(char texto[])
{
    int unEntero;

    printf("%s" , texto);
    scanf("%d" , &unEntero);

    return unEntero;
}
