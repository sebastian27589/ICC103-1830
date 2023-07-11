#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Utilizar una lista doblemente enlazada para controlar una lista de pasajeros de una línea aérea.
    El programa principal debe ser controlado por, y permitir al usuario visualizar los datos de un pasajero
    determinado, insertar un nodo (siempre por el final), eliminar un pasajero de la lista. A la lista se accede
    por un puntero al primer nodo, y otro al último nodo.
*/

typedef struct sNodo
{
    char nombre[50];
    int edad;
    struct sNodo *siguiente;
    struct sNodo *anterior;
}Nodo;

void VisualizarNodo(Nodo*);
void BorrarNodo(Nodo*, Nodo*, char*);
void InsertarNodo(Nodo*, Nodo*, char*);

int main()
{
    Nodo* primerNodo = NULL;
    Nodo* ultimoNodo = NULL;
    int eleccion;
    char nombre[20];

    do
    {
        printf("\n----------LISTA DE PASAJEROS DE LINEA AEREA----------\n");
        printf("1. Visualizar datos de un pasajero\n");
        printf("2. Insertar un pasajero\n");
        printf("3. Eliminar un pasajero.\n");
        printf("4. Salir.\n");

        printf("DIGITE SU OPCION: ");
        scanf("%d", &eleccion);

        switch (eleccion) 
        {
            case 1:
                if (primerNodo == NULL) {
                    printf("La lista de pasajeros está vacía.\n");
                } else 
                {
                    printf("Ingrese el nombre del pasajero: ");
                    scanf("%s", nombre);
                    Nodo* nodoActual = primerNodo;
                    while (nodoActual != NULL) 
                    {
                        if (strcmp(nodoActual->nombre, nombre) == 0) 
                        {
                            VisualizarNodo(nodoActual);
                            break;
                        }
                        nodoActual = nodoActual->siguiente;
                    }
                    
                    if (nodoActual == NULL) 
                            printf("El pasajero '%s' no se encontró en la lista.\n", nombre);
                }
                break;
            case 2:
                printf("Ingrese el nombre del pasajero: ");
                scanf("%s", nombre);
                InsertarNodo(primerNodo, ultimoNodo, nombre);
                printf("El pasajero '%s' ha sido insertado al final de la lista.\n", nombre);
                break;

            case 3:
                if (primerNodo == NULL) 
                {
                    printf("La lista de pasajeros está vacía.\n");
                } else 
                {
                    printf("Ingrese el nombre del pasajero a eliminar: ");
                    scanf("%s", nombre);
                    BorrarNodo(primerNodo, ultimoNodo, nombre);
                }
                break;
            case 4:
                break;
            default:
                break;
        }
    } while (eleccion != 4);

    return 0;
}

void InsertarNodo(Nodo* primerNodo, Nodo* ultimoNodo, char *nombre)
{
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    strcpy(nuevoNodo->nombre, nombre);
    nuevoNodo->anterior = NULL;
    nuevoNodo->siguiente = NULL;

    if (primerNodo == NULL)
    {
        primerNodo = nuevoNodo;
        ultimoNodo = nuevoNodo;
    } else {

        ultimoNodo->siguiente = nuevoNodo;
        nuevoNodo->anterior = ultimoNodo;
        ultimoNodo = nuevoNodo;
    }
}

void BorrarNodo(Nodo* primerNodo, Nodo* ultimoNodo, char *nombre)
{
    // Lista vacía
    if (primerNodo == NULL)
        return;
    
    Nodo* nodoActual = primerNodo;
    while (nodoActual != NULL)
    {
        if (strcmp(nodoActual->nombre, nombre) == 0)
        {
            if (nodoActual->anterior == NULL)
            {
                primerNodo = nodoActual->siguiente;

            } else if (nodoActual->siguiente == NULL)
            {
                ultimoNodo = nodoActual->anterior;
                ultimoNodo->siguiente = NULL;

            } else 
            {
                nodoActual->anterior->siguiente = nodoActual->siguiente;
                nodoActual->siguiente->anterior = nodoActual->anterior;
                return;
            }
        }

        nodoActual = nodoActual->siguiente;
    }

}

void VisualizarNodo(Nodo* nodo)
{
    printf("Nombre del pasajero: %s\n", nodo->nombre);
}