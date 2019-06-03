#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/


int main()
{
    int option;
    char seguir = 's';
    LinkedList* listaEmpleados = ll_newLinkedList();


    Employee* aux1;//creado para el case 3
    Employee* aux;//creadp para el case 2
    int i;


    do{
        printf("Ingrese opcion: ");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                controller_loadFromText("data.csv", listaEmpleados);
                break;
            case 2:
                controller_loadFromBinary("data", listaEmpleados);
                //aux = ll_get(listaEmpleados, 52);
                //printf("%d--%s--%d--%d", aux->id, aux->nombre, aux->horasTrabajadas, aux->sueldo);
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                for(i=0;i<ll_len(listaEmpleados);i++)
                {
                    aux1 = ll_get(listaEmpleados, i);
                    printf("%d--%s--%d--%d\n", aux1->id, aux1->nombre, aux1->horasTrabajadas, aux1->sueldo);
                }
                break;
            case 4:

                break;
            case 5:

                break;
            case 6:

                break;
            case 7:

                break;
            case 8:

                break;
            case 9:

                break;
            case 10:
                ll_deleteLinkedList(listaEmpleados);
                return 0;
                break;
            default:

                break;
        }
    }while(seguir == 's');
    return 0;
}

