#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

typedef struct sNodo
{
    int data;
    struct sNodo *enlace;
}Nodo;

Nodo* EliminarElemento(Nodo *listaEnlazada, int elemento);
Nodo* InsertarElemento(Nodo* listaEnlazada);
void MostrarLista(Nodo *listaEnlazada);

int main()
{
    Nodo *listaEnlazada = NULL;
    char opcion;
    int valorEliminar;

    do
    {
        listaEnlazada = InsertarElemento(listaEnlazada);

        printf("Digitar otro valor? (S/N) ");
        fflush(stdin);
        opcion = tolower(getchar());
    } while (opcion == 's');
    
    printf("Digite el valor que desea eliminar: ");
    scanf("%d", &valorEliminar);
    listaEnlazada = EliminarElemento(listaEnlazada, valorEliminar);

    MostrarLista(listaEnlazada);

    return 0;
}

// Recibe: La lista enlazada con todos los elementos,
// y el elemento que se desea eliminar.
// Recorre la lista enlazada, buscando el valor a
// eliminar, y si lo encuentra, lo elimina de la lista,
// liberando ese espacio en memoria.
Nodo* EliminarElemento(Nodo *listaEnlazada, int elemento)
{
    Nodo *nodoTemporal, *nodoAnterior = NULL;
    if(listaEnlazada == NULL)
        return listaEnlazada; // Lista vacía, nada qué hacer.
    
    nodoTemporal = listaEnlazada;

    while(nodoTemporal->data != elemento)
    {
        nodoAnterior = nodoTemporal;
        nodoTemporal = nodoTemporal->enlace;

        if(nodoTemporal->enlace == NULL)
            break;
    }

    if(nodoTemporal->data == elemento && nodoAnterior == NULL) // Quiero borrar el primer elemento de la lista.
    {
        listaEnlazada = nodoTemporal->enlace;
        free(nodoTemporal);
        return listaEnlazada;
    }
    else if(nodoTemporal->data != elemento && nodoTemporal->enlace == NULL)    
        return listaEnlazada; // No se encontró el elemento, y llegué al final.

    // Tengo que eliminar el elemento.
    nodoAnterior->enlace = nodoTemporal->enlace;
    free(nodoTemporal);

    return listaEnlazada;
}

// Recibe: la lista enlazada donde se agregará el valor.
// Deberá capturar el valor, reservar el espacio en memoria
// para el nuevo valor, e insertarlo en la lista enlazada.
Nodo* InsertarElemento(Nodo* listaEnlazada)
{
    int nuevoValor;
    Nodo *nuevoNodo, *nodoTemporal;

    printf("Digite el nuevo valor: ");
    scanf("%d", &nuevoValor);

    nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->data = nuevoValor;
    nuevoNodo->enlace = NULL;

    if(listaEnlazada == NULL)
    {
        // La lista es nueva, está vacía.
        listaEnlazada = nuevoNodo;
        return listaEnlazada;
    }

    // Nos movemos al final de la lista.
    nodoTemporal = listaEnlazada;
    while(nodoTemporal->enlace != NULL)
        nodoTemporal = nodoTemporal->enlace;
    
    nodoTemporal->enlace = nuevoNodo;

    return listaEnlazada;
}

void MostrarLista(Nodo *listaEnlazada)
{
    Nodo *nodoActual = listaEnlazada;

    while(nodoActual != NULL)
    {
        printf("%d\t", nodoActual->data);
        nodoActual = nodoActual->enlace;
    }
}