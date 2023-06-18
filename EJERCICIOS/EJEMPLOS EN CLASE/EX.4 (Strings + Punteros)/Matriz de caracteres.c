#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cstring>

int capturarMatriz(char**);
int capturarFrase(char*);
void mostrarMatriz(char**, int);

int main()
{
    char **matriz;
    int cantidadFrases;
    matriz = (char**)malloc(sizeof(char**));

    cantidadFrases = capturarMatriz(matriz);

    mostrarMatriz(matriz, cantidadFrases);
    /*
    *(matriz+0) = (char*)malloc(sizeof(char)*100);
    gets(*(matriz+0));
    puts(*(matriz+0));*/

    return 0;
}

int capturarMatriz(char **matr)
{
    char continuar = 's';
    int filas = 0;

    do
    {
        matr = (char**)realloc(matr, sizeof(char**)*(filas+1));
        *(matr+filas) = (char*)malloc(sizeof(char)*(100));

        capturarFrase(*(matr+filas));

        filas++;
        printf("Capturar otra frase? (S/N) ");
        fflush(stdin);
        continuar = tolower(getc(stdin));
    } while (continuar == 's');
    
    return filas;
}

int capturarFrase(char *cadena)
{
    //const int TAMANOMAXIMO = 100;
    int longitudCadena;
    char cadenaTemporal[100];
    
    printf("Digite una frase: ");
    fflush(stdin);
    gets(cadenaTemporal);
    longitudCadena = strlen(cadenaTemporal);

    cadena = (char*)realloc(cadena, longitudCadena * sizeof(char)+1);

    strcpy(cadena, cadenaTemporal);

    return longitudCadena;
}

void mostrarMatriz(char **matr, int filas)
{
    int i;
    
    for(i=0; i<filas; i++)
    {
        puts(*(matr+i));
    }
}