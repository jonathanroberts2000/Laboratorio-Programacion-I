#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "ePelicula.h"
#include "pInput.h"
#include "parser.h"
#include "Controller.h"
//#define PATHT "datosMF1.csv"
int main()
{
    int option;
    char seguir = 's';
    char archivo[50];
    LinkedList* listaPeliculas = ll_newLinkedList();
    do{
        get_Int(&option, "1. Cargar los datos de las peliculas desde el archivo datosMF1.csv (modo texto)\n2. Listar peliculas por Id\n3. Salir\nIngrese una opcion: ");
        switch(option)
        {
            case 1:
                get_String(archivo, "Ingrese el nombre del archivo: ");
                if(stricmp(archivo, "datosMF1.csv") == 0)
                {
                    pointer_error(controller_loadFromText(archivo, listaPeliculas), "\nNo se ha podido completar la operacion solicitada\n", "\nDatos cargados correctamente\n", "", "");
                }else
                {
                    puts("Error! Reingrese el nombre del archivo...");
                }
                break;
            case 2:
                pointer_error(controller_ListPeliculas(listaPeliculas), "\nNo se ha podido listar las peliculas\n", "\nEl listado ha sido mostrado correctamente\n", "", "");
                break;
            case 3:
                ll_deleteLinkedList(listaPeliculas);
                puts("\nEl listado se elimino correctamente...Saliendo");
                return 0;
                break;
            default:
                puts("Error! No ha ingresado una opcion correcta. Por favor reingrese...");
                break;
        system("pause");
        system("cls");
        fflush(stdin);
        }
    }while(seguir == 's');
    return 0;
}
