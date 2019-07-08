typedef struct{
    int id;
    char nombre[128];
    char empleo[128];
    int edad;
    int horasTrabajadas;
    float sueldo;
}eEmpleado;

/** \brief Constructor en memoria dinamica de un empleado
 *
 * \return eEmpleado* Retorna el puntero a la direccion de memoria con espacio para almacenar un empleado
 *
 */
eEmpleado* employee_new();/*LISTO Y USADO...*/

/** \brief Genera un nuevo empleado y pasa todos los datos recibidos como cadenas al tipo de dato correspondiente
 *
 * \param idStr char* Puntero a la cadena que representa el id
 * \param nombreStr char* Puntero a la cadena que representa el nombre
 * \param empleoStr char* Puntero a la cadena que representa el empleo
 * \param edadStr char* Puntero a la cadena que representa la edad
 * \param horasTrabajadasStr char* Puntero a la cadena que representa la cantidad de horas trabajadas
 * \return eEmpleado* Retorna el puntero a un empleado con los datos cargados correctamente a su tipo de dato
 *
 */
eEmpleado* employee_newParametros(char* idStr, char* nombreStr, char* empleoStr, char* edadStr, char* horasTrabajadasStr);/*LISTO Y USADO...*/

/** \brief Setea el id de un empleado
 *
 * \param this eEmpleado* Puntero a un empleado
 * \param id int Id a ser cargado del empleado
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int employee_setId(eEmpleado* this, int id);/*LISTO Y USADO...*/

/** \brief Trae el id de un empleado
 *
 * \param this eEmpleado* Puntero a un empleado
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int employee_getId(eEmpleado* this);/*LISTO Y USADO...*/

/** \brief Setea el nombre de un empleado
 *
 * \param this eEmpleado* Puntero a un empleado
 * \param nombre char* Puntero al nombre del empleado a ser cargado
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int employee_setNombre(eEmpleado* this, char* nombre);/*LISTO Y USADO...*/

/** \brief Trae el nombre de un empleado
 *
 * \param this eEmpleado* Puntero a un empleado
 * \return char* Retorna el puntero a la cadena del nombre del empleado
 *
 */
char* employee_getNombre(eEmpleado* this);/*LISTO Y USADO...*/

/** \brief Setea el empleo de un empleado
 *
 * \param this eEmpleado* Puntero a un empleado
 * \param empleo char* Puntero a la cadena del empleo de un empleado
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int employee_setEmpleo(eEmpleado* this, char* empleo);/*LISTO Y USADO...*/

/** \brief Trae el empleo de un empleado
 *
 * \param this eEmpleado* Puntero a un empleado
 * \return char* Retorna el puntero a la cadena del empleo del empleado
 *
 */
char* employee_getEmpleo(eEmpleado* this);/*LISTO Y USADO...*/

/** \brief Setea la cantidad de horas trabajadas de un empleado
 *
 * \param this eEmpleado* Puntero a un empleado
 * \param horasTrabajadas int Cantidad de horas trabajadas a ser cargadas de un empleado
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int employee_setHorasTrabajadas(eEmpleado* this, int horasTrabajadas);/*LISTO Y USADO...*/

/** \brief Trae la cantidad de horas trabajadas por un empleado
 *
 * \param this eEmpleado* Puntero a un empleado
 * \return int Retorna la cantidad de horas trabajadas por un empleado
 *
 */
int employee_getHorasTrabajadas(eEmpleado* this);/*LISTO Y USADO...*/

/** \brief Setea la edad de un empleado
 *
 * \param this eEmpleado* Puntero a un empleado
 * \param edad int Edad a ser cargada del empleado
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int employee_setEdad(eEmpleado* this, int edad);/*LISTO Y USADO...*/

/** \brief Trae la edad de un empleado
 *
 * \param this eEmpleado* Puntero a un empleado
 * \return int Retorna la edad de un empleado
 *
 */
int employee_getEdad(eEmpleado* this);/*LISTO Y USADO...*/

/** \brief Setea el sueldo de un empleado
 *
 * \param this eEmpleado* Puntero a un empleado
 * \param sueldo float Sueldo a ser cargado del empleado
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int employee_setSueldo(eEmpleado* this, float sueldo);/*LISTO Y USADO...*/

/** \brief Trae el sueldo de un empleado
 *
 * \param this eEmpleado* Puntero a un empleado
 * \return float Retorna el sueldo de un empleado
 *
 */
float employee_getSueldo(eEmpleado* this);/*LISTO Y USADO...*/

/** \brief Compara el nombre de dos empleados alfabeticamente
 *
 * \param this1 eEmpleado* Puntero a un empleado
 * \param this2 eEmpleado* Puntero a otro empleado
 * \return int Retornara -1, 0 o 1 en base a la comparacion que realice de las cadenas
 *
 */
int employee_compareByName(eEmpleado* this1, eEmpleado* this2);/*LISTO Y USADO...*/

/** \brief Realiza el mapeo del sueldo de todos los empleados contenidos en la lista
 *
 * \param this eEmpleado* Puntero a un empleado
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int laQueMapea(eEmpleado* this);/*LISTO Y USADO...*/

/** \brief Realiza el filtro de los empleados por los criterios explicitos dentro de la implementacion de la funcion
 *
 * \param this eEmpleado* Puntero a un empleado
 * \return int Retorna 1 si el empleado cumple con las especificaciones de los criterios, caso contrario retornara -1
 *
 */
int laQuefiltra(eEmpleado* this);/*LISTO Y USADO...*/







