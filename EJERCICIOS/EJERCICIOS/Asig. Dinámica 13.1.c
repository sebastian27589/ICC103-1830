#include <stdio.h>
#include <stdlib.h>

/*
    Encuentre los errores en las siguientes declaraciones 
    y sentencias.

    int n, *p;
    char** dob =  "Cadena de dos punteros";

    p = n*malloc(sizeof(int));


    R: En vez de char** dob, sería char *dob.
    Y en el puntero sería: p = malloc(n*sizeof(int)).
*/

int main()
{

    return 0;
}