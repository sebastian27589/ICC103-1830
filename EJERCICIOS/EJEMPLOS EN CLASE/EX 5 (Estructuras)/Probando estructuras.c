#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
    Realice un programa que permita capturar los clientes de una empresa y los contratos
    que se tienen con estos clientes.

    Cada cliente tiene la siguiente estructura:
    - Identificacion (cadena de 13 caracteres).
    - Dirección (estructura anidada).
        - No. casa/Apto. (cadena de 10 caracteres)
        - Calle (cadena de 20 caracteres)
        - Sector / Barrio (cadena de 25 caracteres)
        - Ciudad (cadena de 30 caracteres)
    - Teléfono (cadena de 20 caracteres)
    - Profesion (cadena de 20 caracteres)
    - Nombre (cadena de 20 caracteres)
    - Tipo (enum: Persona/Empresa)
    - Cantidad de hijos (entero)
    - Altura (flotante)

    Cada Contrato tiene la siguiente estructura:
    - Número (entero)
    - Fecha (estructura anidada)
        - Día (entero)
        - Mes (entero)
        - Año (entero)
    - Identificación Cliente (cadena de 13 caracteres)
    - Pago Inscipción (flotante)
    - Pago Mensual (flotante)

    El programa deberá permitir:
    1- Capturar N Contratos, cada uno con su cliente.
    2- Mostrar los N Clientes capturados.
    3- Sumar total de hijos de los clientes.
    4- Presentar un listado de contrato (número, fecha, mensualidad) y cliente (nombre y tipo).

    Deberá crear una función para cada proceso.
    Deberá usar punteros en algunas de las funciones.
 */

typedef enum
{
    Persona,
    Empresa
}TipoCliente;

typedef struct
{
    char NoCasa[10];
    char Calle[20];
    char Sector[25];
    char Ciudad[30];
}Direccion;

typedef struct
{
    char Identificacion[13];
    Direccion Direccion;
    char Telefono[20];
    char Profesion[20];
    char Nombre[20];
    TipoCliente Tipo;
    int CantidadHijos;
    float Altura;
}Cliente;

typedef struct
{
    int Dia;
    int Mes;
    int Anyo;
}Fecha;

typedef struct
{
    int Numero;
    Fecha Fecha;
    char IDCliente[13];
    float Inscripcion;
    float Mensualidad;
}Contrato;


void CapturarCliente(int, Cliente*);
void CapturarContrato(int, Contrato*);
void MostrarClientes(int, Cliente*);
void MostrarContratos(int, Contrato*, int, Cliente*);
int MostrarMenu(int, int);
long MostrarTotalHijos(int, Cliente*);

int main()
{
    int cantidadClientes = 0, cantidadContratos = 0, seleccion;
    Cliente *listadoClientes = (Cliente*)malloc(sizeof(Cliente) * cantidadClientes);
    Contrato *listadoContratos = (Contrato*)malloc(sizeof(Contrato) * cantidadContratos);

    do
    {
        switch(seleccion = MostrarMenu(cantidadClientes, cantidadContratos))
        {
            case 1:
                // Capturar nuevo cliente.
                cantidadClientes++;
                listadoClientes = (Cliente*)realloc(listadoClientes, sizeof(Cliente) * cantidadClientes);
                CapturarCliente(cantidadClientes - 1, listadoClientes);

                break;
            case 2:
                // Capturar nuevo contrato.
                cantidadContratos++;
                listadoContratos = (Contrato*)realloc(listadoContratos, sizeof(Contrato) * cantidadContratos);
                CapturarContrato(cantidadContratos - 1, listadoContratos);

                break;
            case 3:
                // Mostrar todos los clientes.
                MostrarClientes(cantidadClientes, listadoClientes);
                break;
            case 4:
                // Mostrar todos los contratos.
                MostrarContratos(cantidadContratos, listadoContratos, cantidadClientes, listadoClientes);
                break;
            case 5:
                printf("\nTotal de hijos: %ld\n", MostrarTotalHijos(cantidadClientes, listadoClientes));
                break;
            default:
                break;
        }

    } while (seleccion != 0);
    

    return 0;
}

void CapturarCliente(int indice, Cliente *listadoClientes)
{
    char tipoDigitado;

    // Capturamos un cliente nuevo:
    printf("Identificación: ");
    fflush(stdin);
    gets((*(listadoClientes+indice)).Identificacion);
    
    // Datos de la Dirección:
    printf("Número de casa/apto.: ");
    gets((listadoClientes+indice)->Direccion.NoCasa);

    printf("Calle: ");
    gets((listadoClientes+indice)->Direccion.Calle);

    printf("Sector: ");
    gets((listadoClientes+indice)->Direccion.Sector);

    printf("Ciudad: ");
    gets((listadoClientes+indice)->Direccion.Ciudad);
    
    // Teléfono:
    printf("Teléfono: ");
    gets((listadoClientes+indice)->Telefono);
    
    // Profesión:
    printf("Profesión: ");
    gets((listadoClientes+indice)->Profesion);

    // Nombre
    printf("Nombre: ");
    gets((listadoClientes+indice)->Nombre);

    // Tipo de Cliente:
    printf("Tipo (E/P): ");
    tipoDigitado = getchar();
    (listadoClientes+indice)->Tipo = tolower(tipoDigitado) == 'e' ? Empresa : Persona; // Por defecto, persona.

    // Cantidad de Hijos:
    printf("Cantidad de hijos: ");
    scanf("%d", &((listadoClientes+indice)->CantidadHijos));

    // Altura:
    printf("Altura: ");
    scanf("%f", &((listadoClientes+indice)->Altura));
}

void CapturarContrato(int indice, Contrato *listadoContratos)
{
    // Número de contrato:
    printf("Número: ");
    scanf("%d", &((listadoContratos+indice)->Numero));

    // Datos de la fecha del contrato:
    printf("Día: ");
    scanf("%d", &((listadoContratos+indice)->Fecha.Dia));

    printf("Mes: ");
    scanf("%d", &((listadoContratos+indice)->Fecha.Mes));

    printf("Año: ");
    scanf("%d", &((listadoContratos+indice)->Fecha.Anyo));

    // ID del Cliente:
    printf("ID Cliente: ");
    fflush(stdin);
    gets((listadoContratos+indice)->IDCliente);

    printf("Monto Inscripción: ");
    scanf("%f", &((listadoContratos+indice)->Inscripcion));

    printf("Monto Mensualidad: ");
    scanf("%f", &((listadoContratos+indice)->Mensualidad));
}

void MostrarClientes(int cantidadClientes, Cliente *listadoClientes)
{
    int i;

    for(i = 0; i < cantidadClientes; i++)
    {
        printf("Cliente %d:\n", i+1);
        printf("Identificación: %s\n", (*(listadoClientes+i)).Identificacion);
        printf("No. Casa/Apto.: %s\n", (*(listadoClientes+i)).Direccion.NoCasa);
        printf("Calle: %s\n", (*(listadoClientes+i)).Direccion.Calle);
        printf("Sector: %s\n", (*(listadoClientes+i)).Direccion.Sector);
        printf("Ciudad: %s\n", (*(listadoClientes+i)).Direccion.Ciudad);
        printf("Teléfono: %s\n", (*(listadoClientes+i)).Telefono);
        printf("Profesión: %s\n", (*(listadoClientes+i)).Profesion);
        printf("Nombre: %s\n", (*(listadoClientes+i)).Nombre);
        printf("Tipo: %s\n", (*(listadoClientes+i)).Tipo == Empresa ? "Empresa" : "Persona");
        printf("Cant. Hijos: %d\n", (*(listadoClientes+i)).CantidadHijos);
        printf("Altura: %.2f\n", (*(listadoClientes+i)).Altura);
    }
}

void MostrarContratos(int cantidadContratos,
                    Contrato *listadoContratos,
                    int cantidadClientes,
                    Cliente *listadoClientes)
{
    int i, j;

    printf("No.\tFecha\tMensualidad\tCliente\n");
    for(i = 0; i < cantidadContratos; i++)
    {
        printf("%d\t", (*(listadoContratos+i)).Numero);
        printf("%d/%d/%d\t", (*(listadoContratos+i)).Fecha.Dia,
                        (*(listadoContratos+i)).Fecha.Mes,
                        (*(listadoContratos+i)).Fecha.Anyo);
        printf("%.2f\t", (*(listadoContratos+i)).Mensualidad);
        // Aquí, hay que recorrer la lista de clientes, para buscar el cliente
        // de este contrato y mostrar solo su nombre.
        for(j = 0; j < cantidadClientes; j++)
        {
            if(strcmp((*(listadoClientes+j)).Identificacion, (*(listadoContratos+i)).IDCliente) == 0)
            {
                printf("%s\n", (*(listadoClientes+j)).Nombre);
                break;
            }
        }
    }
}

int MostrarMenu(int cantidadClientes,
                int cantidadContratos)
{
    char opcion;
    //system("cls"); // limpiar la pantalla.
    printf("--- Registro de Contratos y Entidades ---");
    printf("\n\nSeleccione una opción del menú:\n");
    printf("\n\t\t1: Capturar nuevo cliente");
    printf("\n\t\t2: Capturar nuevo contrato");
    printf("\n\t\t3: Mostrar todos los clientes (%d)", cantidadClientes);
    printf("\n\t\t4: Mostrar todos los contratos (%d)", cantidadContratos);
    printf("\n\t\t5: Mostrar el total de hijos");
    printf("\n\n\t\t0: Salir\n\n\t\tSeleccione: ");

    fflush(stdin);
    opcion = getchar();

    switch(opcion) // Esto se puede reemplazar por una sola línea.
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

    return 0;
}

long MostrarTotalHijos(int cantidadClientes, Cliente *listadoClientes)
{
    long cantidadHijos = 0;
    int i;

    for(i=0; i<cantidadClientes; i++)
    {
        cantidadHijos += (*(listadoClientes+i)).CantidadHijos;
    }

    return cantidadHijos;
}