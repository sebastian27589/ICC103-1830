#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

    Escriba un programa en el que se lean 20 líneas de texto, cada línea con un máximo de 80 carácteres.
    Mostrar por pantalla el número de vocales que tiene cada línea.

*/

int main()
{
    char *textline[81];
    const int MAXCHAR = 20;

    printf("Escriba 20 líneas de texto que contengan un máximo de 80 carácteres cada uno.")
    for (int ind = 0; *(maxline+ind); ind++)
    {
        fgets();
        if ( *(maxline+ind) > MAXCHAR)
        {
            printf("Las línes no pueden contener mas de 80 carácteres.");
        }
    }

    return 0;
}