#include <stdio.h>
#include <stdlib.h>

/*
    Realice un programa que busque factorial

*/

int factorial(int);

int main()
{
    int valor;
    printf("Digite el valor: ");
    scanf("%d", &valor);

    printf("El factorial de %d es: %d.", valor, factorial(valor));
    return 0;
}

int factorial( int valor)
{

    // Axioma
    if (valor <= 1)
        return 1;

    // LLamada recursiva y cuerpo:
    return valor * factorial(valor - 1);

}