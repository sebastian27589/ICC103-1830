#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXCADENA 100

void capturarFrase(char *str);
int capturarMatriz(char **str);
void mostrarMatriz(char **, int)

int main()
{
    char **matriz;
    int filas;
    
    //Tengo que asignarle algo a matriz porque no existe. En este caso le asigno un solo espacio.
    matriz = (char**)malloc(sizeof(char**)); 
    
    filas = capturarMatriz(matriz);
    mostrarMatriz(matriz, filas);

    return 0;
}

void capturarFrase(char *str)
{
    //const int MAXCADENA = 100;
    char cadenaTemporal[MAXCADENA];

    printf("Digite una frase: ");
    fflush(stdin);
    gets(cadenaTemporal);

    str = (char *)realloc(str, sizeof(char) * strlen(cadenaTemporal) + 1);
    strcpy(str, cadenaTemporal); 
}

int capturarMatriz(char **matriz)
{
    //char *pFrase;
    char continuar = 's';
    //pFrase = (char *)malloc(sizeof(char));
    
    //Cada que se ejecute el do - while, esta fila será 1+
    int filas = 1;

    do
    {
        //Con este realloc le agrando el espacio al doble puntero. (Primer arreglo)
        matriz = (char**)realloc(matriz, sizeof(char**)*(filas));
    
        //Con este malloc le asigno o le reservo espacio al arreglo que ya le asigne espacios anteriormente.
        //Para esto hago la desreferencia. (*)
        *(matriz+filas-1) = (char*)malloc(sizeof(char));

        //Lo mismo que con lo anterior. Pero ya no lo necesito porque tengo a *(mat+filas)
        //pFrase = (char *)malloc(sizeof(char));
        
        capturarFrase(*(matriz+filas-1));
        //printf("%s\n", *(matriz+filas-1));

        filas++;
        printf("¿Capturar otra frase? (S/N) ");
        fflush(stdin);
        continuar = tolower(getc(stdin));

    } while (continuar == 's');
    
    return filas - 1;
}

void mostrarMatriz(char **matriz, int filas)
{
    int ind;
    for(ind = 0; ind < filas; ind++)
        printf("%s\n", *(matriz+ind)); //Primera desreferencia.
}