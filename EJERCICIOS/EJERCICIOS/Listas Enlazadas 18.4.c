#include <stdio.h>

/*
    Escribir una función que elimine el nodo que ocupa la posición i, siendo el nodo cabecera 
    el que ocupa la posición 0
*/

typedef struct sNodo
{
    int data;
    struct sNodo *link;
}Nodo;

// OJO: EN ESTE EJERCICIO SOLO ESCRIBI LA FUNCIÓN COMO PEDIA

Nodo* BorrarNodo(Nodo *ListaEnlazada, int pos)
{
    Nodo *Anterior = ListaEnlazada, *Temp;
    int ind = 0;

    // Si la lista está vacía
    if (ListaEnlazada == NULL)
        return ListaEnlazada;

    while (ind < pos - 1 && Anterior->link != NULL)
    {
        Anterior = Anterior->link;
        ind++;
    }

    // Si la posición es mayor que el rango indicado
    if (Anterior->link == NULL || ind != pos - 1)
        return ListaEnlazada;

    Temp = Anterior->link;
    Anterior->link = Temp->link;

    return ListaEnlazada;
}