#include <stdio.h>
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int id;
    int estado;
    int idSector;
    char nombre[51];
    char apellido[50];
    float salario;
} eEmpleado;

typedef struct
{
    int idSector;
    char descripcion[20];
}eSector;




void cargarEmpleado(eEmpleado [], int ,eSector[], int);
int buscarLibre(eEmpleado[] , int tam);
int menuDeOpciones(char[]);
void inicializarEmpleado(eEmpleado [], int );
void hardcodearEmpleado(eEmpleado [], int);
void mostrarListaEmpleados(eEmpleado[], int, eSector[], int);
void mostrarEmpleado(eEmpleado ,eSector[], int);
int mayorIdEmpleado(eEmpleado [], int );
void modificarEmpleado(eEmpleado [], int , eSector[], int );
void borrarEmpleado(eEmpleado [], int , int );
void mostrarSectores(eSector [], int ts);

