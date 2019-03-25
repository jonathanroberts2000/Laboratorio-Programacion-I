#include <stdio.h>
#include <stdlib.h>

int sumaNumeros(int,int);

int main()
{
    int numeroUno;
    int numeroDos;
    int resultado;
    printf("Ingrese un numero:\n");
    scanf("%d" , &numeroUno);
    printf("Ingrese otro numero:\n");
    scanf("%d" , &numeroDos);

    resultado = sumaNumeros(numeroUno, numeroDos);
    printf("El resultado es: %d" , resultado);
    system("pause");
    return 0;
}

int sumaNumeros(int unNumero, int otroNumero)
{
    int resultado;

    resultado = unNumero + otroNumero;
    return resultado;
}
