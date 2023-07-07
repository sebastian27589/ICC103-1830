#include <stdio.h>
#include <stdlib.h>

/*
    Realice un programa que, recursivamente, capture valores positivos
    y muestre al final su suma. 

*/

int SumarValoresUsuario();

int main()
{
    printf("%d\n", SumarValoresUsuario());
    return 0;
}

int SumarValoresUsuario()
{
    int valorActual;
    
    // Axioma.
    printf("Digite un valor (positivo): ");
    scanf("%d", &valorActual);

    if (valorActual <= 0)
        return 0; // Para que cuando se sume, no lo altere se le retorna +0.


    // Cuerpo y llamada recursiva
    return valorActual + SumarValoresUsuario();
}