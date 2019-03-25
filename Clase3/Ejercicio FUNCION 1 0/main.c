#include <stdio.h>
#include <stdlib.h>
void sumarNumeros(int, int);
int main()
{
    int numeroUno;
    int numeroDos;
    int resultado;
    printf("Ingrese un numero: ");
    scanf("%d",&numeroUno);
    printf("Ingrese un numero: ");
    scanf("%d",&numeroDos);

    resultado = sumarNumeros(numeroUno , numeroDos);

    printf("El resultado es: %d", resultado);
    return 0;
}
void sumarNumeros(int unNumero, int otroNumero)
{
    int resultado;
    resultado=unNumero+otroNumero;
}
