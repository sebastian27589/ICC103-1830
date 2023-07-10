#include <stdio.h>
#include <stdlib.h>

/*
    Escribir una función que tenga como entrada una cadena y devuelva un número real.
    La cadena contiene caracteres de un número real en formato decimal (por ejemplo, 
    ;a cadena "25.56" se ha de convertir en el correspondiente valor real).
*/

float ConvertirReal(char *);

int main()
{
    char *str = {"25.56"};

    float NumReal = ConvertirReal(str);

    printf("\nValor de la cadena: %s \t Valor real: %f", str, NumReal);

    return 0;
}

float ConvertirReal(char *str)
{
    float resultado = atof(str); // Con atof se puede convertir una cadena a un valor flotante según la librería stdlib.h
    return resultado;
}