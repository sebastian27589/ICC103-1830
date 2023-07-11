#include <stdio.h>
#include <stdlib.h>

/*
    Una bicola es una estructura de datos bilineal en la que la inserción
    y borrado se pueden hacer tanto por el extremo FRENTE como por el extremo
    final. Suponer que se ha elegido una representación dinámica, con punteros 
    y que los extremos de la lista se denominan FRENTE y FINAL. Escribir la 
    implementación de las operaciones: InsertarFrente(), InsertarFinal(), 
    EliminarFrente() y EliminarFinal();
*/

typedef struct sNodo 
{
    int data;
    struct sNodo* siguiente;
    struct sNodo* anterior;
} Nodo;

typedef struct 
{
    Nodo* frente;
    Nodo* cola;
} Bicola;

int main()
{
    printf("----LAS OPERACIONES ESTÁN EN EL PROGRAMA------");
    return 0;
}

// Función para insertar un elemento al frente de la bicola
void InsertarFrente(Bicola* bicola, int elemento) 
{
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->data = elemento;
    nuevoNodo->siguiente = bicola->frente;
    nuevoNodo->anterior = NULL;

    if (bicola->frente == NULL) 
    {
        // La bicola está vacía
        bicola->frente = nuevoNodo;
        bicola->cola = nuevoNodo;
    } else {
        bicola->frente->anterior = nuevoNodo;
        bicola->frente = nuevoNodo;
    }
}

// Función para insertar un elemento al final de la bicola
void InsertarFinal(Bicola* bicola, int elemento) 
{
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));

    nuevoNodo->data = elemento;
    nuevoNodo->siguiente = NULL;
    nuevoNodo->anterior = bicola->cola;

    if (bicola->cola == NULL) {
        // La bicola está vacía
        bicola->frente = nuevoNodo;
        bicola->cola = nuevoNodo;
    } else {
        bicola->cola->siguiente = nuevoNodo;
        bicola->cola = nuevoNodo;
    }
}

// Función para eliminar el elemento del frente de la bicola
void EliminarFrente(Bicola* bicola) 
{
    if (bicola->frente == NULL) {
        // La bicola está vacía
        printf("La bicola está vacía. No se puede eliminar el frente.\n");
        return;
    }

    Nodo* temp = bicola->frente;
    bicola->frente = bicola->frente->siguiente;

    if (bicola->frente == NULL) {
        // La bicola quedó vacía
        bicola->cola = NULL;
    } else {
        bicola->frente->anterior = NULL;
    }

    free(temp);
}

// Función para eliminar el elemento del final de la bicola
void EliminarFinal(Bicola* bicola) 
{
    if (bicola->cola == NULL) 
    {
        // La bicola está vacía
        printf("La bicola está vacía. No se puede eliminar el final.\n");
        return;
    }

    Nodo* temp = bicola->cola;
    bicola->cola = bicola->cola->anterior;

    if (bicola->cola == NULL) 
    {
        // La bicola quedó vacía
        bicola->frente = NULL;
    } else {
        bicola->cola->siguiente = NULL;
    }

    free(temp);
}