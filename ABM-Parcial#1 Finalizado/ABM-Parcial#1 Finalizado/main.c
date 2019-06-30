#include <stdio.h>
#include <stdlib.h>
#include "eStruct.h"
#include "askForData.h"
#define TP 1000
#define TA 10
#define TG 5


int main()
{
    eGenero listaGeneros[TG];
    eActor listaActores[TA];
    ePelicula listaPeliculas[TP];

    inicializarLibre(listaPeliculas, TP);
    hardcodearGeneros(listaGeneros);
    hardcodearActores(listaActores);
    hardcodearPeliculas(listaPeliculas);

    int opcionMPrincipal;
    int opcionMInformes;
    char seguirMP = 's';
    char seguirMI = 's';

    do{
        opcionMPrincipal = pedirEntero("1.ALTA DE PELICULA\n2.MODIFICAR PELICULA\n3.BAJA DE PELICULA\n4.LISTAR PELICULAS Y ACTORES\n5.INFORMES\n6.SALIR\nIngrese una opcion: ");
        switch(opcionMPrincipal)
        {
            case 1:
                cargarPelicula(listaPeliculas, TP, listaActores, listaGeneros);
                break;
            case 2:
                modificarPelicula(listaPeliculas, TP);
                break;
            case 3:
                bajaPelicula(listaPeliculas, TP);
                break;
            case 4:
                listarPorAnioEstreno(listaPeliculas, TP);
                listarActoresPorPais(listaActores);
                break;
            case 5:
                puts("INFORMES");
                do{
                    opcionMInformes = pedirEntero("1.TODAS LAS PELICULAS CON GENERO Y ACTOR\n2.PELICULAS CUYA NACIONALIDAD DEL ACTOR SEA EEUU\n3.POR CADA GENERO EL TITULO DE LAS PELICULAS QUE PERTENENCEN A ESE GENERO\n4.POR CADA GENERO CANTIDAD DE PELICULAS\n5.EL/LOS GENEROS CON MENOS PELICULAS\n6.SALIR DEL MENU INFORMES\nIngrese una opcion: ");
                    switch(opcionMInformes)
                    {
                        case 1:
                            informeUno(listaPeliculas, listaGeneros, listaActores, TP);
                            break;
                        case 2:
                            informeDos(listaPeliculas, listaActores, TP);
                            break;
                        case 3:
                            informeTres(listaPeliculas, listaGeneros, TP);
                            break;
                        case 4:
                            informeCuatro(listaPeliculas, listaGeneros, TP);
                            break;
                        case 5:
                            informeCinco(listaPeliculas, listaGeneros, TP);
                            break;
                        case 6:
                            puts("Salir del menu informes");
                            seguirMI = 'n';
                            break;
                        default:
                            puts("Error! No ha ingresado una opcion correcta! Por favor reingrese...");
                            break;
                    }
                    fflush(stdin);
                }while(seguirMI == 's');
                break;
            case 6:
                puts("SALIR");
                return 0;
                break;
            default:
                puts("Error! No ha ingresado una opcion correcta! Por favor reingrese...");
                break;
        }
        system("pause");
        system("cls");
        fflush(stdin);
    }while(seguirMP == 's');

    return 0;
}
