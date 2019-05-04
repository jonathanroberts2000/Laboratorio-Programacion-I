#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include "ArrayEmployees.h"

void inicializarEmpleados(Employee lista[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        lista[i].isEmpty = LIBRE;
    }
}

int buscarLibre(Employee lista[], int tam)
{
    int indice = -1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(lista[i].isEmpty == LIBRE)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void cargarEmpleado(Employee lista[], int tam)
{
    char respuesta = 's';
    int indice;
    while(respuesta == 's')
    {
        indice = buscarLibre(lista, tam);
        if(indice == -1)
        {
            printf("No hay espacio para ingresar mas empleados! \n");
        }else
        {
            lista[indice].id = generarNumeroRandom();
            printf("Ingrese nombre: ");
            fflush(stdin);
            scanf("%[^\n]" , lista[indice].name);
            printf("Ingrese apellido: ");
            fflush(stdin);
            scanf("%[^\n]" , lista[indice].lastName);
            printf("Ingrese sueldo: ");
            scanf("%f" , &lista[indice].salary);
            printf("Ingrese sector: ");
            scanf("%d" , &lista[indice].sector);
            lista[indice].isEmpty = OCUPADO;
            respuesta = pedirCaracter("Desea cargar mas empleados? s/n: ");
            if(respuesta != 's')
            {
                break;
            }
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
    utilizandoStrings(lista,tam);
    for(i=0;i<tam;i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
            mostrarSectorEmpleados(lista[i]);
            mostrarEmpleado(lista[i]);
        }
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
            if(lista[i].sector>lista[j].sector && lista[i].isEmpty == OCUPADO && lista[j].isEmpty == OCUPADO)
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




void utilizandoStrings(Employee lista[], int tamEmployees)
{
    int i;
    for(i=0;i<tamEmployees;i++)
    {
        strlwr(lista[i].name);
        strlwr(lista[i].lastName);
    }
    pasarMayusculas(lista, tamEmployees);
}

void ordenarAlfabeticamente(Employee lista[], int tamEmployees)
{
    int i,j;
    int auxEnteroId;
    int auxEnteroSector;
    float auxFlotanteSalary;
    char auxCadenaLastName[100];
    char auxCadenaName[100];
    for(i=0;i<tamEmployees-1;i++)
    {
        for(j=i+1;j<tamEmployees;j++)
        {
            if(lista[tamEmployees].isEmpty == OCUPADO && lista[i].sector == lista[j].sector)
            {
                if(strcmp(lista[i].lastName,lista[j].lastName)>0)
                {
                    strcpy(auxCadenaLastName, lista[i].lastName);
                    strcpy(lista[i].lastName, lista[j].lastName);
                    strcpy(lista[j].lastName, auxCadenaLastName);

                    strcpy(auxCadenaName, lista[i].name);
                    strcpy(lista[i].name, lista[j].name);
                    strcpy(lista[j].name, auxCadenaName);

                    auxEnteroSector = lista[i].sector;
                    lista[i].sector = lista[j].sector;
                    lista[j].sector = auxEnteroSector;

                    auxEnteroId = lista[i].id;
                    lista[i].id = lista[j].id;
                    lista[j].id = auxEnteroId;

                    auxFlotanteSalary = lista[i].salary;
                    lista[i].salary = lista[j].salary;
                    lista[j].salary = auxFlotanteSalary;
                    ordenarListaEmpleados(lista, tamEmployees);
                }
            }
        }
    }
}
void pasarMayusculas(Employee lista[], int tamEmployees)
{
    int i;
    int j;
    for(i=0;i<tamEmployees;i++)
    {
        for(j=0;j<tamEmployees;j++)
        {
            if(j==0)
            {
                lista[i].name[j] = toupper(lista[i].name[j]);
                lista[i].lastName[j] = toupper(lista[i].lastName[j]);
            }
        }
    }
}







int pedirEntero(char mensaje[])
{
    int numeroEntero;
    printf("%s" , mensaje);
    scanf("%d" , &numeroEntero);
    return numeroEntero;
}
char pedirCaracter(char mensaje[])
{
    char respuesta;
    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &respuesta);
    return respuesta;
}
int generarNumeroRandom(void)
{
    int numero;
    srand(time(NULL));
    numero = rand();
    return numero;
}




void mostrarSectorEmpleados(Employee unEmpleado)
{
    printf("Sector: %d \n" , unEmpleado.sector);
}



float totalSalarios(Employee lista[], int tam)
{
    float totalSalarios = 0;
    int i;
    for(i=0;i<tam;i++)
    {
        if(lista[i].isEmpty == OCUPADO)
        {
            totalSalarios = totalSalarios + lista[i].salary;
        }
    }
    return totalSalarios;
}

float promedioSalarios(Employee lista[], int tam, float totalSalario)
{
    float promedioSalario = 0;
    int contadorEmpleados = 0;
    int cantidadEmpleadosMayorPromedio = 0;
    int i,j;
    totalSalario = totalSalarios(lista, tam);
    for(i=0;i<tam;i++)
    {
        contadorEmpleados++;
        if(lista[i].isEmpty == OCUPADO)
        {
            promedioSalario = totalSalario / contadorEmpleados;
        }
    }
    for(j=0;j<tam;j++)
    {
        if(lista[j].isEmpty == OCUPADO)
        {
            if(lista[j].salary > promedioSalario)
            {
                cantidadEmpleadosMayorPromedio++;
            }
        }
    }
    printf("La cantidad de empleados que superan el promedio de salario son: %d \n", cantidadEmpleadosMayorPromedio);
    return promedioSalario;
}







