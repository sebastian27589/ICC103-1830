/*
    ESTUDIANTES:

    NICOL SÁNCHEZ UCETA
    ID: 1015-1785

    SEBASTIÁN MIGUEL ROSARIO MERCADO
    ID: 1014-8026

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

// Ya funcionan las validaciones
void CapturarAlmacen(int, Almacen*);
int ValidarIDAlmacen(int, Almacen*);
int ValidarNombreAlmacen(int, Almacen*, char*);

// Ya funcionan las validaciones
void CapturarArticulo(int, Articulo*);
int ValidarIDArticulo(int, Articulo*);
int ValidarNombreArticulo(int, Articulo*, char*);

// Ya se muestran las existencias de forma parcial
void CapturarExistencias(int, int, int, Articulo *, Almacen *, Existencia *);
void MostrarExistencias(int, int, Articulo *, Almacen *, Existencia *);

void Salir(int, int, int, Articulo *, Almacen *, Existencia *);

int Validador(int);


int main() 
{
    int CantidadAlmacen = 0, CantidadArticulos = 0, CantidadExistencia = 0;
    Articulo *listadoArticulo= (Articulo*)malloc(sizeof(Articulo) *CantidadArticulos);
    Almacen *listadoAlmacen= (Almacen *)malloc(sizeof(Almacen) *CantidadAlmacen);
    Existencia *listadoExistencias= (Existencia *)malloc(sizeof(Existencia) *CantidadExistencia);

    char opcion;

    do {

        printf("\n***Registro de Existencias de Articulos en Almacenes***\n");
        printf("1- Registrar un nuevo almacen\n");
        printf("2- Registrar un nuevo articulo\n");
        printf("3- Establecer nueva existencia\n");
        printf("4- Mostrar todos los articulos y sus existencias\n");
        printf("5- Salir\n\n");
        //printf("Introduzca el numero de la opcion que desea: ");
        //opcion = getchar();

        do 
        {
            printf("Por favor, elija una opción del 1 al 5: (NOTA: Si sale fuera de rango, estando dentro del rango, digitar otra vez): ");
            //scanf("%d", &opcion);
            opcion = getchar();

            // Limpiar el búfer de entrada
            while (getchar() != '\n');

            if (opcion < '1' || opcion > '5') 
                printf("Opción inválida. Inténtalo nuevamente.\n");
            
        } while (opcion < '1' || opcion > '5');

        switch (opcion) 
        {
            case '1':
                CantidadAlmacen++;
                listadoAlmacen= (Almacen*) realloc(listadoAlmacen, sizeof(Almacen) * CantidadAlmacen);
                CapturarAlmacen(CantidadAlmacen - 1, listadoAlmacen);
                break;
            case '2':
                CantidadArticulos++;
                listadoArticulo= (Articulo *) realloc(listadoArticulo, sizeof(Articulo) * CantidadArticulos);
                CapturarArticulo(CantidadArticulos - 1, listadoArticulo);
                break;
            case '3':
                CantidadExistencia++;
                listadoExistencias= (Existencia *) realloc(listadoExistencias, sizeof(Existencia) * CantidadExistencia);
                CapturarExistencias(CantidadArticulos , CantidadAlmacen , CantidadExistencia - 1, listadoArticulo,  listadoAlmacen, listadoExistencias);
                break;
            case '4':
                MostrarExistencias(CantidadArticulos, CantidadAlmacen, listadoArticulo, listadoAlmacen, listadoExistencias);
                break;
            case '5':
                Salir(CantidadArticulos, CantidadAlmacen, CantidadExistencia, listadoArticulo, listadoAlmacen, listadoExistencias);
            default:
                break;
        }
    } while(opcion != '5');

    printf("\nGRACIAS POR SU TIEMPO!!\n");

    return 0;
}

// SE CORRIGIÓ LO DE VALIDAR ID Y NOMBRE

void CapturarAlmacen(int indice, Almacen *listadoAlmacen)
{
    printf("ID del Almacén: ");
    scanf("%d", &((listadoAlmacen+indice)->ID_Almacen));

    do
    {
        // Validar ID
        if (ValidarIDAlmacen(indice, listadoAlmacen) == 0)
        {
            printf("\nYA SE HA INGRESADO ESTE ID. \nPOR FAVOR DIGITE OTRO: ");
            scanf("%d", &((listadoAlmacen+indice)->ID_Almacen));
        }
    } while (ValidarIDAlmacen(indice, listadoAlmacen) == 0);

    printf("Nombre del Almacén: ");
    fflush(stdin);
    gets((listadoAlmacen+indice)->nombre_almacen);

    do
    {
        // Validar nombre del almacén
        if (ValidarNombreAlmacen(indice, listadoAlmacen, (listadoAlmacen+indice)->nombre_almacen) == 0)
        {
            printf("\nYA SE HA INGRESADO ESTE NOMBRE. \nPOR FAVOR DIGITE OTRO: ");
            gets((listadoAlmacen+indice)->nombre_almacen);
        }
    } while (ValidarNombreAlmacen(indice, listadoAlmacen, (listadoAlmacen+indice)->nombre_almacen) == 0);
}

int ValidarIDAlmacen(int indice, Almacen *listadoAlmacen)
{
    int ID = (listadoAlmacen+indice)->ID_Almacen;
    for (int ind = 0; ind < indice; ind++)
    {
        if((listadoAlmacen+ind)->ID_Almacen == ID)
            return 0;
    }

    return 1;
}

int ValidarNombreAlmacen(int indice, Almacen *listadoAlmacen, char *nombre)
{
    for (int ind = 0; ind < indice; ind++)
    {
        if(strcmp((listadoAlmacen+ind)->nombre_almacen, nombre) == 0)
            return 0;
    }

    return 1;
}

void CapturarArticulo(int indice, Articulo *listadoArticulo)
{
    printf("ID del Artículo: ");
    scanf("%d", &((listadoArticulo+indice)->ID_Art));

    do
    {
        // Validar ID Artículo
        if (ValidarIDArticulo(indice, listadoArticulo) == 0)
        {
            printf("\nYA SE HA INGRESADO ESTE ID. \nPOR FAVOR DIGITE OTRO: ");
            scanf("%d", &((listadoArticulo+indice)->ID_Art));
        }
    } while (ValidarIDArticulo(indice, listadoArticulo) == 0);

    printf("Nombre del Artículo: ");
    fflush(stdin);
    gets((listadoArticulo+indice)->nombre_art);

    do
    {
        // Validar nombre del Artículo
        if (ValidarNombreArticulo(indice, listadoArticulo, (listadoArticulo+indice)->nombre_art) == 0)
        {
            printf("\nYA SE HA INGRESADO ESTE NOMBRE. \nPOR FAVOR DIGITE OTRO: ");
            gets((listadoArticulo+indice)->nombre_art);
        }
    } while (ValidarNombreArticulo(indice, listadoArticulo, (listadoArticulo+indice)->nombre_art) == 0);

    printf("Precio: ");
    scanf("%f", &((listadoArticulo+indice)->precio));
}

int ValidarIDArticulo(int indice, Articulo *listadoArticulo)
{
    int ID = (listadoArticulo+indice)->ID_Art;
    for(int ind = 0; ind < indice; ind++)
    {
        if ((listadoArticulo+ind)->ID_Art == ID)
            return 0; 
    }

    return 1;
}

int ValidarNombreArticulo(int indice, Articulo *listadoArticulo, char *nombre)
{
    for(int ind = 0; ind < indice; ind++)
    {
        if (strcmp((listadoArticulo+ind)->nombre_art, nombre) == 0)
            return 0; 
    }

    return 1;
}

void CapturarExistencias(int CantidadArticulo, int CantidadAlmacenes, int CantidadExistencia, Articulo *listadoArticulos, Almacen *listadoAlmacen, Existencia *listadoExistencia)
{
    int i, j;
    printf("\n- - - - - - ALMACENES REGISTRADOS - - - - -\n");
    for(i = 0; i < CantidadAlmacenes; i++)
    {
        printf("Almacen ID: %d\n", (*(listadoAlmacen+i)).ID_Almacen);
        printf("Nombre: %s\n", (*(listadoAlmacen+i)).nombre_almacen);
    }
    printf("\n");

    printf("- - - - - - ARTICULOS REGISTRADOS - - - - -\n");
    for( i = 0; i < CantidadArticulo; i++)
    {
        printf("Articulo ID: %d\n", (*(listadoArticulos+i)).ID_Art);
        printf("Nombre: %s\n", (*(listadoArticulos+i)).nombre_art);
    }
    
    printf("\n");

    printf("\nIntroduzca el [ID] del Almacen que desea: ");
    scanf("%d", &((listadoExistencia+CantidadExistencia)->ID_Almacen));

    printf("\nIntroduzca el [ID] del Articulo que desea: ");
    scanf("%d", &((listadoExistencia+CantidadExistencia)->ID_Art));
    
    printf("\nCantidad de existencias para este artículo: ");
    scanf("%d", &((listadoExistencia+CantidadExistencia)->existencia));
 }

void MostrarExistencias(int CantidadArticulo, int CantidadAlmacenes, Articulo *listadoArticulos, Almacen *listadoAlmacen, Existencia *listadoExistencia)
{
    int ind;
    for(ind = 0; ind < CantidadAlmacenes; ind++)
    {
        printf("\nAlmacen [%d] - Nombre [%s]\n", (*(listadoAlmacen+ind)).ID_Almacen, (*(listadoAlmacen+ind)).nombre_almacen);
        printf("- - - - - ARTICULOS - - - - -");

        for( int j = 0; j < CantidadArticulo; j++)
        {
            for(int k = 0; k < CantidadArticulo * CantidadAlmacenes; k++)
            {
                if((listadoExistencia+k)->ID_Almacen == (listadoAlmacen+ind)->ID_Almacen &&
                   (listadoExistencia+k)->ID_Art == (listadoArticulos+j)->ID_Art)
                {
                    printf("\nArticulo ID: [%d]\n", (*(listadoArticulos+j)).ID_Art);
                    printf("Nombre: [%s]\n", (*(listadoArticulos+j)).nombre_art);
                    printf("Precio: [%.2f]\n", (*(listadoArticulos+j)).precio);
                    printf("Existen: [%d] copias. \n", (*(listadoExistencia+k)).existencia);
                }
            }
        }
    }
    printf("\n\n");
}

void Salir(int CantidadArticulo, int CantidadAlmacenes, int cantidadExistencias, Articulo *listadoArticulos, Almacen *listadoAlmacen, Existencia *listadoExistencia)
{
    int ind;
    for(ind = 0; ind < CantidadAlmacenes; ind++)
    {
        printf("\n\tAlmacen [%d]\n", (*(listadoAlmacen+ind)).ID_Almacen);
        printf("- - - - - EXISTENCIAS - - - - -");

        for( int j = 0; j < CantidadArticulo; j++)
        {
            for(int k = 0; k < CantidadArticulo * CantidadAlmacenes; k++)
            {
                if((listadoExistencia+k)->ID_Almacen == (listadoAlmacen+ind)->ID_Almacen &&
                   (listadoExistencia+k)->ID_Art == (listadoArticulos+j)->ID_Art)
                {
                    printf("\nArticulo ID: [%d]\n", (*(listadoArticulos+j)).ID_Art);
                    printf("Existencias registradas: [%d] \n", (*(listadoExistencia+k)).existencia);
                }
            }
        }
    }
}