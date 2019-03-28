#include <stdio.h>
#include <stdlib.h>

int pedirOperandos(char texto[])
{
    int operandos;

    printf("%s" , texto);
    scanf("%d" , &operandos);
    return operandos;
}
int mostrarResultados(char textoMensaje[] , int resultado)
{
    int resultados;

    printf("%s" , textoMensaje);
    printf("%d \n" , resultado);
    return resultados;
}
