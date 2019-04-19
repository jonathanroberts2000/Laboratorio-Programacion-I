#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
int main()
{
    int opcion;
    char seguir = 's';
     do
    {
        opcion = pedirEntero("1.Alta\n2.Modificar\n3.Baja\n4.Informar\n5.Salir\nElija una opcion: ");
        switch(opcion)
        {
            case 1:
                printf("ALTAS\n");
                break;
            case 2:
                printf("MODIFICAR\n");
                break;
            case 3:
                printf("BAJA\n");
                break;
            case 4:
                printf("INFORMAR\n");
                break;
            case 5:
                printf("Saliendo....");
                return 0;
                break;
            default:
                printf("Error! Reingrese una opcion valida!\n");
                break;
        }
        system("pause");
        system("cls");
        fflush(stdin);
    }while(seguir == 's');
    return 0;
}
