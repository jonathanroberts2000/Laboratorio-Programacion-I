#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "eStruct.h"
#include "askForData.h"

void inicializarLibre(ePelicula listaPeliculas[], int tamPeliculas)
{
    int i;
    for(i=0;i<tamPeliculas;i++)
    {
        listaPeliculas[i].estado = LIBRE;
    }
}

int buscarLibre(ePelicula listaPeliculas[], int tamPeliculas)
{
    int i;
    int indice = -1;
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

void cargarPelicula(ePelicula listaPeliculas[], int tamPeliculas, eActor listaActores[], eGenero listaGeneros[])
{
    char pelicula[1000];
    int index = buscarLibre(listaPeliculas,tamPeliculas);
    if(index == -1)
    {
        puts("Error! No hay mas espacio para cargar peliculas!");
    }else
    {
        listaPeliculas[index].idPelicula = generarIdPelicula(listaPeliculas, tamPeliculas);
        puts("Id generado correctamente");
        pedirCadena("Ingrese el titulo de la pelicula: ", "Reingrese el titulo de la pelicula: ", pelicula, listaPeliculas[index].titulo, 61);
        listaPeliculas[index].fechaEstreno.dia = cargarFechaEstreno("Ingrese dia de estreno: ", "Error! Reingrese un dia valido: ", 1, 31);
        listaPeliculas[index].fechaEstreno.mes = cargarFechaEstreno("Ingrese mes de estreno: ", "Error! Reingrese un mes valido: ", 1, 12);
        listaPeliculas[index].fechaEstreno.anio = cargarFechaEstreno("Ingrese año de estreno: ", "Error! Reingrese un año valido: ", 1900, 2019);
        listarActores(listaActores);
        listaPeliculas[index].idActor = cargarValidarEntidad("Ingrese el id de un actor: ", "Error! Reingrese un id valido: ", 1, 10);
        listarGeneros(listaGeneros);
        listaPeliculas[index].idGenero = cargarValidarEntidad("Ingrese el id de un genero: ", "Error! Reingrese un id valido: ", 1, 5);
        listaPeliculas[index].estado = OCUPADO;
    }
}

void hardcodearGeneros(eGenero listaGeneros[])
{
    int i;
    int id[] = {1,2,3,4,5};
    char generos[][61] = {"Accion", "Comedia", "Drama", "Romance", "Terror"};
    for(i=0;i<5;i++)
    {
        listaGeneros[i].idGenero = id[i];
        strcpy(listaGeneros[i].genero, generos[i]);
    }
}

void hardcodearActores(eActor listaActores[])
{
    int i;
    int id[] = {1,2,3,4,5,6,7,8,9,10};
    char nombres[][61] = {"Scarlett Johansson", "Robert Downey Jr", "Mark Ruffalo", "Chris Evans", "Chris Hemsworth", "Samuel Jackson", "Gwyneth Paltrow", "Paul Rudd", "Bradley Cooper", "Josh Brolin"};
    char nacionalidades[][61] = {"Argentina", "EEUU", "Canada", "EEUU", "Argentina", "EEUU", "Canada", "Argentina", "EEUU", "Canada"};
    for(i=0;i<10;i++)
    {
        listaActores[i].idActor = id[i];
        strcpy(listaActores[i].nombre, nombres[i]);
        strcpy(listaActores[i].paisOrigen, nacionalidades[i]);
    }
}

void hardcodearPeliculas(ePelicula listaPeliculas[])
{
    int i;
    char titulos[][61] = {"Avengers EndGame", "Thor", "Cellular", "Men in Black 4", "IronMan", "13 Going on 30", "Lucy", "Nace una estrella", "¿Dime con cuantos?", "Guardianes de la galaxia", "A perfect murder", "La isla", "Que paso ayer", "Home Alone 3", "Deadpool", "Sherlock Holmes", "Men in Black 3", "Avengers infinity war", "Grnades esperanzas", "SWAT", "XxX"};
    int dias[] = {20,10,2,10,5,7,9,8,4,20,6,3,5,6,7,5,2,6,8,20,11};
    int meses[] = {4,6,5,7,9,5,2,3,4,5,8,10,2,10,12,6,5,4,12,2,5};
    int anios[] ={2019,2013,2004,2019,2012,2004,2014,2018,2010,2014,1995,2005,2013,1997,2015,2011,2010,2017,1995,1998,1992};
    int actores[] = {2,5,4,5,2,3,1,9,4,9,7,1,9,1,10,2,10,10,7,6,6};
    int generos[] = {1,1,1,1,1,4,1,4,4,1,3,3,2,2,1,1,1,1,4,1,1};
    for(i=0;i<21;i++)
    {
        listaPeliculas[i].idPelicula = i+1;
        strcpy(listaPeliculas[i].titulo, titulos[i]);
        listaPeliculas[i].fechaEstreno.dia = dias[i];
        listaPeliculas[i].fechaEstreno.mes = meses[i];
        listaPeliculas[i].fechaEstreno.anio = anios[i];
        listaPeliculas[i].idActor = actores[i];
        listaPeliculas[i].idGenero = generos[i];
        listaPeliculas[i].estado = OCUPADO;
    }
}

int generarIdPelicula(ePelicula listaPeliculas[], int tamPeliculas)
{
    int id;
    int i;
    for(i=0;i<tamPeliculas && listaPeliculas[i].estado == OCUPADO;i++)
    {
        id = listaPeliculas[i].idPelicula;
    }
    id++;
    return id;
}

void mostrarPelicula(ePelicula unaPelicula)
{
    printf("%d.%s---%d/%d/%d\n", unaPelicula.idPelicula, unaPelicula.titulo, unaPelicula.fechaEstreno.dia, unaPelicula.fechaEstreno.mes, unaPelicula.fechaEstreno.anio);
}

void listarPeliculas(ePelicula listaPeliculas[], int tamPeliculas)
{
    int i;
    puts("ID PELICULAS--NOMBRE PELICULAS--FECHA DE ESTRENO--ID GENERO--ID ACTOR");
    for(i=0;i<tamPeliculas;i++)
    {
        if(listaPeliculas[i].estado == OCUPADO)
        {
            mostrarPelicula(listaPeliculas[i]);
        }
    }
}

int buscarPorId(ePelicula listaPeliculas[], int tamPeliculas, int index)
{
    int i;
    int indice = -1;
    for(i=0;i<tamPeliculas;i++)
    {
        if(listaPeliculas[i].estado == OCUPADO)
        {
            if(listaPeliculas[i].idPelicula == index)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

void modificarPelicula(ePelicula listaPeliculas[], int tamPeliculas)
{
    char pelicula[1000];
    int idPelicula = pedirEntero("Ingrese el id de la pelicula que deseea modificar: ");
    int index = buscarPorId(listaPeliculas, tamPeliculas, idPelicula);
    int opcion;
    char seguir = 's';
    if(index != -1)
    {
        mostrarPelicula(listaPeliculas[index]);
        do{
            opcion = pedirEntero("1.MODIFICAR TITULO\n2.MODIFICAR ACTOR\n3.MODIFICAR FECHA DE ESTRENO\n4.SALIR DEL MENU DE MODIFICACIONES\nIngrese una opcion: ");
            switch(opcion)
            {
            case 1:
                puts("MODIFICAR TITULO:");
                pedirCadena("Ingrese el nuevo titulo de la pelicula: ", "Error! Reingrese el nuevo titulo de la pelicula: ", pelicula, listaPeliculas[index].titulo, 61);
                break;
            case 2:
                puts("MODIFICAR ACTOR:");
                listaPeliculas[index].idActor = cargarValidarEntidad("Ingrese el nuevo id de actor: ", "Error! Reingrese un id valido: ", 1, 10);
                break;
            case 3:
                puts("MODIFICAR FECHA DE ESTRENO:");
                listaPeliculas[index].fechaEstreno.dia = cargarFechaEstreno("Ingrese nuevo dia de estreno: ", "Error! Reingrese un dia valido: ", 1, 31);
                listaPeliculas[index].fechaEstreno.mes = cargarFechaEstreno("Ingrese nuevo mes de estreno: ", "Error! Reingrese un mes valido: ", 1, 12);
                listaPeliculas[index].fechaEstreno.anio = cargarFechaEstreno("Ingrese nuevo año de estreno: ", "Error! Reingrese un año valido: ", 1900, 2019);
                break;
            case 4:
                puts("SALIR");
                seguir = 'n';
                break;
            default:
                puts("Error! No ha ingresado una opcion correcta! Por favor reingrese...");
                break;
            }
            system("cls");
            fflush(stdin);
        }while(seguir == 's');
    }
}

void bajaPelicula(ePelicula listaPeliculas[], int tamPeliculas)
{
    int i;
    int idPelicula = pedirEntero("Ingrese el id de la pelicula que desea dar de baja: ");
    int index = buscarPorId(listaPeliculas, tamPeliculas, idPelicula);
    char respuesta;
    if(index != -1)
    {
        for(i=0;i<tamPeliculas;i++)
        {
            if(listaPeliculas[i].estado == OCUPADO)
            {
                if(listaPeliculas[i].idPelicula == idPelicula)
                {
                    mostrarPelicula(listaPeliculas[index]);
                    respuesta = pedirCaracterConfirmacion("Desea dar de baja a la pelicula?...s/n: ", "Error! Reingrese s/n: ");
                    if(respuesta == 's')
                    {
                        listaPeliculas[i].estado = LIBRE;
                        puts("Se ha dado de baja correctamente a la pelicula solicitada");
                        break;
                    }else
                    {
                        puts("Operacion de baja cancelada correctamente");
                        break;
                    }
                }
            }
        }

    }else
    {
        puts("El id ingresado no esta registrado en el sistema");
    }
}

void listarPorAnioEstreno(ePelicula listaPeliculas[], int tamPeliculas)
{
    int i,j;
    ePelicula auxPelicula;
    for(i=0;i<tamPeliculas-1;i++)
    {
        for(j=i+1;j<tamPeliculas;j++)
        {
            if(listaPeliculas[i].fechaEstreno.anio < listaPeliculas[j].fechaEstreno.anio)
            {
                auxPelicula = listaPeliculas[i];
                listaPeliculas[i] = listaPeliculas[j];
                listaPeliculas[j] = auxPelicula;
            }
        }
    }
    listarPeliculas(listaPeliculas, tamPeliculas);
}

void listarActoresPorPais(eActor listaActores[])
{
    int i,j;
    eActor auxActor;
    for(i=0;i<10-1;i++)
    {
        for(j=i+1;j<10;j++)
        {
            if(stricmp(listaActores[i].paisOrigen, listaActores[j].paisOrigen) == 1)
            {
                auxActor = listaActores[i];
                listaActores[i] = listaActores[j];
                listaActores[j] = auxActor;
            }
        }
    }
    listarActores(listaActores);
}

void listarActores(eActor listaActores[])
{
    int i;
    puts("\nID ACTORES--NOMBRE DE ACTORES--NACIONALIDAD DE ACTORES:");
    for(i=0;i<10;i++)
    {
        printf("%d.%s---%s\n", listaActores[i].idActor, listaActores[i].nombre, listaActores[i].paisOrigen);
    }
}

void listarGeneros(eGenero listaGeneros[])
{
    int i;
    puts("GENEROS:");
    for(i=0;i<5;i++)
    {
        printf("%d.%s\n", listaGeneros[i].idGenero, listaGeneros[i].genero);
    }
}

void informeUno(ePelicula listaPeliculas[], eGenero listaGeneros[], eActor listaActores[], int tamPeliculas)
{
    int i,j,k;
    char auxGenero[61];
    char auxActor[61];
    for(i=0;i<tamPeliculas;i++)
    {
        if(listaPeliculas[i].estado == OCUPADO)
        {
            for(j=0;j<10;j++)
            {
                if(listaPeliculas[i].idActor == listaActores[j].idActor)
                {
                    strcpy(auxActor, listaActores[j].nombre);
                }
            }
            for(k=0;k<5;k++)
            {
                if(listaPeliculas[i].idGenero == listaGeneros[k].idGenero)
                {
                    strcpy(auxGenero, listaGeneros[k].genero);
                }
            }
            printf("%d.%s---%d/%d/%d---%s---%s\n", listaPeliculas[i].idPelicula, listaPeliculas[i].titulo, listaPeliculas[i].fechaEstreno.dia, listaPeliculas[i].fechaEstreno.mes, listaPeliculas[i].fechaEstreno.mes, auxActor, auxGenero);
        }
    }
}

void informeDos(ePelicula listaPeliculas[], eActor listaActores[], int tamPeliculas)
{
    int i,j;
    for(i=0;i<tamPeliculas;i++)
    {
        for(j=0;j<10;j++)
        {
            if(listaPeliculas[i].idActor == listaActores[j].idActor)
            {
                if(stricmp(listaActores[j].paisOrigen, "EEUU") == 0)
                {
                    mostrarPelicula(listaPeliculas[i]);
                }
            }
        }
    }
}

void informeTres(ePelicula listaPeliculas[], eGenero listaGeneros[], int tamPeliculas)
{
    int i,j;
    for(i=0;i<5;i++)
    {
        printf("%s:\n", listaGeneros[i].genero);
        for(j=0;j<tamPeliculas;j++)
        {
            if(listaGeneros[i].idGenero == listaPeliculas[j].idGenero && listaPeliculas[j].estado == OCUPADO)
            {
                printf("%s\n", listaPeliculas[j].titulo);
            }
        }
    }
}

void informeCuatro(ePelicula listaPeliculas[], eGenero listaGeneros[], int tamPeliculas)
{
    int i,j,k;
    int contadores[5];
    for(k=0;k<5;k++)
    {
        contadores[k] = 0;
    }
    for(i=0;i<tamPeliculas;i++)
    {
        if(listaPeliculas[i].estado == OCUPADO)
        {
            if(listaPeliculas[i].idGenero == 1)
            {
                contadores[0]++;
            }else if(listaPeliculas[i].idGenero == 2)
            {
                contadores[1]++;
            }else if(listaPeliculas[i].idGenero == 3)
            {
                contadores[2]++;
            }else if(listaPeliculas[i].idGenero == 4)
            {
                contadores[3]++;
            }else
            {
                contadores[4]++;
            }
        }
    }
    for(j=0;j<5;j++)
    {
        printf("%s: %d\n", listaGeneros[j].genero, contadores[j]);
    }
}

void informeCinco(ePelicula listaPeliculas[], eGenero listaGeneros[], int tamPeliculas)
{
    int i,j;
    int peliculasMin;
    char generoMin[61];
    int flag = 0;
    int cantPeliculas = 0;
    for(i=0;i<5;i++)
    {
        for(j=0;j<tamPeliculas;j++)
        {
            if(listaPeliculas[j].estado == OCUPADO)
            {
                if(listaPeliculas[j].idGenero == listaGeneros[i].idGenero)
                {
                    cantPeliculas++;
                }
            }
        }
        if(cantPeliculas < peliculasMin || flag == 0)
        {
            strcpy(generoMin, listaGeneros[i].genero);
            peliculasMin = cantPeliculas;
            flag = 1;
        }
        cantPeliculas = 0;
    }
    printf("El/los generos con menor peliculas es/son: %s\n", generoMin);
}

