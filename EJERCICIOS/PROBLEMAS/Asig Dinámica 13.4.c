#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
    Se tiene una matriz de 20 x 20 elementos enteros. En la matriz hay un elemento repetido
    muchas veces. Se quiere generar otra matriz de 20 filas y que en cada fila estén sólo los
    elementos no repetidos. Escribir un programa que tenga como entrada la matriz de 20 x 20, 
    genere la matriz dinámica pedida y que se muestre en pantalla.
*/
const int MAXFIL = 5, MAXCOL = 5;

void GenerarMatriz(int **mat);
void MostrarMatriz(int **mat);
void MatrizSinRepetidos(int **mat, int **mat2);
void MostrarMatrizSinRepetidos(int **mat);

int main()
{
    //const int MAXFIL = 20, MAXCOL = 20;
    int **mat = (int**)malloc(5 * sizeof(int*));
    int **mat2 = (int**)malloc(5 * sizeof(int*));

    for (int i = 0; i < 5; i++)
    {
        mat[i] = (int*)malloc(5 * sizeof(int));
        mat2[i] = (int*)malloc(5 * sizeof(int));
    }

    srand(time(NULL));

    GenerarMatriz(mat);
    MostrarMatriz(mat);
    MatrizSinRepetidos(mat, mat2);
    MostrarMatrizSinRepetidos(mat2);

    return 0;
}

void GenerarMatriz(int **mat)
{
    //printf("\nIngrese los elementos de la matriz:");

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            mat[i][j] = rand() % 15;
        }
    }
}

void MostrarMatriz(int **mat)
{
    printf("\nMatriz original: ");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("[%d]", mat[i][j]);
        }
        printf("\n");
    }
}

void MatrizSinRepetidos(int **mat, int **mat2)
{  
    // Encontrar elementos no repetidos de la matriz

    for (int i = 0; i < MAXFIL; i++)
    {
        int k = 0;
        for (int j = 0; j < MAXCOL; j++)
        {
            int repetido = 0;
            for (int p = 0; p < j; p++)
            {
                if (mat[i][p] == mat[i][j])
                {
                    repetido = 1;
                    break;
                }
            }
            if (!repetido)
            {
                mat2[i][k] = mat[i][j];
                k++;
            }
        }
    }
}

void MostrarMatrizSinRepetidos(int **mat)
{
    printf("\nMatriz sin elementos repetidos: ");
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("[%d]", mat[i][j]);
        }
        printf("\n");
    }
}