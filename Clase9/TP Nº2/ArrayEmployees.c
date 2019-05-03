#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "ValidationFunctions.h"

void cargarEmpleado(Employee lista[], int tam)
{
    int i=0;
    char respuesta;
    for(i=0;i<tam;i++)
    {
        lista[i].id = generarNumeroRandom();
        printf("Ingrese nombre: ");
        fflush(stdin);
        scanf("%[^\n]" , lista[i].name);
        printf("Ingrese apellido: ");
        fflush(stdin);
        scanf("%[^\n]" , lista[i].lastName);
        printf("Ingrese sueldo: ");
        scanf("%f" , &lista[i].salary);
        printf("Ingrese sector: ");
        scanf("%d" , &lista[i].sector);
        lista[i].isEmpty = OCUPADO;
        respuesta = pedirCaracter("Desea cargar mas empleados? s/n: ");
        if(respuesta != 's')
        {
            break;
        }
    }
}

int buscarId(Employee lista[], int tam, int id)
{
    int indice = -1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(lista[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void modificarEmpleado(Employee lista[], int tam)
{
    int id = pedirEntero("Ingrese el Id del empleado a buscar: ");
    int indice = buscarId(lista, tam, id);
    int opcion;
    char respuesta;
    if(indice == -1)
    {
        printf("No se encontro la id solicitada! \n");
    }else{
    do{
        opcion = pedirEntero("1.Modificar nombre\n2.Modificar sexo\n3.Modificar sueldo bruto\n4.Salir del menu\nElija una opcion: ");
        switch(opcion)
        {
            case 1:
                printf("Ingrese el nuevo nombre: ");
                fflush(stdin);
                scanf("%[^\n]" , lista[indice].name);
                break;
            case 2:
                printf("Ingrese el nuevo apellido: ");
                fflush(stdin);
                scanf("%[^\n]" , lista[indice].lastName);
                break;
            case 3:
                printf("Ingrese el nuevo sueldo: ");
                scanf("%f" , &lista[indice].salary);
                break;
            case 4:
                printf("Ingrese el nuevo sector: ");
                scanf("%d" , &lista[indice].sector);
                break;
            case 5:
                printf("Saliendo de este menu...");
                break;
            default:
                printf("Error! Reingrese una opcion valida!\n");
                break;
        }
        respuesta = pedirCaracter("Desea modificar otro campo? s/n: ");
    }while(respuesta == 's');
    }
}

void borrarEmpleado(Employee lista[], int tam)
{
    int id = pedirEntero("Ingrese el Id del empleado a buscar: ");
    int indice = buscarId(lista, tam, id);
    int i;
    if(indice == -1)
    {
        printf("No se encontro la id solicitada! \n");
    }else
    {
        for(i=0;i<tam;i++)
        {
            if(lista[i].isEmpty == indice)
            {
                lista[i].isEmpty = LIBRE;
            }
        }
    }
}

void mostrarEmpleado(Employee unEmpleado)
{
    printf("%d--%s--%s--%f--%d \n" , unEmpleado.id, unEmpleado.name, unEmpleado.lastName, unEmpleado.salary, unEmpleado.sector);
}

void mostrarListaEmpleados(Employee lista[], int tam)
{
    int i;
    ordenarListaEmpleados(lista, tam);
    ordenarAlfabeticamente(lista,tam);
    utilizandoStrings(lista,tam);
    for(i=0;i<tam;i++)
    {
        mostrarEmpleado(lista[i]);
    }
}

void ordenarListaEmpleados(Employee lista[], int tam)
{
    int i;
    int j;
    char auxCadenaLastName[51];
    int auxEnteroSector;
    int auxEnteroId;
    char auxCadenaName[51];
    float auxFlotanteSalary;
    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(lista[i].sector>lista[j].sector)
            {
                strcpy(auxCadenaLastName, lista[i].lastName);
                strcpy(lista[i].lastName, lista[j].lastName);
                strcpy(lista[j].lastName, auxCadenaLastName);

                auxEnteroSector = lista[i].sector;
                lista[i].sector = lista[j].sector;
                lista[j].sector = auxEnteroSector;

                auxEnteroId = lista[i].id;
                lista[i].id = lista[j].id;
                lista[j].id = auxEnteroId;

                strcpy(auxCadenaName, lista[i].name);
                strcpy(lista[i].name, lista[j].name);
                strcpy(lista[j].name, auxCadenaName);

                auxFlotanteSalary = lista[i].salary;
                lista[i].salary = lista[j].salary;
                lista[j].salary = auxFlotanteSalary;
            }
        }
    }
}

