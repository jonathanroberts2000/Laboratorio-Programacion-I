#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
//#include "eEntidad.h"
#include "pInput.h"
#include "controller.h"

int main()
{
    int option;
    char seguir = 's';
    LinkedList* lista = ll_newLinkedList();
    do{
        get_Int(&option, "OPCIONES\n1.Case 1:\n2.Case 2\n3.Case 3:\n4.Case 4:\nIngrese una opcion: ");
        switch(option)
        {
            case 1:
                pointer_error(1, "\nMENSAJE ERROR NULL\n", "\nMENSAJE EXITO\n", "\nMENSAJE AUX 2\n", "\nMENSAJE AUX 3\n");
                break;
            case 2:
                pointer_error(1, "\nMENSAJE ERROR NULL\n", "\nMENSAJE EXITO\n", "\nMENSAJE AUX 2\n", "\nMENSAJE AUX 3\n");
                break;
            case 3:
                pointer_error(1, "\nMENSAJE ERROR NULL\n", "\nMENSAJE EXITO\n", "\nMENSAJE AUX 2\n", "\nMENSAJE AUX 3\n");
                break;
            case 4:
                ll_deleteLinkedList(lista);
                puts("\nEl listado ha sido eliminado correctamente...Saliendo");
                return 0;
                break;
            default:
                puts("\nError! No ha ingresado una opcion correcta. Por favor reingrese....");
                break;
        system("pause");
        system("cls");
        fflush(stdin);
        }
    }while(seguir == 's');
    return 0;
}
