#define LIBRE 0
#define OCUPADO 1

typedef struct{
    int dia;
    int mes;
    int anio;
}eFechaEstreno;

typedef struct{
    int idGenero;
    char genero[61];
}eGenero;

typedef struct{
    int idActor;
    char nombre[61];
    char paisOrigen[61];
}eActores;

typedef struct{
    char titulo[61];
    eFechaEstreno estreno;
    int idGenero;
    int idActor;
    int idPelicula;
    int estado;
}ePeliculas;

/** \brief Setear los 1000 espacios de memoria en estado LIBRE
 *
 * \param ePeliculas[] Array que contiene todas las peliculas
 * \param int tamaño del array
 * \return void
 *
 */
void inicializarLibre(ePeliculas[], int);
/** \brief Busca un espacio libre en memoria para almacenar las peliculas
 *
 * \param ePeliculas[] Array que contiene las peliculas
 * \param int Tamaño del array
 * \return int Retorna el indice del espacio libre para cargar una pelicula
 *
 */
int buscarLibre(ePeliculas[], int);
/** \brief Carga secuencial de las peliculas
 *
 * \param ePeliculas[] Array que contiene las peliculas
 * \param eGenero[] Array que contiene los generos
 * \param eActores[] Array que contiene los actores
 * \param int Tamaño del array de las peliculas
 * \return void
 *
 */
void cargarPelicula(ePeliculas[],eGenero[], eActores[], int);
/** \brief Cargar la fecha de estreno
 *
 * \param mensaje[] char Mensaje que indica al usuario que debe ingresar
 * \param fecha eFechaEstreno Estructura a cargar los datos
 * \return void
 *
 */
void cargarFechaEstreno(char mensaje[], eFechaEstreno fecha);
/** \brief Modifica los datos de las peliculas y los actores
 *
 * \param ePeliculas[] Array que contiene todas las peliculas
 * \param int Tamaño del array de las peliculas
 * \param eActores[] Array que contiene los actores
 * \return void
 *
 */
void modificarPeliculaPorId(ePeliculas[], int, eActores[]);
/** \brief Busca una pelicula por id
 *
 * \param ePeliculas[] Array que contiene todas las peliculas
 * \param int Tamaño del array de las peliculas
 * \param int Id de la pelicula a buscar
 * \return int Retorna el indice de la pelicula si la encontro, si no retorna -1
 *
 */
int buscarPeliculaPorId(ePeliculas[], int, int);
/** \brief Borra una pelicula del sistema
 *
 * \param ePeliculas[] Array que contiene todas las peliculas
 * \param int Tamaño del array de las peliculas
 * \return void
 *
 */
void borrarPeliculas(ePeliculas[], int);
/** \brief Busca un id en el sistema
 *
 * \param ePeliculas[] Array que contiene todas las peliculas
 * \param int Tamaño del array de las peliculas
 * \return int Retorna el indice donde se encuentra la pelicula
 *
 */
int buscarEntero(ePeliculas[], int);
/** \brief Carga datos pre ingresados en el sistema
 *
 * \param listaPeliculas[] ePeliculas Array que contiene todas las peliculas
 * \param listaGeneros[] eGenero Array que contiene todos los generos
 * \param listaActores[] eActores Array que contiene todos los actores
 * \return void
 *
 */
void hardcodearDatos(ePeliculas listaPeliculas[], eGenero listaGeneros[], eActores listaActores[]);
/** \brief Ordena a las peliculas por los años
 *
 * \param ePeliculas[] Array que contiene todas las peliculas
 * \param int Tamaño del array de las peliculas
 * \return void
 *
 */
void ordenarAnioPeliculas(ePeliculas[], int);
/** \brief Ordena a los actores por nacionalidad
 *
 * \param eActores[] Array que contiene todos los actores
 * \param int Tamaño del array de los actores
 * \return void
 *
 */
void ordenarNacionalidadActores(eActores[], int);
/** \brief Muestra la descripcion de un genero
 *
 * \param eGenero Estructura que contiene los generos
 * \return void
 *
 */
void mostrarGenero(eGenero);
/** \brief Muestra todos los generos que estan ingresados
 *
 * \param eGenero[] Array que contiene todos los generos
 * \param int Tamaño del array de los generos
 * \return void
 *
 */
void mostrarListaGeneros(eGenero[], int);
/** \brief Muestra el nombre y la nacionalidad de un actor
 *
 * \param eActores Estructura que contiene los datos de un actor
 * \return void
 *
 */
void mostrarActor(eActores);
/** \brief Muestra todos los actores que estan ingresados
 *
 * \param eActores[] Array que contiene todos los actores
 * \param int Tamaño del array de los actores
 * \return void
 *
 */
void mostrarListaActores(eActores[], int);
/** \brief Muestra los datos de una pelicula
 *
 * \param ePeliculas Estructura con los datos de una pelicula
 * \return void
 *
 */
void mostrarPelicula(ePeliculas);
/** \brief Muestra la lista de todas las peliculas
 *
 * \param ePeliculas[] Array que contiene todas las peliculas
 * \param int Tamaño del array de las peliculas
 * \return void
 *
 */
void mostrarPeliculas(ePeliculas[], int);
