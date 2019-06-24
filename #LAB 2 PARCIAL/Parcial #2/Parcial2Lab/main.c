#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "eEmpleado.h"
#include "pInput.h"
#include "Controller.h"
#define PATHT "datos.csv"

int main()
{
    int option;
    char seguir = 's';
    int i;
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* newlist;
    do{
        get_Int(&option, "1. Cargar los datos de los empleados desde el archivo data.csv (modo texto)\n2. Listar empleados\n3. Calcular sueldos\n4. Listar empleados con sueldos\n5. Salir\nIngrese una opcion: ");
        switch(option)
        {
            case 1:
                pointer_error(controller_loadFromText(PATHT, listaEmpleados), "\nNo se ha podido completar la operacion solicitada\n", "\nDatos cargados correctamente\n", "", "");
                break;
            case 2:
                pointer_error(controller_ListEmployee(listaEmpleados), "\nNo se ha podido listar los empleados\n", "\nEl listado ha sido mostrado correctamente\n", "", "");
                //pointer_error(controller_addEmployee(listaEmpleados), "\nNo se ha podido dar de alta al empleado solicitado\n", "\nEmpleado correctamente ingresado\n", "", "");
                break;
            case 3:
                pointer_error(controller_sueldoAllEmployee(listaEmpleados), "\nNo se ha podido completar la operacion solicitada\n", "\nEl calculo de los sueldos se realizo correctamente\n", "", "");
                //pointer_error(controller_editEmployee(listaEmpleados), "\nNo se ha podido modificar el empleado correctamente\n", "\nSe ha modificado el empleado correctamente\n", "\nEl id ingresado no corresponde a ningun empleado en el sistema\n", "");
                break;
            case 4:
                pointer_error(controller_ListEmployeeSueldos(listaEmpleados), "\nNo se ha podido listar los empleados\n", "\nEl listado ha sido mostrado correctamente\n", "", "");
                break;
            case 5:
                //pointer_error(controller_ListEmployee(listaEmpleados), "\nNo se ha podido listar los empleados\n", "\nEl listado ha sido mostrado correctamente\n", "", "");
                newlist=ll_filter(listaEmpleados, &laQuefiltra);
                controller_ListEmployee(newlist);
                break;
            /*case 6:
                pointer_error(controller_sortEmployee(listaEmpleados), "\nNo se ha podido ordenar los empleados correctamente\n", "\nOrdenamiento alfabetico de empleados correctamente ejecutado\n", "", "");
                break;
            case 7:
                pointer_error(controller_saveAsText(PATHT, listaEmpleados), "\nNo se ha podido guardar los cambios en el archivo data.csv (modo texto)\n", "\nSe han guardado correctamente todos los cambios en el archivo data.csv (modo texto)\n", "", "\nSe ha cancelado el guardado de los cambios\n");
                break;*/
            case 6:
                ll_deleteLinkedList(listaEmpleados);
                puts("\nLa lista de empleados ha sido eliminada correctamente...saliendo del programa!\n");
                system("pause");
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
