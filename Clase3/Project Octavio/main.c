#include <stdio.h>
#include <stdlib.h>

int pedirNota(void);
float sacarPromedio(int suma, int cantidad);
int aprobarMaterias(int notaMinima, int nota);
void ejercicioUno(void);
int main()
{
    int datoRecibido = pedirNota();
    float promedio = sacarPromedio(15 , 2);
    int valorUno = aprobarMaterias(6 , 2); //0
    int valorDos = aprobarMaterias(6 , 8); //1
    printf("La nota ingresada fue %d \n" , datoRecibido);
    printf("El promedio es: %f \n" , promedio);
    printf("Valor Uno %d \n" , valorUno);
    printf("Valor Dos %d \n" , valorDos);
    ejercicioUno();
}
int pedirNota(void)
{
    int nota;
    do{
        printf("Ingrese un numero entre 0 y 10: \n");
        scanf("%d" , &nota);
    }while(nota > 10 || nota < 0);
    return nota;
}
float sacarPromedio(int suma, int cantidad)
{
    float promedio;
    promedio = (float)suma / cantidad;

    return promedio;
}
int aprobarMaterias(int notaMinima , int nota)
{
    if(nota <= notaMinima){
        return 0;
    }else{
        return 1;
    }
}
void ejercicioUno(void)
{
    int i;
    int nota;
    int cantAprobados = 0;
    int cantDesaprobados = 0;
    int sumaAprobados = 0;
    int sumaDesaprobados = 0;
    float promedioAprobados;
    float promedioDesaprobados;
    for(i = 0; i < 5; i++){
        nota = pedirNota();
        if(aprobarMaterias(6 , nota)){
                cantAprobados++;
                sumaAprobados = sumaAprobados + nota;
           }else{
                cantDesaprobados++;
                sumaDesaprobados = sumaDesaprobados + nota;
           }
    }
    promedioAprobados = sacarPromedio(sumaAprobados , cantAprobados);
    promedioDesaprobados = sacarPromedio(sumaDesaprobados , cantDesaprobados);

    printf("\n La cantidad de aprobados es: %d \n" , cantAprobados);
    printf("\n El promedio de aprobados es: %f \n" , promedioAprobados);
    printf("\n El promedio de los no aprobados es: %f \n" , promedioDesaprobados);
}
