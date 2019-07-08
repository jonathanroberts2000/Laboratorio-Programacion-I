#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "eEmpleado.h"
#include "pInput.h"
#include "Controller.h"
#define PATHT "datos.csv"
#define PATHTR "resultados.csv"

int main()
{
    int option;
    char seguir = 's';
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* newList;
    do{
        get_Int(&option, "1. Cargar los datos de los empleados desde el archivo datos.csv (modo texto)\n2. Listar empleados\n3. Calcular sueldos\n4. Listar empleados con sueldos\n5. Empleados que sean programadores y mayores de 20 años\n6. Guardar en el archivo resultados.csv los resultados de la busqueda\n7. Salir\nIngrese una opcion: ");
        switch(option)
        {
            case 1:
                /*LISTO...*/pointer_error(controller_loadFromText(PATHT, listaEmpleados), "\nNo se ha podido completar la operacion solicitada\n", "\nDatos cargados correctamente\n", "", "");
                break;
            case 2:
                /*LISTO...*/pointer_error(controller_ListEmployee(listaEmpleados), "\nNo se ha podido listar los empleados\n", "\nEl listado ha sido mostrado correctamente\n", "", "");
                break;
            case 3:
                /*LISTO...*/pointer_error(controller_sueldoAllEmployee(listaEmpleados), "\nNo se ha podido calcular el sueldo de todos los empleados\n", "\nEl calculo de los sueldos se realizo correctamente\n", "", "");
                break;
            case 4:
                /*LISTO...*/pointer_error(controller_ListEmployeeSueldos(listaEmpleados), "\nNo se ha podido listar los empleados\n", "\nEl listado ha sido mostrado correctamente\n", "", "");
                break;
            case 5:
                /*LISTO...*/newList = controller_ListEmployeeFilter(listaEmpleados);
                /*LISTO...*/pointer_error(controller_ListEmployeeSueldos(newList), "\nNo se ha podido listar los empleados filtrados\n", "\nEl listado ha sido mostrado correctamente\n", "", "");
                break;
            case 6:
                /*LISTO...*/pointer_error(controller_saveAsText(PATHTR, newList), "\nNo se ha podido guardar los empleados filtrados en el archivo resultados.csv (modo texto)\n", "Se han guardado los empleados filtrados en el archivo resultados.csv (modo texto)\n", "", "\nSe ha cancelado el guardado de los empleados filtrados\n");
                break;
            case 7:
                ll_deleteLinkedList(listaEmpleados);
                ll_deleteLinkedList(newList);
                puts("\nLos listados han sido borrados correctamente...Saliendo");
                return 0;
                break;
            default:
                puts("Error! No ha ingresado una opcion correcta. Por favor reingrese...");
                break;
        system("pause");
        system("cls");
        fflush(stdin);
        }
    }while(seguir == 's');
    return 0;
}
