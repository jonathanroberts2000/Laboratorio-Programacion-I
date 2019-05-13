
/** \brief Pide al usuario un numero entero
 *
 * \param mensaje[] char Mensaje que le indica al usuario que ingresar
 * \return int Retorna el numero ingresado por el usuario
 *
 */
int pedirEntero(char mensaje[]);
/** \brief Valida que el numero ingresado sea un numero positivo
 *
 * \param num1 int El numero ingresado previamente por el usuario
 * \return int Retorna el numero entero validado
 *
 */
int validacionDeEnterosPositivos(int num1);
/** \brief Genera un numero random mayor a 1000
 *
 * \param void
 * \return int Retorna un numero random mayor a 1000
 *
 */
int generarNumeroRandom(void);
/** \brief Solicita el ingreso de una cadena de caracteres al usuario
 *
 * \param mensaje[] char Mensaje que le indica que ingresar al usuario
 * \param cadena[] char Array de tipo char donde se almacenara la cadena ingresada por el usuario
 * \param tamCadena int Tamaño del array
 * \return void
 *
 */
void pedirCadena(char mensaje[], char cadena[], int tamCadena);
/** \brief Validar el correcto ingreso del tamaño de la cadena
 *
 * \param mensajeError[] char Mensaje de error que vuelve a solicitar el ingreso de la cadena de ser necesario
 * \param cadena[] char Array de tipo char ingresado previamente por el usuario
 * \param tamCadena int Tamaño del array
 * \return void
 *
 */
void validarCadena(char mensajeError[], char cadena[], int tamCadena);
/** \brief Valida el ingreso de un numero entre un minimo y un maximo
 *
 * \param int Numero ingresado por el usuario
 * \param int Numero minimo de limite
 * \param int Numero maximo de limite
 * \return int Retorna el numero ya validado
 *
 */
int validarRangoPositivos(int,int,int);
