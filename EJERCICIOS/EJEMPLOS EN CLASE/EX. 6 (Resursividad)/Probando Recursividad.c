#include <stdio.h>
#include <stdlib.h>

void MostrarRangoIterativo(int, int);
void MostrarRangoRecursivo(int, int, int);

int main()
{
    int limI, limS, ValorActual;

    printf("Digite los limites: ");
    do
    {
        printf("Inferior: ");
        scanf("%d", &limI);
        printf("Superior: ");
        scanf("%d", &limS);
    } while (limI > limS);

    //MostrarRangoIterativo(limI, limS);
    MostrarRangoRecursivo(limI, limS, limI);
    return 0;
}

void MostrarRangoIterativo(int LimI, int LimS)
{
    int ValorActual;
    for(ValorActual = LimI; ValorActual <= LimS; ValorActual++)
    {
        printf("%d\t", ValorActual);
    }
}

void MostrarRangoRecursivo(int LimI, int LimS, int ValorActual)
{
    // Axioma, o caso base. (Condición de parada)
    if(ValorActual > LimS)
        return;

    // Cuerpo:
    printf("%d\t", ValorActual);

    // Llamada recursiva (con un cambio).
    MostraRangoRecursivo(LimI, LimS, ValorActual + 1);

    // Ahora imprimo otra cosa:
    printf("\n Mitad: %d\t", ValorActual / 2);
    printf("%d\t", ValorActual);
}