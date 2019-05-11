#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include <string.h>
#define T 10
#define TS 3

int menuDeOpciones(char mensaje[])
{
    int opcion;
    printf("%s", mensaje);
    scanf("%d", &opcion);

    return opcion;
}


void inicializarEmpleado(eEmpleado lista[], int tam)
{
    int i;
    for(i=0; i<tam; i++)
    {
        lista[i].id=0;
        lista[i].estado = LIBRE;
    }
}

int buscarLibre(eEmpleado lista[], int tam)
{
    int i;
    int index=-1;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

int mayorIdEmpleado(eEmpleado lista[], int tam)
{
    int i;
    int flag = 0;
    int aux = 0;
    for(i=0; i<tam; i++)
    {
        if(flag==0 || lista[i].id>aux)
        {
            aux = lista[i].id;
            flag = 1;
        }
    }
    return aux;
}
void mostrarSectores(eSector listaSector[], int ts)
{
    int i;

    for(i=0;i<ts;i++)
    {
        printf("%d-%s\n", listaSector[i].idSector, listaSector[i].descripcion);
    }
}

void hardcodearEmpleado(eEmpleado lista[], int tam)
{
    int i;
    int id[]= {1,8,9,7,2,4};
    char nombres[][50]= {"Carlos","Maria","Matias","Pedro","Alfonso","Mateo"};
    char apellido[][50]= {"Gabriel","Magdalena","Gardel","Robert","Jose","Bautista"};
    float salario[]= {22000,22000,15000,4000,21000,6000};
    int sector[]={1,2,3,1,2,2};



    for(i=0; i<tam; i++)
    {
        lista[i].id = id[i];
        strcpy(lista[i].nombre, nombres[i]);
        strcpy(lista[i].apellido,apellido[i]);
        lista[i].salario = salario[i];
        lista[i].estado = OCUPADO;
        lista[i].idSector = sector[i];
    }
}


void cargarEmpleado(eEmpleado lista[], int tam,eSector sectores[], int ts)
{
        int i;
    i = buscarLibre(lista, tam);
    if(i!=-1)
    {
        lista[i].id = mayorIdEmpleado(lista, T) + 1;
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(lista[i].nombre);
        printf("Ingrese ultimo nombre: ");
        fflush(stdin);
        gets(lista[i].apellido);
        printf("ingrese su sector: \n");
        fflush(stdin);
        mostrarSectores(sectores, TS);
        scanf("%d", &lista[i].idSector);
        printf("Ingrese el salario ");
        scanf("%f", &lista[i].salario);
        lista[i].estado = OCUPADO;
    }
    else
    {
        printf("No hay espacio");
    }
}

void borrarEmpleado(eEmpleado lista[], int tam , int id )
{
    int i;
    int loEncontro = 0;
    printf("Ingrese id: ");
    scanf("%d", &id);

    for(i=0; i<tam; i++)
    {
        if(id == lista[i].id)
        {
            lista[i].estado = LIBRE;
            loEncontro = 1;
            break;//modifcar
        }
    }

    if(loEncontro==0)
    {
        printf("El dato no existe");
    }
}

void modificarEmpleado(eEmpleado lista[], int tam,eSector sectores[], int id)
{

    int i;
    int opcion;
    int loEncontro = 0;
    printf("Ingrese id: ");
    scanf("%d", &id);

    for(i=0; i<tam; i++)
    {
        if(id == lista[i].id  && lista[i].estado == OCUPADO)
        {


                opcion=menuDeOpciones("\nIngrese que desea modificar: 1)nombre  2)Apellido 3)Sector 4)No quiero modificar nada.\n");
                switch(opcion)
                {


                    case 1:
                        system("cls");
                        printf("Ingrese un nuevo nombre: ");
                        fflush(stdin);
                        gets(lista[i].nombre);
                    break;
                    case 2:
                        system("cls");
                        printf("ingrese un nuevo Apelldo: ");
                        fflush(stdin);
                        gets(lista[i].apellido);
                    break;
                    case 3:
                        system("cls");
                        printf("Ingrese un nuevo Sector: \n");
                        fflush(stdin);
                        mostrarSectores(sectores, TS);
                        scanf("%d", &lista[i].idSector);
                    break;
                    case 4:
                        system("cls");
                    break;
                    default:
                        system("cls");
                        printf("opcion incorrecta, seleccione una opcion valida\n");
                }



            loEncontro = 1;
            break;//modifcar

        }

        if(loEncontro==0)
        {
            printf("El dato no existe");
            break;
        }

    }
}


void mostrarEmpleado(eEmpleado unEmpleado, eSector sectores[], int ts)
{
    char descripcionSector[20];
    int i;

    for(i=0; i<ts; i++)
    {
        if(unEmpleado.idSector==sectores[i].idSector)
        {
            strcpy(descripcionSector, sectores[i].descripcion);
            break;
        }
    }
    printf("%4d %10s %10s %.2f %s\n", unEmpleado.id,unEmpleado.nombre, unEmpleado.apellido, unEmpleado.salario,descripcionSector);
}

void mostrarListaEmpleados(eEmpleado lista[], int tam, eSector sectores[], int ts)
{
    int i;
    for(i=0; i<tam; i++)
    {
        if(lista[i].estado!=LIBRE)
        {
            mostrarEmpleado(lista[i], sectores, ts);
        }
    }
}
