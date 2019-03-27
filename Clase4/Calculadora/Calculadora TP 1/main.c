#include <stdio.h>
#include <stdlib.h>
#include "pedirOperandos.h"
//#include "menuOpciones.h"
int main()
{
    //int opcion;
    /*int operando1;
    int operando2;
    operando1 = pedirOperandos("1. Ingresar 1er operando: \n");
    operando2 = pedirOperandos("2. Ingresar 2do operando: \n");

    printf("operando1: %d \n" , operando1);
    printf("operando2: %d \n" , operando2);*/
    int opcion;
    int operando1;
    int operando2;
    int suma;
    int resta;
    int division;
    int multiplicacion;
    int factorial1;
    int factorial2;
    char seguir = 's';
    do{
        printf("1.Ingresar 1er operando (A=x) \n ");
        printf("2.Ingresar 2do operando (B=y) \n ");
        printf("3.Calcular todas las operaciones \n ");
        printf("4.Informar resultados \n");
        printf("5.Salir \n ");

        opcion = pedirOperandos("Ingrese una opcion por favor: ");

        switch(opcion)
        {
            case 1:
                //funcion pedir numero
                operando1 = pedirOperandos("1.Ingresar 1er operando: ");
                break;
            case 2:
                //funcion pedir numero
                operando2 = pedirOperandos("2.Ingresar 2do operando: ");
                break;
            case 3:
                //funcion calcular todas las operaciones
                printf("Entro case 3, calcular todas la operaciones. \n ");
                suma = sumaOperandos(operando1 , operando2);
                resta = restaOperandos(operando1 , operando2);
                division = divisionOperandos(operando1 , operando2);
                multiplicacion = multiplicacionOperandos(operando1 , operando2);
                factorial1 = factorialOperandos(operando1);
                factorial2 = factorialOperandos(operando2);
                break;
            case 4:
                //funcion mostrar todos los resultados
                //printf("Entro case 4, mostrar todos los resultados. \n ");
                printf("%d \n" , suma);
                printf("%d \n" , resta);
                printf("%d \n" , division);
                printf("%d \n" , multiplicacion);
                printf("%d \n" , factorial1);
                printf("%d \n" , factorial2);
                break;
            case 5:
                //salir del programa
                printf("Entro case 5, salir del programa. \n ");
                return 0;
                break;
            default:
                //no ingreso una opcion valida, error.
                printf("Error! No ha ingresado una opcion correcta. \n ");
                break;
        }
        system("pause");
        system("cls");
    }while(seguir == 's');
    return 0;
}
