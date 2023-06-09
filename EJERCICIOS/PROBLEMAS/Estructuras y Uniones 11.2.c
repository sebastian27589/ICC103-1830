#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*

    Escriba un programa de facturación de clientes.
    Los clientes tienen:

    -   Nombre
    -   Núm. Unidades 
    -   Precio 
    -   Estado 

    Estado debe ser:

    -   Moroso
    -   Atrasado
    -   Pagado

    Debe generar a los diversos clientes.

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

int main()
{
    int cantClientes = 0;
    char option; 

    Clientes *listadoFactura = (Clientes*)malloc(sizeof(Clientes)*cantClientes); // Se reserva la cantidad de clientes a facturar.

    printf("\n\tPROGRAMA DE FACTURACIÓN DE CLIENTES\n");

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
        }

        MostrarClientes(cantClientes, listadoFactura);

    }while(option != 'n');

    printf("\n\tVUELVA PRONTO !!\n");

    free(listadoFactura);

    return 0;
}

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

void MostrarClientes(int cantidadClientes, Clientes *listadoFactura)
{
    int ind;

    printf("\n\t\tNOMBRE    ||    UNIDADES     ||       PRECIO      ||       ESTADO      ");
    for(ind = 0; ind < cantidadClientes; ind++)
    {
        printf("\n\t\t%s      ||     %d     ||      %.2f      ||      %s      ", (*(listadoFactura+ind)).nombre,
                                                                                (*(listadoFactura+ind)).unidades,
                                                                                (*(listadoFactura+ind)).precio,
                                                                                (*(listadoFactura+ind)).estado);
    }

    printf("\n\n");
        

}