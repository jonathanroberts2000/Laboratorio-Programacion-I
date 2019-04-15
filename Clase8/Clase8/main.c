#include <stdio.h>
#include <stdlib.h>
#define T 3
#define OCUPADO 1
#define LIBRE 0
typedef struct{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldoBruto;
    float sueldoNeto;
    int estado;
}eEmpleado;

void cargarEmpleado(eEmpleado[], int);
void mostrarEmpleado(eEmpleado);
void mostrarListaEmpleado(eEmpleado[], int);
void inicializarEmpleados(eEmpleado[], int);
int buscarLibre(eEmpleado[], int);
int pedirOpcion(char mensaje[]);
int buscarUno(eEmpleado[], int, int);
int borrarUno(eEmpleado[], int, int);


int main()
{
    //eEmpleado unEmpleado;
    eEmpleado lista[T];
    char seguir = 's';
    int opcion;

    do{
        printf("1. inicializar empleado \n");
        printf("2. cargar empledos \n");
        printf("3. mostrar lista empleados \n");
        printf("4. Salir \n");

        opcion = pedirOpcion("Ingrese una opcion por favor: ");
        switch(opcion)
        {
            case 1:
                inicializarEmpleados(lista, T);
                break;
            case 2:
                cargarEmpleado(lista, T);
                break;
            case 3:
                mostrarListaEmpleado(lista, T);
                break;
            case 4:
                return 0;
                break;
            default:
                opcion = pedirOpcion("Error! Ingrese una opcion correcta: ");
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
int pedirOpcion(char mensaje[])
{
    int opcion;
    printf("%s" , mensaje);
    scanf("%d" , &opcion);
    return opcion;
}
int buscarLibre(eEmpleado miEmpleado[], int tam)
{
    int indice = -1;
    int i;
    for(i=0;i<tam;i++)
    {
        if(miEmpleado[i].estado == LIBRE)
        {
            indice = i;
        }
    }
    return indice;
}
void inicializarEmpleados(eEmpleado miEmpleado[] , int tam)
{
    int i;
    for(i=0;i<tam;i++)
    {
        miEmpleado[i].estado = -1;
    }
}
int buscarUno(eEmpleado miEmpleado[], int indice , int tam)
{
    int posicion;
    int i;

    for(i=0;i<tam;i++)
    {
        if(miEmpleado[i].estado == LIBRE)
        {
            posicion = i;
        }
    }
    return posicion;

}
int borrarUno(eEmpleado miEmpleado[], int indice, int tam)
{
    int posicion;


    return posicion;
}
