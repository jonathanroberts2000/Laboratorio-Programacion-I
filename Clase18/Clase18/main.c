#include <stdio.h>
#include <stdlib.h>


int main()
{
    /*FILE* miArchivo;
    char nombre[20] = "Jonathan";
    miArchivo = fopen("D:\\misdatos.txt", "w");
    if(miArchivo != NULL)
    {
        fprintf(miArchivo,"Su nombre es: \n%s" ,nombre);//funciona igual q un printf()
    }else
    {
        printf("No existe el archivo!\n");
    }
    fclose(miArchivo);*/
    FILE* miArchivo;
    char nombre[20];
    miArchivo = fopen("D:\\misdatos.txt", "r");
    while(!feof(miArchivo))
    {
        fgets(nombre, 30, miArchivo);
        printf("%s", nombre);
    }
    //fgets(nombre, 30, miArchivo);
    //fgets(nombre, 30, miArchivo);
    fclose(miArchivo);
    //fgets lee la primer linea
    return 0;
}
