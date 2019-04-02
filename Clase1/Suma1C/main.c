#include <stdio.h>
#include <stdlib.h>

int main()
{
    float numero1;
    float numero2;
    float suma;
    printf("Ingrese el primer numero: ");
    scanf("%f" , &numero1);
    printf("Ingrese el segundo numero: ");
    scanf("%f" , &numero2);
    suma = numero1 + numero2;
    printf("El resultado de la suma es: %f" , suma);
    system("pause");
    return 0;
}
