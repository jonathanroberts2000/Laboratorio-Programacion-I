#include <stdio.h>
#include <stdlib.h>
#define T 3
#define OCUPADO 1
#define LIBRE 0
typedef struct{
    int legajo;
    int estado;
    float sueldoBruto;
    float sueldoNeto;
    char nombre[20];
    char sexo;
}eEmpleado;

void inicializarEmpleados(eEmpleado[], int);
void cargarEmpleado(eEmpleado[], int);
void mostrarEmpleado(eEmpleado);
void mostrarListaEmpleado(eEmpleado[], int);
int pedirOpcion(char mensaje[]);
int buscarLibre(eEmpleado[], int);
int buscarUno(eEmpleado[], int, int);
int borrarUno(eEmpleado[], int, int);

int main()
{
    eEmpleado lista[T];
    char seguir = 's';
    int opcion;

    do{
        printf("1. Inicializar empleado \n");
        printf("2. Cargar empledos \n");
        printf("3. Mostrar lista de empleados \n");
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
                //return 0;
                seguir = 'n';
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
        miEmpleado[i].sueldoNeto = miEmpleado[i].sueldoBruto*0.85;
        miEmpleado[i].estado = OCUPADO;
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
        miEmpleado[i].estado = LIBRE;
    }
}
int buscarUno(eEmpleado miEmpleado[], int legajo , int tam)
{
    int posicion;
    int i;

    for(i=0;i<tam;i++)
    {
        if(miEmpleado[i].legajo == legajo)
        {
            posicion = i;
        }
    }
    return posicion;

}
int borrarUno(eEmpleado miEmpleado[], int legajo, int tam)
{
    int posicion;
    posicion = buscarUno(miEmpleado, legajo, tam);

    if(posicion == -1)
    {
        return 0;
    }else{
        miEmpleado[posicion].estado = LIBRE;
        return 1;
    }
}
