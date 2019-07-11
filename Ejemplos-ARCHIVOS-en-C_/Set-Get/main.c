#include <stdio.h>
#include <stdlib.h>

#include "Dato.h"


int main()
{
    eDato* dato = (eDato*) malloc(sizeof(eDato));
    //eDato* d;

    //d=&dato;

    eDato_set_a(dato,1800);

    eDato_set_b(dato,"holas");

    printf("%d--%s", eDato_get_a(dato),eDato_get_b(dato));

    return 0;
}

