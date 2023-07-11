#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Escribir un programa para obtener una lista doblemente enlazada con los caracteres de una cadena leída
    desde el teclado. Cada nodo de la lista tendrá un caracter.

    Una vez que se obtiene la lista ordenada alfabéticamente, escribirlar por pantalla.
*/

typedef struct sNodo
{
    char letra;
    struct sNodo* anterior;
    struct sNodo* siguiente;
}Nodo;

void InsertarNodo(Nodo*, Nodo*, char);
void OrdenarLista(Nodo*);
void MostrarLista(Nodo*);

int main()
{
    Nodo* primerNodo = NULL;
    Nodo* ultimoNodo = NULL;
    char str[50];

    printf("Ingrese una cadena: ");
    gets(str);

    int longitud = strlen(str);

    for(int ind = 0; ind < longitud; ind++)
        InsertarNodo(primerNodo, ultimoNodo, str[ind]);

    OrdenarLista(primerNodo);
    printf("\nLista ordenada: ");
    MostrarLista(primerNodo);
    
    return 0;
}

void InsertarNodo(Nodo* primerNodo, Nodo* ultimoNodo, char letra)
{
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->letra = letra;
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

void OrdernarLista(Nodo* primerNodo)
{
    Nodo* i;
    Nodo* j;
    char temp;

    for (i = primerNodo; i != NULL; i = i->siguiente)
    {
        for(j = i->siguiente; j != NULL; j = j->siguiente)
        {
            if(i->letra > j->letra)
            {
                temp = i->letra;
                i->letra = j->letra;
                j->letra = temp;
            }
        }
    }
}

void MostrarLista(Nodo* primerNodo)
{
    // Lista vacía
    if (primerNodo == NULL)
        return;
    
    Nodo* nodoActual = primerNodo;
    while (nodoActual != NULL)
    {
        printf("%c ", nodoActual->letra);
        nodoActual = nodoActual->siguiente;
    }
    printf("\n");
}