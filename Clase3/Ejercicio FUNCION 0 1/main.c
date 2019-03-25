#include <stdio.h>
#include <stdlib.h>
int sumarNumeros(void);
int main()
{ int resultado;

    resultado=sumarNumeros();

    printf("El resultado es: %d", resultado);
    return 0;
}
int sumarNumeros(void)
{
   int numeroUno;
    int numeroDos;
    int resultado;
    printf("Ingrese un numero: ");
    scanf("%d",&numeroUno);
    printf("Ingrese un numero: ");
    scanf("%d",&numeroDos);

    resultado=numeroDos+numeroUno;

    return resultado;

}
