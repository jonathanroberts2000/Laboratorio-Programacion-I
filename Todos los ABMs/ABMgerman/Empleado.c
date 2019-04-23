
#include "Empleado.h"
#include <string.h>

void cargarEmpleado(eEmpleado lista[], int te, eSector sector[], int ts)
{
    int i;
    int j;

    i = buscarLibre(lista, te);
    if(i!=-1)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &lista[i].legajo);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(lista[i].nombre);
        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &lista[i].sexo);
        printf("Ingrese cantidad de horas: ");
        scanf("%d", &lista[i].cantidadHoras);
        printf("Elija secto: \n");
        for(j=0;j<ts;j++)
        {
            printf("%d. \t%s \n" , sector[j].idSector, sector[j].descripcion);
        }
        scanf("%d", &lista[i].idSector);

        //lista[i].sueldoNeto =lista[i].sueldoBruto*0.85;

        lista[i].estado = OCUPADO;
        lista[i].sueldoBruto = sector[lista[i].idSector].valor*lista[i].cantidadHoras;
        lista[i].sueldoNeto = lista[i].sueldoBruto * 0.85;

    }
    else
    {
        printf("No hay espacio para cargar mas empleados!");
    }

}

void mostrarListaEmpleados(eEmpleado lista[], int tam, eSector sectores[], int ts)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado!=LIBRE)
        {
            mostrarEmpleado(lista[i], sectores, ts);
        }
    }
}
void mostrarEmpleado(eEmpleado unEmpleado, eSector sectores[], int ts)
{

    char descripcionSector[20];
    int i;

    for(i=0; i<ts; i++)
    {
        if(unEmpleado.idSector==sectores[i].idSector)
        {
            strcpy(descripcionSector, sectores[i].descripcion);
            break;
        }
    }
    printf("%2d %2s %2c %2.2f %2.2f   %s\n", unEmpleado.legajo,unEmpleado.nombre, unEmpleado.sexo, unEmpleado.sueldoBruto,unEmpleado.sueldoNeto,descripcionSector);
}
int buscarLibre(eEmpleado lista[], int tam)
{
    int i;
    int index=-1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}
void inicializarEmpleados(eEmpleado lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].estado = LIBRE;
    }
}

void hardcodearDatosEmpleados(eEmpleado lista[], int tam, eSector sectores[])
{
    int i;
    int legajos[]= {1,8,9,7,2,4};
    char nombres[][50]= {"Carlos","Maria","Carlos","Pedro","Carlos","Mateo"};
    char sexo[]= {'M','F','M','M','M','M'};
    //float sueldosBruto[]= {22000,22000,15000,4000,21000,6000};
    int sector[]={0,1,2,0,1,1};
    int cantHoras[]={120,128,128,116,114,130};

    //eFecha unaFecha = {22,04,2019};

    for(i=0; i<tam; i++)
    {
        lista[i].legajo = legajos[i];
        strcpy(lista[i].nombre, nombres[i]);
        lista[i].sexo = sexo[i];
        lista[i].idSector = sector[i];
        lista[i].cantidadHoras = cantHoras[i];
        lista[i].sueldoBruto = sectores[lista[i].idSector].valor*lista[i].cantidadHoras;
        lista[i].sueldoNeto = lista[i].sueldoBruto * 0.85;
        lista[i].estado = OCUPADO;
        lista[i].idSector = sector[i];
    }
}
void modificar(eEmpleado lista[], int tam, int legajo)
{
    int i;
    int loEncontro = 0;
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    for(i=0; i<tam; i++)
    {
        if(legajo == lista[i].legajo)
        {
            printf("Ingrese un nuevo sueldo bruto: ");
            scanf("%f", &lista[i].sueldoBruto);

            lista[i].sueldoNeto = lista[i].sueldoBruto*0.85;
            loEncontro = 1;
            break;//modifcar
        }
    }
    if(loEncontro==0)
    {
        printf("El dato no existe");
    }
}

void borrarEmpleado(eEmpleado lista[], int tam, int legajo)
{

    int i;
    int loEncontro = 0;
    printf("Ingrese legajo: ");
    scanf("%d", &legajo);

    for(i=0; i<tam; i++)
    {
        if(legajo == lista[i].legajo)
        {

            lista[i].estado = LIBRE;


            loEncontro = 1;
            break;//modifcar
        }
    }

    if(loEncontro==0)
    {
        printf("El dato no existe");
    }

}

float buscarSueldoMaximo(eEmpleado lista[], int tam)
{
    float maximo;
    int flag = 0;
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            if(flag==0 || lista[i].sueldoBruto>maximo)
            {
                maximo = lista[i].sueldoBruto;
                flag = 1;
            }
        }
    }
    return maximo;
}
void mostrarEmpleadosSueldoMaximo(eEmpleado lista[], int tam)
{
    float maximo = buscarSueldoMaximo(lista, tam);
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==OCUPADO && maximo == lista[i].sueldoBruto)
        {
            //mostrarEmpleado(lista[i]);

        }
    }
}

int contarCarlos(eEmpleado lista[], int tam)
{
    int contadorCarlos = 0;
    int i;

    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            if(stricmp(lista[i].nombre,"carlos")==0 && lista[i].sueldoBruto>20000)
            {
                contadorCarlos++;
            }
        }
    }
    return contadorCarlos;
}

int buscarLegajo(eEmpleado lista[], int tam, int legajo)
{
    //eliminar
    return 0;
}

void mostrarEmpleadoPorSector(eEmpleado lista[], int tam, eSector sectores)
{
    int i;
    for(i=0;i<tam;i++)
    {
        if(lista[i].idSector == sectores.idSector)
        {
            printf("%s \n" , lista[i].nombre);
        }
    }
}

void mostrarListaEmpleadosPorSector(eEmpleado lista[], int tam, eSector sectores[], int ts)
{
    int i;
    for(i=0;i<ts;i++)
    {
        mostrarSector(sectores[i]);
        mostrarEmpleadoPorSector(lista, tam, sectores[i]);
    }
}

void mostrarSector(eSector sectores)
{
    printf("%s \n" , sectores.descripcion);
}

void mostrarListaSectores(eSector sectores[], int ts)
{
    int i;
    for (i=0;i<ts;i++)
    {
        mostrarSector(sectores[i]);
    }
}
