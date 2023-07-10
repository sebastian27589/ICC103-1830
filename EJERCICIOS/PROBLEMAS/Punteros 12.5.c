#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Se quiere sumar enteros largos, con un número de dígitos que supera el máximo entero
    largo. Los enteros tienen un máximo de 40 dígitos. Para solventar el problema se 
    utilizan cadenas de caracteres para guardar cada entero y realizar la suma. 

    Escribir un programa que lea dos enteros largos y realice la suma.
*/

void Suma(char*, char*);

int main()
{
    const int MAXDIGIT = 41; // Núm maximo de enteros 
    char entero1[MAXDIGIT], entero2[MAXDIGIT];
    

    printf("Digite el primer entero largo: ");
    scanf("%s", entero1);
    printf("\nDigite el segundo entero largo: ");
    scanf("%s", entero2);

    Suma(entero1, entero2);

    return 0;
}

void Suma(char *str1, char *str2)
{
    int digit1, digit2, longitudMaxima, suma, ind, carry = 0;
    int longitud1 = strlen(str1);
    int longitud2 = strlen(str2);
    char *resultado;

    // Determinar longitud maxima
    
    if (longitud1 > longitud2) 
        longitudMaxima = longitud1;
    else
        longitudMaxima = longitud2;

    resultado = (char *)malloc((longitudMaxima + 2) * sizeof(char));

    for (ind = longitudMaxima; ind >= 0; ind--) 
    {
        digit1 = (ind < longitud1) ? (str1[longitud1 - 1 - ind] - '0') : 0;
        digit2 = (ind < longitud2) ? (str2[longitud2 - 1 - ind] - '0') : 0;
        suma = digit1 + digit2 + carry;
        carry = suma / 10;
        resultado[ind] = (suma % 10) + '0';
    }

    if (carry != 0) 
    {
        resultado[ind] = carry + '0';
        ind++;
    }

    resultado[ind] = '\0';

    printf("La suma es: %s", resultado);

}