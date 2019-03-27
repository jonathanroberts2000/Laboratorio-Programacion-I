#include <stdio.h>
#include <stdlib.h>
#include "Ingresos.h"
#include "Recursividad.h"
//menu de opciones ahora todo en main, pero para el tp en funciones y librerias
int main()
{
    /*int edad;
    int legajo;
    int peso;

    edad = pedirEntero("Ingrese edad: ");
    legajo = pedirEntero("Ingrese legajo: ");
    peso = pedirEntero("Ingrese peso: ");
    int numero = 5;
    int resultado = factorial(numero); //(parametros actuales)jarcodear, es poner un numero desde aca sin preguntarle al usuario

    printf("%d" , resultado);*/

    int opcion;
    char seguir = 's';

    do{
        printf("1. Alta \n2.Baja\n3.Informar\n4.Salir\n Elija una opcion");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
                printf("Estoy dando de alta\n");
                break;
            case 2:
                printf("Estoy dando de baja\n");
                break;
            case 3:
                printf("Estoy informando\n");
                break;
            case 4:
                printf("Estoy saliendo del programa\n");
                break;
            default:
                printf("Error! No ingreso una opcion correcta!\n");
                break;
        }

    }while(seguir == 's');

//antes de iterar, puedo poner system("pause");//system("cls") para ver el menu sin el anterior


    return 0;
}
