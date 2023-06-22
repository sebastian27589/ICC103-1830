#include <stdio.h>

/*
    se requiere evaluar las funciones f(x), g(x) y z(x) para todos los valores de x 
    en el intervalo 0 <= x <3.5 con incremento de 0.2. Escribir un programa en C que evalue 
    dichas funciones, utilizar un array de punteros a funcion. Las funciones son las siiguientes: 
    f(x) = 3*e^x - 2x, g(x)= -x*sin(x) + 1.5 y z(x) = x^2 - 2x +3

*/

// Declaración de las funciones
double f(double x);
double g(double x);
double z(double x);

int main() {
    double x = 0.0;
    double incremento = 0.2;
    double limite = 3.5;

    // Array de punteros a función
    double (*funciones[])(double) = {f, g, z};

    int numFunciones = sizeof(funciones) / sizeof(funciones[0]);
    int numValores = (limite - x) / incremento;

    for (int i = 0; i < numFunciones; i++) {
        printf("Evaluando función %d:\n", i + 1);
        printf("x\t\tf(x)\n");
        printf("-----------------\n");
        for (int j = 0; j < numValores; j++) {
            double resultado = funciones[i](x);
            printf("%.1f\t\t%.2f\n", x, resultado);
            x += incremento;
        }
        printf("\n");
        x = 0.0;
    }

    return 0;
}

// Implementación de las funciones
double f(double x) {
    double e = 2.71828;  // Valor aproximado de e
    return 3 * pow(e, x) - 2 * x;
}

double g(double x) {
    double sin_x = 0.0;
    double term = x;
    double sign = 1.0;
    double fact = 1.0;

    for (int i = 1; i <= 9; i++) {
        sign *= -1;
        term *= x * x;
        fact *= (2 * i) * (2 * i + 1);
        sin_x += sign * term / fact;
    }

    return -x * sin_x + 1.5;
}

double z(double x) {
    return x * x - 2 * x + 3;
}