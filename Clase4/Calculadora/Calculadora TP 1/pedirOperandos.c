#include <stdio.h>
#include <stdlib.h>

int pedirOperandos(char texto[])
{
    int operandos;

    printf("%s" , texto);
    scanf("%d" , &operandos);
    return operandos;
}
