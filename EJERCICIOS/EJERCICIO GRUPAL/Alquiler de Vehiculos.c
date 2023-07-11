/*
    ESTUDIANTES:

    NICOL SÁNCHEZ    -  ID: 1015-1785
    SEBASTIÁN MIGUEL -  ID: 1014-8026
*/

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


// Menues
int mostrarMenu();
int mostrarMenu2();
int mostrarMenu3();

// Capturas
void capturarCliente(FILE*, Cliente*);
void capturarAutomovil(FILE*, Automovil*);
void capturarAlquiler(FILE*, Alquiler*);

// Automoviles
void mostrarAutomoviles(FILE*);
void mostrarAutomovilesMarca(FILE*, char*);
void mostrarAutomovilAlquilerMayorUnaSemana(FILE*);
void mostrarAutomovilAlquilerEntreUnaSemanaDiezDias(FILE*);
void mostrarAutomovilAlquilerMayorDiezMil(FILE*);

// Clientes
void mostrarClientes(int, FILE*, FILE*);
void mostrarClientes_Sant(FILE *);
void mostrarClientes_Alquileres(FILE *);
void mostrarClientes_EntreDiezDias(FILE*);
void mostrarClientes_Alquiler_Precio(FILE *);

int main() 
{

    char rutaClientes[] = "clientes.bin", marca[30];
    Cliente cliente;
    Automovil automovil;
    Alquiler alquiler;
    int opcion, opcion2, opcion3, idAutomovil;


    FILE *archivoClientes = fopen(rutaClientes, "a+b");
    FILE *archivoAutomoviles = fopen("automoviles.dat", "a+b");
    FILE *archivoAlquiler = fopen("archivos.dat", "a+b");

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
                capturarAlquiler(archivoAlquiler, &alquiler);
                break;
            case 4:
                opcion2 = mostrarMenu2();
            
                switch(opcion2)
                {
                    case 1:
                        //int idAutomovil;
                        printf("\nIngrese ID del automovil que desea ver: ");
                        scanf("%d", &idAutomovil);
                        mostrarClientes(idAutomovil, archivoAlquiler, archivoClientes);
                        break;
                    case 2:
                        mostrarClientes_Sant(archivoClientes);
                        break;
                    case 3:
                        mostrarClientes_Alquileres(archivoAlquiler);
                        break;
                    case 4:
                        mostrarClientes_EntreDiezDias(archivoAlquiler);
                        break;
                    case 5:
                        mostrarClientes_Alquiler_Precio(archivoAlquiler);
                        break;
                }
                break;

            case 5:
                opcion3 = mostrarMenu3();
                
                switch (opcion3) 
                {
                    case 1:
                        mostrarAutomoviles(archivoAutomoviles);
                        break;
                    case 2:
                        printf("Ingrese la marca del automóvil: ");
                        scanf("%s", marca);
                        mostrarAutomovilesMarca(archivoAutomoviles, marca);
                        break;
                    case 3:
                        mostrarAutomovilAlquilerMayorUnaSemana(archivoAlquiler);
                        break;
                    case 4:
                        mostrarAutomovilAlquilerEntreUnaSemanaDiezDias(archivoAlquiler);
                        break;
                    case 5:
                        mostrarAutomovilAlquilerMayorDiezMil(archivoAlquiler);
                        break;
                }
                break;
        }

    } while (opcion != 0);

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

    fwrite(cliente, sizeof(Cliente), 1, archivoClientes);
}


void capturarAutomovil(FILE* archivoAutomoviles, Automovil *automovil)
{
    printf("\nDigite el ID: ");
    scanf("%d", &automovil->id);
    fflush(stdin);
    printf("\nDigite la marca: ");
    gets(automovil->marca);

    fwrite(automovil, sizeof(Automovil), 1, archivoAutomoviles);
}

void capturarAlquiler(FILE* archivoAlquiler, Alquiler *alquiler)
{
    printf("\nDigite el ID del Cliente: ");
    scanf("%d", &alquiler->id_Cliente);

    printf("\nDigite el ID del Vehiculo: ");
    scanf("%d", &alquiler->id_vehiculo);

    printf("\nDigite el precio: ");
    scanf("%f", &alquiler->precio);

    printf("\nDigite la cantidad de dias: ");
    scanf("% d", &alquiler->dias);

    fwrite(alquiler, sizeof(Alquiler), 1, archivoAlquiler);
}

// AUTOMOVILES

void mostrarAutomoviles(FILE *archivoAutomovil)
{
    Automovil automovilActual;

    fseek(archivoAutomovil, 0, SEEK_END);
    int tam = ftell(archivoAutomovil);
    fseek(archivoAutomovil, 0, SEEK_SET);

    while (ftell(archivoAutomovil) < tam)
    {
        fread(&automovilActual, sizeof(Automovil), 1, archivoAutomovil);
        printf("\nID: %d\nMarca: %s\n", automovilActual.id, automovilActual.marca);
    }
}

void mostrarAutomovilesMarca(FILE* archivoAutomoviles, char *marca)
{
    Automovil automovilActual;
    fseek(archivoAutomoviles, 0, SEEK_SET);

    while (fread(&automovilActual, sizeof(Automovil), 1, archivoAutomoviles) == 1)
    {
        if (strcmp(automovilActual.marca, marca) == 0)
            printf("\nID: %d\nMarca: %s\n\n", automovilActual.id, automovilActual.marca);
    }
}

void mostrarAutomovilAlquilerMayorUnaSemana(FILE* ArchivoAlquiler)
{
    Alquiler alquilerActual;
    fseek(ArchivoAlquiler, 0, SEEK_SET);

    while (fread(&alquilerActual, sizeof(Alquiler), 1, ArchivoAlquiler) == 1)
    {
        if (alquilerActual.dias > 7)
            printf("\nID del Cliente: %d\nID del Vehiculo: %d\nCantidad de días: %d\n\n", alquilerActual.id_Cliente, alquilerActual.id_vehiculo, alquilerActual.dias);
    }
}

void mostrarAutomovilAlquilerEntreUnaSemanaDiezDias(FILE* archivoAlquiler)
{
    Alquiler alquilerActual;
    fseek(archivoAlquiler, 0, SEEK_SET);

    while (fread(&alquilerActual, sizeof(Alquiler), 1, archivoAlquiler) == 1)
    {
        if (alquilerActual.dias >= 7 && alquilerActual.dias <= 10)
            printf("\nID del Cliente: %d\nID del Vehiculo: %d\nCantidad de días: %d\n\n", alquilerActual.id_Cliente, alquilerActual.id_vehiculo, alquilerActual.dias);
    }
}

void mostrarAutomovilAlquilerMayorDiezMil(FILE* archivoAlquiler)
{
    Alquiler alquilerActual;
    fseek(archivoAlquiler, 0, SEEK_SET);

    while (fread(&alquilerActual, sizeof(Alquiler), 1, archivoAlquiler) == 1)
    {
        if (alquilerActual.precio > 10000)
        {
            printf("\nID del Cliente: %d\nID del Vehiculo: %d\nCantidad de días: %d\n\n",
                alquilerActual.id_Cliente, alquilerActual.id_vehiculo, alquilerActual.dias);
        }
    }
}

// CLIENTES

void mostrarClientes(int idAutomovil, FILE* archivoAlquiler, FILE *archivoClientes)
{
    Cliente clienteActual;
    Alquiler alquilerActual;

    // fseek(archivoClientes, 0, SEEK_END);
    // int tamano = ftell(archivoClientes);
    // fseek(archivoClientes, 0, SEEK_SET);

    fseek(archivoAlquiler, 0, SEEK_SET);

    while (fread(&alquilerActual, sizeof(Alquiler), 1, archivoAlquiler) == 1)
    {
        if (alquilerActual.id_vehiculo == idAutomovil)
        {
            Cliente clienteActual;
            fseek(archivoClientes, (alquilerActual.id_Cliente - 1) * sizeof(Cliente), SEEK_SET);
            fread(&clienteActual, sizeof(Cliente), 1, archivoClientes);
            printf("ID: %d\nNombre: %s\nCiudad: %s\n\n", clienteActual.id, clienteActual.nombre, clienteActual.ciudad);
        }
    }
}

void mostrarClientes_Sant(FILE *archivoClientes)
{
    Cliente clienteActual;

    //fseek(archivoClientes, 0, SEEK_END);
    //int tamano = ftell(archivoClientes);
    fseek(archivoClientes, 0, SEEK_SET);

    while(fread(&clienteActual, sizeof(Cliente), 1, archivoClientes) == 1)
    {
        //fread(&clienteActual, sizeof(Cliente), 1, archivoClientes);
        if(strcmp(clienteActual.ciudad, "Santiago") == 0)
            printf("\nID: %d\nNombre: %s\nCiudad: %s\n", clienteActual.id, clienteActual.nombre, clienteActual.ciudad);
    }
}


void mostrarClientes_Alquileres(FILE *archivoAlquiler) 
{
    Alquiler alquilerActual;
    fseek(archivoAlquiler, 0, SEEK_SET);

    while (fread(&alquilerActual, sizeof(Alquiler), 1, archivoAlquiler) == 1)
    {
        if (alquilerActual.dias > 7)
        {
            printf("ID del Cliente: %d\nID del Vehiculo: %d\nCantidad de días: %d\n\n", alquilerActual.id_Cliente, alquilerActual.id_vehiculo, alquilerActual.dias);
        }
    }
}

void mostrarClientes_EntreDiezDias(FILE* archivoAlquiler)
{
    Alquiler alquilerActual;
    Cliente clienteActual;
    fseek(archivoAlquiler, 0, SEEK_SET);

    while (fread(&alquilerActual, sizeof(Alquiler), 1, archivoAlquiler) == 1)
    {
        if (alquilerActual.dias >= 7 && alquilerActual.dias <= 10)
            printf("ID del Cliente: %d\nID del Vehiculo: %d\nCantidad de días: %d\nCiudad: %s\n\n", alquilerActual.id_Cliente, alquilerActual.id_vehiculo, alquilerActual.dias, clienteActual.ciudad);
    }
}

void mostrarClientes_Alquiler_Precio(FILE *archivoAlquiler) 
{
    Alquiler alquilerActual;
    //Cliente clienteActual;

    fseek(archivoAlquiler, 0, SEEK_END);
    int tamano = ftell(archivoAlquiler);
    fseek(archivoAlquiler, 0, SEEK_SET);


    while (ftell(archivoAlquiler) < tamano) // reemplazando el feof().
    {
        fread(&alquilerActual, sizeof(Alquiler), 1, archivoAlquiler);

        if (alquilerActual.precio > 10000) 
        {
        printf("\nID del Cliente: %d\nID del Vehiculo: %d\nCantidad de dias: %d\n",
        alquilerActual.id_Cliente, alquilerActual.id_vehiculo, alquilerActual.dias);
        }
    }
}

// Menú general

int mostrarMenu()
{
    char opciones;
    printf("\n****MENU****\n");
    printf("1: Capturar cliente.\n");
    printf("2: Capturar automovil.\n");
    printf("3: Registrar alquiler.\n");
    printf("4: Mostrar Clientes.\n");
    printf("5: Mostrar Automoviles.\n");
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

// Menú de los clientes

int mostrarMenu2()
{
    printf("\n1) Todos los clientes.");
    printf("\n2) Todos los clientes de Santiago.");
    printf("\n3) Todos los alquileres mayores de una semana.");
    printf("\n4) Todos los alquileres por entre una semana y 10 dias, agrupandolos por la ciudad del cliente. ");
    printf("\n5) Todos los alquileres por un valor total superior a $10,000, agrupados por la cantidad de dias alquilados, de la siguiente manera:");
    printf("\n\ta) Entre 1-7 dias \tb) Entre 8-10 dias \tc) Por mas de 10 dias");
    printf("\n\nRespuesta: ");

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

// Menú de los automóviles

int mostrarMenu3()
{
    printf("\n1) Todos los automoviles. ");
    printf("\n2) Todos los automoviles de una marca especifica. ");
    printf("\n3) Todos los alquileres mayores de una semana. ");
    printf("\n4) Todos los alquileres por entre una semana y 10 dias. ");
    printf("\n5) Todos los alquileres por un valor total superior a $10,000.");
    printf("\n\nRespuesta: ");

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

