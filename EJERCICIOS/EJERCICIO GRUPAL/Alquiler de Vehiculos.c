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
void mostrarAutomoviles(int, FILE*, FILE*);
void mostrarAutomovilesMarca(int, FILE*, FILE*, char*);
void mostrarAutomovilAlquilerMayorUnaSemana(int, FILE*, FILE*);
void mostrarAutomovilAlquilerEntreUnaSemanaDiezDias(FILE*);
void mostrarAutomovilAlquilerMayorDiezMil(int, FILE*, FILE*);

// Clientes
void mostrarClientes(int, FILE*, FILE*);
void mostrarClientes_Sant(int, FILE*, FILE*);
void mostrarClientes_Alquileres(int, FILE*, FILE *);
void mostrarClientes_EntreDiezDias(FILE*);
void mostrarClientes_Alquiler_Precio(int, FILE *);

int main() 
{

    char rutaClientes[] = "clientes.bin", marca[30];
    Cliente cliente;
    Automovil automovil;
    Alquiler alquiler;
    int opcion, opcion2, opcion3, idAutomovil, idCliente;


    FILE *archivoClientes = fopen(rutaClientes, "a+b");
    FILE *archivoAutomoviles = fopen("automoviles.dat", "a+b");
    FILE *archivoAlquiler = fopen("archivos.dat", "a+b");

    printf("\nUPDATE!! MAYORIA DE ERRORES SOLUCIONADOS!!!\n");

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
                        mostrarClientes(idAutomovil, archivoClientes, archivoAlquiler);
                        break;
                    case 2:
                        printf("\nIngrese ID del automovil que desea ver: ");
                        scanf("%d", &idAutomovil);
                        mostrarClientes_Sant(idAutomovil, archivoClientes, archivoAlquiler);
                        break;
                    case 3:
                        printf("\nIngrese ID del automovil que desea ver: ");
                        scanf("%d", &idAutomovil);
                        mostrarClientes_Alquileres(idAutomovil, archivoClientes, archivoAlquiler);
                        break;
                    case 4:
                        mostrarClientes_EntreDiezDias(archivoAlquiler);
                        break;
                    case 5:
                        printf("\nIngrese ID del automovil que desea ver: ");
                        scanf("%d", &idAutomovil);
                        mostrarClientes_Alquiler_Precio(idAutomovil, archivoAlquiler);
                        break;
                }
                break;

            case 5:
                opcion3 = mostrarMenu3();
                
                switch (opcion3) 
                {
                    case 1:
                        printf("\nIngrese ID del cliente que desea ver: ");
                        scanf("%d", &idCliente);
                        mostrarAutomoviles(idCliente, archivoAlquiler, archivoAutomoviles);
                        break;
                    case 2:
                        printf("\nIngrese ID del cliente que desea ver: ");
                        scanf("%d", &idCliente);
                        printf("\nIngrese la marca del automóvil: ");
                        scanf("%s", marca);
                        mostrarAutomovilesMarca(idCliente, archivoAlquiler, archivoAutomoviles, marca);
                        break;
                    case 3:
                        printf("\nIngrese ID del cliente que desea ver: ");
                        scanf("%d", &idCliente);
                        mostrarAutomovilAlquilerMayorUnaSemana(idCliente, archivoAlquiler, archivoAutomoviles);
                        break;
                    case 4:
                        mostrarAutomovilAlquilerEntreUnaSemanaDiezDias(archivoAlquiler);
                        break;
                    case 5:
                        printf("\nIngrese ID del cliente que desea ver: ");
                        scanf("%d", &idCliente);
                        mostrarAutomovilAlquilerMayorDiezMil(idCliente, archivoAlquiler, archivoAutomoviles);
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

    Cliente clienteExistente;

    fseek(archivoClientes, 0, SEEK_SET);
    while (fread(&clienteExistente, sizeof(Cliente), 1, archivoClientes) == 1)
    {
        if (clienteExistente.id == cliente->id)
        {
            printf("El ID ingresado ya existe. Intente nuevamente.\n");
            return;
        }
    }

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
    //fflush(stdin);

    Automovil automovilExistente;

    fseek(archivoAutomoviles, 0, SEEK_SET);
    while (fread(&automovilExistente, sizeof(Automovil), 1, archivoAutomoviles) == 1)
    {
        if (automovilExistente.id == automovil->id)
        {
            printf("El ID ingresado ya existe. Intente nuevamente.\n");
            return;
        }
    }

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
    scanf("%d", &alquiler->dias);

    fwrite(alquiler, sizeof(Alquiler), 1, archivoAlquiler);
}

// AUTOMOVILES

void mostrarAutomoviles(int idCliente, FILE *archivoAlquiler, FILE *archivoAutomovil)
{
    Alquiler alquilerActual;
    Automovil automovilActual;

    fseek(archivoAlquiler, 0, SEEK_SET);

    while (fread(&alquilerActual, sizeof(Alquiler), 1, archivoAlquiler) == 1)
    {
        if (alquilerActual.id_Cliente == idCliente)
        {
            fseek(archivoAutomovil, 0, SEEK_SET);

            while (fread(&automovilActual, sizeof(Automovil), 1, archivoAutomovil) == 1)
            {
                if (automovilActual.id == alquilerActual.id_vehiculo)
                {
                    printf("\nID: %d\nMarca: %s\n", automovilActual.id, automovilActual.marca);
                }
            }
        }
    }
}

void mostrarAutomovilesMarca(int idCliente, FILE*archivoAlquileres, FILE* archivoAutomoviles, char *marca)
{
    Alquiler alquilerActual;
    Automovil automovilActual;

    fseek(archivoAlquileres, 0, SEEK_SET);

    while (fread(&alquilerActual, sizeof(Alquiler), 1, archivoAlquileres) == 1)
    {
        if (alquilerActual.id_Cliente == idCliente)
        {
            fseek(archivoAutomoviles, (alquilerActual.id_vehiculo - 1) * sizeof(Automovil), SEEK_SET);
            fread(&automovilActual, sizeof(Automovil), 1, archivoAutomoviles);
            if (strcmp(automovilActual.marca, marca) == 0)
            {
                printf("\nID: %d\nMarca: %s\n\n", automovilActual.id, automovilActual.marca);
            }
        }
    }
}

void mostrarAutomovilAlquilerMayorUnaSemana(int idCliente, FILE* archivoAlquiler, FILE* archivoAutomoviles)
{
    Alquiler alquilerActual;
    Automovil automovilActual;

    fseek(archivoAlquiler, 0, SEEK_SET);

    while (fread(&alquilerActual, sizeof(Alquiler), 1, archivoAlquiler) == 1)
    {
        if (alquilerActual.dias > 7)
        {
            fseek(archivoAutomoviles, (alquilerActual.id_vehiculo - 1) * sizeof(Automovil), SEEK_SET);
            fread(&automovilActual, sizeof(Automovil), 1, archivoAutomoviles);

            printf("\nID del Cliente: %d\nID del Vehiculo: %d\nCantidad de días: %d\nMarca: %s\n\n", alquilerActual.id_Cliente, alquilerActual.id_vehiculo, alquilerActual.dias, automovilActual.marca);
        }
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

void mostrarAutomovilAlquilerMayorDiezMil(int idCliente, FILE* archivoAlquiler, FILE* archivoAutomoviles)
{
    Alquiler alquilerActual;
    Automovil automovilActual;

    fseek(archivoAlquiler, 0, SEEK_SET);

    while (fread(&alquilerActual, sizeof(Alquiler), 1, archivoAlquiler) == 1)
    {
        if (alquilerActual.precio > 10000 && alquilerActual.id_Cliente == idCliente)
        {
            fseek(archivoAutomoviles, (alquilerActual.id_vehiculo - 1) * sizeof(Automovil), SEEK_SET);
            fread(&automovilActual, sizeof(Automovil), 1, archivoAutomoviles);

            printf("\nID del Cliente: %d\nID del Vehiculo: %d\nCantidad de días: %d\nMarca: %s\nAlquiler: %.2f\n\n",
                   alquilerActual.id_Cliente, alquilerActual.id_vehiculo, alquilerActual.dias, automovilActual.marca, alquilerActual.precio);
        }
    }
}

// CLIENTES

void mostrarClientes(int idAutomovil, FILE* archivoClientes, FILE *archivoAlquiler)
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

void mostrarClientes_Sant(int idAutomovil, FILE *archivoClientes, FILE* archivoAlquiler)
{
    Cliente clienteActual;
    Alquiler alquilerActual;

    fseek(archivoClientes, 0, SEEK_SET);
    while (fread(&clienteActual, sizeof(Cliente), 1, archivoClientes) == 1)
    {
        fseek(archivoAlquiler, 0, SEEK_SET);
        while (fread(&alquilerActual, sizeof(Alquiler), 1, archivoAlquiler) == 1)
        {
            if (alquilerActual.id_vehiculo == idAutomovil && strcmp(clienteActual.ciudad, "Santiago") == 0)
            {
                printf("\nID: %d\nNombre: %s\nCiudad: %s\n", clienteActual.id, clienteActual.nombre, clienteActual.ciudad);
                //break; // Romper el bucle interno después de encontrar una coincidencia
            }
        }
    }
}

void mostrarClientes_Alquileres(int idAutomovil, FILE *archivoClientes, FILE *archivoAlquiler) 
{
    Alquiler alquilerActual;
    fseek(archivoAlquiler, 0, SEEK_SET);

    while (fread(&alquilerActual, sizeof(Alquiler), 1, archivoAlquiler) == 1)
    {
        if (alquilerActual.dias > 7 && alquilerActual.id_vehiculo == idAutomovil)
        {
            Cliente clienteActual;
            fseek(archivoClientes, (alquilerActual.id_Cliente - 1) * sizeof(Cliente), SEEK_SET);
            fread(&clienteActual, sizeof(Cliente), 1, archivoClientes);

            printf("ID del Cliente: %d\nNombre: %s\nCiudad: %s\n\n",
                   clienteActual.id, clienteActual.nombre, clienteActual.ciudad);
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

void mostrarClientes_Alquiler_Precio(int idAutomovil, FILE *archivoAlquiler) 
{
    Alquiler alquilerActual;

    fseek(archivoAlquiler, 0, SEEK_SET);

    while (fread(&alquilerActual, sizeof(Alquiler), 1, archivoAlquiler) == 1)
    {
        if (alquilerActual.precio > 10000 && alquilerActual.id_vehiculo == idAutomovil)
        {
            printf("ID del Cliente: %d\nID del Vehiculo: %d\nCantidad de días: %d\n", 
                   alquilerActual.id_Cliente, alquilerActual.id_vehiculo, alquilerActual.dias);

            if (alquilerActual.dias >= 1 && alquilerActual.dias <= 7)
            {
                printf("Duración del alquiler: Entre 1-7 días\n");
            }
            else if (alquilerActual.dias >= 8 && alquilerActual.dias <= 10)
            {
                printf("Duración del alquiler: Entre 8-10 días\n");
            }
            else if (alquilerActual.dias > 10)
            {
                printf("Duración del alquiler: Por más de 10 días\n");
            }

            printf("\n");
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

