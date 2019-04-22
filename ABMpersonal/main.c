#include <stdlib.h>
#include "Empleado.h"
#define T 6

int main()
{
    int opcion;
    eEmpleado lista[T];
    eSectores listaSector[T];
    inicializarEmpleados(lista,T);
    hardcodearDatosEmpleados(lista,T);
    hardcodearDatosSectores(listaSector,T);
    do
    {
        opcion = pedirOpcion("1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Informar\n6.Salir\nElija una opcion: ");
        switch(opcion)
        {
            case 1:
                cargarEmpleado(lista,  T);
                break;
            case 2:
                borrarDatos(lista, T, 3);
                break;
            case 3:
                modificarDatos(lista, T);
                break;
            case 4:
                mostrarListaEmpleados(lista, T);
                //mostrarListaSectores(listaSector, T);
                break;
            case 5:
                //el o los mayores sueldos y q se llame carlos y gane 20000
                buscarMaximoEmpleados(lista,T);
                printf("La cantidad de empleados que se llaman Carlos son: %d \n" ,buscarEmpleado(lista,T));
                break;
            case 6:
                return 0;
                break;
            default:
                opcion = pedirOpcion("Error! Por favor reingrese una opcion valida.");
                break;
        }
    }while(opcion!=6);

    return 0;
}
