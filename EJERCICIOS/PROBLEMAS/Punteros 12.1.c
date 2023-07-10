#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

    Escriba un programa en el que se lean 20 líneas de texto, cada línea con un máximo de 80 carácteres.
    Mostrar por pantalla el número de vocales que tiene cada línea.

*/

int NumVocales(char *);

int main()
{
    const int MAXCHAR = 81, MAXLINE = 20;
    char textline[MAXLINE][MAXCHAR];
    //const int MAXCHAR = 81;

    int cont = 19;

    printf("\nEscriba 20 líneas de texto que contengan un máximo de 80 carácteres cada uno.");
    printf("Comience aquí (20): ");
    for (int ind = 0; ind < MAXLINE; ind++)
    {
        fgets(textline[ind], MAXCHAR, stdin);

        int CantVocales = NumVocales(textline[ind]);

        printf("Esta línea tiene: %d vocales.\n", CantVocales);
        printf("\nDigite la siguiente línea (%d): ", cont--);
    }

    return 0;
}

int NumVocales(char *str)
{
    int cont = 0;
    //char caracter = *str;

    while (*str != '\0')
    {
        char caracter = *str;
        if (caracter == 'a' || caracter == 'e' || caracter == 'i'
            || caracter == 'o' || caracter == 'u')
            cont++;

        str++;
    }

    return cont;
}