#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_PALABRA 100
#define MAX_DEFINICION 1000

typedef struct 
{
    char palabra[MAX_PALABRA];
    int longitud;
    char definicion[MAX_DEFINICION];
    long posicion;
}EntradaDiccionario;

int compararPorAlfabeticoInverso(const void *a, const void *b);
int compararPorLongitud(const void *a, const void *b);
int compararPorPalabra(const void *a, const void *b);
void agregarEntrada(FILE *archivoDiccionario);
void buscarPalabra(const char *palabraBuscada, FILE *archivoDiccionario, int numEntradas);
void eliminarEntrada(FILE *archivoDiccionario);
void leerDefinicion(FILE *archivo, char *definicion);
void mostrarEntradasEnOrden(FILE *archivoDiccionario);
void mostrarEntradasOrdenAlfabeticoInverso(FILE *archivoDiccionario, int numEntradas);
void mostrarEntradasOrdenLongitud(FILE *archivoDiccionario, int numEntradas);
void mostrarMenu();

int main() 
{
    FILE *archivoDiccionario = fopen("diccionario.txt", "r+");
    if (archivoDiccionario == NULL) {
        printf("Error al abrir el archivo.\n");
        return 1;
    }

    char palabra[MAX_PALABRA];
    char definicion[MAX_DEFINICION];
    EntradaDiccionario entrada;
    int numEntradas = 0;

    while (fscanf(archivoDiccionario, "%s", palabra) == 1) 
    {
        fseek(archivoDiccionario, 1, SEEK_CUR); 
        fgets(definicion, MAX_DEFINICION, archivoDiccionario);
        definicion[strcspn(definicion, "\n")] = '\0'; 

        strcpy(entrada.palabra, palabra);
        entrada.longitud = strlen(palabra);
        strcpy(entrada.definicion, definicion);
        entrada.posicion = ftell(archivoDiccionario) - strlen(definicion) - strlen(palabra) - 2;

        numEntradas++;
    }

    int opcionPrincipal;
    do 
    {
        mostrarMenu();
        scanf("%d", &opcionPrincipal);

        switch (opcionPrincipal) 
        {
            case 1:
                // Buscar el significado de una palabra en el diccionario
                {
                    char palabraBuscada[MAX_PALABRA];
                    printf("Ingrese la palabra a buscar: ");
                    scanf("%s", palabraBuscada);
                    buscarPalabra(palabraBuscada, archivoDiccionario, numEntradas);
                }
                break;

            case 2:
                // Agregar una nueva entrada al diccionario
                agregarEntrada(archivoDiccionario);
                numEntradas++;
                break;

            case 3:
                // Eliminar una entrada del diccionario
                eliminarEntrada(archivoDiccionario);
                numEntradas--;
                break;

            case 4:
                int opcion, opcionSalida = 0;
                do
                {
                
                    printf("\nATENCION: SE MOSTRARAN TODAS LAS PALABRAS [POR ORDEN ALFABETICO] QUE ESTEN REGISTRADAS EN EL ARCHIVO.\n");
                    printf("CUANDO SE GENEREN PUEDE IR PRESIONANDO [ENTER] PARA GENERAR MAS ENTRADAS O [Q] PARA TERMINAR DE GENERAR Y SALIR.\n");
                    printf("\nINGRESE [1] PARA COMENZAR CON LA EJECUCION - [2] PARA VOLVER: ");

                    scanf("%d", &opcion);
                    
                    switch (opcion)
                    {
                        
                        case 1:
                            // Mostrar las entradas en el mismo orden en el que estan registradas en el archivo de texto
                            mostrarEntradasEnOrden(archivoDiccionario);
                            opcionSalida = 1;
                            break;

                        case 2:
                            //char salida;
                            printf("\n\n[Saliendo...]");
                            opcionSalida = 1;
                            break;
                        
                        default:
                            printf("\nOpcion invalida. Intente nuevamente.\n");
                            break;
                    }
                } while (opcionSalida != 1);
                break;
        
            case 5:
                int opcion2, opcionSalida2 = 0;
                do
                {
                
                    printf("\nATENCION: SE MOSTRARAN TODAS LAS PALABRAS [POR ORDEN ALFABETICO INVERSO] QUE ESTEN REGISTRADAS EN EL ARCHIVO.\n");
                    printf("CUANDO SE GENEREN PUEDE IR PRESIONANDO [ENTER] PARA GENERAR MAS ENTRADAS O [Q] PARA TERMINAR DE GENERAR Y SALIR.\n");
                    printf("\nINGRESE [1] PARA COMENZAR CON LA EJECUCION - [2] PARA VOLVER: ");

                    scanf("%d", &opcion2);
                    
                    switch (opcion2)
                    {
                        
                        case 1:
                            // Mostrar las entradas ordenadas inversamente por orden alfabetico
                            mostrarEntradasOrdenAlfabeticoInverso(archivoDiccionario, numEntradas);
                            opcionSalida2 = 1;
                            break;

                        case 2:
                            //char salida;
                            printf("\n\n[Saliendo...]");
                            opcionSalida2 = 1;
                            break;
                        
                        default:
                            printf("\nOpcion invalida. Intente nuevamente.\n");
                            break;
                    }
                } while (opcionSalida2 != 1);
                break;
                
            case 6:
                int opcion3, opcionSalida3 = 0;
                do
                {
                
                    printf("\nATENCION: SE MOSTRARAN TODAS LAS PALABRAS [POR ORDEN DE LONGITUD] QUE ESTEN REGISTRADAS EN EL ARCHIVO.\n");
                    printf("CUANDO SE GENEREN PUEDE IR PRESIONANDO [ENTER] PARA GENERAR MAS ENTRADAS O [Q] PARA TERMINAR DE GENERAR Y SALIR.\n");
                    printf("\nINGRESE [1] PARA COMENZAR CON LA EJECUCION - [2] PARA VOLVER: ");

                    scanf("%d", &opcion3);
                    
                    switch (opcion3)
                    {
                        
                        case 1:
                            // Mostrar las entradas ordenadas por la longitud de su palabra
                            mostrarEntradasOrdenLongitud(archivoDiccionario, numEntradas);
                            opcionSalida3 = 1;
                            break;

                        case 2:
                            //char salida;
                            printf("\n\n[Saliendo...]");
                            opcionSalida3 = 1;
                            break;
                        
                        default:
                            printf("\nOpcion invalida. Intente nuevamente.\n");
                            break;
                    }
                } while (opcionSalida3 != 1);
                break;

            case 0:
                printf("\n[Saliendo del programa...]\n");
                break;

            default:
                printf("Opcion invalida. Intente nuevamente.\n");
                break;
        }

    } while (opcionPrincipal != 0);

    fclose(archivoDiccionario);
    return 0;
}

// Función de comparación para qsort (ordenar en orden alfabético inverso)
int compararPorAlfabeticoInverso(const void *a, const void *b) 
{
    const EntradaDiccionario *entradaA = (const EntradaDiccionario *)a;
    const EntradaDiccionario *entradaB = (const EntradaDiccionario *)b;
    return strcmp(entradaB->palabra, entradaA->palabra); // Cambio de orden para el orden inverso
}

// Función de comparación para qsort (ordenar por longitud de palabra en forma ascendente)
int compararPorLongitud(const void *a, const void *b) 
{
    const EntradaDiccionario *entradaA = (const EntradaDiccionario *)a;
    const EntradaDiccionario *entradaB = (const EntradaDiccionario *)b;
    return entradaA->longitud - entradaB->longitud;
}

// Función de comparación para qsort (ordenar por orden alfabético)
int compararPorPalabra(const void *a, const void *b) 
{
    const EntradaDiccionario *entradaA = (const EntradaDiccionario *)a;
    const EntradaDiccionario *entradaB = (const EntradaDiccionario *)b;
    return strcmp(entradaA->palabra, entradaB->palabra);
}

void agregarEntrada(FILE *archivoDiccionario) 
{
    EntradaDiccionario nuevaEntrada;

    printf("Ingrese la palabra: ");
    scanf("%99s", nuevaEntrada.palabra);
    nuevaEntrada.longitud = strlen(nuevaEntrada.palabra);

    printf("Ingrese la definicion (Para terminar la definion agregue un punto al final): ");
    leerDefinicion(stdin, nuevaEntrada.definicion);

    // Obtener la posición actual en el archivo
    long posicionActual = ftell(archivoDiccionario);

    // Verificar si el archivo esta vacío
    if (posicionActual == 0) 
        fseek(archivoDiccionario, 0, SEEK_END);
    else 
    {
        // Si el archivo no esta vacío, verificar si el último carácter es un salto de línea
        fseek(archivoDiccionario, -1, SEEK_CUR);
        char ultimoCaracter = fgetc(archivoDiccionario);

        // Si no hay un salto de línea, agregar uno antes de la nueva entrada
        if (ultimoCaracter != '\n') 
            fprintf(archivoDiccionario, "\n");
    }

    fseek(archivoDiccionario, posicionActual, SEEK_SET);
    fprintf(archivoDiccionario, "%s %s\n", nuevaEntrada.palabra, nuevaEntrada.definicion);
    fflush(archivoDiccionario);

    printf("Entrada agregada al diccionario.\n");
}


// Implementacion de la funcion buscarPalabra() utilizando busqueda binaria
void buscarPalabra(const char *palabraBuscada, FILE *archivoDiccionario, int numEntradas) 
{
    char palabra[MAX_PALABRA];
    char definicion[MAX_DEFINICION];

    EntradaDiccionario *entradas = (EntradaDiccionario *)malloc(numEntradas * sizeof(EntradaDiccionario));

    // Leer todas las entradas del archivo y guardar solo las no vacias en el arreglo
    rewind(archivoDiccionario);
    for (int i = 0; i < numEntradas; i++) 
    {
        if (fscanf(archivoDiccionario, "%s", entradas[i].palabra) == 1) 
        {
            leerDefinicion(archivoDiccionario, entradas[i].definicion);
            entradas[i].longitud = strlen(entradas[i].palabra);
        }
    }

    qsort(entradas, numEntradas, sizeof(EntradaDiccionario), compararPorPalabra);

    // Busqueda binaria para encontrar la palabra buscada
    int inicio = 0;
    int fin = numEntradas - 1;
    int encontrado = 0;
    int indicePalabra = -1;

    while (inicio <= fin) 
    {
        int medio = inicio + (fin - inicio) / 2;
        if (strcmp(entradas[medio].palabra, palabraBuscada) == 0) 
        {
            encontrado = 1;
            indicePalabra = medio;
            break;
        } else if (strcmp(entradas[medio].palabra, palabraBuscada) < 0) 
            inicio = medio + 1;
          else 
            fin = medio - 1;
    }

    if (encontrado) 
    {
        printf("Palabra encontrada: \n");
        printf("Palabra: [%s] \n", entradas[indicePalabra].palabra);
        printf("Definicion: [%s] \n", entradas[indicePalabra].definicion);
    } else 
        printf("Palabra no encontrada en el diccionario.\n");
    
    free(entradas);
}

void eliminarEntrada(FILE *archivoDiccionario) 
{
    char palabraBuscada[MAX_PALABRA];
    printf("Ingrese la palabra a eliminar: ");
    scanf("%99s", palabraBuscada);

    FILE *archivoTemporal = fopen("temp_diccionario.txt", "w");
    if (archivoTemporal == NULL) 
    {
        printf("Error al abrir el archivo temporal.\n");
        return;
    }

    char palabra[MAX_PALABRA];
    char definicion[MAX_DEFINICION];
    int eliminado = 0;

    rewind(archivoDiccionario);

    while (fscanf(archivoDiccionario, "%s", palabra) == 1) 
    {
        leerDefinicion(archivoDiccionario, definicion);

        if (strcmp(palabraBuscada, palabra) == 0) 
            eliminado = 1;
         else 
            fprintf(archivoTemporal, "%s %s\n", palabra, definicion);
    }

    fclose(archivoDiccionario);
    fclose(archivoTemporal);

    if (eliminado) 
    {
        // Reemplazar el archivo original con el archivo temporal
        remove("diccionario.txt");
        rename("temp_diccionario.txt", "diccionario.txt");
        printf("Entrada eliminada del diccionario.\n");
    } else 
    {
        // Si no se encontro la palabra a eliminar, eliminar el archivo temporal
        remove("temp_diccionario.txt");
        printf("Palabra no encontrada en el diccionario. No se realizo ninguna eliminacion.\n");
    }

    archivoDiccionario = fopen("diccionario.txt", "r+");
    if (archivoDiccionario == NULL) 
    {
        printf("Error al abrir el archivo.\n");
        return;
    }
}

void leerDefinicion(FILE *archivo, char *definicion) 
{
    char c;
    int i = 0;
    int puntoEncontrado = 0; // Variable para indicar si ya se encontro un punto al final

    while ((c = fgetc(archivo)) != EOF) 
    {
        definicion[i] = c;
        i++;

        if (c == '.') 
        {
            char siguiente = fgetc(archivo);
            if (siguiente == '\n') 
            {
                if (puntoEncontrado) 
                {
                    definicion[i] = c; // Agregar el punto al final de la definicion
                    puntoEncontrado = 1; // Marcar que se encontro un punto
                    i++;
                }
                definicion[i] = '\0';
                break;
            } else 
            {
                definicion[i] = siguiente;
                i++;
            }
        } else if (c != ' ') 
                puntoEncontrado = 0;
        
    }
}

void mostrarEntradasEnOrden(FILE *archivoDiccionario) 
{
    char palabra[MAX_PALABRA];
    char definicion[MAX_DEFINICION];

    rewind(archivoDiccionario);

    printf("Diccionario: \n");

    int contador = 0;
    while (fgets(palabra, MAX_PALABRA, archivoDiccionario) != NULL) 
    {
        palabra[strcspn(palabra, "\n")] = '\0';
        leerDefinicion(archivoDiccionario, definicion);

        printf("Palabra: [%s] \n", palabra);
        printf("Definicion: [%s] \n\n", definicion);

        contador++;

        // Mostrar 5 entradas y luego preguntar si generar más
        if (contador % 5 == 0) 
        {
            printf("Presione [ENTER] para continuar mostrando más entradas o 'q' para salir.\n");

            char entrada;
            do {
                entrada = getchar();
            } while (entrada != '\n' && entrada != 'q' && entrada != 'Q');

            if (entrada == 'q' || entrada == 'Q') 
                break;
        }
    }
}

// Implementacion de la funcion mostrarEntradasOrdenAlfabeticoInverso() usando qsort
void mostrarEntradasOrdenAlfabeticoInverso(FILE *archivoDiccionario, int numEntradas) 
{
    if (numEntradas <= 0) {
        printf("El diccionario esta vacio.\n");
        return;
    }

    EntradaDiccionario *entradas = (EntradaDiccionario *)malloc(numEntradas * sizeof(EntradaDiccionario));
    int indice = 0; 

    // Leer todas las entradas
    rewind(archivoDiccionario);
    for (int i = 0; i < numEntradas; i++) 
    {
        if (fscanf(archivoDiccionario, "%s", entradas[indice].palabra) == 1) 
        {
            leerDefinicion(archivoDiccionario, entradas[indice].definicion);
            entradas[indice].longitud = strlen(entradas[indice].palabra);
            indice++;
        }
    }

    qsort(entradas, indice, sizeof(EntradaDiccionario), compararPorAlfabeticoInverso);

    int contador = 0;

    // Mostrar las entradas ordenadas alfabeticamente en orden inverso
    printf("Diccionario ordenado alfabeticamente (inverso):\n");
    for (int i = 0; i < indice; i++) 
    {
        printf("Palabra: [%s] \n", entradas[i].palabra);
        printf("Definicion: [%s] \n\n", entradas[i].definicion);

        contador++;

        // Mostrar 5 entradas y luego preguntar si generar más
        if (contador % 5 == 0) 
        {
            printf("Presione [ENTER] para continuar mostrando más entradas o 'q' para salir.\n");

            char entrada;
            do {
                entrada = getchar();
            } while (entrada != '\n' && entrada != 'q' && entrada != 'Q');

            if (entrada == 'q' || entrada == 'Q') 
                break;
        }
    }

    free(entradas);
}

// Implementacion de la funcion mostrarEntradasOrdenLongitud() usando qsort
void mostrarEntradasOrdenLongitud(FILE *archivoDiccionario, int numEntradas) 
{
    if (numEntradas <= 0) {
        printf("El diccionario esta vacio.\n");
        return;
    }

    EntradaDiccionario *entradas = (EntradaDiccionario *)malloc(numEntradas * sizeof(EntradaDiccionario));
    int indice = 0; 

    // Leer todas las entradas
    rewind(archivoDiccionario);
    for (int i = 0; i < numEntradas; i++) 
    {
        if (fscanf(archivoDiccionario, "%s", entradas[indice].palabra) == 1) 
        {
            leerDefinicion(archivoDiccionario, entradas[indice].definicion);
            entradas[indice].longitud = strlen(entradas[indice].palabra);
            indice++;
        }
    }

    qsort(entradas, indice, sizeof(EntradaDiccionario), compararPorLongitud);

    int contador;

    // Mostrar las entradas ordenadas por longitud de palabra en forma ascendente
    printf("Diccionario ordenado por longitud de palabra:\n");
    for (int i = 0; i < indice; i++) 
    {
        printf("Palabra: [%s]\n", entradas[i].palabra);
        printf("Definicion: [%s]\n\n", entradas[i].definicion);

        contador++;

        // Mostrar 5 entradas y luego preguntar si generar más
        if (contador % 5 == 0) 
        {
            printf("Presione [ENTER] para continuar mostrando más entradas o 'q' para salir.\n");

            char entrada;
            do {
                entrada = getchar();
            } while (entrada != '\n' && entrada != 'q' && entrada != 'Q');

            if (entrada == 'q' || entrada == 'Q') 
                break;
        }
    }

    free(entradas);
}

// Implementacion de la funcion mostrarMenu()
void mostrarMenu() 
{
    printf("\n--------------- MENU ---------------\n\n");
    printf("1. Buscar el significado de una palabra en el diccionario.\n");
    printf("2. Agregar una nueva entrada al diccionario.\n");
    printf("3. Eliminar una entrada del diccionario.\n");
    printf("4. Mostrar las entradas en el mismo orden en el que estan registradas en el archivo de texto.\n");
    printf("5. Mostrar las entradas ordenadas inversamente por orden alfabetico.\n");
    printf("6. Mostrar las entradas ordenadas por la longitud de su palabra.\n");
    printf("0. Salir.\n");
    printf("\n--------------------------------------\n");
    printf("\n Ingrese el numero de opcion deseada: ");
}
