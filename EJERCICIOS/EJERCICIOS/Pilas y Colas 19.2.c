#include <stdio.h>
#include <stdlib.h>

/*
    Escribir en el archivo pila.h los tipos de datos y los
    prototipos de las operaciones básicas sobre pilas con estructuras
    dinámicas.
*/

typedef struct sNodo
{
    int data;
    struct sNodo *siguiente;
}Nodo;

typedef struct
{
    Nodo* cima;
}Pila;


// Prototipos básicos de las operaciones de pilas comn estructuras
void CrearPila(Pila* );
void Apilar (Pila* );
void Desapilar (Pila*);
void CimaPila(Pila*);
void PilaVacia(Pila*);

int main()
{

    return 0;
}