#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    char marca[20];
    int anio;
    char ficha[10];
    char propietario[20];
}Carro;

typedef struct 
{
    int ID;
    char nombre[40];
    char trabajo[20];
    char celular[15];
    char comp_movil[20];
}Pasajeros;

typedef struct 
{
    int dia;
    int mes;
    int year;
    char hora[10]; // Hora, minuto y segundos
}Tiempo;

typedef struct 
{
    Carro concho;  // Creo que no será necesario
    Tiempo tiempo;
    Pasajeros cliente; // Esto tampoco
    int pago;
    int devuelta;
    int cant_estimada;
}Servicio;

int MostrarMenu();
void CapturarConcho(int, Carro*);
void CapturarPasajeros(int, Pasajeros*);
void CapturarServicio(int, Servicio*);

int main()
{
    int CantPasajeros = 0, CantConcho = 0, CantServicio = 0;
    Carro *ListadoConcho = (Carro*)malloc(sizeof(Carro) *CantConcho);
    Pasajeros *ListadoPasajeros = (Pasajeros*)malloc(sizeof(Pasajeros) *CantPasajeros);
    Servicio *ListadoServicio = (Servicio*)malloc(sizeof(Servicio) *ListadoServicio);
    
    int option;

    do
    {
        option = MostrarMenu();

        switch (option)
        {
        case 1:
            CantConcho++;
            ListadoConcho = (Carro*)realloc(ListadoConcho, sizeof(Carro) * CantConcho);
            CapturarConcho(CantConcho - 1, ListadoConcho);
            break;
        case 2:
            CantPasajeros++;
            ListadoPasajeros = (Pasajeros*)realloc(ListadoPasajeros, sizeof(Pasajeros) * CantPasajeros);
            CapturarPasajeros(CantPasajeros - 1, ListadoPasajeros);
            break;
        case 3:
            CantServicio++;
            ListadoServicio = (Servicio*)realloc(ListadoServicio, sizeof(Servicio) * CantServicio);
            CapturarServicio(CantServicio - 1, ListadoServicio);
            break;
        
        default:
            break;
        }
    } while (option != 7);


    return 0;
}

int MostrarMenu()
{
    int opcion;

    do
    {
        printf("DEPARTAMENTO DE TRANSPORTE PUBLICO DE CONCHOS\n");
        printf("Elija las siguientes opciones para:\n\n");
        printf("1. Registar un carro público.\n");
        printf("2. Registar un pasajero.\n");
        printf("3. Registrar un servicio de transporte.\n");
        printf("4. Mostrar pasajeros que un concho ha tomado.\n");  //  Agregar criterios de filtrado.
        printf("5. Mostrar datos de los conchos que un cliente especifico ha tomado. \n"); //  Agregar criterios de filtrado.
        printf("6. Mostrar servicios de transporte.\n");    //  Agregar criterios de filtrado.
        printf("7. Salir\n\n.");

        printf("RESPUESTA: ");
        scanf("%d", &opcion);

    } while (opcion != 7);

    return opcion;
}

    // char marca[20];
    // int anio;
    // char ficha[10];
    // char propietario[20];

void CapturarConcho(int ind, Carro* ListadoConcho)
{
    printf("MARCA DEL VEHICULO: ");
    fflush(stdin);
    gets((ListadoConcho+ind)->marca);

    printf("\n");

    printf("AÑO DEL VEHICULO: ");
    scanf("%d", &((ListadoConcho+ind)->anio));

    printf("\n");

    printf("FICHA: ");
    fflush(stdin);
    gets((ListadoConcho+ind)->ficha);

    printf("\n");

    printf("PROPIETARIO: ");
    fflush(stdin);
    gets((ListadoConcho+ind)->propietario);

}


    // int ID;
    // char nombre[40];
    // char trabajo[20];
    // char celular[15];
    // char comp_movil[20];

void CapturarPasajeros(int ind, Pasajeros* ListadoPasajeros)
{
    printf("ID DEL CLIENTE: ");
    scanf("%d", &((ListadoPasajeros+ind)->ID));

    printf("\n");

    printf("NOMBRE COMPLETO : ");
    fflush(stdin);
    gets((ListadoPasajeros+ind)->nombre);

    printf("\n");

    printf("LUGAR DE TRABAJO: ");
    fflush(stdin);
    gets((ListadoPasajeros+ind)->trabajo);

    printf("\n");

    printf("CELULAR: ");
    fflush(stdin);
    gets((ListadoPasajeros+ind)->celular);

    printf("\n");

    printf("COMPAÑIA MOVIL: ");
    fflush(stdin);
    gets((ListadoPasajeros+ind)->comp_movil);
}

    // Carro concho;
    // Tiempo tiempo;
    // Pasajeros cliente;
    // int pago;
    // int devuelta;
    // int cant_estimada;

void CapturarServicio(int ind, Servicio* ListadoServicio)
{
    printf("INDIQUE PAGO DEL SERVICIO: ");
    scanf("%d", &((ListadoServicio+ind)->pago));

    printf("\n");

    printf("INDIQUE PAGO DE LA DEVUELTA: ");
    scanf("%d", &((ListadoServicio+ind)->devuelta));

    printf("\n");

    printf("INDIQUE CANTIDAD ESTIMADA DEL SERVICIO: ");
    scanf("%d", &((ListadoServicio+ind)->cant_estimada));

    printf("\n");

    // int dia;
    // int mes
    // int anio;
    // char hora[10]; Hora, minuto y segundos

    printf("DIA DEL SERVICIO");
    scanf("%d", &((ListadoServicio+ind)->tiempo.dia));

    printf("MES DEL SERVICIO");
    scanf("%d", &((ListadoServicio+ind)->tiempo.mes));

    printf("AÑO DEL SERVICIO");
    scanf("%d", &((ListadoServicio+ind)->tiempo.year));

    printf("HORA APROXIMADA DEL SERVICIO(HORA/MINUTO/SEGUNDO): ");
    fflush(stdin);
    gets((ListadoServicio+ind)->tiempo.hora);


}