#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
    Escribir un programa que permita calcular el área de diversas
    figuras: un triángulo rectángulo, isósceles, cuadrado, trapecio
    y un círculo. Utilizar array de punteros de funciones, siendo las 
    funciones las que permiten calcular el área. 
*/

float CalcAreaCuadrado(float lado);
float CalcAreaTriRectangulo(float base, float altura);
float CalcAreaTriIsosceles(float base, float altura);
float CalcAreaTrapecio(float baseMenor, float baseMayor, float altura);
float CalcAreaCirc(float radio);

int main()
{
    float base, altura, lado, baseMayor, baseMenor, Pi;
    int opcion;
    float (*areaFigura[])(float, float) = { CalcAreaTriRectangulo, CalcAreaTriIsosceles};
    float (*areaFigura2[])(float) = { CalcAreaCuadrado, CalcAreaCirc };
    float (*areaFigura3[])(float, float, float) = { CalcAreaTrapecio };

    printf("Seleccione una figura:\n");
    printf("1. Cuadrado\n");
    printf("2. Triángulo rectángulo\n");
    printf("3. Triángulo isósceles\n");
    printf("4. Trapecio\n");
    printf("5. Círculo\n");
    printf("Opción: ");
    //scanf("%d", &opcion);
    
    // Verificar respuesta
    do
    {
        scanf("%d", &opcion);

        if (opcion < 1 || opcion > 5)
            printf("\nFUERA DEL RANGO. Escriba de nuevo:");
    }while (opcion < 1 || opcion > 5);

        switch (opcion)
        {
        case 1:
            printf("Lado del cuadrado: ");
            scanf("%f", &lado);
            float resultado1 = areaFigura2[0](lado);
            printf("Resultado: %.2f" , resultado1);
            break;
        case 2:
            printf("Base del triángulo: ");
            scanf("%f", &base);
            printf("\nAltura del triángulo: ");
            scanf("%f", &altura);
            float resultado2 = areaFigura[opcion - 1](base, altura);
            printf("Resultado: %.2f" , resultado2);
            break;
        case 3:
            printf("Base del triángulo: ");
            scanf("%f", &base);
            printf("\nAltura del triángulo: ");
            scanf("%f", &altura);
            float resultado3 = areaFigura[opcion - 1](base, altura);
            printf("Resultado: %.2f" , resultado3);
            break;
        case 4:
            printf("Base menor: ");
            scanf("%f", &baseMenor);
            printf("\nBase mayor: ");
            scanf("%f", &baseMayor);
            printf("\nAltura: ");
            scanf("%f", &altura);
            float resultado4 = areaFigura3[0](baseMenor, baseMayor, altura);
            printf("Resultado: %.2f" , resultado4);
            break;
        case 5:
            printf("Radio: ");
            scanf("%f", &Pi);
            float resultado5 = areaFigura2[1](Pi);
            printf("Resultado: %.2f" , resultado5);
            break;
        default:
            break;
        }

    return 0;
}

float CalcAreaCuadrado(float lado)
{
    return lado * lado;
}
float CalcAreaTriRectangulo(float base, float altura)
{
    return (base * altura) / 2;
}
float CalcAreaTriIsosceles(float base, float altura)
{
    return (base * altura) / 2;
}
float CalcAreaTrapecio(float baseMenor, float baseMayor, float altura)
{
    return ((baseMayor*baseMenor) * altura) / 2;
}
float CalcAreaCirc(float radio)
{
    return 3.14 * radio * radio;
}