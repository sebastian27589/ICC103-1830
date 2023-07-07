#include <stdio.h>
#include <stdlib.h>

/*
    Programar un algoritmo recursivo que permita sumar
    los elementos de un arreglo de enteros.
*/

void CapturarArreglo(int, int arr[]);
void MostrarArreglo(int, int arr[]);
int SumarArreglo(int, int arr[], int);

int main()
{
    int n;
    printf("Digite la cantidad de valores: ");
    scanf("%d", &n);
    printf("\n");

    int arr[n];

    CapturarArreglo(n, arr);
    printf("\n");
    MostrarArreglo(n, arr);

    printf("\nCantidad Sumada: [%d]\n", SumarArreglo(n, arr, 0));

    return 0;
}

void CapturarArreglo(int n, int arr[])
{
    int ind;
    for(ind = 0; ind < n; ind++)
    {
        printf("Digite el valor [%d]: ", ind+1);
        scanf("%d", &arr[ind]);
    }
}

void MostrarArreglo(int n, int arr[])
{
    int ind;
    for(ind = 0; ind < n; ind++)
    {
        printf("Valor [%d]: %d\n ", ind + 1, arr[ind]);
    }
}

int SumarArreglo(int n, int arr[], int posActual)
{
    // Hasta el final del arreglo.
    if (posActual >= n)
        return 0;

    return arr[posActual] + SumarArreglo(n, arr, posActual + 1);
}