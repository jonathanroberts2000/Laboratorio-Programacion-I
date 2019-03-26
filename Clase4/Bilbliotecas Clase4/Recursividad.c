#include "Recursividad.h"
int factorial(int numero) //parametro formal, no cambia
{
    int resultado;

    //pienso la condicion de corte
    if(numero == 0 || numero == 1)
    {
        resultado = 1;
    }else
    {
        resultado = numero * factorial(numero -1);
    }

    return resultado;
}
