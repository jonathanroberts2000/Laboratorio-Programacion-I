#include <stdio.h>
#include <stdlib.h>

/*int menuOpciones(char menuOpciones[])
{
    int opcion;

    int operando1;
    int operando2;

    char seguir = 's';
    do{
        printf("1. Ingresar 1er operando (A=x) \n ");
        printf("2. Ingresar 2do operando (B=y) \n ");
        printf("3. Calcular todas las operaciones \n ");
        printf("4. Informar resultados \n");
        printf("5. Salir \n ");

        opcion = pedirOperandos("Ingrese una opcion por favor: \n");

        switch(opcion)
        {
            case 1:
                //funcion pedir numero
                operando1 = pedirOperandos();
                return operando1;
                break;
            case 2:
                //funcion pedir numero
                operando2 = pedirOperandos();
                return operando2;
                break;
            case 3:
                //funcion calcular todas las operaciones
                break;
            case 4:
                //funcion mostrar todos los resultados
                break;
            case 5:
                //salir del programa
                break;
            default:
                //no ingreso una opcion valida, error.
                printf("Error! No ha ingresado una opcion correcta. \n ");
                break;
        }
        system("pause");
        system("cls");
    }while(seguir == 's');
    }*/
int sumaOperandos(int operando1, int operando2)
{
    int suma;

    suma = operando1 + operando2;
    return suma;
}
int restaOperandos(int operando1 , int operando2)
{
    int resta;

    resta = operando1 - operando2;
    return resta;
}
int divisionOperandos(int operando1 , int operando2)
{
    int division;

    division = operando1 / operando2;
    return division;
}
int multiplicacionOperandos(int operando1, int operando2)
{
    int multiplicacion;

    multiplicacion = operando1 * operando2;
    return multiplicacion;
}
int factorialOperandos(int numero)
{
    int factorial;
    if(numero == 0 || numero == 1)
    {
        factorial = 1;
    }else
    {
        factorial = numero * factorialOperandos(numero -1);
    }
    return factorial;
}


