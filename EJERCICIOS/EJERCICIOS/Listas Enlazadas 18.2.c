#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*
    Escribir una función entera que devuelva el número de nodos de una lista enlazada

    OJO: SOLO ERA ESCRIBIR LA FUNCIÓN PERO PUSE UN PROGRAMA
*/

typedef struct sNodo
{
    int dato;
    struct sNodo *link;
}Nodo;

int ContarNodos(Nodo *ListaEnlazada);
Nodo* InsertarNodo(Nodo *ListaEnlazada);

int main()
{
    Nodo *ListaEnlazada = NULL;
    int NumNodos;
    char opcion;

    do
    {
        NumNodos = ContarNodos(ListaEnlazada);
        printf("\nCantidad de nodos: [%d]\n", NumNodos);
        
        printf("¿Digitar nuevo valor? (S/N) ");
        fflush(stdin);
        opcion = tolower(getchar());

        if (opcion == 's')
            ListaEnlazada = InsertarNodo(ListaEnlazada);

    } while (opcion == 's');

    return 0;
}

Nodo* InsertarNodo(Nodo *ListaEnlazada)
{
    int nuevoValor;
    printf("Digite el nuevo valor: ");
    scanf("%d", &nuevoValor);

    Nodo *nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->dato = nuevoValor;
    nuevoNodo->link = NULL;

    if (ListaEnlazada == NULL)
    {
        ListaEnlazada = nuevoNodo;
    }
    else
    {
        Nodo *Temp = ListaEnlazada;
        while (Temp->link != NULL)
        {
            Temp = Temp->link;
        }
        Temp->link = nuevoNodo;
    }

    return ListaEnlazada;
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

    return cont;
}