#include <stdio.h>
#include <stdlib.h>
#define T 2
typedef struct{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldoBruto;
    float sueldoNeto;
}eEmpleado;

void cargarEmpleado(eEmpleado[], int tam);
void mostrarEmpleado(eEmpleado);
void mostrarListaEmpleado(eEmpleado[], int tam);
int buscarLibre(eEmpleado[], int tam);
void inicializarEmpleados(eEmpleado[], int tam);
int main()
{
    //eEmpleado unEmpleado;
    eEmpleado lista[T];
    char seguir = 's';
    int opcion;

    do{
        printf("1. cargarEmpleado \n ");
        printf("2. mostrar lista empleados \n ");
        printf("5. Salir \n ");

        switch(opcion)
        {
            case 1:
                cargarEmpleado(lista, T);
                break;
            case 2:
                mostrarListaEmpleado(lista, T);
                break;
            case 3:

                break;
            default:

                break;
        }

    system("pause");
    system("cls");
    fflush(stdin);
    }while(seguir == 's');

    return 0;
}

void mostrarEmpleado(eEmpleado miEmpleado)
{
    printf("%d--%s--%c--%f--%f--\n" , miEmpleado.legajo , miEmpleado.nombre , miEmpleado.sexo , miEmpleado.sueldoBruto , miEmpleado.sueldoNeto);
}
void mostrarListaEmpleado(eEmpleado miEmpleado[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        mostrarEmpleado(miEmpleado[i]);
    }
}
void cargarEmpleado(eEmpleado miEmpleado[], int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        printf("Ingrese legajo: ");
        scanf("%d" , &miEmpleado[i].legajo);
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(miEmpleado[i].nombre);
        printf("Ingrese sexo(F o M): ");
        fflush(stdin);
        scanf("%c" , &miEmpleado[i].sexo);
        printf("Ingrese sueldo bruto: ");
        scanf("%f" , &miEmpleado[i].sueldoBruto);
        miEmpleado[i].sueldoBruto = miEmpleado[i].sueldoBruto*0.85;
    }
}
int buscarLibre(eEmpleado miEmpleado[], int tam)
{
    int libre;
}
void inicializarEmpleados(eEmpleado miEmpleado[] , int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        miEmpleado[i].legajo = -1;
    }
}
