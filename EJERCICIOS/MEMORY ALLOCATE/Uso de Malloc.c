#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

    const int TAMANOCADENA  = 100;
    char cadena[TAMANOCADENA];

    printf("Digite su nombre completo: ");
    //fflush(stdin);
    gets(cadena);
    //puts(cadena);
    longitud = strlen(cadena);
    printf("%s\n Tamaño: %d\n", cadena, longitud);

    // Manejo dinámico de Memoria //

    char *pCadena;
    pCadena = (char*)malloc(sizeof(char)*longitud+1);

    strcpy(pCadena, cadena);

    puts(pCadena);

    return 0;
}