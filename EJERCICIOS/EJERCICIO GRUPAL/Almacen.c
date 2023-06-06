/*
    ESTUDIANTES:

    NICOL SÁNCHEZ UCETA
    ID: 1015-1785

    SEBASTIÁN MIGUEL ROSARIO MERCADO
    ID: 1014-8026

    COMPAÑERO 3: (RANDALL) SE SALIÓ DE LA LLAMADA, SOLO TRABAJAMOS 2.

    GRUPO 4


*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ID_Art;
    char nombre_art[30];
    float precio;
}Articulo;

typedef struct {
    int ID_Almacen;
    char nombre_almacen[30];

}Almacen;

typedef struct {
    int ID_Art;
    int ID_Almacen;
    int existencia;
}Existencia;


void CapturarAlmacen(int, Almacen*);

void CapturarArticulo(int, Articulo*);

void CapturarExistencias(int, int, Articulo *, Almacen *, Existencia *);

void MostrarExistencias(int, int, Articulo *, Almacen *, Existencia *);

void Salir(int, int, int, Articulo *, Almacen *, Existencia *);


int main() {

    int CantidadAlmacen = 0, CantidadArticulos = 0, CantidadExistencia = 0;
    Articulo *listadoArticulo= (Articulo*)malloc(sizeof(Articulo) *CantidadArticulos);
    Almacen *listadoAlmacen= (Almacen *)malloc(sizeof(Almacen) *CantidadAlmacen);
    Existencia *listadoExistencias= (Existencia *)malloc(sizeof(Existencia) *CantidadExistencia);

    int opcion;


    do {


        printf("\n***Registro de Existencias de Articulos en Almacenes***\n");
        printf("1- Registrar un nuevo almacen\n");
        printf("2- Registrar un nuevo articulo\n");
        printf("3- Establecer nueva existencia\n");
        printf("4- Mostrar todos los articulos y sus existencias\n");
        printf("5- Salir\n\n");
        printf("Introduzca el numero de la opcion que desea: ");
        scanf("%d", &opcion);


        switch (opcion) {

            case 1:
                CantidadAlmacen++;
                listadoAlmacen= (Almacen*) realloc(listadoAlmacen, sizeof(Almacen) * CantidadAlmacen);
                CapturarAlmacen(CantidadAlmacen - 1, listadoAlmacen);
                break;

            case 2:

                CantidadArticulos++;
                listadoArticulo= (Articulo *) realloc(listadoArticulo, sizeof(Articulo) * CantidadArticulos);
                CapturarArticulo(CantidadArticulos - 1, listadoArticulo);

                break;

            case 3:
                CantidadExistencia++;
                listadoExistencias= (Existencia *) realloc(listadoExistencias, sizeof(Existencia) * CantidadExistencia);
                CapturarExistencias(CantidadArticulos, CantidadAlmacen,
                                    listadoArticulo,  listadoAlmacen, listadoExistencias);
                break;

            case 4:
                MostrarExistencias(CantidadArticulos, CantidadAlmacen, 
                                    listadoArticulo, listadoAlmacen, listadoExistencias);
                break;

            case 5:
                Salir(CantidadArticulos, CantidadAlmacen, 
                                   CantidadExistencia, listadoArticulo, listadoAlmacen, listadoExistencias);

            default:
                break;
        }
    } while(opcion != 5);

    printf("\n\nGRACIAS POR SU TIEMPO!!");

    return 0;
}

void CapturarAlmacen(int indice, Almacen *listadoAlmacen){

    printf("ID:");
    scanf("%d", &((listadoAlmacen+indice)->ID_Almacen));

    printf("\nNombre:");
    fflush(stdin);
    gets((listadoAlmacen+indice)->nombre_almacen);
}


void CapturarArticulo(int indice, Articulo *listadoArticulo){

    printf("ID:");
    scanf("%d", &((listadoArticulo+indice)->ID_Art));
    printf("\nNombre:");
    fflush(stdin);
    gets((listadoArticulo+indice)->nombre_art);
    printf("\nPrecio:");
    scanf("%f", &((listadoArticulo+indice)->precio));
}

void CapturarExistencias(int CantidadArticulo, int CantidadAlmacenes, Articulo *listadoArticulos, Almacen *listadoAlmacen,
                        Existencia *listadoExistencia)
{

    int i, j;

    for(i=0; i < CantidadAlmacenes; i++)
    {
        printf("Almacen ID: %d\n", (*(listadoAlmacen+i)).ID_Almacen);
        printf("Nombre: %s\n", (*(listadoAlmacen+i)).nombre_almacen);
        /*for( j=0; j < CantidadArticulo; j++)
        {
            printf("Artículo ID: %d\n", (*(listadoArticulos+j)).ID_Art);
            printf("Nombre: %s\n", (*(listadoArticulos+j)).nombre_art);
        }*/

    }

    
    printf("\n\n");

    for( i=0; i < CantidadArticulo; i++)
    {
        printf("Articulo ID: %d\n", (*(listadoArticulos+i)).ID_Art);
        printf("Nombre: %s\n", (*(listadoArticulos+i)).nombre_art);
    }
    
    printf("\n");

    /*
        do 
        {
            CantidadAlmacenes++;
            for( j = 0; j < CantidadAlmacenes; j++)
            {
                scanf("%d", &((listadoExistencia+j)->ID_Almacen));
                
                //if( ((*(listadoExistencia+j)).ID_Almacen) != ((*(listadoAlmacen+j)).ID_Almacen) ) 
                // printf("Error. Intentalo de nuevo.");

            }
        } while (((*(listadoExistencia+j)).ID_Almacen) != ((*(listadoAlmacen+j)).ID_Almacen));
    */

   // if (((*(listadoExistencia)).ID_Almacen) != ((*(listadoAlmacen)).ID_Almacen))


    printf("Introduzca el ID de Almacen que desea: ");
    scanf("%d", &((listadoExistencia)->ID_Almacen));

    /*

    for( i=0; i < CantidadAlmacenes; i++)
    {
        printf("Articulo ID: %d\n", (*(listadoArticulos+i)).ID_Art);
        printf("Nombre: %s\n", (*(listadoArticulos+i)).nombre_art);
    }

    */

    printf("Introduzca el ID del Artículo que desea: ");
    scanf("%d", &((listadoExistencia)->ID_Art));
    
    printf("Cantidad de existencias para este artículo: ");
    scanf("%d", &((listadoExistencia+i)->existencia));



 }


void MostrarExistencias(int CantidadArticulo, int CantidadAlmacenes, Articulo *listadoArticulos, Almacen *listadoAlmacen,
                        Existencia *listadoExistencia)
{

    int i;
    for(i=0; i < CantidadAlmacenes; i++)
    {
        printf("Almacen ID: %d\n", (*(listadoAlmacen+i)).ID_Almacen);
        printf("Nombre: %s\n", (*(listadoAlmacen+i)).nombre_almacen);

    }
    printf("\n\n");

    for( i=0; i < CantidadArticulo; i++)
    {
        printf("Articulo ID: %d\n", (*(listadoArticulos+i)).ID_Art);
        printf("Nombre: %s\n", (*(listadoArticulos+i)).nombre_art);
        printf("Precio: %.2f\n", (*(listadoArticulos+i)).precio);
        printf("Existen: %d\n", (*(listadoExistencia+i)).existencia);

    }

}


void Salir(int CantidadArticulo, int CantidadAlmacenes, int cantidadExistencias, Articulo *listadoArticulos, Almacen *listadoAlmacen,
                        Existencia *listadoExistencia)

{
    int i;
    for(i=0; i < CantidadAlmacenes; i++)
    {
        printf("Almacen ID: %d\n", (*(listadoAlmacen+i)).ID_Almacen);
        printf("Nombre: %s\n", (*(listadoAlmacen+i)).nombre_almacen);

    }
    printf("\n\n");

    for( i=0; i < CantidadArticulo; i++)
    {
        printf("Articulo ID: %d\n", (*(listadoArticulos+i)).ID_Art);
        printf("Nombre: %s\n", (*(listadoArticulos+i)).nombre_art);
        printf("Precio: %.2f\n", (*(listadoArticulos+i)).precio);
        printf("Existen: %d\n", (*(listadoExistencia+i)).existencia);

    }

}