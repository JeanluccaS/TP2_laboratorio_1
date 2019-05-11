#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#define T 1000
#define TS 3
int main()
{
    int opcion;

    eEmpleado lista[T];
    inicializarEmpleado(lista,T);
    eSector sectores[3] = {{1,"Contabilidad"},{2,"Sistemas"},{3, "RRHH"}};
    hardcodearEmpleado(lista,6);
    do
    {
        opcion = menuDeOpciones("1.Alta\n2.Baja\n3.Modificar\n4.Mostrar\n5.Salir\nElija una opcion: ");
        switch(opcion)
        {
            case 1:
                system("cls");
                cargarEmpleado(lista,T,sectores,TS);
                break;


            case 2:
                system("cls");
                borrarEmpleado(lista, T, TS);
                break;
            case 3:
                system("cls");
                modificarEmpleado(lista, T, sectores, TS);
            break;
            case 4:
                system("cls");
                mostrarListaEmpleados(lista, T , sectores, TS);
                break;
            case 5:

            break;

            default:
                system("cls");
                printf("ingrese una opcion valida");

        }
    }while(opcion!=5);


    return 0;
}
