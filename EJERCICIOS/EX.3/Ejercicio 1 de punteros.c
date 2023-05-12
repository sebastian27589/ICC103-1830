#include <stdio.h>
#include <stdlib.h>

void capturarTamano(int*);
void capturarArreglo(int, int[]);
void mostrarArreglo(int, int[]);

int main()
{
    int cantidad; //Valor: Indefinido. Dirección: 20aafe
    
    capturarTamano(&cantidad); //20aafe

    //printf("%d\n", cantidad);
    int arreglo[cantidad];

    capturarArreglo(cantidad, arreglo);
    mostrarArreglo(cantidad, arreglo);


    return 0;
}

void capturarTamano(int *tamano) //Valor: 20aafe. Dirección: feab16
{
    printf("Digite el tama%co del arreglo: ", 164);
    scanf("%d", tamano); //ERROR: Si fuera &tamano = feab16 // Forma correcta sería: tamano = 20aafe
    printf("\n");
}

void capturarArreglo(int cantidad, int *arr)
{
    int ind;
    for(ind = 0; ind < cantidad; ind++)
    {
        printf("Digite el valor %d: ", ind+1);
        scanf("%d", arr+ind);
    }

}

void mostrarArreglo(int cantidad, int *arr)
{
    int ind;
    for(ind = 0; ind < cantidad; ind++)
    {
        printf("%d ", *(arr+ind));
    }

}