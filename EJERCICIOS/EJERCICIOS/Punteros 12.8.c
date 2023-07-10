#include <stdio.h>
#include <stdlib.h>

int main()
{
    /*

    P: ¿Qué diferencia se puede encontrar entre estas dos declaraciones?


    float  mt[5][5];
    float *m[5];

    R: La diferencia es que en mt[5][5] es un arreglo multidimensional 
    mientras que *m[5], quiere decir que es un arreglo de punteros en el que hay 5 elementos, y que esos 5 elementos,
    cada uno tiene un puntero.

    P2: Se podría hacer estas asignaciones?

    m = mt;
    m[1] = mt[1];
    m[2] = &mt[2][0];

    R: Si se puede, siempre y cuando tengan espacio asignado. 
    m[1] quiere decir que le asigno la dirección de memoria la primer elemento de la matriz en mt[1]
    m[2] quiere decir que le asigno la dirección al primer elemento de la 2da fila de mt[2][0]
    
    */

    return 0;
}