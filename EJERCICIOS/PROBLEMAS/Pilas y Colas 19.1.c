#include <stdio.h>
#include <stdlib.h>

/*
    Escribir una función CopiarPila, que copie el contenido de una pila a otra.
    La función tendrá dos argumentos de tipo pila, uno para la pila fuente y otro para la pila destino. 
    Utilizar las operaciones definidas sobre el tipo de dato pila.
*/

int main()
{
    printf("\nFUNCION HECHA EN EL PROGRAMA.");
    return 0;
}

// Definición de la estructura del nodo
typedef struct sNodo 
{
    int data;
    struct sNodo* siguiente;
}Nodo;

// Definición del tipo de dato de la pila
typedef struct 
{
    Nodo* cima;
}Pila;

// Inicializar una pila vacía
void inicializarPila(Pila* pila) 
{
    pila->cima = NULL;
}

// Verificar si la pila está vacía
int pilaVacia(Pila* pila) 
{
    return (pila->cima == NULL);
}

// Obtener el elemento en la parte superior de la pila sin extraerlo
int cima(Pila* pila) 
{
    if (pilaVacia(pila)) 
    {
        printf("Error: la pila está vacía.\n");
        return;
    }
    return pila->cima->data;
}

// Insertar un elemento en la parte superior 
void push(Pila* pila, int elemento) 
{
    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    nuevoNodo->data = elemento;
    nuevoNodo->siguiente = pila->cima;
    pila->cima = nuevoNodo;
}

// Eliminar el elemento en la parte superior 
void pop(Pila* pila) 
{
    if (pilaVacia(pila)) 
    {
        printf("Error: la pila está vacía.\n");
        return;
    }
    Nodo* temp = pila->cima;
    pila->cima = pila->cima->siguiente;
    free(temp);
}

// Función para copiar el contenido de una pila a otra
void CopiarPila(Pila* pilaFuente, Pila* pilaDestino) 
{
    
    Pila pilaTemporal;
    inicializarPila(&pilaTemporal);

    
    Nodo* nodoActual = pilaFuente->cima;
    while (nodoActual != NULL) 
    {
        push(&pilaTemporal, nodoActual->data);
        nodoActual = nodoActual->siguiente;
    }

    
    nodoActual = pilaTemporal.cima;
    while (nodoActual != NULL) 
    {
        push(pilaDestino, nodoActual->data);
        nodoActual = nodoActual->siguiente;
    }
}