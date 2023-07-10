#include <stdio.h>
#include <stdlib.h>

/*
    Se tiene una lista simplemente enlazada de números reales. 
    Escribir una función para obtener una lista doble ordenada respecto 
    al campo dato, con los valores reales de la lista simple.
*/

typedef struct sNodo
{
    double data;
    struct sNodo* anterior;
    struct sNodo* siguiente;
}Nodo;

void InsertarDobleEnlazada(Nodo* cabeza)
{
    int nuevoValor;
    Nodo* nodoActual = cabeza, *nodoAnterior = NULL;

    printf("Valor del nodo: \n");
    scanf("%d", &nuevoValor);

    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->data = nuevoValor;
    nuevoNodo->anterior = NULL;
    nuevoNodo->siguiente = NULL;

    // Si la lista está vacía
    if (cabeza == NULL)
        return cabeza;
    
    while(nodoActual != NULL )
    {
        nodoAnterior = nodoActual;
        nodoActual = nodoActual->siguiente;
    }

    if(nodoAnterior == NULL)
    {
        nuevoNodo->siguiente = cabeza;
        cabeza->anterior = nuevoNodo;
        cabeza = nuevoNodo;
    }
    else
    {
        nodoAnterior->siguiente = nuevoNodo;
        nuevoNodo->anterior = nodoAnterior;
        nuevoNodo->siguiente = nodoActual;

        if (nodoActual != NULL)
            nodoActual->anterior = nuevoNodo;
    }
}