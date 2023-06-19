#include <stdio.h>
#include <stdlib.h>

/*
    Se tiene una lista simplemente enlazada de números reales. 
    Escribir una función para obtener una lista doble ordenada respecto 
    al campo dato, con los valores reales de la lista simple.
*/

typedef struct sDoubleNode
{
    double data;
    struct sDoubleNode* prev;
    struct sDoubleNode* next;
} DoubleNode;

void InsertInOrder(DoubleNode** head, double value) 
{
    DoubleNode* newNode = (DoubleNode*)malloc(sizeof(DoubleNode));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (*head == NULL) 
    {
        // La lista está vacía, el nuevo nodo se convierte en el primer y único nodo
        *head = newNode;
        return;
    }

    if (value < (*head)->data) 
    {
        // El nuevo nodo debe ser el nuevo nodo cabeza de la lista
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }

    DoubleNode* current = *head;

    while (current->next != NULL && current->next->data < value) 
    {
        current = current->next;
    }

    newNode->next = current->next;
    newNode->prev = current;
    if (current->next != NULL) 
    {
        current->next->prev = newNode;
    }
    current->next = newNode;
}

void CreateDoubleListFromSingle(DoubleNode** doubleList, SingleNode* singleList) 
{
    SingleNode* current = singleList;

    while (current != NULL) {
        InsertInOrder(doubleList, current->data);
        current = current->next;
    }
}