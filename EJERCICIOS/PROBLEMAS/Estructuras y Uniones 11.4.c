#include <stdio.h>
#include <stdlib.h>

/*
    Escriba un programa que permita hacer las operaciones de suma, resta, multipiclación y división de números
    complejos. El tipo complejo ha de definirse como una estructura. 
*/

typedef struct 
{
    float real;
    float imaginario;
}Complejo;

Complejo SumarComplejos(Complejo, Complejo);
Complejo RestaComplejos(Complejo, Complejo);
Complejo ProductoComplejos(Complejo, Complejo);
Complejo DivisionComplejos(Complejo, Complejo);

int main()
{
    Complejo num1, num2, resultado;

    printf("Primer número complejo: \n");
    printf("Real: ");
    scanf("%f",&num1.real);
    printf("\nImaginario: ");
    scanf("%f",&num1.imaginario);

    printf("Segundo número complejo: \n");
    printf("Real: ");
    scanf("%f",&num2.real);
    printf("\nImaginario: ");
    scanf("%f",&num2.imaginario);

    resultado = SumarComplejos(num1, num2);
    printf("\nSuma de complejos = [%.2f] + [%.2fi]\n", resultado.real, resultado.imaginario);

    resultado = RestaComplejos(num1, num2);
    printf("\nResta de complejos = [%.2f] + [%.2fi]\n", resultado.real, resultado.imaginario);

    resultado = ProductoComplejos(num1, num2);
    printf("\nProducto de complejos = [%.2f] + [%.2fi]\n", resultado.real, resultado.imaginario);

    resultado = DivisionComplejos(num1, num2);
    printf("\nDivision de complejos = [%.2f] + [%.2fi]\n", resultado.real, resultado.imaginario);


    return 0;
}

Complejo SumarComplejos(Complejo num1, Complejo num2)
{
    Complejo resultado;

    resultado.real = num1.real + num2.real;
    resultado.imaginario = num1.imaginario + num2.imaginario;

    return resultado;
}

Complejo RestaComplejos(Complejo num1, Complejo num2)
{
    Complejo resultado;

    resultado.real = num1.real - num2.real;
    resultado.imaginario = num1.imaginario - num2.imaginario;

    return resultado;
}

Complejo ProductoComplejos(Complejo num1, Complejo num2)
{
    Complejo resultado;

    resultado.real = (num1.real * num2.real) - (num1.imaginario * num2.imaginario);
    resultado.imaginario = (num1.real * num2.real) + (num1.imaginario * num2.imaginario);

    return resultado;
}

Complejo DivisionComplejos(Complejo num1, Complejo num2)
{
    Complejo resultado;
    float denominadorReal = (num2.real * num2.real) + (num2.imaginario * num2.imaginario);
    resultado.real = ((num1.real * num2.real) + (num1.imaginario * num2.imaginario)) / denominadorReal;
    resultado.imaginario = ((num1.real * num2.real) - (num1.imaginario * num2.imaginario)) / denominadorReal;

    return resultado;
}