#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pInput.h"

int get_Int(int* pNum, char mUser[])
{
    int status = 0;
    if(pNum != NULL)
    {
        printf("%s", mUser);
        scanf("%d", pNum);
        status = 1;
    }
    return status;
}

int get_Float(float* pNum, char mUser[])
{
    int status = 0;
    if(pNum != NULL)
    {
        printf("%s", mUser);
        scanf("%f", pNum);
        status = 1;
    }
    return status;
}

int get_Char(char* pCarac, char mUser[])
{
    int status = 0;
    if(pCarac != NULL)
    {
        printf("%s", mUser);
        fflush(stdin);
        scanf("%c", pCarac);
        status = 1;
    }
    return status;
}

int get_String(char* pString, char mUser[])
{
    int status = 0;
    if(pString != NULL)
    {
        printf("%s", mUser);
        fflush(stdin);
        scanf("%s", pString);
        status = 1;
    }
    return status;
}

void pointer_error(int retorno, char null[], char exito[], char eCondicion[])
{
    if(retorno == 0)
    {
        printf("%s\n", null);
    }else if(retorno == 1)
    {
        printf("%s\n", exito);
    }else{
        printf("%s\n", eCondicion);
    }
}
