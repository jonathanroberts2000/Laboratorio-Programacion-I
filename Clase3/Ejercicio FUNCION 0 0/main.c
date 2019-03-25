#include <stdio.h>
#include <stdlib.h>
void sumarNumeros(void);
int main()
{
    sumarNumeros();
    return 0;
}
void sumarNumeros(void)
{
    int numeroUno;
    int numeroDos;
    int resultado;
    printf("Ingrese un numero: ");
    scanf("%d",&numeroUno);
    printf("Ingrese un numero: ");
    scanf("%d",&numeroDos);

    resultado=numeroUno+numeroDos;

    printf("El resultado es: %d", resultado);

}
