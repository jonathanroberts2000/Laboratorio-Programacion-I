
typedef struct{
    int id;
    char nombre[1000];
    int anio;
    char genero[1000];
}ePelicula;

ePelicula* pelicula_new();
ePelicula* pelicula_newParametros(char* idStr, char* nombreStr, char* anioStr, char* generoStr);

int pelicula_setId(ePelicula* this, int id);
int pelicula_setNombre(ePelicula* this, char* nombre);
int pelicula_setAnio(ePelicula* this, int anio);
int pelicula_setGenero(ePelicula* this, char* genero);

int pelicula_getId(ePelicula* this);
char* pelicula_getNombre(ePelicula* this);
int pelicula_getAnio(ePelicula* this);
char* pelicula_getGenero(ePelicula* this);

int pelicula_compareById(ePelicula* p1, ePelicula* p2);
