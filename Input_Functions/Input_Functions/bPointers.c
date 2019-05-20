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
            scanf("%d", inputArray+i);
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
            printf("%d\n", *inputArray+i);
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
    if(inputArray != NULL)
    {
        for(i=0;i<tam;i++)
        {

        }
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
    if(inputArray != NULL)
    {
        for(i=0;i<tam;i++)
        {

        }
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
    if(inputArray != NULL)
    {
        for(i=0;i<tam;i++)
        {

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
    if(inputArray != NULL)
    {
        for(i=0;i<tam;i++)
        {

        }
        return 0;
    }else
    {
        printf("%s", eMessage);
        return 1;
    }
}

