#include <stdio.h>
#include <stdlib.h>

/*
    Programar un algoritmo recursivo que permita sumar
    los elementos de un arreglo de enteros.
*/

void CapturarMatriz(int fils, int cols, int mat[fils][cols]);
void MostrarMatriz(int fils, int cols, int mat[fils][cols]);
int SumarMatriz(int fils, int cols, int mat[fils][cols], int, int);

int main()
{
    int fils, cols;
    printf("Digite la cantidad de filas: ");
    scanf("%d", &fils);
    printf("\n");
    printf("Digite la cantidad de columnas: ");
    scanf("%d", &cols);

    int mat[fils][cols];

    CapturarMatriz(fils, cols, mat);
    printf("\n");
    MostrarMatriz(fils, cols, mat);

    printf("\nCantidad Sumada: [%d]\n", SumarMatriz(fils, cols, mat, 0, 0));

    return 0;
}

void CapturarMatriz(int fils, int cols, int mat[fils][cols])
{
    int indfil, indcol;
    for(indfil = 0; indfil < fils; indfil++)
    {
        for (indcol = 0; indcol < cols; indcol++)
        {
            printf("Digite el valor [%d][%d]: ", indfil + 1, indcol + 1);
            scanf("%d", &mat[indfil][indcol]);
        }
    }
}

void MostrarMatriz(int fils, int cols, int mat[fils][cols])
{
    int indfil, indcol;
    for(indfil = 0; indfil < fils; indfil++)
    {
        for (indcol = 0; indcol < cols; indcol++)
        {
            printf("[%d] ", mat[indfil][indcol]);
        }
        printf("\n");
    }
}

int SumarMatriz(int fils, int cols, int mat[fils][cols], int FilActual, int ColActual)
{
    // Hasta el final del arreglo.
    if (FilActual >= fils)
        return 0;
    
    if(ColActual + 1 >= cols)
        return mat[FilActual][ColActual] + SumarMatriz(fils, cols, mat, FilActual + 1, 0); // 0 Para poder iniciar en la siguiente linea
    else
        return mat[FilActual][ColActual] + SumarMatriz(fils, cols, mat, FilActual, ColActual + 1);

}