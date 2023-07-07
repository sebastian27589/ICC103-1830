#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

/*
    Realice un programa que permita imprimir una línea
    de texto de manera inversa utilizando una función
    recursiva sin emplear arreglos.
*/

void CapturarTextoInverso();

int main()
{
    // char letra;
    // fflush(stdin);
    // letra = getch();
    // printf("Letra capturada fue: %c", letra);
    fflush(stdin);
    CapturarTextoInverso();
    return 0;
}

void CapturarTextoInverso()
{
    char letraActual = getch();

    // Axioma
    //printf("%d", letraActual);
    if(letraActual == 13); // LF = LINE FEED (LINUX)  CR = CARRIAGE RETURN + LINE FIT (WINDOWS)
        return;

    // Llamada recursiva
    CapturarTextoInverso();

    printf("%c", letraActual);
}