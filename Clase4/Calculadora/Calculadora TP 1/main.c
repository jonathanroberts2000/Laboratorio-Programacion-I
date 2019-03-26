#include <stdio.h>
#include <stdlib.h>
#include "pedirOperandos.h"
#include "menuOpciones.h"
int main()
{
    int operando1;
    int operando2;
    operando1 = pedirOperandos("1. Ingresar 1er operando: \n");
    operando2 = pedirOperandos("2. Ingresar 2do operando: \n");

    printf("operando1: %d \n" , operando1);
    printf("operando2: %d \n" , operando2);
    return 0;
}
