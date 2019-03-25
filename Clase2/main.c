#include <stdio.h>
#include <stdlib.h>
//fflush funcion para vaciar el buffer
//fflush(stdin) va antes del scanf

int main()
{
    int numeros; //bien
    int contadorNumeros = 0; //bien
    int contadorPares = 0; //bien
    int contadorNegativos = 0; //bien
    int acumuladorPositivos = 0; //bien
    int acumuladorNegativos = 0; //bien
    int acumuladorNumeros = 0; //bien
    float promedioNegativos; //bien
    float promedioTotal; //bien
    int max; //bien
    int min; //bien
    int flag = 0; //bien
    int minimoPositivo = 0; //bien
    int maximoNegativo = 0; //bien
    int flagn = 0; //bien
    int flagp = 0; //bien
    int contadorRangoNumeros = 0; //bien
    char seguir; //bien


    do{
        printf("Ingrese un numero: ");
        fflush(stdin);
        scanf("%d" , &numeros);
        while(numeros == 0){
            printf("Error! Reingrese un numero distinto de 0: \n");
            fflush(stdin);
            scanf("%d" , &numeros);
        }

        contadorNumeros++;
        acumuladorNumeros = acumuladorNumeros + numeros;

        if(numeros % 2 == 0){
            contadorPares++;
        }

        if(numeros > 0){
            acumuladorPositivos = acumuladorPositivos + numeros;
        }else{
            acumuladorNegativos = acumuladorNegativos + numeros;
            contadorNegativos++;
        }

        if(numeros >= -10 && numeros <= 50){
            contadorRangoNumeros++;
        }
        if(numeros > max || flag == 0){
            max = numeros;
        }
        if(numeros < min || flag == 0){
            min = numeros;
            flag = 1;
        }
        if(numeros > minimoPositivo || flagp == 0){
            minimoPositivo = numeros;
            flagp = 1;
        }
        if(numeros < maximoNegativo || flagn == 0){
            maximoNegativo = numeros;
            flagn = 1;
        }

        printf("Desea seguir ingresando numeros? s/n \n");
        fflush(stdin);
        scanf("%c" , &seguir);
    }while(seguir == 's');

    promedioNegativos = (float)acumuladorNegativos / contadorNegativos;
    promedioTotal = (float)acumuladorNumeros / contadorNumeros;
    printf("A) La cantidad de numeros que ingreso es de: %d \n" , contadorNumeros);
    printf("B) La cantidad de numeros pares que ingreso es de: %d \n" , contadorPares);
    printf("C) La suma de todos los positivos es de: %d \n" , acumuladorPositivos);
    printf("D) El promedio de todos los negativos es de %f \n" , promedioNegativos);
    printf("E.1) El numero maximo ingresado es %d \n" , max);
    printf("E.2) El numero minimo ingresado es %d \n" , min);
    printf("F) El numero mas chico de los positivos es %d \n" , minimoPositivo);
    printf("G) El numero mas grande de los negativos es %d \n" , maximoNegativo);
    printf("H) La cantidad de numeros ingresados que se encuentren entre -10 y 50 son: %d \n" , contadorRangoNumeros);
    printf("I) El promedio total de todos los numeros ingresados es de: %f \n" , promedioTotal);
    system("pause");
    return 0;
}
