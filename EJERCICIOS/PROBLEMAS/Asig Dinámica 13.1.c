#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Escriba un programa para leer n cadenas de caracteres.
    Cada cadena tiene una longitud variable y está formada por cualquier carácter.
    La memoria que ocupa cada cadena se ha de ajustar al tamaño que tiene. Una vez 
    leídas las cadenas se debe realizar un proceso que consiste en eliminar todos los blancos,
    siempre manteniendo el espacio ocupado ajustado al número de caracteres. El programa
    debe mostrar las cadenas leídas y las cadenas transformadas.
*/

void SuprimirEspacio(char[]);

int main()
{
    int n, ind;
    const int MAX = 50;
    printf("Cantidad de cadenas que se van a leer: ");
    scanf("%d", &n);

    char **str = (char**)malloc(n * sizeof(char*));

    printf("\nIngrese las cadenas: ");
    fflush(stdin);
    for (ind = 0; ind < n; ind++)
    {
        printf("\nCadena [%d]: ", ind+1);
        str[ind] = (char*)malloc(MAX * sizeof(char));
        fgets(str[ind], MAX, stdin);

        // Para eliminar caracter nulo
        str[ind][strcspn(str[ind], "\n")] = '\0' ;
    }

    printf("\nCadenas originales: \n\n ");
    for (ind = 0; ind < n; ind++)
        printf("%s\n", str[ind]);

    printf("\nCadenas transformadas: \n\n");
    for (ind = 0; ind < n; ind++)
    {
        SuprimirEspacio(str[ind]);
        printf("%s\n", str[ind]);
    }
    

    return 0;
}

void SuprimirEspacio(char str[])
{
    int i, j = 0;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] != ' ')
        {
            str[j] = str[i];
            j++;
        }
    }
    str[j] = '\0';
}