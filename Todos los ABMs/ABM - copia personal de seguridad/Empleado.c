#include "Empleado.h"
#include <string.h>
void cargarEmpleado(eEmpleado lista[], int tam)
{
    int i;
    i = buscarLibre(lista, tam);
    if(i != -1)
    {
        printf("Ingrese legajo: ");
        scanf("%d", &lista[i].legajo);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(lista[i].nombre);
        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &lista[i].sexo);
        printf("Ingrese sueldo bruto: ");
        scanf("%f", &lista[i].sueldoBruto);

        lista[i].sueldoNeto =lista[i].sueldoBruto*0.85;

        lista[i].estado = OCUPADO;
    }
    else
    {
        printf("No hay espacio");
    }
}

void mostrarListaEmpleados(eEmpleado lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado!=LIBRE)
        {
            mostrarEmpleado(lista[i]);
        }
    }
}

void mostrarEmpleado(eEmpleado unEmpleado)
{
    printf("%d-%s-%c-%f-%f\n", unEmpleado.legajo,unEmpleado.nombre, unEmpleado.sexo, unEmpleado.sueldoBruto,unEmpleado.sueldoNeto);
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

void hardcodearDatosEmpleados(eEmpleado lista[], int tam)
{
    int i;
    int legajos[]={1,8,9,7,2,4};
    char nombres[][50]={"Maria","Pedro","Jose","Pedro","Pablo","Mateo"};
    char sexo[]={'F','M','M','M','M','M'};
    float sueldosBruto[]={1000,2000,3000,4000,5000,6000};

    for(i=0; i<tam; i++)
    {
        lista[i].legajo = legajos[i];
        strcpy(lista[i].nombre, nombres[i]);
        lista[i].sexo = sexo[i];
        lista[i].sueldoBruto = sueldosBruto[i];
        lista[i].sueldoNeto = sueldosBruto[i] * 0.85;
        lista[i].estado = OCUPADO;
    }
}
int buscarLegajo(eEmpleado lista[], int tam, int valor)
{
    int indice = -1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(lista[i].legajo == valor)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void modificarDatos(eEmpleado lista[], int tam)
{
    int legajo = pedirOpcion("Ingrese el legajo a buscar: ");
    int index = buscarLegajo(lista, tam, legajo);
    int opcion;
    if(index == -1)
    {
        printf("No se encontro el valor solicitado! \n");
    }else{
        do{
        opcion = pedirOpcion("1.Modificar nombre\n2.Modificar sexo\n3.Modificar sueldo bruto\n4.Salir del menu\nElija una opcion: ");
    switch(opcion)
    {
        case 1:
            printf("Ingrese el nuevo nombre: ");
            fflush(stdin);
            scanf("%s" , lista[index].nombre);
            break;
        case 2:
            printf("Ingrese el nuevo sexo: ");
            fflush(stdin);
            scanf("%s" , &lista[index].sexo);
            break;
        case 3:
            printf("Modificar sueldo bruto: ");
            scanf("%f" , &lista[index].sueldoBruto);
            lista[index].sueldoNeto = lista[index].sueldoBruto * 0.85;
            break;
        case 4:
            printf("Saliendo...\n");
            break;
        default:
            opcion = pedirOpcion("Error! Reingrese una opcion valida: ");
            break;
        }
    }while(opcion !=4);
    }
}

int pedirOpcion(char mensaje[])
{
    int opcion;
    printf("%s" , mensaje);
    scanf("%d" , &opcion);
    return opcion;
}

void borrarDatos(eEmpleado lista[], int tam, int valor)
{
    int legajo = pedirOpcion("Ingrese el legajo del empleado que desea borrar: ");
    int i;
    int flag = 0;
    for(i=0;i<tam;i++)
    {
        if(lista[i].legajo == legajo)
        {
            lista[i].estado = LIBRE;
            flag = 1;
        }
    }
   if(flag == 0)
   {
       printf("El legajo ingresado no esta registrado en el sistema! \n");
   }
}
