#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *x = NULL;
    int v = 10;
    x = &v;
    printf("%d \n", v);
    printf("%p \n", &v);//direccion de memoria de v
    printf("%p \n", &x);//direccion de memoria de x
    printf("%p \n", x);//el valor de x
    printf("%d \n", *x);//el valor al que apunta
    return 0;
}
