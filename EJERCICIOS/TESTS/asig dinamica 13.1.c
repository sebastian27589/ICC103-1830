#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
    Escribir un programa en C para leer N cadenas de caracteres. Cada cadena tiene una longitud variable y esta 
    formada por cualquier caracter. La memoria que ocupa cada caracter se ha de ajustar al tamaño que tiene UNa 
    vez leidas las cadenas, se debe realizar un proceso que consiste en eliminar todos los blancos, siempre manteniendo el 
    espacio ocupado ajustado al numero de caracteres. El programa debe mostrar las cadenas leidas y las cadenas transformadas. 
*/

#define MAX_CADENAS 10
#define MAX_LONGITUD 100

void eliminarBlancos(char *cadena);

int main() {
    char cadenas[MAX_CADENAS][MAX_LONGITUD];
    int n;

    printf("Ingrese el número de cadenas a leer (máximo %d): ", MAX_CADENAS);
    scanf("%d", &n);

    // Limpiar el búfer del teclado
    fflush(stdin);

    if (n > MAX_CADENAS) {
        printf("El número de cadenas supera el máximo permitido.\n");
        return 1;
    }

    // Leer las cadenas
    printf("Ingrese las cadenas de caracteres:\n");
    for (int i = 0; i < n; i++) {
        printf("Cadena %d: ", i + 1);
        fgets(cadenas[i], MAX_LONGITUD, stdin);

        // Eliminar el salto de línea final
        int longitud = strlen(cadenas[i]);
        if (cadenas[i][longitud - 1] == '\n') {
            cadenas[i][longitud - 1] = '\0';
        }
    }

    // Mostrar las cadenas originales
    printf("\nCadenas originales:\n");
    for (int i = 0; i < n; i++) {
        printf("Cadena %d: %s\n", i + 1, cadenas[i]);
    }

    // Eliminar los espacios en blanco
    for (int i = 0; i < n; i++) {
        eliminarBlancos(cadenas[i]);
    }

    // Mostrar las cadenas transformadas
    printf("\nCadenas transformadas:\n");
    for (int i = 0; i < n; i++) {
        printf("Cadena %d: %s\n", i + 1, cadenas[i]);
    }

    return 0;
}

// Función para eliminar los espacios en blanco de una cadena
void eliminarBlancos(char *cadena) {
    char *destino = cadena;
    char *origen = cadena;

    while (*origen != '\0') {
        if (*origen != ' ') {
            *destino = *origen;
            destino++;
        }
        origen++;
    }

    *destino = '\0';  // Agregar el carácter nulo al final de la cadena
}