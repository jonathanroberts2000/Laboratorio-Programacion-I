
#include <stdlib.h>
#include "Empleado.h"

#define T 10


int menuDeOpciones(char[]);

/*
Informes:

1- EL/LOS Empleados con mayor sueldo.
2- Cantidad de empleados que se llamen carlos y ganen mas de 20000
*/

int main()
{

    int opcion;

    eEmpleado lista[T];
    inicializarEmpleados(lista,T);

    eSector sectores[3] = {{0,"Contabilidad",100},{1,"Sistemas",200},{2, "RRHH", 150}};




    hardcodearDatosEmpleados(lista,6, sectores);
    do
    {
        opcion = menuDeOpciones("1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Informar\n10.Salir\nElija una opcion: ");
        switch(opcion)
        {
            case 1:
                cargarEmpleado(lista,  T, sectores,3);

            break;
            case 2:
                borrarEmpleado(lista, T, 3);
                break;
            case 3:

                modificar(lista, T, 3);
            break;

            case 4:
                mostrarListaEmpleados(lista, T, sectores, 3);
                break;
            case 5:

                mostrarEmpleadosSueldoMaximo(lista,T);
                printf("La cantidad de carlos es: %d\n", contarCarlos(lista,T));
                //mostrarListaSectores(sectores, 3);
                mostrarListaEmpleadosPorSector(lista,T,sectores,3);
                totalSueldosPorSector(sectores,3,lista,T);
                break;
        }
    }while(opcion!=10);



    //inicializarEmpleados(lista, T);




    return 0;
}

int menuDeOpciones(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);

    return opcion;
}
