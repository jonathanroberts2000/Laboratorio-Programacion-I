/** \brief Controla la carga del archivo en modo texto
 *
 * \param path char* Ruta del archivo
 * \param pArrayList LinkedList* Puntero a la lista de empleados
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayList);

/** \brief Controla la carga del archivo en modo binario
 *
 * \param path char* Ruta del archivo
 * \param pArrayList LinkedList* Puntero a la lista de empleados
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornata 0
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayList);

/** \brief Controla la carga de un empleado a la lista
 *
 * \param pArrayList LinkedList* Puntero a la lista de empleados
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int controller_addEntidad(LinkedList* pArrayList);

/** \brief Controla la edicion de los datos de un empleado
 *
 * \param pArrayList LinkedList* Puntero a la lista de empleados
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, si no se encuentra al empleado retornara 2 y retornara 0 si es NULL el puntero a la lista
 *
 */
int controller_editEntidad(LinkedList* pArrayList);

/** \brief Controla la baja de un empleado en la lista
 *
 * \param pArrayList LinkedList* Puntero a la lista de empleados
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, si se cancela la operacion retornara 2, si el id no existe en la lista retornara 3 y retornara 0 si es NULL el puntero a la lista
 *
 */
int controller_removeEntidad(LinkedList* pArrayList);

/** \brief Controla el listado de los empleados
 *
 * \param pArrayList LinkedList* Puntero a la lista de empleados
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int controller_ListEntidad(LinkedList* pArrayList);

/** \brief Controla el ordenamiento de los empleados por orden alfabetico
 *
 * \param pArrayList LinkedList* Puntero a la lista de empleados
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int controller_sortEntidad(LinkedList* pArrayList);

/** \brief Controla el guardado en modo texto de la lista de empleados tras los cambios hechos por el usuario
 *
 * \param path char* Ruta del archivo
 * \param pArrayList LinkedList* Puntero a la lista de empleados
 * \return int Retorna 1 en caso de haber completado la operacion correctamente, caso contrario retornara 0
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayList);
