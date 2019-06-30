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

/** \brief Valida el ingreso de un numero entre un minimo y un maximo
 *
 * \param int Numero ingresado por el usuario
 * \param int Numero minimo de limite
 * \param int Numero maximo de limite
 * \return int Retorna el numero ya validado
 *
 */
int validarRangoPositivos(int, int, int);

/** \brief Cargar el dia o mes o año de la fecha de estreno de una pelicula
 *
 * \param char[] Mensaje que le indica al usuario que debe ingresar
 * \param char[] Mensaje de error que le advierte al usuario que debe reingresar
 * \param int Limite minimo de numero que se puede ingresar
 * \param int Limite maximo de numero que se puede ingresar
 * \return int Retorna el numero ingresado y validado segun sus rangos
 *
 */
int cargarFechaEstreno(char[], char[], int, int);

/** \brief Pide un caracter al usario para la confirmacion o denegacion de una funcion
 *
 * \param char[] Mensaje que le indica al usuario que debe ingresar en caso afirmativo o negativo
 * \param char[] Mensaje de error que le advierte al usuario que debe reingresar en caso afirmativo o negativo
 * \return char Retorna el caracter ingresado y validado
 *
 */
char pedirCaracterConfirmacion(char[], char[]);

/** \brief Cargar el id de una entidad listada previamente
 *
 * \param char[] Menssje que le indica al usuario que debe ingresar
 * \param char[] Mensaje de error que le advierte al usuario que debe reingresar
 * \param int Limite minimo de indice que se puede ingresar
 * \param int Limite msximo de indice que se puede ingresar
 * \return int Retorna el numero ingresado y validado segun sus rangos maximo y minimo
 *
 */
int cargarValidarEntidad(char[], char[], int, int);

/** \brief Solicita el ingreso de una cadena de caracteres al usuario
 *
 * \param mensaje[] char Mensaje que le indica al usuario que debe ingresar
 * \param mensajeError[] char Mensaje de error que le advierte al usuario que debe reingresar
 * \param auxCadena[] char Variable auxiliar para validar
 * \param cadenaFinal[] char Variable final donde se guarda la cadena
 * \param tamCadena int Tamaño de la cadena
 * \return void
 *
 */
void pedirCadena(char mensaje[], char mensajeError[], char auxCadena[], char cadenaFinal[], int tamCadena);

/** \brief Validar el correcto ingreso del tamaño de la cadena
 *
 * \param mensajeError[] char Mensaje de error que le advierte al usuario que debe reingresar
 * \param auxCadena[] char Variable auxiliar para validad
 * \param cadenaFinal[] char Variable final donde se guarda la cadena
 * \param tamCadena int Tamaño de la cadena
 * \return void
 *
 */
void validarCadena(char mensajeError[], char auxCadena[], char cadenaFinal[], int tamCadena);
