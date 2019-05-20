#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bPointers.h"
int getInt(int* inputInt, char message[], char eMessage[], int lowLimit, int highLimit)
{
    if(inputInt != NULL)
    {
        printf("%s", message);
        scanf("%d", inputInt);
        while(*inputInt < lowLimit || *inputInt > highLimit)
        {
            return 2;
        }
        return 0;
    }else
    {
        printf("%s \n", eMessage);
        return 1;
    }
}

int getFloat(float* inputFloat, char message[], char eMessage[], float lowLimit, float highLimit)
{
    if(inputFloat != NULL){
        printf("%s", message);
        scanf("%f", inputFloat);
        while(*inputFloat < lowLimit || *inputFloat > highLimit)
        {
            return 2;
        }
        return 0;
    }else
    {
        printf("%s \n", eMessage);
        return 1;
    }
}

int getChar(char* inputChar, char message[], char eMessage[], char limit_1, char limit_2)
{
    if(inputChar != NULL)
    {
        printf("%s", message);
        fflush(stdin);
        scanf("%c", inputChar);
        while(*inputChar != limit_1 && *inputChar != limit_2)
        {
            return 2;
        }
        return 0;
    }else
    {
        printf("%s", eMessage);
        return 1;
    }
}

int getString(char* inputString, char message[], char eMessage[], int limit)
{
    int estado = 0;
    if(inputString != NULL)
    {
        printf("%s", message);
        fflush(stdin);
        scanf("%s", inputString);
        while(strlen(inputString) > limit)
        {
            estado = getString(inputString, message, eMessage, limit);
            return estado;
        }
        return estado;
    }else
    {
        printf("%s", eMessage);
        estado = 1;
        return estado;
    }
}

int loadVector(int* inputArray, char message[], char eMessage[], int tam)
{
    int i;
    if(inputArray != NULL)
    {
        for(i=0;i<tam;i++)
        {
            printf("%s", message);
            scanf("%d", (inputArray+i));
            while(inputArray[i] == 0)
            {
                printf("Reingrese un numero distinto de 0: ");
                scanf("%d", (inputArray+i));
            }
        }
        return 0;
    }else
    {
        printf("%s", eMessage);
        return 1;
    }
}

int showVector(int* inputArray, char message[], char eMessage[], int tam)
{
    int i;
    if(inputArray != NULL)
    {
        printf("%s\n", message);
        for(i=0;i<tam;i++)
        {
            if(*(inputArray+i) != 0)
            {
                printf("%d\n", *(inputArray+i));
            }

        }
        return 0;
    }else
    {
        printf("%s", eMessage);
        return 1;
    }
}

int searchMax(int* inputArray, char message[], char eMessage[], int tam)
{
    int i;
    int flag = 0;
    int numMax;
    if(inputArray != NULL)
    {
        for(i=0;i<tam;i++)
        {
            if(*(inputArray+i)> numMax || flag == 0)
            {
                numMax = inputArray[i];
                flag = 1;
            }
        }
        printf("El numero maximo es: %d\n", numMax);
        return 0;
    }else
    {
        printf("%s", eMessage);
        return 1;
    }
}

int searchMin(int* inputArray, char message[], char eMessage[], int tam)
{
    int i;
    int flag = 0;
    int numMin;
    if(inputArray != NULL)
    {
        for(i=0;i<tam;i++)
        {
            if(*(inputArray+i) < numMin || flag == 0)
            {
                numMin = inputArray[i];
                flag = 1;
            }
        }
        printf("El numero minimo es: %d\n", numMin);
        return 0;
    }else
    {
        printf("%s", eMessage);
        return 1;
    }
}

int sortArray(int* inputArray, char message[], char eMessage[], int tam)
{
    int i;
    int j;
    int aux;
    int status;
    if(inputArray != NULL)
    {
        for(i=0;i<tam-1;i++)
        {
            for(j=i+1;j<tam;j++)
            {
                if(inputArray[i] > inputArray[j])
                {
                    aux = inputArray[i];
                    inputArray[i] = inputArray[j];
                    inputArray[j] = aux;
                }
            }
        }
        status = showVector(inputArray, "El vector ordenado es: ", "No se pudo mostrar el vector!", tam);
        if(status == 0)
        {
            printf("Orden exitoso!");
        }
        return 0;
    }else
    {
        printf("%s", eMessage);
        return 1;
    }
}

int deleteNum(int* inputArray, char message[], char eMessage[], int tam, int numeric_limits)
{
    int i;
    int num;
    if(inputArray != NULL)
    {
        printf("Ingrese el numero a buscar: ");
        scanf("%d", &num);
        for(i=0;i<tam;i++)
        {
            if(inputArray[i] == num)
            {
                inputArray[i] = 0;
                break;
            }
        }
        //printf("El numero se encuentra en la posicion: %d", num);
        return 0;
    }else
    {
        printf("%s", eMessage);
        return 1;
    }
}

