#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

/** \brief Constructor en memoria dinamica de un empleado
 *
 * \return Employee* Retorna el puntero a la direccion de memoria con espacio para almacenar un empleado
 *
 */
Employee* employee_new();
/** \brief Carga los datos de los empleados que estan en modo texto al tipo de dato correspondiente
 *
 * \param idStr char* Recibe el id como cadena
 * \param nombreStr char* Recibe el nombre como una cadena
 * \param horasTrabajadasStr char* Recibe las horas trabajadas como una cadena
 * \param sueldoStr char* Recibe el sueldo como una cadena
 * \return Employee* Retorna el puntero al tipo de dato Employee con los datos cargados correctamente seteados
 *
 */
Employee* employee_newParametros(char* idStr, char* nombreStr, char* horasTrabajadasStr, char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this, int id);
int employee_getId(Employee* this, int* id);

int employee_setNombre(Employee* this, char* nombre);
int employee_getNombre(Employee* this, char* nombre);

int employee_setHorasTrabajadas(Employee* this, int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas);

int employee_setSueldo(Employee* this, int sueldo);
int employee_getSueldo(Employee* this, int* sueldo);

int employee_compareByName(Employee*, Employee*);
#endif // employee_H_INCLUDED
