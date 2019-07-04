typedef struct{
    int id;
    char nombre[128];
    char empleo[128];
    int edad;
    int horasTrabajadas;
    int sueldo;
}eEmpleado;

/** \brief Constructor en memoria dinamica de un empleado
 *
 * \return Employee* Retorna el puntero a la direccion de memoria con espacio para almacenar un empleado
 *
 */
eEmpleado* employee_new();
/** \brief Carga los datos de los empleados que estan en modo texto al tipo de dato correspondiente
 *
 * \param idStr char* Recibe el id como cadena
 * \param nombreStr char* Recibe el nombre como una cadena
 * \param horasTrabajadasStr char* Recibe las horas trabajadas como una cadena
 * \param sueldoStr char* Recibe el sueldo como una cadena
 * \return Employee* Retorna el puntero al tipo de dato Employee con los datos cargados correctamente seteados
 *
 */
eEmpleado* employee_newParametros(char* idStr, char* nombreStr, char* empleo, char* horasTrabajadasStr, char* sueldoStr);
/** \brief Setea el Id de un empleado
 *
 * \param this Employee* Puntero al empleado
 * \param id int Id a cargar del empleado
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int employee_setId(eEmpleado* this, int id);
/** \brief Trae el Id de un empleado
 *
 * \param this Employee* Puntero al empleado
 * \param id int* Puntero al Id
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int employee_getId(eEmpleado* this);
/** \brief Setea el nombre de un empleado
 *
 * \param this Employee* Puntero al empleado
 * \param nombre char* Puntero del nombre a cargar
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int employee_setNombre(eEmpleado* this, char* nombre);
/** \brief Trae el nombre de un empleado
 *
 * \param this Employee* Puntero al empleado
 * \param nombre char* Puntero al nombre
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
char* employee_getNombre(eEmpleado* this);
/** \brief Setea la cantidad de horas trabajadas de un empleado
 *
 * \param this Employee* Puntero al empleado
 * \param horasTrabajadas int Cantidad de horas trabajadas a cargar del empleado
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int employee_setHorasTrabajadas(eEmpleado* this, int horasTrabajadas);
/** \brief Trae la cantidad de horas trabajadas de un empleado
 *
 * \param this Employee* Puntero al empleado
 * \param horasTrabajadas int* Puntero a la cantidad de horas trabajadas
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int employee_getHorasTrabajadas(eEmpleado* this);
/** \brief Setea el sueldo de un empleado
 *
 * \param this Employee* Puntero al empleado
 * \param sueldo int Sueldo a cargar del empleado
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int employee_setSueldo(eEmpleado* this, int sueldo);
/** \brief Trae el sueldo de un empleado
 *
 * \param this Employee* Puntero al empleado
 * \param sueldo int* Puntero al sueldo
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int employee_getSueldo(eEmpleado* this);
/** \brief Compara los empleados por orden alfabetico
 *
 * \param Employee* Puntero a un empleado
 * \param Employee* Puntero a otro empleado
 * \return int Retorna el entero en base a la comparacion realizada de los empleados
 *
 */
int employee_compareByName(eEmpleado*, eEmpleado*);

int employee_setEdad(eEmpleado* this, int edad);
int employee_getEdad(eEmpleado* this);
int employee_setEmpleo(eEmpleado* this, char* empleo);
char* employee_getEmpleo(eEmpleado* this);
int laQueMapea(eEmpleado* unEmpleado);
int laQuefiltra(eEmpleado*);
