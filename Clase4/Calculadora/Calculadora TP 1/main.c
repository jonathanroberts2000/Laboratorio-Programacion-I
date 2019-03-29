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
    float division;
    int multiplicacion;
    int factorial1;
    int factorial2;
    int flagX = 0;
    int flagY = 0;
    int flagCero = 0;
    char seguir = 's';
    do{
        if(flagX == 0)
        {
             printf("1.Ingresar 1er operando (A=x) \n ");
        }else
        {
            printf("1.Ingresar 1er operando (A=%d) \n " , operando1);
        }
        if(flagY == 0)
        {
            printf("2.Ingresar 2do operando (B=y) \n ");
        }else
        {
            printf("2.Ingresar 2do operando (B=%d) \n " , operando2);
        }

        printf("3.Calcular todas las operaciones \n ");
        printf("4.Informar resultados \n");
        printf("5.Salir \n ");

        opcion = pedirOperandos("Ingrese una opcion por favor: ");

        switch(opcion)
        {
            case 1:
                operando1 = pedirOperandos("1.Ingresar 1er operando: ");
                flagX = 1;
                break;
            case 2:
                operando2 = pedirOperandos("2.Ingresar 2do operando: ");
                if(operando2 == 0)
                {
                    flagCero = 1;
                }
                flagY = 1;
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
                printf("El resultado de A+B es: %d \n" , suma);
                printf("El resultado de A-B es: %d \n" , resta);
                if(flagCero == 1)
                {
                    printf("No es posible dividir por cero \n");
                }else
                {
                    printf("El resultado de A/B es: %f \n" , division);
                }
                printf("El resultado de A*B es: %d \n" , multiplicacion);
                printf("El factorial de A es: %d \n" , factorial1);
                printf("El factorial de B es: %d \n" , factorial2);
                break;
            case 5:
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
