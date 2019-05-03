#define OCUPADO 1
#define LIBRE 0
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}Employee;

int buscarId(Employee[], int, int);
void cargarEmpleado(Employee[], int);
void modificarEmpleado(Employee[], int);
void borrarEmpleado(Employee[], int);
void mostrarEmpleado(Employee);
void mostrarListaEmpleados(Employee[], int);
void ordenarListaEmpleados(Employee[], int);


void utilizandoStrings(Employee[], int);
void ordenarAlfabeticamente(Employee[], int);
void pasarMayusculas(Employee[], int);



int pedirEntero(char[]);
char pedirCaracter(char[]);
int generarNumeroRandom(void);
