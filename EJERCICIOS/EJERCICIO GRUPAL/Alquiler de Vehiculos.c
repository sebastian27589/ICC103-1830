#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct 
{
    int id;
    char marca[30];
}Automovil;

typedef struct
{
    int id;
    char nombre[30];
    char ciudad[50];
}Cliente;

typedef struct
{
    int id_Cliente;
    int id_vehiculo;
    int dias;
    float precio;
}Alquiler;

int mostrarMenu();
int mostrarMenu2();
int mostarMenu3();
void capturarCliente(FILE*, Cliente*);
void capturarAutomovil(FILE*, Automovil*);
void capturarAlquilar(FILE*, Alquiler*);
void mostrarClientes(FILE*);
void mostrarClientes_Sant(FILE *);
void mostrarClientes_Alquileres(FILE*);
void mostrarAutomoviles(FILE*);
void mostrarAutomoviles_Marca(FILE*);
void mostrarAutomoviles_Alquileres(FILE*);

int main() 
{

    char rutaClientes[] = "clientes.bin";
    char rutaAutomoviles[] = "automoviles.bin";
    char rutaAlquiler[] = "alquiler.bin";

    Cliente cliente;
    Automovil automovil;
    Alquiler alquiler;
    int opcion, opcion2, opcion3;

    FILE *archivoClientes = fopen(rutaClientes, "a+b");
    FILE *archivoAutomoviles = fopen(rutaClientes, "a+b");
    FILE *archivoAlquileres = fopen(rutaClientes, "a+b");

    do
    {
        opcion = mostrarMenu();

        switch(opcion)
        {
            case 0:
                printf("Hasta luego!");
                break;
            case 1:
                capturarCliente(archivoClientes, &cliente);
                break;
            case 2:
                capturarAutomovil(archivoAutomoviles, &automovil);
                break;
            case 3:
                capturarAlquilar(archivoAlquileres, &alquiler);
                break;
            case 4:
                opcion2 = mostrarMenu2();

                switch(opcion2)
                {
                    case 1:
                        mostrarClientes(archivoClientes);
                        break;
                    case 2:
                        mostrarClientes_Sant(archivoClientes);
                        break;
                    case 3:
                        mostrarClientes_Alquileres(archivoAlquileres);
                        break;
                    default:
                        break;
                }

            // case 5:
            //     opcion3 = mostarMenu3();

            //     switch (opcion3)
            //     {
            //         case 1:
            //             mostrarAutomoviles(archivoAutomoviles);
            //             break;
            //         case 2:
            //             mostrarAutomoviles_Marca(archivoAutomoviles);
            //             break;
            //         case 3:
            //             mostrarAutomoviles_Alquileres(archivoAutomoviles);
            //         default:
            //             break;
            //     }
        }

    } while (opcion != 0);

    mostrarClientes(archivoClientes);

    return 0;
}


void capturarCliente(FILE *archivoClientes, Cliente *cliente)
{
    printf("\nDigite el ID: ");
    scanf("%d", &cliente->id);
    fflush(stdin);
    printf("\nDigite el nombre: ");
    gets(cliente->nombre);
    printf("\nDigite la ciudad: ");
    gets(cliente->ciudad);

    fwrite(cliente, sizeof(Cliente), 5, archivoClientes);
}


void capturarAutomovil(FILE* archivoAutomoviles, Automovil *automovil)
{
    printf("\nDigite el ID: ");
    scanf("%d", &automovil->id);
    fflush(stdin);
    printf("\nDigite la marca: ");
    gets(automovil->marca);

    fwrite(automovil, sizeof(Automovil), 5, archivoAutomoviles);
}

void capturarAlquilar(FILE* archivoAlquiler, Alquiler* alquiler)
{
    printf("\nDigite el ID del Cliente: ");
    scanf("%d", &alquiler->id_Cliente);
    fflush(stdin);
    printf("\nDigite el ID del Vehiculo: ");
    scanf("%d", &alquiler->id_vehiculo);
    printf("\nDigite el precio: ");
    scanf("%f", &alquiler->precio);
    printf("\nDigite la cantidad de dias: ");
    scanf("%d", &alquiler->dias);

    fwrite(alquiler, sizeof(Alquiler), 5, archivoAlquiler);
}


void mostrarClientes(FILE *archivoClientes)
{
    Cliente clienteActual;

    fseek(archivoClientes, 0, SEEK_END);
    int tamano = ftell(archivoClientes);
    fseek(archivoClientes, 0, SEEK_SET);

    while(ftell(archivoClientes) < tamano) // reemplazando el feof().
    {
        fread(&clienteActual, sizeof(Cliente), 1, archivoClientes);

        //if(strcmp(clienteActual.ciudad, ciudadFiltro) == 0)
        printf("\nID: %d\nNombre: %s\nCiudad: %s\n",
        clienteActual.id, clienteActual.nombre, clienteActual.ciudad);
    }

}

void mostrarClientes_Sant(FILE *archivoClientes)
{
    Cliente clienteActual;

    fseek(archivoClientes, 0, SEEK_END);
    int tamano = ftell(archivoClientes);
    fseek(archivoClientes, 0, SEEK_SET);

    while(ftell(archivoClientes) < tamano) // reemplazando el feof().
    {
        fread(&clienteActual, sizeof(Cliente), 1, archivoClientes);

        if(strcmp(clienteActual.ciudad, "Santiago") == 0)
        printf("\nID: %d\nNombre: %s\nCiudad: %s\n",
        clienteActual.id, clienteActual.nombre, clienteActual.ciudad);
    }

}

void mostrarClientes_Alquileres(FILE *archivoAlquiler) 
{
    Alquiler alquilerActual;
    //Cliente clienteActual;

    fseek(archivoAlquiler, 0, SEEK_END);
    long tamano = ftell(archivoAlquiler);
    fseek(archivoAlquiler, 0, SEEK_SET);

    while (ftell(archivoAlquiler) < tamano) // reemplazando el feof().
    {

        fread(&alquilerActual, sizeof(Alquiler), 1, archivoAlquiler);

        if (alquilerActual.dias > 7) 
        {
            printf("\nID del Cliente: %d\nID del Vehiculo: %d\nCantidad de dias: %d\n",
            alquilerActual.id_Cliente, alquilerActual.id_vehiculo, alquilerActual.dias);
        }
    }
}

// void mostrarAutomoviles(FILE *archivoAutomovil)
// {
//     Automovil automovilActual;

//     fseek(archivoAutomovil, 0, SEEK_END);
//     int tam = ftell(archivoAutomovil);
//     fseek(archivoAutomovil, 0, SEEK_SET);

//     while (ftell(archivoAutomovil) < tam)
//     {
//         fread(&automovilActual, sizeof(Automovil), 1, archivoAutomovil);
//         printf("\nID: %d\nMarca: %s\n",
//         automovilActual.id, automovilActual.marca);
//     }
// }

// void mostrarAutomoviles_marca(FILE *archivoAutomovil)
// {
//     Automovil automovilActual;
//     char marca[15];

//     fseek(archivoAutomovil, 0, SEEK_END);
//     int tam = ftell(archivoAutomovil);
//     fseek(archivoAutomovil, 0, SEEK_SET);

//     printf("Especifique la marca que quiere buscar:");
//     fflush(stdin);
//     gets(marca);

//     while(ftell(archivoAutomovil) < tam) // reemplazando el feof().
//     {
//         fread(&archivoAutomovil, sizeof(Automovil), 1, archivoAutomovil);

//         if(strcmp(automovilActual.ciudad, "Santiago") == 0)
//         printf("\nID: %d\nNombre: %s\nCiudad: %s\n",
//         clienteActual.id, clienteActual.nombre, clienteActual.ciudad);
//     }
// }

void mostrarAutomoviles_Alquileres(FILE *archivoAutomovil)
{

}

int mostrarMenu()
{
    char opciones;
    printf("\n****MENU****\n");
    printf("1: Capturar cliente.\n");
    printf("2: Capturar automovil.\n");
    printf("3: Registrar alquiler.\n");
    printf("4: Mostrar Clientes.\n");
    printf("5: Mostrar Automoviles\n");
    printf("\n0: Salir.\n");
    printf("\nSeleccione: ");
    fflush(stdin);
    opciones = getchar();

    switch(opciones)
    {
        case '1':
            return 1;
        case '2':
            return 2;
        case '3':
            return 3;
        case '4':
            return 4;
        case '5':
            return 5;
        default:
            return 0;
    }
}


int mostrarMenu2()
{
    printf("1) Todos los clientes.\n2) Todos los clientes de Santiago\n3) Todos los alquileres mayores de una semana.\n"
    "4) Todos los alquileres por entre una semana y 10 dias, agrupandolos por la ciudad del cliente.\n"
    "5) Todos los alquileres por un valor total superior a $10,000, agrupandolos por la cantidad de dias alquilados, de la siguiente manera:\n"
    "\ta) Entre 1-7 dias"
    "\tb) Entre 8-10 dias"
    "\tc) Por mas de 10 dias.\n Cual quiere seleccionar?");

    char opciones;

    fflush(stdin);
    opciones = getchar();

        switch(opciones)
        {
            case '1':
                return 1;
            case '2':
                return 2;
            case '3':
                return 3;
            case '4':
                return 4;
            case '5':
                return 5;
            default:
                return 0;
        }
}

int MostrarMenu3()
{
    printf("1) Todos los automoviles. \n 2) Todos los automoviles de una marca especifica \n 3)Todos los alquileres mayores de una semana.\n"
    "4) Todos los alquileres por entre una semana y 10 dias\n 5) Todos los alquileres por un valor total superior a $10,000.\n"
    "Cual quiere seleccionar?");

    char opciones2;

    fflush(stdin);
    opciones2 = getchar();
    
    switch (opciones2)
        {
            case '1':
                return 1;
            case '2':
                return 2;
            case '3':
                return 3;
            case '4':
                return 4;
            case '5':
                return 5;
            default:
                return 0;
        }
}

