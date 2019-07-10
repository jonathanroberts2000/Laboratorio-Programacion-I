#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ePelicula.h"
ePelicula* pelicula_new()
{
    ePelicula* pelicula = (ePelicula*)malloc(sizeof(ePelicula));
    return pelicula;
}

ePelicula* pelicula_newParametros(char* idStr, char* nombreStr, char* anioStr, char* generoStr)
{
    ePelicula* pelicula = pelicula_new();
    if(idStr != NULL && nombreStr != NULL && anioStr != NULL && generoStr != NULL && pelicula != NULL)
    {
        pelicula_setId(pelicula, atoi(idStr));
        pelicula_setNombre(pelicula, nombreStr);
        pelicula_setAnio(pelicula, atoi(anioStr));
        pelicula_setGenero(pelicula, generoStr);
        return pelicula;
    }else
    {
        return NULL;
    }
}

int pelicula_setId(ePelicula* this, int id)
{
    int status = 0;
    if(this != NULL)
    {
        this->id = id;
        status = 1;
    }
    return status;
}

int pelicula_setNombre(ePelicula* this, char* nombre)
{
    int status = 0;
    if(this != NULL && nombre != NULL)
    {
        strcpy(this->nombre, nombre);
        status = 1;
    }
    return status;
}

int pelicula_setAnio(ePelicula* this, int anio)
{
    int status = 0;
    if(this != NULL)
    {
        this->anio = anio;
        status = 1;
    }
    return status;
}

int pelicula_setGenero(ePelicula* this, char* genero)
{
    int status = 0;
    if(this != NULL && genero != NULL)
    {
        strcpy(this->genero, genero);
        status = 1;
    }
    return status;
}

int pelicula_getId(ePelicula* this)
{
    int id;
    if(this != NULL)
    {
        id = this->id;
    }
    return id;
}

char* pelicula_getNombre(ePelicula* this)
{
    char* nombre;
    if(this != NULL)
    {
        nombre = this->nombre;
    }
    return nombre;
}

int pelicula_getAnio(ePelicula* this)
{
    int anio;
    if(this != NULL)
    {
        anio = this->anio;
    }
    return anio;
}

char* pelicula_getGenero(ePelicula* this)
{
    char* genero;
    if(this != NULL)
    {
        genero = this->genero;
    }
    return genero;
}

int pelicula_compareById(ePelicula* p1, ePelicula* p2)
{
    int comp = -1;
    if(pelicula_getId(p1) > pelicula_getId(p2))
    {
        comp = 1;
    }
    return comp;
}

