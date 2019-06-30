#define LIBRE 0
#define OCUPADO 1

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int idGenero;
    char genero[61];
}eGenero;

typedef struct{
    int idActor;
    char nombre[61];
    char paisOrigen[61];
}eActor;

typedef struct{
    char titulo[61];
    eFecha fechaEstreno;
    int idGenero;
    int idActor;
    int idPelicula;
    int estado;
}ePelicula;

/** \brief Genera un id incremental distinto para cada pelicula ingresada en el sistema
 *
 * \param ePelicula[] Array que contiene todas las peliculas
 * \param int Tamaño del array de peliculas
 * \return int Retorna el id generado para la pelicula que se desee cargar al sistema
 *
 */
int generarIdPelicula(ePelicula[], int);///LISTO

/** \brief Busca una pelicula en el array de peliculas por su id y retorna el indice
 *
 * \param ePelicula[] Array que contiene todas las peliculas
 * \param int Tamaño del array de peliculas
 * \param int Id de la pelicula que el usuario desea buscar en el array de peliculas
 * \return int Retorna el indice de la pelicula si la encontro por su id, caso contrario retornara -1
 *
 */
int buscarPorId(ePelicula[], int, int);///LISTO

/** \brief Busca una posicion en el array de peliculas en la que haya un espacio libre para cargar una nueva pelicula
 *
 * \param ePelicula[] Array que contiene todas las peliculas
 * \param int Tamaño del array de peliculas
 * \return int Retorna el indice de la posicion del array en la que hay espacio para alamacenar una pelicula, caso contrario retornara -1
 *
 */
int buscarLibre(ePelicula[], int);///LISTO

/** \brief Inicializa todo el array de peliculas en estado libre
 *
 * \param ePelicula[] Array que contiene todas las peliculas
 * \param int Tamaño del array de peliculas
 * \return void SIN RETORNO
 *
 */
void inicializarLibre(ePelicula[], int);///LISTO

/** \brief Hardcodea los datos de la entidad eGenero con datos ya entregados
 *
 * \param eGenero[] Array que contiene los generos
 * \return void SIN RETORNO
 *
 */
void hardcodearGeneros(eGenero[]);///LISTO

/** \brief Hardcodea los datos de la entidad eActor con datos ya entregados
 *
 * \param eActor[] Array que contiene los actores
 * \return void SIN RETORNO
 *
 */
void hardcodearActores(eActor[]);///LISTO

/** \brief Hardcodea los datos de la entidad ePelicula con datos ya entregados
 *
 * \param ePelicula[] Array que contiene las peliculas
 * \return void SIN RETORNO
 *
 */
void hardcodearPeliculas(ePelicula[]);///LISTO

/** \brief Cargar los datos de una pelicula con sus correspondientes campos
 *
 * \param ePelicula[] Array que contiene todas las peliculas
 * \param int Tamaño del array de peliculas
 * \param eActor[] Array que contiene todos los actores
 * \param eGenero[] Array que contiene todos los generos
 * \return void SIN RETORNO
 *
 */
void cargarPelicula(ePelicula[], int, eActor[], eGenero[]);///LISTO

/** \brief Modifica una pelicula en la posicion solicitada
 *
 * \param ePelicula[] Array que contiene todas las peliculas
 * \param int Tamaño del array de peliculas
 * \return void SIN RETORNO
 *
 */
void modificarPelicula(ePelicula[], int);///LISTO

/** \brief Da de baja una pelicula en la posicion solicitada
 *
 * \param ePelicula[] Array que contiene todas las peliculas
 * \param int Tamaño del array de peliculas
 * \return void SIN RETORNO
 *
 */
void bajaPelicula(ePelicula[], int);///LISTO

/** \brief Muestra todos los actores contenidos en el array con sus respectivos campos
 *
 * \param eActor[] Array que contiene todos los actores
 * \return void SIN RETORNO
 *
 */
void listarActores(eActor[]);///LISTO

/** \brief Muestra todos los generos contenidos en el array con sus respectivos campos
 *
 * \param eGenero[] Array que contiene todos los generos
 * \return void SIN RETORNO
 *
 */
void listarGeneros(eGenero[]);///LISTO

/** \brief Muestra una pelicula con sus respectivos campos
 *
 * \param ePelicula Entidad donde esta contenida una pelicula
 * \return void SIN RETORNO
 *
 */
void mostrarPelicula(ePelicula);///LISTO

/** \brief Ordena el array de peliculas segun el año en que se estreno
 *
 * \param ePelicula[] Array que contiene todas las peliculas
 * \param int Tamaño del array de peliculas
 * \return void SIN RETORNO
 *
 */
void listarPorAnioEstreno(ePelicula[], int);///LISTO

/** \brief Ordena el array de actores segun nacionalidad de cada actor
 *
 * \param eActor[] Array que contiene todos los actores
 * \return void SIN RETORNO
 *
 */
void listarActoresPorPais(eActor[]);///LISTO

/** \brief Muestra toda la lista de peliculas que esten ocupadas en el sistema
 *
 * \param ePelicula[] Array que contiene todas la peliculas
 * \param int Tamaño del array de peliculas
 * \return void SIN RETORNO
 *
 */
void listarPeliculas(ePelicula[], int);///LISTO

/** \brief Informa todas las peliculas con genero y actor correspondiente
 *
 * \param ePelicula[] Array que contiene todas las peliculas
 * \param eGenero[] Array que contiene todos los generos
 * \param eActor[] Array que contiene todos los actores
 * \param int Tamaño del array de peliculas
 * \return void SIN RETORNO
 *
 */
void informeUno(ePelicula[], eGenero[], eActor[], int);///LISTO

/** \brief Informa todas las peliculas cuya nacionalidad del actor sea EEUU
 *
 * \param ePelicula[] Array que contiene todas las peliculas
 * \param eActor[] Array que contiene todos los actores
 * \param int Tamaño del array de peliculas
 * \return void SIN RETORNO
 *
 */
void informeDos(ePelicula[], eActor[], int);///LISTO

/** \brief Informa por cada genero el titulo de las peliculas que pertenecen a ese genero
 *
 * \param ePelicula[] Array que contiene todas la peliculas
 * \param eGenero[] Array que todos los generos
 * \param int Tamaño del array de peliculas
 * \return void SIN RETORNO
 *
 */
void informeTres(ePelicula[], eGenero[], int);///LISTO

/** \brief Por cada genero la cantidad de peliculas que hay
 *
 * \param ePelicula[] Array que contiene todas las peliculas
 * \param eGenero[] Array que contiene todos los generos
 * \param int Tamaño del array de peliculas
 * \return void SIN RETORNO
 *
 */
void informeCuatro(ePelicula[], eGenero[], int);///LISTO

/** \brief El/Los generos con menos peliculas
 *
 * \param ePelicula[] Array que contiene todas las peliculas
 * \param eGenero[] Array que contiene todos los generos
 * \param int Tamaño del array de peliculas
 * \return void SIN RETORNO
 *
 */
void informeCinco(ePelicula[], eGenero[], int);///LISTO
