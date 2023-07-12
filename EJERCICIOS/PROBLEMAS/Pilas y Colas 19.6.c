#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Escribir un programa en el que se generen 100 números aleatorios en el rango -25...+25 y se guarden en una cola implementada
    mediante un array considerado circular. Una vez creada la cola, el usuario debe pedir que se forme otra cola con los números
    negativos que tiene la cola original.
*/

typedef struct 
{
    int arr[100];
    int frente;
    int cola;
    int cont;
}Cola;

void insertarElemento(Cola*, int);
void eliminarElemento(Cola*);
void MostrarCola(Cola*);
void ColaNegativa(Cola*, Cola*);

int main ()
{
    int valor;
    srand(time(NULL));

    Cola colaOriginal;

    for(int ind = 0; ind < 100; ind++)
    {
        valor = rand() % 25;
        insertarElemento(&colaOriginal, valor);
    }

    printf("Cola Original: \n");
    MostrarCola(&colaOriginal);

    Cola colaNegativa;

    ColaNegativa(&colaOriginal, &colaNegativa);

    printf("\nCola Negativa: \n");
    MostrarCola(&colaNegativa);

    return 0;
}

void insertarElemento(Cola* cola, int elemento) 
{
    cola->cola = (cola->cola + 1) % 100;
    cola->arr[cola->cola] = elemento;
    cola->cont++;
}

void eliminarElemento(Cola* cola) 
{

    cola->frente = (cola->frente + 1) % 100;
    cola->cont--;
}

void MostrarCola(Cola* cola)
{
    int i, j;
    for(i = 0, j = cola->frente; i < cola->cont; i++)
    {
        printf("%d", cola->arr[j]);
        j = (j + 1) % 100;
    }

    printf("\n");
}

void ColaNegativa(Cola* colaOriginal, Cola* colaNegativa)
{
    int i, j;
    for(i =0, j = colaOriginal->frente; i < colaOriginal->cont; i++)
    {
        if(colaOriginal->arr[j] < 0)
            insertarElemento(colaNegativa, colaOriginal->arr[j]);

        j = (j + 1) % 100;
    }
}