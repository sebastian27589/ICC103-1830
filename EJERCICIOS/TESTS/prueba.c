#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct sAlumno {
    char nombre[100];
    int edad;
    char sexo;
    struct sAlumno* next;
} Alumno;

void TransformarLista(Alumno** head) {
    if (*head == NULL || (*head)->next == NULL) {
        // La lista está vacía o solo tiene un elemento, no hay cambios que hacer
        return;
    }

    Alumno* current = *head;
    Alumno* next = (*head)->next;

    while (current != NULL && next != NULL) {
        if (current->sexo == 'M' && next->sexo == 'F') {
            // El primer nodo es masculino y el siguiente es femenino, avanzamos dos nodos
            current = next->next;
            if (current != NULL) {
                next = current->next;
            }
        } else if (current->sexo == 'F' && next->sexo == 'M') {
            // El primer nodo es femenino y el siguiente es masculino, intercambiamos los nodos
            Alumno* temp = current->next;
            current->next = next->next;
            next->next = current;
            if (*head == current) {
                *head = next;
            }
            current = temp;
            if (current != NULL) {
                next = current->next;
            }
        } else {
            // Los nodos no cumplen el patrón de sexo esperado, avanzamos un nodo
            current = next;
            next = (current != NULL) ? current->next : NULL;
        }
    }
}

void PrintList(Alumno* head) {
    Alumno* current = head;

    while (current != NULL) {
        printf("Nombre: %s, Edad: %d, Sexo: %c\n", current->nombre, current->edad, current->sexo);
        current = current->next;
    }
}

int main() {
    Alumno* lista = NULL;

    // Agregar nodos a la lista (ejemplo)
    Alumno* alumno1 = (Alumno*)malloc(sizeof(Alumno));
    strcpy(alumno1->nombre, "Maria");
    alumno1->edad = 20;
    alumno1->sexo = 'F';
    alumno1->next = NULL;

    Alumno* alumno2 = (Alumno*)malloc(sizeof(Alumno));
    strcpy(alumno2->nombre, "Roberto");
    alumno2->edad = 22;
    alumno2->sexo = 'M';
    alumno2->next = NULL;

    Alumno* alumno3 = (Alumno*)malloc(sizeof(Alumno));
    strcpy(alumno3->nombre, "Carlos");
    alumno3->edad = 19;
    alumno3->sexo = 'M';
    alumno3->next = NULL;

    // Construir la lista enlazada
    alumno1->next = alumno2;
    alumno2->next = alumno3;
    lista = alumno1;

    printf("Lista original:\n");
    PrintList(lista);

    // Transformar la lista
    TransformarLista(&lista);

    printf("\nLista transformada:\n");
    PrintList(lista);

    // Liberar memoria
    Alumno* current = lista;
    Alumno* next = NULL;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }

    return 0;
}