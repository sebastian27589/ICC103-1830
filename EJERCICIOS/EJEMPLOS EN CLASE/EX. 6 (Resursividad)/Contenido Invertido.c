#include <stdio.h>
#include <stdlib.h>

/*
    Realice un programa que cpature un arreglo de valores enteros de tamaño
    N y los invierta utilizando una función recursiva void inverso_arreglo(int[], ind, int);

    La aplicación deberá al final imprimir el contenido invertido de dicho arreglo.
*/

void CapturarArreglo(int, int[]);
void Inverso_Arreglo(int[], int, int);
void MostrarArreglo(int, int[]);

int main()
{
    int n;
    printf("Cantidad de valores: ");
    scanf("%d", &n);

    int arr[n];

    CapturarArreglo(n, arr);
    MostrarArreglo(n, arr);
    Inverso_Arreglo(arr, 0, n - 1);
    printf("\n");
    MostrarArreglo(n, arr);
    return 0;
}

void CapturarArreglo(int n, int arr[])
{
    int ind;
    for(ind = 0; ind < n; ind++)
    {
        printf("\nValor [%d]:", ind + 1);
        scanf("%d", &arr[ind]);
    }
}

void Inverso_Arreglo(int arr[], int limI, int limS)
{
    int temp;

    // Axioma
    if (limI >= limS)
        return;
    
    // Cuerpo
    temp = arr[limI];
    arr[limI] = arr[limS];
    arr[limS] = temp;

    Inverso_Arreglo(arr, limI + 1, limS - 1);
}

void MostrarArreglo(int n, int arr[])
{
    int ind;
    for(ind = 0; ind < n; ind++)
        printf("\t%d", arr[ind]);
}