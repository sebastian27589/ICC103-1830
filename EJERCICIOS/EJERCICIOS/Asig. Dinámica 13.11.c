#include <stdio.h>
#include <stdlib.h>

/*
    ¿Qué diferencia existe entre las siguientes declaraciones?

    char *c[15];
    char **c,
    char c[15][12];

    R: char *c[15], es un arreglo de 15 punteros que puede apuntar a una cadena de caracteres.
    char **c, es un doble puntero, en la que uno de ellos apunta a otro, y ese otro puede apuntar a un arreglo de caracteres.
    char c[15][12], es una matriz 15x12
    
*/

int main()
{

    return 0;
}