#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct eEmpleado /*typedef struct*/
{
    int legajo;
    char nombre[20];
    char sexo;
    float sueldoBruto;
    float sueldoNeto;
} /*eEmpleado*/;
//funciones se declaran debajo de estructuras;

void mostrarEmpleado(eEmpleado);

int main()
{
    struct eEmpleado unEmpleado; //no pondria struct de la forma del comentario;
    struct eEmpleado otroEmpleado;
    printf("Ingrese legajo: ");
    scanf("%d" , &unEmpleado.legajo);
    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(unEmpleado.nombre);
    printf("Ingrese sexo(F o M): ");
    fflush(stdin);
    scanf("%c" , &unEmpleado.sexo);
    printf("Ingrese sueldo bruto: ");
    scanf("%f" , &unEmpleado.sueldoBruto);
    unEmpleado.sueldoBruto = unEmpleado.sueldoBruto*0.85;

    otroEmpleado = unEmpleado; //se puede hacer sin importar que este algo adentro
    unEmpleado.legajo = 7000;//mirar esto y sus efectos al ejecutar

    mostrarEmpleado(unEmpleado);
    mostrarEmpleado(otroEmpleado);
    //puts(unEmpleado.nombre);

    return 0;
}

void mostrarEmpleado(eEmpleado miEmpleado)
{
    printf("%d--%s--%c--%f--%f--\n" , miEmpleado.legajo , miEmpleado.nombre , miEmpleado.sexo , miEmpleado.sueldoBruto , miEmpleado.sueldoNeto);
    //printf("%d--%s--%c--%f--%f--\n" , otroEmpleado.legajo , otroEmpleado.nombre , otroEmpleado.sexo , otroEmpleado.sueldoBruto , otroEmpleado.sueldoNeto);

}
