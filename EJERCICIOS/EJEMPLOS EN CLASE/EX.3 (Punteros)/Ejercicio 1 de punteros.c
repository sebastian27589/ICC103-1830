#include <stdio.h>
#include <stdlib.h>

void capturarTamano(int*);
void capturarArreglo(int, int[]);
void mostrarArreglo(int, int[]);

int main()
{
    int n; // Valor: ¿indefinido? Dirección: 20aafe

    capturarTamano(&n); // 20aafe

    int arreglo[n];
    capturarArreglo(n, arreglo);
    mostrarArreglo(n, arreglo);

    return 0;
}

void capturarTamano(int *tamano) // Valor: 20aafe. Dirección: feab16
{
    printf("Digite el tama%co del arreglo: ", 164);
    scanf("%d", tamano); // &tamano = feab16  // tamano = 20aafe
}

void capturarArreglo(int n, int *arr)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("Digite el valor %d: ", i+1);
        scanf("%d", arr+i);
    }
}

void mostrarArreglo(int n, int *arr)
{
    int i;
    for(i=0; i<n; i++)
    {
        printf("%d\t", *(arr+i));
    }
}