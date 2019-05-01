#include <stdio.h>
#include <stdlib.h>
#include "BibliotecaFuncionesGenericas.h"
#define T 3
int main()
{
    int opcion;
    eEmpleados lista[T];
    char respuesta = 's';
    do{
        opcion = pedirEntero("1.ALTAS\n2.BAJAS\n3.MODIFICACIONES\n4.MOSTRAR\n5.INFORMAR\n6.SALIR\nIngrese una opcion: ");
        switch(opcion)
        {
            case 1:
                puts("ALTAS");
                cargarEstructura(lista,T);
                break;
            case 2:
                puts("BAJAS");
                break;
            case 3:
                puts("MODIFICACIONES");
                break;
            case 4:
                puts("MOSTRAR");
                break;
            case 5:
                puts("INFORMAR");
                break;
            case 6:
                puts("SALIR");
                return 0;
                break;
            default:
                puts("Error! No ha ingresado una opcion correcta!");
                break;
        }
        system("pause");
        system("cls");
        fflush(stdin);
    }while(respuesta == 's');
    return 0;
}
