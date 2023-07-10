#include <stdio.h>
#include <stdlib.h>

/*
    Se desea escribir un programa para leer números grandes y obtener la suma de ellos.
    El almacenamiento de un número grande se ha de hacer en una estructura que tenga un array dinámico
    y otro campo con el número de dígitos. La suma de dos números grandes dará como resultado otro
    número grande representado en su correspondiente estrcutura. 
*/

typedef struct 
{
    int numDigit;
    int* arr;
} NumLargo;

NumLargo SumarNumeros(NumLargo, NumLargo);

int main()
{
    NumLargo num1, num2, suma;
    int cantDigitos;

    printf("\nDigite primer número grande. \n");
    printf("Cantidad de dígitos: ");
    scanf("%d", &cantDigitos);

    num1.arr = (int*)malloc(cantDigitos * sizeof(int));
    num1.numDigit = cantDigitos;

    printf("\nIngrese sus dígitos: \n ");
    for (int ind = 0; ind < cantDigitos; ind++)
    {
        printf("Digito [%d]: ", ind + 1);
        scanf("%d", &num1.arr[ind]);
    }
        
    
    printf("\n\nDigite segundo número grande. \n");
    printf("Cantidad de dígitos: ");
    scanf("%d", &cantDigitos);

    num2.arr = (int*)malloc(cantDigitos * sizeof(int));
    num2.numDigit = cantDigitos;

    printf("\nIngrese sus dígitos: \n");
    for (int ind = 0; ind < cantDigitos; ind++)
    {
        printf("Digito [%d]: ", ind + 1);
        scanf("%d", &num2.arr[ind]);
    }

    suma = SumarNumeros(num1, num2);

    printf("La suma de los números grandes es: ");
    for (int ind = 0; ind < suma.numDigit; ind++)
        printf("%d", suma.arr[ind]);
    
    return 0;
}
NumLargo SumarNumeros(NumLargo num1, NumLargo num2)
{
    NumLargo suma;
    int carry = 0; // Llevamos el acarreo al sumar los dígitos
    suma.arr = (int*)malloc((num1.numDigit + 1) * sizeof(int)); 
    suma.numDigit = num1.numDigit + 1;

    // Suma dígito a dígito
    for (int i = num1.numDigit - 1; i >= 0; i--) {
        int digitSuma = num1.arr[i] + num2.arr[i] + carry;
        suma.arr[i + 1] = digitSuma % 10; // El dígito se guarda en la posición correspondiente en el array
        carry = digitSuma / 10; // Calculamos el acarreo para la siguiente suma
    }

    suma.arr[0] = carry; 
    return suma;
}