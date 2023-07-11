#include <stdio.h>
#include <stdlib.h>


// Encuentre los errores de la siguiente declaración de estructura y posterior definición de variable //

struct hormiga
{
   int patas;
   char especie[41];
   float tiempo;
}hormiga colonia[100];

int main()
{

    /*
    
    R: El Error aquí es que no se puede poner "colonia[100]" donde va el nombre de la estructura,
    sino, que debería permanecer con los demás tipos de datos. 

    */

    return 0;
}