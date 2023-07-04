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
    int hora;
    int minuto;
    int segundo;
}Tiempo;

typedef struct
{
    char ficha[10];
    Tiempo tiempo;
    int cliente;
    double pago;
    double devuelta;
    int cant_estimada;
}Servicio;

int MostrarMenu();
int MostrarMenu2();
int MostrarMenu3();
int MostrarMenu4();
void CapturarConcho(int, Carro*);
void CapturarPasajeros(int, Pasajeros*);
void CapturarServicio(int, Servicio*);
void MostrarTodosPasajeros(int, Pasajeros*);
void VerPasajerosdeUnConcho(int, Servicio*, Pasajeros*, Carro*);
void VerPasajerosdeUnConcho_Trabajo(int, Servicio*, Pasajeros*, Carro*);
void VerPasajerosdeUnConcho_Telef(int, Servicio*, Pasajeros*, Carro*);
void VerPasajerosdeUnConcho_Tiempo(int, Servicio*, Pasajeros*, Carro*);
void VerPasajerosdeUnConcho_Monto(int, Servicio*, Pasajeros*, Carro*);
void VerPasajerosdeUnConcho_Monto_Devuelta(int, Servicio*, Pasajeros*, Carro*);
void VerPasajerosdeUnConcho_Fecha(int, Servicio*, Pasajeros* , Carro*);
int CompararFecha(Tiempo, Tiempo);
void VerConchoqueMontaUnPasajero(int, Servicio* , Pasajeros* , Carro*);
void VerConchoModelo(int, Servicio*, Pasajeros*, Carro*);
void VerConchoMarca(int, Servicio*, Pasajeros* , Carro* );
void VerConchoPropietario(int, Servicio*, Pasajeros*, Carro*);
void VerConchoMonto(int, Servicio* , Pasajeros* , Carro* );
void VerConchoFecha(int, Servicio*, Pasajeros*, Carro*);
void VerFichaCarro(int, Servicio*, Pasajeros*, Carro*);
void VerIDPasajero(int, Servicio*, Pasajeros*, Carro*);
void VerRangoMonto(int, Servicio* , Pasajeros* , Carro*);
void VerRangoFecha(int, Servicio*, Pasajeros*, Carro*);
void formatearFechaHora(Tiempo tiempo, char fechaHora[]);
void VerRangoTiempo(int, Servicio*, Pasajeros*, Carro*);

int main()

{

    int CantPasajeros = 0, CantConcho = 0, CantServicio = 0;

    Carro *ListadoConcho = (Carro*)malloc(sizeof(Carro) *CantConcho);
    Pasajeros *ListadoPasajeros = (Pasajeros*)malloc(sizeof(Pasajeros) *CantPasajeros);
    Servicio *ListadoServicio = (Servicio*)malloc(sizeof(Servicio) *CantServicio);

    int option=0, option2=0, option3=0, option4=0;

    do 
    {
        option = MostrarMenu();
        switch (option) 
        {
            case 1:
                CantConcho++;
                ListadoConcho = (Carro *) realloc(ListadoConcho, sizeof(Carro) * CantConcho);
                CapturarConcho(CantConcho - 1, ListadoConcho);
                break;
            case 2:
                CantPasajeros++;
                ListadoPasajeros = (Pasajeros *) realloc(ListadoPasajeros, sizeof(Pasajeros) * CantPasajeros);
                CapturarPasajeros(CantPasajeros - 1, ListadoPasajeros);
                break;
            case 3:
                CantServicio++;
                ListadoServicio = (Servicio *) realloc(ListadoServicio, sizeof(Servicio) * CantServicio);
                CapturarServicio(CantServicio - 1, ListadoServicio);
                break;
            case 4:
            do 
            {
                option2 = MostrarMenu2();
                switch (option2) 
                {
                    case 1:
                        VerPasajerosdeUnConcho(CantServicio, ListadoServicio, ListadoPasajeros, ListadoConcho);
                        break;
                    case 2:
                        VerPasajerosdeUnConcho_Trabajo(CantServicio, ListadoServicio, ListadoPasajeros,ListadoConcho);
                        break;
                    case 3:
                        VerPasajerosdeUnConcho_Telef(CantServicio, ListadoServicio, ListadoPasajeros, ListadoConcho);
                        break;
                    case 4:
                        VerPasajerosdeUnConcho_Tiempo(CantServicio, ListadoServicio, ListadoPasajeros, ListadoConcho);
                        break;
                    case 5:
                        VerPasajerosdeUnConcho_Monto(CantServicio, ListadoServicio, ListadoPasajeros, ListadoConcho);
                        break;
                    case 6:
                        VerPasajerosdeUnConcho_Monto_Devuelta(CantServicio, ListadoServicio, ListadoPasajeros, ListadoConcho);
                        break;
                    case 7:
                        VerPasajerosdeUnConcho_Fecha(CantServicio, ListadoServicio, ListadoPasajeros, ListadoConcho);
                        break;
                }

            } while (option2 != 8);

            if (option2 == 8)
                    break;
            case 5:
            do 
            {
                option3 = MostrarMenu3();

                switch (option3) 
                {
                    case 1:
                        VerConchoqueMontaUnPasajero(CantServicio, ListadoServicio, ListadoPasajeros, ListadoConcho);
                        break;
                    case 2:
                        VerConchoModelo(CantServicio, ListadoServicio, ListadoPasajeros,ListadoConcho);
                        break;
                    case 3:
                        VerConchoMarca(CantServicio, ListadoServicio, ListadoPasajeros, ListadoConcho);
                        break;
                    case 4:
                        VerConchoMonto(CantServicio, ListadoServicio, ListadoPasajeros, ListadoConcho);
                        break;
                    case 5:
                        VerConchoPropietario(CantServicio, ListadoServicio, ListadoPasajeros, ListadoConcho);
                        break;
                    case 6:
                        VerConchoFecha(CantServicio, ListadoServicio, ListadoPasajeros, ListadoConcho);
                        break;
                }

            } while (option3 != 7);

            if(option3 == 7)
                break;

            case 6:
            do 
            {
                option4 = MostrarMenu4();
                switch (option4) 
                {
                    case 1:
                        VerFichaCarro(CantServicio, ListadoServicio, ListadoPasajeros,ListadoConcho);
                        break;
                    case 2:
                        VerIDPasajero(CantServicio, ListadoServicio, ListadoPasajeros, ListadoConcho);
                        break;
                    case 3:
                        VerRangoMonto(CantServicio, ListadoServicio, ListadoPasajeros, ListadoConcho);
                        break;
                    case 4:
                        VerRangoFecha(CantServicio, ListadoServicio, ListadoPasajeros, ListadoConcho);
                        break;
                    case 5:
                        VerRangoTiempo(CantServicio, ListadoServicio, ListadoPasajeros, ListadoConcho);
                        break;
                    case 6:
                        break;
                }

            } while (option4 != 7);

            if(option4== 7)
                break;
        }

    } while (option != 7);

    printf("\n=====Hasta luego!=====\n");

    return 0;

}


int MostrarMenu()

{
    char opcion;

    printf("\n======DEPARTAMENTO DE TRANSPORTE PUBLICO DE CONCHOS======\n");
    printf("Elija las siguientes opciones para:\n\n");
    printf("1. Registar un carro publico.\n");
    printf("2. Registar un pasajero.\n");
    printf("3. Registrar un servicio de transporte.\n");
    printf("4. Mostrar pasajeros que un concho ha tomado.\n");
    printf("5. Mostrar datos de los conchos que un cliente especifico ha tomado. \n");
    printf("6. Mostrar servicios de transporte.\n");
    printf("7. Salir\n\n.");

    printf("RESPUESTA: ");

    fflush(stdin);
    opcion= getchar();

    switch(opcion)
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
        case '6':
            return 6;
        case '7':
            return 7;
        default:
            return 0;
    }
}


int MostrarMenu2()

{
    char opcion2;

    printf("Elija las siguientes opciones para mostrar:\n\n");
    printf("1. Todos los pasajeros (sin ningun criterio de filtrado).\n");
    printf("2. Todos los pasajeros cuyo lugar de trabajo sea especificado.\n");
    printf("3. Todos los pasajeros cuyo celular sea de una compania especificada.\n");
    printf("4. Todos los pasajeros cuyo tiempo de viaje promedio este en un rango especificado.\n");
    printf("5. Todos los pasajeros cuyo monto con el que pago este en un rango especificado. \n");
    printf("6. Todos los pasajeros cuyo monto del servicio (monto con el que pago menos la devuelta) este en un \n"
    "rango especificado.\n");
    printf("7. Todos los pasajeros cuya fecha y hora de servicio esta en un rango de fecha y hora especificado.\n");
    printf("8. Volver al Menu Principal.\n\n.");

    printf("RESPUESTA: ");

    fflush(stdin);
    opcion2= getchar();

    switch(opcion2)
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
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        default:
            return 0;
    }
}


int MostrarMenu3()
{
    char opcion3;

    printf("Elija las siguientes opciones para mostrar:\n\n");
    printf("1. Todos los carros publicos (sin ningun criterio de filtrado).\n");
    printf("2. Todos los carros cuyo anyo del modelo este en un rango.\n");
    printf("3. Todos los carros cuya marca sea la especificada por el usuario.\n");
    printf("4. Todos los carros a los que se les haya pagado con un monto que este en un rango especificado.\n");
    printf("5. Todos los carros de un propietario especificado.\n");
    printf("6. Todos los carros en los que se haya montado en una fecha dentro de un rango especificado.\n");
    printf("7. Volver al Menu Principal.\n\n.");

    printf("RESPUESTA: ");

    fflush(stdin);
    opcion3= getchar();

    switch(opcion3)
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
        case '6':
            return 6;
        case '7':
            return 7;
        case '8':
            return 8;
        default:
            return 0;
    }
}


int MostrarMenu4()
{
    char opcion4;

    printf("\nElija las siguientes opciones para mostrar:\n\n");
    printf("1. Ficha del carro.\n");
    printf("2. Id del pasajero.\n");
    printf("3. Rango del monto del servicio.\n");
    printf("4. Rango de fecha y hora del servicio.\n");
    printf("5. Rango de tiempo estimado del viaje.\n");
    //printf("6. Todos.\n");
    printf("7. Volver al Menu Principal.\n.");

    printf("RESPUESTA: ");

    fflush(stdin);
    opcion4= getchar();

    switch(opcion4)
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
        case '6':
            return 6;
        case '7':
            return 7;
        default:
            return 0;
    }
}

void CapturarConcho(int ind, Carro* ListadoConcho)

{

    printf("MARCA DEL VEHICULO: ");
    fflush(stdin);
    gets((ListadoConcho+ind)->marca);
    printf("\n");


    printf("ANYO DEL VEHICULO: ");
    scanf(" %d", &((ListadoConcho+ind)->anio));
    printf("\n");


    printf("FICHA: ");
    fflush(stdin);
    gets((ListadoConcho+ind)->ficha);
    printf("\n");


    printf("PROPIETARIO: ");
    fflush(stdin);
    gets((ListadoConcho+ind)->propietario);

    printf("\nAGREGADO EXITOSAMENTE.\n\n");

}



void CapturarPasajeros(int ind, Pasajeros* ListadoPasajeros)
{
    int id, i;
    int repetido;
    do 
    {
        repetido = 0;
        printf("ID DEL CLIENTE: ");
        scanf("%d", &id);

        for (i = 0; i < ind; i++) 
        {
            if ((ListadoPasajeros + i)->ID == id) 
            {
                printf("El ID ya existe, por favor, ingrese un ID unico.\n");
                repetido = 1;
                break;
            }
        }
    } while (repetido);

    (ListadoPasajeros + ind)->ID = id;

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

    printf("COMPANIA MOVIL: ");
    fflush(stdin);
    gets((ListadoPasajeros+ind)->comp_movil);

    printf("\nAGREGADO EXITOSAMENTE\n\n");
}

void CapturarServicio(int ind, Servicio* ListadoServicio)
{

    printf("ID DEL CLIENTE: ");
    scanf("%d", &((ListadoServicio+ind)->cliente));
    printf("\n");

    printf("INDIQUE PAGO DEL SERVICIO: ");
    scanf("%lf", &((ListadoServicio+ind)->pago));
    printf("\n");


    printf("INDIQUE PAGO DE LA DEVUELTA: ");
    scanf("%lf", &((ListadoServicio+ind)->devuelta));
    printf("\n");

    printf("INDIQUE CANTIDAD ESTIMADA DEL SERVICIO (UN VALOR EXPRESADO EN MINUTOS): ");
    scanf("%d", &((ListadoServicio+ind)->cant_estimada));
    printf("\n");

    // int dia;
    // int mes
    // int anio;
    // int hora;
    // int minuto;
    // int segundo;

    printf("FECHA DEL SERVICIO - DIGITE SIGUIENDO ESTE FORMATO: (DD/MM/YY): ");
    scanf("%d/%d/%d", &((ListadoServicio+ind)->tiempo.dia), &((ListadoServicio+ind)->tiempo.mes), &((ListadoServicio+ind)->tiempo.year));
    printf("\nFECHA DEL SERVICIO - DIGITE SIGUIENDO ESTE FORMATO: (HH:MM:SS): ");
    scanf("%d:%d:%d", &((ListadoServicio+ind)->tiempo.hora), &((ListadoServicio+ind)->tiempo.minuto), &((ListadoServicio+ind)->tiempo.segundo));
    
    printf("\nFICHA: ");
    fflush(stdin);
    gets((ListadoServicio+ind)->ficha);
    printf("\n");

    printf("\nAGREGADO EXITOSAMENTE\n\n");
}

//PASAJEROS

void MostrarTodosPasajeros(int ind, Pasajeros* ListaPasajeros)
{
    int i;
    for(i = 0; i < ind; i++) 
    {
        printf("\nCLIENTE ID: %d\n", (ListaPasajeros+i)->ID);
        printf("NOMBRE: %s\n", (ListaPasajeros+i)->nombre);
        printf("LUGAR DE TRABAJO: %s\n", (ListaPasajeros+i)->trabajo);
        printf("CEULAR: %s\n", (ListaPasajeros+i)->celular);
        printf("COMPANIA MOVIL: %s\n", (ListaPasajeros+i)->comp_movil);
    }
}

void VerPasajerosdeUnConcho(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho)
{

    int i =0;
    char fiches[10];

    printf("\nDIGITE LA FICHA DEL CONCHO QUE DESEA VER: ");
    fflush(stdin);
    gets(fiches);
    printf("\n");

    for(i = 0; i < ind; i++) 
    {
        if (strcmp(fiches, (ListadoServicio + i)->ficha) == 0)
        { 

            if( (ListaPasajeros + i)->ID == (ListadoServicio + i)->cliente)
            {
                printf("CLIENTE ID: %d\n", (ListaPasajeros+i)->ID);
                printf("NOMBRE: %s\n", (ListaPasajeros+i)->nombre);
                printf("LUGAR DE TRABAJO: %s\n", (ListaPasajeros+i)->trabajo);
                printf("CEULAR: %s\n", (ListaPasajeros+i)->celular);
                printf("COMPANIA MOVIL: %s\n\n", (ListaPasajeros+i)->comp_movil);
            }
        }
    }
}

void VerPasajerosdeUnConcho_Trabajo(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho)
{

    int i =0;
    char fiches[10], trabajar[10];

    printf("\nDIGITE LA FICHA DEL CONCHO QUE DESEA VER: ");
    fflush(stdin);
    gets(fiches);
    printf("\n");

    printf("\nDIGITE EL TRABAJO DE LOS PASAJEROS QUE DESEA VER: ");
    fflush(stdin);
    gets(trabajar);
    printf("\n");

    for(i = 0; i < ind; i++) 
    {
        if (strcmp(fiches, (ListadoServicio + i)->ficha) == 0)
        { //AGREGAR EL LISTADOCONCHO -> && (ListadoConcho+i)->ficha ==(ListadoServicio+i)->ficha)
            if(strcmp(trabajar, (ListaPasajeros + i)->trabajo) == 0)
            {
                printf("CLIENTE ID: %d\n", (ListaPasajeros+i)->ID);
                printf("NOMBRE: %s\n", (ListaPasajeros+i)->nombre);
                printf("LUGAR DE TRABAJO: %s\n", (ListaPasajeros+i)->trabajo);
                printf("CEULAR: %s\n", (ListaPasajeros+i)->celular);
                printf("COMPANIA MOVIL: %s\n\n", (ListaPasajeros+i)->comp_movil);
            }
        }
    }
}

void VerPasajerosdeUnConcho_Telef(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho)
{

    int i;
    char fiches[10], comp_telefonica[10];

    printf("\nDIGITE LA FICHA DEL CONCHO QUE DESEA VER: ");
    fflush(stdin);
    gets(fiches);
    printf("\n");

    printf("\nDIGITE LA COMPANIA TELEFONICA DE LOS PASAJEROS QUE DESEA VER: ");
    fflush(stdin);
    gets(comp_telefonica);
    printf("\n");

    for(i = 0; i < ind; i++) 
    {
        if ((strcmp(fiches, (ListadoServicio + i)->ficha) == 0) && (strcmp(comp_telefonica, (ListaPasajeros + i)->comp_movil) == 0))
        {
            printf("CLIENTE ID: %d\n", (ListaPasajeros+i)->ID);
            printf("NOMBRE: %s\n", (ListaPasajeros+i)->nombre);
            printf("LUGAR DE TRABAJO: %s\n", (ListaPasajeros+i)->trabajo);
            printf("CEULAR: %s\n", (ListaPasajeros+i)->celular);
            printf("COMPANIA MOVIL: %s\n\n", (ListaPasajeros+i)->comp_movil);
        }
    }
}

void VerPasajerosdeUnConcho_Tiempo(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho)
{

    int i, tiempo_min, tiempo_max;
    char fiches[10];

    printf("\nDIGITE LA FICHA DEL CONCHO QUE DESEA VER: ");
    fflush(stdin);
    gets(fiches);
    printf("\n");

    printf("\nINGRESE UN RANGO MINIMO DE TIEMPO (UN VALOR EXPRESADO EN MINUTOS): ");
    scanf("%d", &tiempo_min);

    printf("\nINGRESE UN RANGO MAXIMO DE TIEMPO (UN VALOR EXPRESADO EN MINUTOS): ");
    scanf("%d", &tiempo_max);
    printf("\n");

    for(i = 0; i < ind; i++) 
    {
        if (strcmp(fiches, (ListadoServicio + i)->ficha) == 0)
        {
            int tiempo_servicio = (ListadoServicio+i)->cant_estimada;
            if(tiempo_servicio >= tiempo_min && tiempo_servicio <= tiempo_max)
            {
                printf("CLIENTE ID: %d\n", (ListaPasajeros+i)->ID);
                printf("NOMBRE: %s\n", (ListaPasajeros+i)->nombre);
                printf("LUGAR DE TRABAJO: %s\n", (ListaPasajeros+i)->trabajo);
                printf("CEULAR: %s\n", (ListaPasajeros+i)->celular);
                printf("COMPANIA MOVIL: %s\n\n", (ListaPasajeros+i)->comp_movil);
                //printf("%d\n", i);
            }
        }
    }
}

void VerPasajerosdeUnConcho_Monto(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho)
{
    int i =0;
    double monto_min, monto_max;
    char fiches[10];

    printf("\nDIGITE LA FICHA DEL CONCHO QUE DESEA VER: ");
    fflush(stdin);
    gets(fiches);
    printf("\n");

    printf("\nDIGITE UN RANGO MINIMO DEL PAGO DE LOS PASAJEROS QUE DESEA VER: ");
    scanf("%lf", &monto_min);
    printf("\n");

    printf("\nDIGITE UN RANGO MAXIMO DEL PAGO DE LOS PASAJEROS QUE DESEA VER: ");
    scanf("%lf", &monto_max);
    printf("\n");

    double suma_monto;
    printf("%.0lf", &suma_monto);
    for(i = 0; i < ind; i++) 
    {
        if (strcmp(fiches, (ListadoServicio+i)->ficha) == 0)
        {
            suma_monto = ((ListadoServicio+i)->pago);
            if(monto_min <= suma_monto && monto_max >= suma_monto)
            {
                printf("CLIENTE ID: %d\n", (ListaPasajeros+i)->ID);
                printf("NOMBRE: %s\n", (ListaPasajeros+i)->nombre);
                printf("LUGAR DE TRABAJO: %s\n", (ListaPasajeros+i)->trabajo);
                printf("CEULAR: %s\n", (ListaPasajeros+i)->celular);
                printf("COMPANIA MOVIL: %s\n\n", (ListaPasajeros+i)->comp_movil);
            }
        }
    }
}

void VerPasajerosdeUnConcho_Monto_Devuelta(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho)
{
    int i =0, monto_min, monto_max;
    char fiches[10];

    printf("\nDIGITE LA FICHA DEL CONCHO QUE DESEA VER: ");
    fflush(stdin);
    gets(fiches);
    printf("\n");

    printf("\nDIGITE UN RANGO MINIMO DEL PAGO MENOS LA DEVUELTA DE LOS PASAJEROS QUE DESEA VER: ");
    fflush(stdin);
    scanf("%d", &monto_min);
    printf("\n");

    printf("\nDIGITE UN RANGO MAXIMO DEL PAGO MENOS LA DEVULETA DE LOS PASAJEROS QUE DESEA VER: ");
    fflush(stdin);
    scanf("%d", &monto_max);
    printf("\n");

    for(i = 0; i < ind; i++) 
    {
        if (strcmp(fiches, (ListadoServicio+i)->ficha) == 0)
        {
            if(monto_min <= (ListadoServicio+i)->cant_estimada <= monto_max && (ListadoServicio+i)->cliente == (ListaPasajeros+i)->ID)
            {
                printf("CLIENTE ID: %d\n", (ListaPasajeros+i)->ID);
                printf("NOMBRE: %s\n", (ListaPasajeros+i)->nombre);
                printf("LUGAR DE TRABAJO: %s\n", (ListaPasajeros+i)->trabajo);
                printf("CEULAR: %s\n", (ListaPasajeros+i)->celular);
                printf("COMPANIA MOVIL: %s\n\n", (ListaPasajeros+i)->comp_movil);
                //printf("%d\n", i);
            }
        }
    }
}

void VerPasajerosdeUnConcho_Fecha(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho)
{
    int i = 0, j = 0;
    char fiches[10];
    Tiempo tiempo_ini, tiempo_fin;

    printf("\nDIGITE LA FICHA DEL CONCHO QUE DESEA VER: ");
    fflush(stdin);
    gets(fiches);
    printf("\n");

    printf("\nINGRESE UN RANGO DE FECHA Y HORA INICIAL: (DD/MM/YY HH:MM:SS): ");
    scanf("%d/%d/%d %d:%d:%d", &tiempo_ini.dia, &tiempo_ini.mes, &tiempo_ini.year,
                               &tiempo_ini.hora, &tiempo_ini.minuto, &tiempo_ini.segundo);
    printf("\n");

    printf("\nINGRESE UN RANGO DE FECHA Y HORA FINAL: (DD/MM/YY HH:MM:SS): ");
    scanf("%d/%d/%d %d:%d:%d", &tiempo_fin.dia, &tiempo_fin.mes, &tiempo_fin.year,
                               &tiempo_fin.hora, &tiempo_fin.minuto, &tiempo_fin.segundo);
    printf("\n");

    for(i = 0; i < ind; i++) 
    {
        Servicio servicio = ListadoServicio[i];
        if (strcmp(fiches, (ListadoServicio+i)->ficha) == 0)
        {
            if(CompararFecha((ListadoServicio+i)->tiempo, tiempo_ini) >= 0 && CompararFecha((ListadoServicio+i)->tiempo, tiempo_fin) <= 0)
            {
                for (j = 0; j < ind; j++)
                {
                    if ((ListaPasajeros+j)->ID == servicio.cliente)
                    {
                        printf("CLIENTE ID: %d\n", (ListaPasajeros+j)->ID);
                        printf("NOMBRE: %s\n", (ListaPasajeros+j)->nombre);
                        printf("LUGAR DE TRABAJO: %s\n", (ListaPasajeros+j)->trabajo);
                        printf("CEULAR: %s\n", (ListaPasajeros+j)->celular);
                        printf("COMPANIA MOVIL: %s\n\n", (ListaPasajeros+j)->comp_movil);
                    }
                }
            }
        }
    }
}

int CompararFecha(Tiempo Fecha1, Tiempo Fecha2)
{
    if (Fecha1.year < Fecha2.year) {
        return -1;
    } else if (Fecha1.year > Fecha2.year) {
        return 1;
    } else {
        if (Fecha1.mes < Fecha2.mes) {
            return -1;
        } else if (Fecha1.mes > Fecha2.mes) {
            return 1;
        } else {
            if (Fecha1.dia < Fecha2.dia) {
                return -1;
            } else if (Fecha1.dia > Fecha2.dia) {
                return 1;
            } else {
                if (Fecha1.hora < Fecha2.hora) {
                    return -1;
                } else if (Fecha1.hora > Fecha2.hora) {
                    return 1;
                } else {
                    if (Fecha1.minuto < Fecha2.minuto) {
                        return -1;
                    } else if (Fecha1.minuto > Fecha2.minuto) {
                        return 1;
                    } else {
                        if (Fecha1.segundo < Fecha2.segundo) {
                            return -1;
                        } else if (Fecha1.segundo > Fecha2.segundo) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
}

//CARROS

void VerConchoqueMontaUnPasajero(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho)
{

    int i =0, ids;

    printf("\nDIGITE EL ID DEL PASAJERO QUE DESEA VERIFICAR QUE CONCHOS HA TOMADO: ");

    scanf("%d", &ids);
    printf("\n");

    for(i = 0; i < ind; i++) 
    {
        if(ids == (ListadoServicio+i)->cliente && ids == (ListaPasajeros+i)->ID)
        {
            //if (strcmp((ListadoConcho+i)->ficha, (ListadoServicio + i)->ficha) == 0){
            printf("FICHA: %s\n", (ListadoConcho+i)->ficha);
            printf("MARCA: %s\n", (ListadoConcho+i)->marca);
            printf("MODELO: %d\n", (ListadoConcho+i)->anio);
            printf("PROPIETARIO: %s\n\n", (ListadoConcho+i)->propietario);
            // }
        }
    }
}

void VerConchoModelo(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho)
{

    int i =0, ids, p_rango, ul_rango;

    printf("\nDIGITE EL ID DEL PASAJERO QUE DESEA VERIFICAR: ");
    fflush(stdin);
    scanf("%d", &ids);
    printf("\n");

    printf("\nDIGITE El PRIMER RANGO DE MODELO: ");
    fflush(stdin);
    scanf("%d", &p_rango);
    printf("\n");

    printf("\nDIGITE El PRIMER RANGO DE MODELO: ");
    fflush(stdin);
    scanf("%d", &ul_rango);
    printf("\n");

    for(i = 0; i < ind; i++) 
    {
        //if(ids == (ListadoServicio+i)->cliente && ids == (ListaPasajeros+i)->ID)
        //{
            if (strcmp((ListadoConcho+i)->ficha, (ListadoServicio + i)->ficha) == 0)
            {
                if(p_rango <= (ListadoConcho+i)->anio && ul_rango >= (ListadoConcho+i)->anio)
                {
                    printf("FICHA: %s\n", (ListadoConcho+i)->ficha);
                    printf("MARCA: %s\n", (ListadoConcho+i)->marca);
                    printf("MODELO: %d\n", (ListadoConcho+i)->anio);
                    printf("PROPIETARIO: %s\n\n", (ListadoConcho+i)->propietario);
                }
            }
        //}
    }
}

void VerConchoMarca(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho)
{

    int i =0, ids;
    char marcas[10];

    printf("\nDIGITE EL ID DEL PASAJERO QUE DESEA VERIFICAR QUE CONCHOS HA TOMADO: ");
    fflush(stdin);
    scanf("%d", &ids);
    printf("\n");

    printf("\nDIGITE LA MARCA DEL CARRO: ");
    fflush(stdin);
    gets(marcas);
    printf("\n");

    for(i = 0; i < ind; i++) 
    {
        //if(ids == (ListadoServicio+i)->cliente && ids == (ListaPasajeros+i)->ID)
        //{
            if (strcmp((ListadoConcho+i)->ficha, (ListadoServicio + i)->ficha) == 0) 
            {
                if (strcmp(marcas, (ListadoConcho + i)->marca) == 0) 
                {
                    printf("FICHA: %s\n", (ListadoConcho + i)->ficha);
                    printf("MARCA: %s\n", (ListadoConcho + i)->marca);
                    printf("MODELO: %d\n", (ListadoConcho + i)->anio);
                    printf("PROPIETARIO: %s\n\n", (ListadoConcho + i)->propietario);
                }
            }
        //}
    }
}

void VerConchoPropietario(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho)
{

    int i =0, ids;
    char dueno[10];

    printf("\nDIGITE EL ID DEL PASAJERO QUE DESEA VERIFICAR QUE CONCHOS HA TOMADO: ");
    fflush(stdin);
    scanf("%d", &ids);
    printf("\n");

    printf("\nDIGITE EL NOMBRE DEL PROPIETARIO DE CARROS: ");
    fflush(stdin);
    gets(dueno);
    printf("\n");

    for(i = 0; i < ind; i++) 
    {
        //if(ids == (ListadoServicio+i)->cliente && ids == (ListaPasajeros+i)->ID)
        //{
            if (strcmp((ListadoConcho+i)->ficha, (ListadoServicio + i)->ficha) == 0) 
            {
                if (strcmp(dueno, (ListadoConcho + i)->propietario) == 0) 
                {
                    printf("FICHA: %s\n", (ListadoConcho + i)->ficha);
                    printf("MARCA: %s\n", (ListadoConcho + i)->marca);
                    printf("MODELO: %d\n", (ListadoConcho + i)->anio);
                    printf("PROPIETARIO: %s\n\n", (ListadoConcho + i)->propietario);
                }
            }
        //}
    }
}

void VerConchoMonto(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho)
{
    int i =0, ids, p_rango, ul_rango;

    printf("\nDIGITE EL ID DEL PASAJERO QUE DESEA VERIFICAR: ");
    fflush(stdin);
    scanf("%d", &ids);
    printf("\n");

    printf("\nDIGITE El PRIMER RANGO DE MONTO: ");
    fflush(stdin);
    scanf("%d", &p_rango);
    printf("\n");

    printf("\nDIGITE El PRIMER RANGO DE MONTO: ");
    fflush(stdin);
    scanf("%d", &ul_rango);
    printf("\n");

    for(i = 0; i < ind; i++) 
    {
        if(ids == (ListadoServicio+i)->cliente && ids == (ListaPasajeros+i)->ID)
        {
            if (strcmp((ListadoConcho+i)->ficha, (ListadoServicio + i)->ficha) == 0)
            {
                if(p_rango <= (ListadoServicio+i)->pago && ul_rango >= (ListadoServicio+i)->pago)
                {
                    printf("FICHA: %s\n", (ListadoConcho+i)->ficha);
                    printf("MARCA: %s\n", (ListadoConcho+i)->marca);
                    printf("MODELO: %d\n", (ListadoConcho+i)->anio);
                    printf("PROPIETARIO: %s\n\n", (ListadoConcho+i)->propietario);
                }
            }
        }
    }
}

void VerConchoFecha(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho)
{

    int i =0, id_pasajero;
    char fecha_ini[20], fecha_max[20];

    printf("\nDIGITE EL ID DEL PASAJERO QUE DESEA VERIFICAR: ");
    fflush(stdin);
    scanf("%d", &id_pasajero);
    printf("\n");

    printf("\nDIGITE El PRIMER RANGO DE FECHA: (formato: dd/mm/yyyy): ");
    fflush(stdin);
    gets(fecha_ini);
    printf("\n");

    printf("\nDIGITE El ULTIMO RANGO DE FECHA: (formato: dd/mm/yyyy): ");
    fflush(stdin);
    gets(fecha_max);
    printf("\n");
}


//SERVICIOS


void VerFichaCarro(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho)
{
    int i;
    for(i = 0; i < ind; i++) 
    {
        if (strcmp((ListadoConcho+i)->ficha, (ListadoServicio + i)->ficha) == 0)
        {
            printf("FICHA DE CARRO: %s\n", (ListadoServicio+i)->ficha);
        }
    }
}

void VerIDPasajero(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho)
{
    int i;
    for(i = 0; i < ind; i++) 
    {
        if ((ListaPasajeros+i)->ID == (ListadoServicio + i)->cliente)
        {
            printf("\nNOMBRE DEL PASAJERO: %s\t", (ListaPasajeros+i)->nombre);
            printf("ID DEL PASAJERO: %d\n", (ListadoServicio+i)->cliente);
        }
    }
}

void VerRangoMonto(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho)
{
    int i;
    double p_rango, ul_rango;
    
    printf("\nDIGITE El PRIMER RANGO DE MONTO: ");
    fflush(stdin);
    scanf("%lf", &p_rango);
    printf("\n");

    printf("\nDIGITE El PRIMER RANGO DE MONTO: ");
    fflush(stdin);
    scanf("%lf", &ul_rango);
    printf("\n");
    for(i = 0; i < ind; i++) 
    {
        if (p_rango <= (ListadoServicio+i)->pago && ul_rango >= (ListadoServicio+i)->pago && (ListadoServicio+i)->cliente == (ListaPasajeros+i)->ID)
        {
            printf("\nNOMBRE DEL PASAJERO: %s\t", (ListaPasajeros+i)->nombre);
            printf("MONTO: %.2lf\n", (ListadoServicio+i)->pago);
        }
    }
}

void VerRangoFecha(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho)
{
    int i;
    char p_rango[20], ul_rango[20];

    printf("\nDIGITE El PRIMER RANGO DE FECHA: ");
    fflush(stdin);
    gets(p_rango);
    printf("\n");

    printf("\nDIGITE El SEGUNDO RANGO DE FECHA: ");
    fflush(stdin);
    gets(ul_rango);
    printf("\n");

    for(i = 0; i < ind; i++) 
    {
        char fechaHora[20];
        formatearFechaHora((ListadoServicio+i)->tiempo, fechaHora);
        if (strcmp(p_rango, fechaHora) <= 0 && strcmp(ul_rango, fechaHora) >= 0 && (ListaPasajeros+i)->ID == (ListadoServicio+i)->cliente)
        {
            printf("\nNOMBRE DEL PASAJERO: %s\t", (ListaPasajeros+i)->nombre);
            printf("FECHA DEL SERVICIO: %s\n", fechaHora);
        }
    }
}

void formatearFechaHora(Tiempo tiempo, char fechaHora[])
{
    sprintf(fechaHora, "%02d/%02d/%04d %02d:%02d:%02d", tiempo.dia, tiempo.mes, tiempo.year, tiempo.hora, tiempo.minuto, tiempo.segundo);
}

void VerRangoTiempo(int ind, Servicio* ListadoServicio, Pasajeros* ListaPasajeros, Carro* ListadoConcho)
{
    int tiempo_min, tiempo_max;
    printf("\nINGRESE UN RANGO MINIMO DE TIEMPO (EXPRESADO EN MINUTOS): ");
    scanf("%d", &tiempo_min);

    printf("\nINGRESE UN RANGO MAXIMO DE TIEMPO (EXPRESADO EN MINUTOS): ");
    scanf("%d", &tiempo_max);

    int i;
    for (i = 0; i < ind; i++)
    {
        int tiempoEstimado = (ListadoServicio + i)->cant_estimada;
        if (tiempoEstimado >= tiempo_min && tiempoEstimado <= tiempo_max)
        {
            printf("\nID DEL PASAJERO: %d\t", (ListadoServicio + i)->cliente);
            printf("TIEMPO ESTIMADO DEL SERVICIO: %d minutos\n", tiempoEstimado);
        }
    }
}