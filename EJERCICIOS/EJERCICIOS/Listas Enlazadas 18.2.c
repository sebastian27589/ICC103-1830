#include <stdio.h>
#include <stdlib.h>

/*
    Escribir una función entera que devuelva el número de nodos de una lista enlazada
*/

typedef struct sNodo
{
    struct sNodo *link;
}Nodo;

int ContarNodos(Nodo *ListaEnlazada);

int main()
{
    Nodo *ListaEnlazada;

    int NumNodos = ContarNodos(ListaEnlazada);
    printf("Cantidad de nodos: %d", NumNodos);

    return 0;
}

int ContarNodos(Nodo *ListaEnlazada)
{
    int cont = 0;

    Nodo *Temp = ListaEnlazada;

    while (Temp != NULL)
    {
        cont++;
        Temp = Temp->link;
    }
}