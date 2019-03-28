#include <stdio.h>
#include <stdlib.h>
#include "pedirOperandos.h"
#include "menuOpciones.h"
int main()
{
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
                operando1 = pedirOperandos("1.Ingresar 1er operando: ");
                break;
            case 2:
                operando2 = pedirOperandos("2.Ingresar 2do operando: ");
                break;
            case 3:
                printf("Calculando las operaciones solicitadas... \n ");
                suma = sumaOperandos(operando1 , operando2);
                resta = restaOperandos(operando1 , operando2);
                division = divisionOperandos(operando1 , operando2);
                multiplicacion = multiplicacionOperandos(operando1 , operando2);
                factorial1 = factorialOperandos(operando1);
                factorial2 = factorialOperandos(operando2);
                break;
            case 4:
                //printf("El resultado de A+B es: %d \n" , suma);
                mostrarResultados("El resultado de A+B es: \n" , suma);
                //printf("El resultado de A-B es: %d \n" , resta);
                mostrarResultados("El resultado de A-B es: \n" , resta);
                //printf("El resultado de A/B es: %d \n" , division);
                mostrarResultados("El resultado de A/B es: \n" , division);
                //printf("El resultado de A*B es: %d \n" , multiplicacion);
                mostrarResultados("El resultado de A*B es: \n" , multiplicacion);
                //printf("El factorial de A es: %d \n" , factorial1);
                mostrarResultados("El factorial de A es: \n" , factorial1);
                //printf("El factorial de B es: %d \n" , factorial2);
                mostrarResultados("El factorial de B es: \n" , factorial2);
                break;
            case 5:
                printf("Entro case 5, salir del programa. \n ");
                return 0;
                break;
            default:
                printf("Error! No ha ingresado una opcion correcta. \n ");
                break;
        }
        system("pause");
        system("cls");
    }while(seguir == 's');
    return 0;
}
