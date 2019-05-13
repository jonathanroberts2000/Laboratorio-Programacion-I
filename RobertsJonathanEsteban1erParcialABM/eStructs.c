#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eStructs.h"
#include "askForData.h"

void inicializarLibre(ePeliculas listaPeliculas[], int tamPeliculas)
{
    int i;
    for(i=0;i<tamPeliculas;i++)
    {
        listaPeliculas[i].estado = LIBRE;
    }
}

int buscarLibre(ePeliculas listaPeliculas[], int tamPeliculas)
{
     int indice = -1;
    int i;
    for(i=0;i<tamPeliculas;i++)
    {
        if(listaPeliculas[i].estado == LIBRE)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void cargarPelicula(ePeliculas listaPeliculas[], eGenero listaGeneros[], eActores listaActores[], int tamPeliculas)
{
    int indice = buscarLibre(listaPeliculas, tamPeliculas);
    if(indice == -1)
    {
        printf("No hay espacio para ingresar mas peliculas! \n");
    }else
    {
        pedirCadena("Ingrese titulo de la pelicula: ", listaPeliculas[indice].titulo, 61);
        cargarFechaEstreno("Ingrese la fecha de estreno ", listaPeliculas[indice].estreno);
        mostrarListaGeneros(listaGeneros, 5);
        listaPeliculas[indice].idGenero = pedirEntero("Ingrese id de genero: ");
        mostrarListaActores(listaActores, 10);
        listaPeliculas[indice].idActor = pedirEntero("Ingrese Id del actor: ");
        listaPeliculas[indice].idPelicula = generarNumeroRandom();
        listaPeliculas[indice].estado = OCUPADO;
    }
}

void modificarPeliculaPorId(ePeliculas listaPeliculas[], int tamPeliculas, eActores listaActores[])
{
    int idPelicula = pedirEntero("Ingrese el id de la pelicula a buscar: ");
    int indice = buscarPeliculaPorId(listaPeliculas, tamPeliculas, idPelicula);
    int opcion;
    char resp = 's';
    if(indice == -1)
    {
        printf("Error! El id solicitado no esta ingresado en el sistema! \n");
    }else{
        do{
            opcion = pedirEntero("1.Modificar titulo\n2.Modificar fecha de estreno\n3.Modificar Actor\n4.Salir del menu modificaciones\nElija una opcion: ");
            switch(opcion)
            {
                case 1:
                    pedirCadena("Ingrese el nuevo titulo de la pelicula: ", listaPeliculas[indice].titulo, 61);
                    break;
                case 2:
                    cargarFechaEstreno("Ingrese la nueva fecha de estreno: ", listaPeliculas[indice].estreno);
                    break;
                case 3:
                    pedirCadena("Ingrese el nuevo nombre del actor: ", listaActores[indice].nombre,61);
                    pedirCadena("Ingrese la nueva nacionalidad del actor: ", listaActores[indice].paisOrigen, 61);
                    break;
                case 4:
                    printf("Saliendo...\n");
                    break;
                default:
                    printf("Error! No ha ingresado una opcion correcta! \n");
                    break;
            }
        system("pause");
        system("cls");
        fflush(stdin);
        }while(resp == 's');
    }
}

int buscarPeliculaPorId(ePeliculas listaPeliculas[], int tamPeliculas, int idPelicula)
{
    int indice = -1;
    int i;
    for(i=0;i<tamPeliculas;i++)
    {
        if(listaPeliculas[i].idPelicula == idPelicula)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void borrarPeliculas(ePeliculas listaPeliculas[], int tamPeliculas)
{
    int indice = buscarEntero(listaPeliculas,tamPeliculas);
    if(indice == -1)
    {
        printf("Error! El id ingresado no esta registrado en el sistema! \n");
    }else{
        listaPeliculas[indice].estado = LIBRE;
        strcpy(listaPeliculas[indice].titulo, "");
        listaPeliculas[indice].idActor = -1;
        listaPeliculas[indice].idGenero = -1;
        listaPeliculas[indice].idPelicula = -1;
        printf("La pelicula ha sido borrada del sistema exitosamente. \n");
    }
}

int buscarEntero(ePeliculas listaPeliculas[], int tamPeliculas)
{
    int i;
    int indice = -1;
    int numero = pedirEntero("Ingrese el numero que desea buscar: ");
    for(i=0;i<tamPeliculas;i++)
    {
        if(listaPeliculas[i].idPelicula == numero)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void hardcodearDatos(ePeliculas listaPeliculas[], eGenero listaGeneros[], eActores listaActores[])
{
    char titulo[][61] = {"Avengers EndGame","Thor","Cellular","Men in Black 4","IronMan","13 Going on 30","Lucy","Nace una estrella","¿Dime con cuantos?","Guardianes de la galaxia","A perfect murder","La isla","Que paso ayer","Home Alone 3","Deadpool","Sherlock Holmes","Men in Black 3","Avengers infinity war", "Grandes esperanzas", "SWAT", "XxX"};
    int idActor[] = {2,5,4,5,2,3,1,9,4,9,7,1,9,1,10,2,10,10,7,6,6};
    int idGenero[] = {1,1,1,1,1,4,1,4,4,1,3,3,2,2,1,1,1,1,4,1,1};
    int idPelicula[] = {1000,1001,1002,1003,1004,1005,1006,1007,1008,1009,1010,1011,1012,1013,1014,1015,1016,1017,1018,1019,1020};

    int dia[] = {20,10,2,10,5,7,9,8,4,20,6,3,5,6,7,5,2,6,8,20,11};
    int mes[] = {4,6,4,7,9,5,2,3,4,5,8,10,2,10,12,6,5,4,12,6,5,4,12,2,5};
    int anio[] = {2019,2013,2004,2019,2012,2004,2014,2018,2010,2014,1995,2005,2013,1997,2015,2011,2010,2017,1995,1998,1992};

    char actor[][61] = {"Scarlett Johansson","Robert Downey Jr","Mark Ruffalo","Chris Evans","Chris Hemsworth","Samuel Jackson","Gwyneth Paltrow","Paul Rudd","Bradley Cooper","Josh Brolin"};
    int ideActor[] = {1,2,3,4,5,6,7,8,9,10};
    char nacActor[][61] = {"Argentina","EEUU","Canada","EEUU","Argentina","EEUU","Canada","Argentina","EEUU","Canada"};

    int ideGenero[] = {1,2,3,4,5};
    char genero[][61] = {"Accion","Comedia","Drama","Romance","Terror"};

    int i,j,k;

    for(i=0;i<=20;i++)
    {
        strcpy(listaPeliculas[i].titulo, titulo[i]);
        listaPeliculas[i].idActor = idActor[i];
        listaPeliculas[i].idGenero = idGenero[i];
        listaPeliculas[i].idPelicula = idPelicula[i];
        listaPeliculas[i].estado = OCUPADO;
        listaPeliculas[i].estreno.dia = dia[i];
        listaPeliculas[i].estreno.mes = mes[i];
        listaPeliculas[i].estreno.anio = anio[i];
    }

    for(j=0;j<=10;j++)
    {
        strcpy(listaActores[j].paisOrigen, nacActor[j]);
        strcpy(listaActores[j].nombre, actor[j]);
        listaActores[j].idActor = ideActor[j];
    }

    for(k=0;k<=5;k++)
    {
        strcpy(listaGeneros[k].genero, genero[k]);
        listaGeneros[k].idGenero = ideGenero[k];
    }
}

void ordenarAnioPeliculas(ePeliculas listaPeliculas[], int tamPeliculas)
{
    int i,j;
    ePeliculas auxPeliculas;
    for(i=0;i<tamPeliculas-1;i++)
    {
        for(j=i+1;j<tamPeliculas;j++)
        {
            if(listaPeliculas[i].estado == OCUPADO && listaPeliculas[j].estado == OCUPADO)
            {
                if(listaPeliculas[i].estreno.anio > listaPeliculas[j].estreno.anio)
                {
                    auxPeliculas = listaPeliculas[i];
                    listaPeliculas[i] = listaPeliculas[j];
                    listaPeliculas[j] = auxPeliculas;
                }
            }
        }
    }
}

void ordenarNacionalidadActores(eActores listaActores[], int tamActores)
{
    int i,j;
    eActores auxActores;

    for(i=0;i<tamActores-1;i++)
    {
        for(j=i+1;j<tamActores;j++)
        {
            if(strcmp(listaActores[i].paisOrigen, listaActores[j].paisOrigen) >0)
            {
                auxActores = listaActores[i];
                listaActores[i] = listaActores[j];
                listaActores[j] = auxActores;
            }
        }
    }
}

void cargarFechaEstreno(char mensaje[], eFechaEstreno fecha)
{
    printf("%s \n", mensaje);
    fecha.dia = pedirEntero("Ingrese el dia: ");
    fecha.dia = validarRangoPositivos(fecha.dia, 1, 31);
    fecha.mes = pedirEntero("Ingrese el mes: ");
    fecha.mes = validarRangoPositivos(fecha.mes, 1, 12);
    fecha.anio = pedirEntero("Ingrese el anio: ");
    fecha.anio = validarRangoPositivos(fecha.anio, 1, 2019);
}

void mostrarGenero(eGenero unGenero)
{
    printf("%d.%s\n",unGenero.idGenero, unGenero.genero);
}

void mostrarListaGeneros(eGenero listaGeneros[], int tamGeneros)
{
    int i;
    printf("Generos: \n");
    for(i=0;i<tamGeneros;i++)
    {
        mostrarGenero(listaGeneros[i]);
    }
}

void mostrarActor(eActores unActor)
{
    printf("%d.%s, %s\n",unActor.idActor, unActor.nombre, unActor.paisOrigen);
}

void mostrarListaActores(eActores listaActores[], int tamActores)
{
    int i;
    printf("Actores: \n");
    for(i=0;i<tamActores;i++)
    {
        mostrarActor(listaActores[i]);
    }
}

void mostrarPelicula(ePeliculas unaPelicula)
{
    printf("%s, %d\n",unaPelicula.titulo, unaPelicula.estreno.anio);
}

void mostrarPeliculas(ePeliculas listaPeliculas[], int tamPeliculas)
{
    int i;
    printf("Peliculas: \n");
    for(i=0;i<tamPeliculas;i++)
    {
        if(listaPeliculas[i].estado == OCUPADO)
        {
            mostrarPelicula(listaPeliculas[i]);
        }
    }
}

