#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int numero;
    char letra;

} eDato;

int mostrarDatos(eDato*,int);
int ordenarDatos(eDato*,int);

int main()
{
    eDato muchosDatos[3]= {{1,'C'},{1,'B'},{1,'A'}};
    eDato* pUnDato=NULL;


    /*pUnDato=muchosDatos;
    if(ordenarDatos(pUnDato,3)==0)
    {
        printf("Puntero nulo");
    }
    if(mostrarDatos(pUnDato,3)==0)
    {
        printf("Puntero nulo");
    }*/

    //printf("%d---%c",pUnDato->numero,pUnDato->letra);//printf("%d---%c",(*pUnDato).numero,(*pUnDato).letra);



    return 0;
}

int mostrarDatos(eDato* pDato,int tam)
{
    int i;
    int estado=1;
    if(pDato!=NULL)
    {
        for(i=0; i<tam; i++)
        {
            printf("%d---%c\n",(pDato+i)->numero,(pDato+i)->letra);
        }
    }
    else
    {
        estado=0;
    }
    return estado;
}


int ordenarDatos(eDato* pDato,int tam)
{
    int i;
    int j;
    eDato datoAux;
    int estado=1;
    if(pDato!=NULL)
    {
        for(i=0; i<tam-1; i++)
        {
            for(j=i+1; j<tam; j++)
            {
                if(((pDato+i)->letra)>((pDato+j)->letra))
                {
                    datoAux=*(pDato+i);
                    *(pDato+i)=*(pDato+j);
                    *(pDato+j)=datoAux;
                }
            }
        }
    }
    else
    {
        estado=0;
    }


    return estado;
}
