#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "BibliotecaFuncionesGenericas.h"
int pedirEntero(char mensaje[])
{
    int numeroEntero;
    printf("%s" , mensaje);
    scanf("%d" , &numeroEntero);
    return numeroEntero;
}

float pedirFlotante(char mensaje[])
{
    float numeroFlotante;
    printf("%s" , mensaje);
    scanf("%f" , &numeroFlotante);
    return numeroFlotante;
}

char pedirCaracter(char mensaje[])
{
    char caracter;
    printf("%s" , mensaje);
    fflush(stdin);
    scanf("%c" , &caracter);
    return caracter;
}

void recorrerVector(int vector_1[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("%d" , vector_1[i]);
    }
}

int generarNumeroRandom()
{
    int numero;
    srand(time(NULL));
    numero = rand();
    return numero;
}

int buscarMaximo(int vector_1[], int tam)
{
    int i;
    int maximo;
    int flag = 0;
    for(i=0;i<tam;i++)
    {
        if(vector_1[i]>maximo || flag == 0)
        {
            maximo = vector_1[i];
            flag = 1;
        }
    }
    return maximo;
}

float sumaNumeros(float num1, float num2)
{
    float resultado;
    resultado = num1 + num2;
    return resultado;
}

float restaNumeros(float num1, float num2)
{
    float resultado;
    resultado = num1 - num2;
    return resultado;
}

float divisionNumeros(float num1, float num2)
{
    float resultado;
    resultado = num1 / num2;
    return resultado;
}

float multiplicacionNumeros(float num1, float num2)
{
    float resultado;
    resultado = num1 * num2;
    return resultado;
}

int factorialNumero(int num1)
{
    int resultado;
    if(num1 == 0 || num1 == 1)
    {
        resultado = 1;
    }else
    {
        resultado = num1 * factorialNumero(num1 -1);
    }
    return resultado;
}

int buscarEntero(eEmpleados lista[], int tam)
{
    int i;
    int indice = -1;
    int numero = pedirEntero("Ingrese el numero que desea buscar: ");
    for(i=0;i<tam;i++)
    {
        if(lista[i].idSector == numero)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void pedirCadena(char mensaje[] , char cadena[] , int tamCadena)
{
    printf("%s" , mensaje);
    fflush(stdin);
    scanf("%[^\n]" , cadena);
    validarCadena("cadena: " , cadena , tamCadena);
}

void validarCadena(char mensajeError[] , char cadena[] , int tamCadena)
{
    char auxCadena[100];
    strcpy(auxCadena, cadena);
    while(strlen(auxCadena)>tamCadena)
    {
        printf("Reingrese %s" , mensajeError);
        fflush(stdin);
        scanf("%[^\n]" , auxCadena);
    }
    strcpy(cadena, auxCadena);
}

void cargarEstructura(eEmpleados lista[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        pedirCadena("Ingrese apellido: ", lista[i].apellido, 51);
        pedirCadena("Ingrese nombre: ", lista[i].nombre, 51);
        lista[i].estado = OCUPADO;
        lista[i].idSector = pedirEntero("Ingrese Id: ");
        lista[i].sueldoBruto = pedirFlotante("Ingrese sueldo bruto: ");
        lista[i].sueldoNeto = lista[i].sueldoBruto * 0.85;
    }
}

void ordenarMenorMayor(eEmpleados lista[], int tam)
{
    int i,j;
    char auxNombre[51];
    char auxApellido[51];
    int auxEstado;
    int auxIdSector;
    float auxSueldoBruto;
    float auxSueldoNeto;
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(lista[i].idSector > lista[j].idSector)
            {
                strcpy(auxApellido, lista[i].apellido);
                strcpy(lista[i].apellido, lista[j].apellido);
                strcpy(lista[j].apellido, auxApellido);

                strcpy(auxNombre, lista[i].nombre);
                strcpy(lista[i].nombre, lista[j].nombre);
                strcpy(lista[j].nombre, auxNombre);

                auxEstado = lista[i].estado;
                lista[i].estado = lista[j].estado;
                lista[j].estado = auxEstado;

                auxIdSector = lista[i].idSector;
                lista[i].idSector = lista[j].idSector;
                lista[j].idSector = auxIdSector;

                auxSueldoBruto = lista[i].sueldoBruto;
                lista[i].sueldoBruto = lista[j].sueldoBruto;
                lista[j].sueldoBruto = auxSueldoBruto;

                auxSueldoNeto = lista[i].sueldoNeto;
                lista[i].sueldoNeto = lista[j].sueldoNeto;
                lista[j].sueldoNeto = auxSueldoNeto;
            }
        }
    }
}

void mostrarEmpleado(eEmpleados unEmpleado)
{
    printf("%s--%s--%d--%d--%.2f--%.2f", unEmpleado.nombre, unEmpleado.apellido, unEmpleado.estado, unEmpleado.idSector, unEmpleado.sueldoBruto, unEmpleado.sueldoNeto);
}

void mostrarListaEmpleados(eEmpleados lista[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(lista[i].estado == OCUPADO)
        {
            mostrarEmpleado(lista[i]);
        }
    }
}

int buscarLibre(eEmpleados lista[], int tam)
{
    int indice = -1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(lista[i].estado == LIBRE)
        {
            indice = i;
        }
    }
    return indice;
}

void inicializarEmpleados(eEmpleados lista[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        lista[i].estado = LIBRE;
    }
}

void hardcodearDatos(eEmpleados lista[], int tam)
{
    char nombre[][51] = {"Matias","Jonathan","Martina"};
    char apellido[][51] = {"Perez","Di Martino","Roberts"};
    int idSector[] = {1,3,5};
    float sueldoBruto[] = {1000,2000,3000};
    int i;
    for(i=0;i<tam;i++)
    {
        strcpy(lista[i].nombre, nombre[i]);
        strcpy(lista[i].apellido, apellido[i]);
        lista[i].estado = OCUPADO;
        lista[i].idSector = idSector[i];
        lista[i].sueldoBruto = sueldoBruto[i];
        lista[i].sueldoNeto = lista[i].sueldoBruto * 0.85;
    }
}

void borrarEmpleado(eEmpleados lista[], int tam)
{
    int i;
    int indice = buscarEntero(lista,tam);
    for(i=0;i<tam;i++)
    {
        if(lista[i].idSector == indice)
        {
            lista[i].estado = LIBRE;
            strcpy(lista[i].nombre, "");
        }
    }
}

