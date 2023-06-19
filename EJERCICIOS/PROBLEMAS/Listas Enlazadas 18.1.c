#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Escribir un programa o funciones individuales que realicen las siguientes tareas:

    - Crear una lista enlazada de números enteros positivos al azar, la inserción se realiza por el último nodo.
    - Recorrer la lista para mostrar los elementos por pantalla.
    - Eliminar todos los nodos que superen un valor dado. 

*/

typedef struct sKnot
{
    int data;
    struct sKnot *link; // Creo el nodo.
}Knot;


Knot* RandomPositive(Knot *LinkList);
Knot* DeleteNumbers(Knot *LinkList, int);
void ShowList(Knot *LinkList);


int main()
{
    short LIMIT = 5;
    int ind, value;
    Knot *LinkList = NULL;

    // Inicializador de números aleatorios.
    srand(time(NULL)); 

    for (ind = 0; ind < LIMIT; ind++)
    {
        LinkList = RandomPositive(LinkList);
    }

    printf("\t--LISTA ORIGINAL--\n");
    ShowList(LinkList);

    printf("\n\nElija un valor para eliminar números que superen ese valor: ");
    scanf("%d", &value);

    LinkList = DeleteNumbers(LinkList, value);
    printf("\t--LISTA CAMBIADA--\n");
    ShowList(LinkList);

    return 0;
}

// Función para añadir elementos positivos aleatorios en la lista

Knot* RandomPositive(Knot *LinkList)
{
    Knot *NewKnot, *TempKnot;

    NewKnot = (Knot*)malloc(sizeof(Knot));
    NewKnot->data = rand() % 100;           // Guarda números positivos aleatorios entre 0 y 99
    NewKnot->link = NULL;                   // Hago que apunte al nuevo valor

    // Si la lista está vacía
    if (LinkList == NULL)
    {
        LinkList = NewKnot;                 // Asigna primer valor en la lista
        return LinkList;
    }

    // Sino, entonces se mueve al final de la lista
    TempKnot = LinkList;
    while(TempKnot->link != NULL)
        TempKnot = TempKnot->link;          // Se va cambiando la dirección del siguiente hasta encontrar el último

    TempKnot->link = NewKnot;

    return LinkList;

}

// Función para eliminar números mayores a un valor

Knot* DeleteNumbers(Knot *LinkList, int value)
{
    Knot *Actual, *Anterior = NULL;

    // Si la lista está vacía no hace nada
    if(LinkList ==  NULL)
        return LinkList;

    Actual = LinkList;

    while(Actual != NULL)
    {
        // Si el nodo es mayor
        if (Actual->data > value)
        {
            // Y si es el primero de la fila, se elimina
            if (Anterior == NULL)
            {
                LinkList = Actual->link;
                free(Actual);
                Actual = LinkList;
            }
            
            // Sino es el primero de la fila, se elimina
            else if(Anterior != NULL)
            {
                Anterior->link = Actual->link;
                free(Actual);
                Actual = Anterior->link;
            }
        }
        // Si el nodo es menor, se mueve al siguiente nodo
        else if (Actual->data < value)
        {
            Anterior = Actual;
            Actual = Actual->link;
        }

    }

    return LinkList;
}


// Función para mostrar todos los números

void ShowList(Knot *LinkList)
{
    Knot *PrintList = LinkList;

    while (PrintList != NULL)
    {
        printf("%d\t", PrintList->data);
        PrintList = PrintList->link;        // Se encuentra el último valor y se imprime
    }
}