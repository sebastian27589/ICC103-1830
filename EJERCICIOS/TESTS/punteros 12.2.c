#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*

    Escribir un programa en C que encuentre una matriz de numeros reales simetrica. 
    Para ello una funcion entera con entrada la matriz determinará si es simetrica. 
    En otra funcion se genera la matriz con numeros aleatorios de 1 a 19. Utilizar aritmetica 
    de punteros en la primera funcion, e indexacion en la segunda
*/

#define FILAS 3
#define COLUMNAS 3

// Prototipos de funciones
void generarMatriz(float matriz[FILAS][COLUMNAS]);
int esMatrizSimetrica(float matriz[FILAS][COLUMNAS]);

int main() {
    float matriz[FILAS][COLUMNAS];

    // Generar matriz aleatoria
    generarMatriz(matriz);

    // Verificar si es simétrica
    if (esMatrizSimetrica(matriz)) {
        printf("La matriz es simétrica.\n");
    } else {
        printf("La matriz no es simétrica.\n");
    }

    return 0;
}

// Función para generar la matriz con números aleatorios
void generarMatriz(float matriz[FILAS][COLUMNAS]) {
    srand(time(NULL));

    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            matriz[i][j] = rand() % 19 + 1;
        }
    }
}

// Función para verificar si la matriz es simétrica
int esMatrizSimetrica(float matriz[FILAS][COLUMNAS]) {
    // Comprobamos la simetría comparando los elementos de la matriz
    // mediante aritmética de punteros
    for (int i = 0; i < FILAS; i++) {
        for (int j = 0; j < COLUMNAS; j++) {
            if (*(matriz[i] + j) != *(matriz[j] + i)) {
                return 0;  // No es simétrica
            }
        }
    }

    return 1;  // Es simétrica
}