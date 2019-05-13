#include <stdio.h>
#include <stdlib.h>
#include "eStructs.h"
#include "askForData.h"
#define TP 1000
#define TA 10
#define TG 5
int main()
{
    ePeliculas listaPeliculas[TP];
    eGenero listaGeneros[TG];
    eActores listaActores[TA];
    inicializarLibre(listaPeliculas, TP);
    hardcodearDatos(listaPeliculas, listaGeneros, listaActores);
    int opcion;
    char respuesta = 's';
     do{
        opcion = pedirEntero("1.ALTAS PELICULAS\n2.MODIFICAR DATOS DE UNA PELICULA\n3.BAJA DE PELICULA\n4.LISTAR\n5.SALIR\nIngrese una opcion: ");
        switch(opcion)
        {
            case 1:
                puts("ALTAS PELICULAS");
                cargarPelicula(listaPeliculas, listaGeneros, listaActores, TP);
                break;
            case 2:
                puts("MODIFICAR DATOS DE UNA PELICULA");
                modificarPeliculaPorId(listaPeliculas, TP, listaActores);
                break;
            case 3:
                puts("BAJA DE PELICULA");
                borrarPeliculas(listaPeliculas, TP);
                break;
            case 4:
                puts("LISTAR");
                ordenarAnioPeliculas(listaPeliculas, TP);
                mostrarPeliculas(listaPeliculas, TP);
                ordenarNacionalidadActores(listaActores, TA);
                mostrarListaActores(listaActores, TA);
                break;
            case 5:
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

