#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#include "BibliotecaFuncionesGenericas.h"
int pedirEntero(char mensaje[])
{
    int numeroEntero;
    printf("%s" , mensaje);
    scanf("%d" , &numeroEntero);
    numeroEntero = validacionDeEnterosPositivos(numeroEntero);
    return numeroEntero;
}

float pedirFlotante(char mensaje[])
{
    float numeroFlotante;
    printf("%s" , mensaje);
    scanf("%f" , &numeroFlotante);
    numeroFlotante = validacionDeFlotantesPositivos(numeroFlotante);
    return numeroFlotante;
}

char pedirCaracter(char mensaje[])
{
    char caracter;
    printf("%s" , mensaje);
    fflush(stdin);
    scanf("%c" , &caracter);
    caracter = validacionCaracterSexo(caracter);
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
        if(lista[i].legajo == numero)
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
        //printf("Reingrese %s" , mensajeError);
        //fflush(stdin);
        //scanf("%[^\n]" , auxCadena);
        pedirCadena("Reingrese nombre: ", auxCadena, 21);
    }
    strcpy(cadena, auxCadena);
}

void cargarEmpleado(eEmpleados lista[], int tam)
{
    int indice = buscarLibre(lista, tam);
    if(indice == -1)
    {
        printf("No hay espacio para ingresar mas empleados! \n");
    }else
    {
        pedirCadena("Ingrese apellido: ", lista[indice].apellido, 51);
        pedirCadena("Ingrese nombre: ", lista[indice].nombre, 51);
        lista[indice].sexo = pedirCaracter("Ingrese sexo: ");
        lista[indice].estado = OCUPADO;
        lista[indice].legajo = pedirEntero("Ingrese legajo: ");
        lista[indice].idSector = pedirEntero("Ingrese Id: ");
        lista[indice].sueldoBruto = pedirFlotante("Ingrese sueldo bruto: ");
        lista[indice].sueldoNeto = multiplicacionNumeros(lista[indice].sueldoBruto, 0.85);
    }
}

void ordenarMenorMayor(eEmpleados lista[], int tam)
{
    int i,j;
    char auxNombre[51];
    char auxApellido[51];
    int auxEstado;
    int auxLegajo;
    int auxIdSector;
    float auxSueldoBruto;
    float auxSueldoNeto;
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(lista[i].legajo > lista[j].legajo)
            {
                auxLegajo = lista[i].legajo;
                lista[i].legajo = lista[j].legajo;
                lista[j].legajo = auxLegajo;

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
    printf("%s--%s--%c--%d--%d--%d--%.2f--%.2f \n", unEmpleado.nombre, unEmpleado.apellido, unEmpleado.sexo, unEmpleado.estado, unEmpleado.idSector, unEmpleado.legajo, unEmpleado.sueldoBruto, unEmpleado.sueldoNeto);
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
            break;
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
    char sexo[] = {'M','M','F'};
    int idSector[] = {1,3,5};
    int legajo[] = {10,21,32};
    float sueldoBruto[] = {1000,2000,3000};
    int i;
    for(i=0;i<tam;i++)
    {
        strcpy(lista[i].nombre, nombre[i]);
        strcpy(lista[i].apellido, apellido[i]);
        lista[i].sexo = sexo[i];
        lista[i].estado = OCUPADO;
        lista[i].idSector = idSector[i];
        lista[i].legajo = legajo[i];
        lista[i].sueldoBruto = sueldoBruto[i];
        lista[i].sueldoNeto = lista[i].sueldoBruto * 0.85;
    }
}

void borrarEmpleado(eEmpleados lista[], int tam)
{
    int indice = buscarEntero(lista,tam);
    if(indice == -1)
    {
        printf("Error! El legajo ingresado no esta registrado en el sistema! \n");
    }else{
        lista[indice].estado = LIBRE;
        strcpy(lista[indice].nombre, "");
        strcpy(lista[indice].apellido, "");
        lista[indice].sexo = ' ';
        lista[indice].legajo = -1;
        lista[indice].idSector = -1;
        lista[indice].sueldoBruto = 0;
        lista[indice].sueldoNeto = 0;
        printf("El empleado ha sido borrado del sistema exitosamente. \n");
    }
}

int validacionDeEnterosPositivos(int num1)
{
    int auxNum = num1;
    while(auxNum < 0)
    {
        auxNum = pedirEntero("Error! Reingrese un numero positivo: ");
    }
    return auxNum;
}

float validacionDeFlotantesPositivos(float num1)
{
    float auxNum = num1;
    while(auxNum < 0)
    {
        auxNum = pedirFlotante("Error! Reingrese un numero positivo: ");
    }
    return auxNum;
}

char validacionCaracterSexo(char caracter)
{
    char auxCaracter = caracter;
    auxCaracter = tolower(auxCaracter);
    while(auxCaracter != 'm' && auxCaracter != 'f')
    {
        auxCaracter = pedirCaracter("Error! Reingrese un sexo valido: ");
    }
    return auxCaracter;
}

void modificarEmpleado(eEmpleados lista[], int tam) //complementar funcion preguntando al usuario si cuando ingresa mal el legajo desea ver los empleados
{
    int legajo = pedirEntero("Ingrese el legajo a buscar: ");
    int indice = buscarEmpleadoPorLegajo(lista, tam, legajo);
    int opcion;
    if(indice == -1)
    {
        printf("Error! El legajo solicitado no esta ingresado en el sistema! \n");
        //desea ver los empleados para comrpobar sus legajos?
    }else{
        do{
            opcion = pedirEntero("1.Modificar nombre\n2.Modificar apellido\n3.Modificar id sector\n4.Modificar sueldo bruto\n5.Salir del menu modificaciones\nElija una opcion: ");
            switch(opcion)
            {
                case 1:
                    pedirCadena("Ingrese el nuevo nombre del empleado: ", lista[indice].nombre, 51);
                    break;
                case 2:
                    pedirCadena("Ingrese el nuevo apellido del empleado: ", lista[indice].apellido, 51);
                    break;
                case 3:
                    lista[indice].idSector = pedirEntero("Ingrese el nuevo sector del empleado: ");
                    break;
                case 4:
                    lista[indice].sueldoBruto = pedirFlotante("Ingrese el nuevo sueldo bruto del empleado: ");
                    lista[indice].sueldoNeto =  multiplicacionNumeros(lista[indice].sueldoBruto, 0.85);
                    break;
                case 5:
                    printf("Saliendo...\n");
                    break;
                default:
                    printf("Error! No ha ingresado una opcion correcta! \n");
                    break;
            }
        system("pause");
        system("cls");
        fflush(stdin);
        }while(opcion !=5);
    }
}

int buscarEmpleadoPorLegajo(eEmpleados lista[], int tam, int legajo)
{
    int indice = -1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(lista[i].legajo == legajo)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int buscarEmpleadoEspecifico(eEmpleados lista[], int tam)
{
    int i;
    int cantEmpleados = 0;
    char nombre[51];
    float sueldoBruto = pedirFlotante("Ingrese el parametro con el que desea comparar a el/los empleado/s: ");
    pedirCadena("Ingrese el nombre del/los empleado/s a buscar: ", nombre, 51);
    for(i=0;i<tam;i++)
    {
        if(stricmp(lista[i].nombre, nombre) == 0 && lista[i].sueldoBruto > sueldoBruto)
        {
            cantEmpleados++;
        }
    }
    return cantEmpleados;
}


