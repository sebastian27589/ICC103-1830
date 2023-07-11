#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    Un punto en el plano se puede representar mediante una estructura de dos campos. Escribir un programa que realice
    las siguientes operaciones con puntos en el plano.

    - Dado dos puntos, calcular la distancia entre ellos.
    - Dado dos puntos determinar la ecuación de la recta que pasa por ellos.
*/

typedef struct
{
    float x;
    float y;
}PuntoPlano;

typedef struct
{
    float Pendiente;
    float CorteEjeY;
}Ecuacion;

float CalcularDistancia(PuntoPlano, PuntoPlano);
Ecuacion EcuacionLinealRecta(PuntoPlano, PuntoPlano);

int main()
{
    PuntoPlano p1, p2;
    float resultado;

    printf("Ingrese primer par ordenado separados por comas (x,y): ");
    scanf("%f,%f", &p1.x, &p1.y);

    printf("\n");
    printf("Ingrese segundo par ordenado separados por comas (x,y): ");
    scanf("%f,%f", &p2.x, &p2.y);

    // Distancia entre puntos.
    printf("\n");
    resultado = CalcularDistancia(p1, p2);
    printf("DISTANCIA ENTRE PUNTOS: [%.2f]\n", resultado);

    // Ecuación de la recta que pasa entre ellos.
    Ecuacion ecuacion = EcuacionLinealRecta(p1, p2);
    printf("ECUACION LINEAL DE LA RECTA: [y = %.2fx + %.2f]", ecuacion.Pendiente, ecuacion.CorteEjeY);
    
    return 0;
}

float CalcularDistancia(PuntoPlano p1, PuntoPlano p2)
{
    float resultado;

    // Fórmula que calcula la distancia entre dos puntos.
    resultado = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));

    return resultado;
}

Ecuacion EcuacionLinealRecta(PuntoPlano p1, PuntoPlano p2)
{
    Ecuacion Recta;

    // Fórmula de la pendiente.
    Recta.Pendiente = (p2.y - p1.y) / (p2.x - p1.x);

    // Buscar corte con el eje Y.
    Recta.CorteEjeY = p1.y - (Recta.Pendiente * p1.x);

    return Recta;
}
