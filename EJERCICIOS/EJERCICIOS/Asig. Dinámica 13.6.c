#include <stdio.h>
#include <stdlib.h>

/*
    ¿Qué diferencia existen entre las funciones 
    malloc(), calloc() y realloc();

    R: Tanto malloc como calloc, sirven para alojar memoria, sin embargo,
    malloc toma datos cualquiera lo cual hace que no esté vacío. Mientras que calloc
    no lo hace, porque lo inicializa en 0, es decir NULL.

    Y realloc, se encarga de incrementar esa cantidad alojada luego de calloc / malloc.
*/

int main()
{

    return 0;
}