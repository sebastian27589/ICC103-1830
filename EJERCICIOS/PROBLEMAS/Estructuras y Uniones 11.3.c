#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

Modifique el programa de facturación de clientes de tal modo que se puedan obtener los
siguientes listados.

    -Clientes en estado moroso.
    -Clientes en estado pagado con factura mayor de una determinada cantidad.

*/

typedef struct 
{
    char nombre[30];
    int unidades;
    float precio;
    char estado[15];
}Clientes;

void Facturacion(int, Clientes*);
void MostrarClientes(int, Clientes*);
void MostrarClientesMorosos(int, Clientes*);
void MostrarClientesPagados(int, Clientes*, float);

int main()
{
    int cantClientes = 0;
    char option; 
    float factMin;

    Clientes *listadoFactura = (Clientes*)malloc(sizeof(Clientes)*cantClientes); // Se reserva la cantidad de clientes a facturar.

    printf("\n\tPROGRAMA DE FACTURACIÓN DE CLIENTES\n");

    printf("\n\tIngrese factura mínima (precio): ");
    scanf("%f", &factMin);

    do 
    {
        printf("\t¿Desea ingresar un nuevo cliente? (S/N)");
        scanf("%c", &option);

        if (option == 's')
        {
            cantClientes++; //  Inicialmente comienza en cero.
            listadoFactura = (Clientes*)realloc(listadoFactura, sizeof(Clientes)*cantClientes); //  Se añade nuevo cliente 
            printf("\n\t\tGenerando Cliente...");
            Facturacion(cantClientes - 1, listadoFactura); //   Se le resta uno para que no comience un espacio después
        

            MostrarClientes(cantClientes, listadoFactura);
        
            printf("\n\t\t-- CLIENTES EN ESTADO MOROSO --\n");
            MostrarClientesMorosos(cantClientes, listadoFactura);

            printf("\n\t\t-- CLIENTES EN ESTADO PAGADO --\n");
            MostrarClientesPagados(cantClientes, listadoFactura, factMin);
        }

    }while(option != 'n');

    printf("\n\tVUELVA PRONTO !!\n");

    free(listadoFactura); // Libero la memoria que reservé

    return 0;
}

// Escaneo los clientes con sus datos //

void Facturacion(int ind, Clientes *listadoFactura)
{
    printf("\n\t\tNombre del cliente: ");
    fflush(stdin);
    gets((listadoFactura+ind)->nombre);

    printf("\t\tCantidad de unidades: ");
    scanf("%d", &((listadoFactura+ind))->unidades);

    printf("\t\tPrecio: ");
    scanf("%f", &((listadoFactura+ind))->precio);

    printf("\t\tEstado en el que se encuentra: ");
    fflush(stdin);
    gets((listadoFactura+ind)->estado);

}

// Muestro los clientes con todos sus datos //

void MostrarClientes(int cantidadClientes, Clientes *listadoFactura)
{

    printf("\n\t\tNOMBRE    ||    UNIDADES     ||       PRECIO      ||       ESTADO      ");
    for(int ind = 0; ind < cantidadClientes; ind++)
    {
        printf("\n\t\t%s      ||     %d     ||      %.2f      ||      %s      ", (*(listadoFactura+ind)).nombre,
                                                                                (*(listadoFactura+ind)).unidades,
                                                                                (*(listadoFactura+ind)).precio,
                                                                                (*(listadoFactura+ind)).estado);
    }

    printf("\n\n");
        

}

// Muestro los clientes en estado "Moroso" // 

void MostrarClientesMorosos(int cantidadClientes, Clientes *listadoFactura)
{
    for(int ind = 0; ind < cantidadClientes; ind++)
    {
        if (strcmp((listadoFactura+ind)->estado, "Moroso") == 0) // Verifica los clientes en estado Moroso
            printf("\n\t\t\t\t%s\n", (*(listadoFactura+ind)).nombre); //Los imprime.
    }

}

// Muestro los clientes en estado "Pagado" con factura mayor

void MostrarClientesPagados(int cantidadClientes, Clientes *listadoFactura, float factMin)
{
    int ind;

    for(ind = 0; ind < cantidadClientes; ind++)
    {
        if (strcmp((listadoFactura+ind)->estado, "Pagado") == 0)  // Primero verifica si el cliente ingresado tiene un estado "Pagado"
        {
            if((listadoFactura+ind)->precio > factMin) // Luego verifica si su monto es mayor al mínimo
                printf("\n\t\t\t\t%s\n", (*(listadoFactura+ind)).nombre); // Si es mayor, lo imprime.
        }
    }
}