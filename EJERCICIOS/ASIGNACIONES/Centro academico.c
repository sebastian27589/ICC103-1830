#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura de estudiante
typedef struct sEstudiante
{
    int ID;
    char Matricula[9];
    char Nombres[50];
    char Apellidos[50];
    char Carrera[5];
    short Inactivo;
    struct sEstudiante *siguiente;
} Estudiante;

// Estructura de asignatura
typedef struct sAsignatura
{
    int ID;
    char Codigo[10];
    char Nombre[25];
    int Creditos;
    short Inactivo;
    struct sAsignatura* siguiente;
} Asignatura;

// Estructura de calificacion
typedef struct sCalificacion
{
    int ID_Actividad;
    int ID_Estudiante; // Esto fue añadido
    float Calificacion;
    short Inactivo;
    struct sCalificacion *siguiente;
} Calificacion;

// Estructura de actividad
typedef struct sActividad
{
    int ID;
    int ID_Asignatura;
    char Nombre[25];
    short Inactivo;
    struct sActividad *siguiente;
} Actividad;

// Estructura de estudiante-asignatura
typedef struct EstudianteAsignatura
{
    int ID_Estudiante;
    int ID_Asignatura;
    Calificacion ListaCalificaciones[20];
    short Inactivo;
    struct EstudianteAsignatura* siguiente;
} EstudianteAsignatura;

// Estructura principal
typedef struct
{
    Estudiante estudiantes[50];
    Estudiante* listaEstudiantes;
    int numEstudiantes;
    int indiceEstudiantes[50];                          // Indice de estudiantes basado en ID
    int listaIDsEstudiantes[100];

    Asignatura asignaturas[20];
    Asignatura* listaAsignaturas;
    int numAsignaturas;
    int indiceAsignaturas[20];                          // Indice de asignaturas basado en ID

    Actividad actividades[30];
    Actividad* listaActividades;
    int numActividades;
    int indiceActividades[30];                          // Indice de actividades basado en ID

    Calificacion calificaciones[30];
    Calificacion* listaCalificaciones;
    int numCalificaciones;
    int indiceCalificaciones[30];                          // Indice de actividades basado en ID

    EstudianteAsignatura inscripciones[50];
    EstudianteAsignatura *listaInscripciones;
    int numInscripciones;
    int indiceInscripciones[30];

} CentroEducativo;



// Funciones del estudiante
void guardarEstudiantesEnArchivo(CentroEducativo*); // Modificada
void ordenarEstudiantesPorID(Estudiante**);
void mostrarEstudiantes(CentroEducativo*);
void crearOcargarArchivoEstudiantes(CentroEducativo*); // Modificada
int mostrarMenuEstudiante();
void crearEstudiante(CentroEducativo*); // Modificada
void modificarEstudiante(CentroEducativo*); // Modificada
void inactivarEstudiante(CentroEducativo*); // Modificada
void mostrarEstudiantesConInactividad(FILE*); // Modificada

// Funcionas de la asignatura
void guardarAsignaturasEnArchivo(CentroEducativo*); // Modificada
void ordenarAsignaturasPorID(Asignatura asignaturas[], int);
void mostrarAsignaturas(Asignatura*);
void crearOcargarArchivoAsignaturas(CentroEducativo*); // Modificada
int mostrarMenuAsignatura();
void crearAsignatura(CentroEducativo*); // Modificada
void modificarAsignatura(CentroEducativo*); // Modificada
void inactivarAsignatura(CentroEducativo*); // Modificada
void mostrarAsignaturasConInactividad(FILE*); // Modificada

// Funciones de la actividad
void guardarActividadesEnArchivo(CentroEducativo*); // Modificada
void ordenarActividadesPorID(Actividad Actividades[], int); // Modificada
void mostrarActividades(CentroEducativo*, int); // Modificada
void crearOcargarArchivoActividades(CentroEducativo*); // Modificada
int mostrarMenuActividad();
void crearActividad(CentroEducativo*);
void modificarActividad(CentroEducativo*); // Modificada
void inactivarActividad(CentroEducativo*); // Modificada
void mostrarActividadesConInactividad(FILE*); // Modificada

// Funciones de la calificacion
void guardarCalificacionesEnArchivo(CentroEducativo*); // Modificada
void ordenarCalificacionesPorID(); // Modificada
void mostrarCalificaciones(CentroEducativo*); // Modificada
void crearOcargarArchivoCalificaciones(CentroEducativo*);
int mostrarMenuCalificacion();
void crearCalificacion(CentroEducativo*); // Modificada
void modificarCalificacion(CentroEducativo*); // Modificada
void inactivarCalificacion(CentroEducativo*); // Modificada
void mostrarCalificacionesConInactividad(FILE*); // Modificada

// Funciones crear estudiante con asignatura
int mostrarMenuEstudiantesInscritos();
void crearOcargarArchivoInscripciones(CentroEducativo*);
void guardarInscripcionesEnArchivo(CentroEducativo*);
void inscribirEstudiantes(CentroEducativo*);
void modificarInscripcion(CentroEducativo*);
void inactivarInscripcion(CentroEducativo*);
void mostrarInscripcionesConInactividad(CentroEducativo*);
void mostrarInscripciones(EstudianteAsignatura*);


int mostrarMenuEstudiante()
{
    int opcion;

    printf("======== MENU ESTUDIANTE ========\n");
    printf("1. Crear estudiante\n");
    printf("2. Modificar estudiante\n");
    printf("3. Inactivar estudiante\n");
    printf("4. Mostrar estudiantes\n");
    printf("5. Gestionar calificaciones\n");
    printf("6. Volver al menu principal\n");
    printf("===================================\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);
    return opcion;

}

void mostrarEstudiantes(CentroEducativo *CentroEducativo)
{

    Estudiante* estudiante = CentroEducativo->listaEstudiantes;
    int contadorEstudiantesInactivos = 0;  // Variable para contar estudiantes inactivos

    // Encabezado de la tabla
    printf("\n");
    printf("ID   MATRICULA        NOMBRES             APELLIDOS          CARRERA\n");
    printf("======================================================================\n");

    //Recorrer la lista para mostrar estudainte
    while (estudiante != NULL)
    {
        if (estudiante->Inactivo == 0)
            printf("[%-4d] [%-11s] [%-19s] [%-19s] [%-9s]\n", estudiante->ID, estudiante->Matricula, estudiante->Nombres,
                    estudiante->Apellidos, estudiante->Carrera);
        else
            contadorEstudiantesInactivos++;

        estudiante = estudiante->siguiente;
    }

    printf("\n======================================================================\n");

    // Mostrar el contador de estudiantes inactivos
    printf("ESTUDIANTE INACTIVOS: [%d]\n", contadorEstudiantesInactivos);
}

void mostrarEstudiantesConInactividad(FILE* archivo)
{
    Estudiante estudiante;

    // Encabezado de la tabla
    printf("\n");
    printf("ID   MATRICULA        NOMBRES             APELLIDOS          CARRERA    ESTADO\n");
    printf("==================================================================================\n");

    while (fread(&estudiante, sizeof(Estudiante), 1, archivo) == 1)
    {
        printf("[%-4d] [%-11s] [%-19s] [%-19s] [%-9s]   [%s]\n", estudiante.ID, estudiante.Matricula,
               estudiante.Nombres, estudiante.Apellidos, estudiante.Carrera,
               estudiante.Inactivo ? "Inactivo" : "Activo");
    }

    printf("\n==================================================================================\n");
}

void crearOcargarArchivoEstudiantes(CentroEducativo* centroEducativo)
{
    FILE* archivo = fopen("estudiantes.dat", "rb");
    if (archivo == NULL)
    {
        printf("El archivo de estudiantes no existe. Se creara un archivo nuevo.\n\n");
        archivo = fopen("estudiantes.dat", "wb");
        if (archivo == NULL)
        {
            printf("ERROR: No se pudo crear el archivo de estudiantes.\n");
            return;
        }
        fclose(archivo);
        return;
    }

    // // Inicializar la lista en 0
    centroEducativo->listaEstudiantes = NULL;

    // Leer los estudiantes desde el archivo
    Estudiante estudiante;
    while (fread(&estudiante, sizeof(estudiante), 1, archivo) == 1)
    {
        Estudiante* nuevoEstudiante = (Estudiante*)malloc(sizeof(Estudiante));
        if (nuevoEstudiante == NULL)
        {
            printf("ERROR: No se pudo asignar memoria para el nuevo estudiante.\n");
            break;
        }

        // Copiar datos del estudiante leido al nuevo estudiante
        *nuevoEstudiante = estudiante;
        nuevoEstudiante->siguiente = centroEducativo->listaEstudiantes;
        centroEducativo->listaEstudiantes = nuevoEstudiante;

        centroEducativo->numEstudiantes++;
    }


    fclose(archivo);
}

void guardarEstudiantesEnArchivo(CentroEducativo* centroEducativo)
{
    // Se ordenan los estudiantes por ID
    //ordenarEstudiantesPorID(&(centroEducativo->listaEstudiantes));

    FILE* archivo = fopen("estudiantes.dat", "wb");
    if (archivo == NULL)
    {
        printf("ERROR: No se pudo abrir el archivo de estudiantes.\n");
        return;
    }

    Estudiante *nodoActual = centroEducativo->listaEstudiantes;
    while (nodoActual != NULL)
    {
        fwrite(nodoActual, sizeof(Estudiante), 1, archivo);
        nodoActual = nodoActual->siguiente;
    }

    fclose(archivo);
}

void crearEstudiante(CentroEducativo* centroEducativo)
{

    Estudiante* nuevoEstudiante = (Estudiante*)malloc(sizeof(Estudiante));
    if (nuevoEstudiante == NULL)
    {
        printf("ERROR: No se pudo asignar memoria para el nuevo estudiante.");
        return;
    }

    // Solicitar los datos del nuevo estudiante al usuario
    printf("Ingrese el ID del estudiante: ");
    scanf("%d", &nuevoEstudiante->ID);

    // Verificar si el ID ya esta registrado
    for (Estudiante* estudianteActual = centroEducativo->listaEstudiantes; estudianteActual != NULL; estudianteActual = estudianteActual->siguiente)
    {
        if (estudianteActual->ID == nuevoEstudiante->ID)
        {
            printf("ERROR: El ID del estudiante ya esta registrado. Ingrese un ID unico.\n");
            free(nuevoEstudiante);
            return;
        }
    }

    printf("Ingrese la matricula del estudiante: ");
    scanf("%s", nuevoEstudiante->Matricula);

    // Verificar si la matricula ya esta registrada
    for (Estudiante* estudianteActual = centroEducativo->listaEstudiantes; estudianteActual != NULL; estudianteActual = estudianteActual->siguiente)
    {
        if (strcmp(estudianteActual->Matricula, nuevoEstudiante->Matricula) == 0)
        {
            printf("ERROR: La matricula ya esta registrada por otro estudiante. Ingrese una matricula unica.\n");
            free(nuevoEstudiante);
            return;
        }
    }

    printf("Ingrese el nombre del estudiante: ");
    fflush(stdin);
    gets(nuevoEstudiante->Nombres);

    printf("Ingrese el apellido del estudiante: ");
    fflush(stdin);
    gets(nuevoEstudiante->Apellidos);

    // Verificar que la carrera no tenga mas de 5 caracteres
    do
    {
        printf("Ingrese la carrera del estudiante (maximo 5 caracteres): ");
        fflush(stdin);
        gets(nuevoEstudiante->Carrera);
        if (strlen(nuevoEstudiante->Carrera) > 5)
        {
            printf("ERROR: La carrera no puede tener mas de 5 caracteres. Intente nuevamente.\n");
        }
    } while (strlen(nuevoEstudiante->Carrera) > 5);

    // Marcar al estudiante como activo
    nuevoEstudiante->Inactivo = 0;

    // Agregar el estudiante al arreglo de estudiantes en el centro educativo
    nuevoEstudiante->siguiente = centroEducativo->listaEstudiantes;
    centroEducativo->listaEstudiantes = nuevoEstudiante;

    // Incrementar el contador de estudiantes en el centro educativo
    centroEducativo->numEstudiantes++;

    // Guardar los cambios en el archivo
    guardarEstudiantesEnArchivo(centroEducativo);

    printf("Estudiante creado con exito.\n\n");
}

void modificarEstudiante(CentroEducativo* centroEducativo)
{
    int indiceSeleccionado;
    printf("Ingrese el ID del estudiante que desea modificar (0 para salir): ");
    scanf("%d", &indiceSeleccionado);

    if (indiceSeleccionado != 0)
    {
        Estudiante* estudiante = centroEducativo->listaEstudiantes;

        // Verificar si el ID ya esta registrado
        while (estudiante != NULL)
        {
            if (estudiante->ID == indiceSeleccionado)
            {
                // Datos actuales del estudiante
                printf("\nDatos actuales del estudiante:\n");
                printf("ID: [%d]\n", estudiante->ID);
                printf("Matricula: [%s]\n", estudiante->Matricula);
                printf("Nombres: [%s]\n", estudiante->Nombres);
                printf("Apellidos: [%s]\n", estudiante->Apellidos);
                printf("Carrera: [%s]\n", estudiante->Carrera);

                // Variables para almacenar los nuevos datos del estudiante
                int nuevoID;
                char nuevaMatricula[9];

                // Obtener los nuevos datos del estudiante
                // Se verifica si el ID o la matricula ya existen antes de solicitar los nuevos datos
                do
                {
                    printf("\nIngrese los nuevos datos del estudiante.\n");
                    printf("ID: ");
                    scanf("%d", &nuevoID);

                    // Verificar si el ID ya esta registrado
                    Estudiante* estudianteActual = centroEducativo->listaEstudiantes;
                    while (estudianteActual != NULL)
                    {
                        if (estudianteActual->ID == nuevoID && estudianteActual != estudiante)
                        {
                            printf("ERROR: El ID del estudiante ya esta registrado. Ingrese un ID unico.\n");
                            return;
                        }
                        estudianteActual = estudianteActual->siguiente;
                    }
                } while (nuevoID <= 0);

                printf("Matricula: ");
                scanf("%s", nuevaMatricula);

                // Verificar si la matricula ya esta registrada
                Estudiante* estudianteActual = centroEducativo->listaEstudiantes;
                while (estudianteActual != NULL)
                {
                    if (strcmp(estudianteActual->Matricula, nuevaMatricula) == 0 && estudianteActual != estudiante)
                    {
                        printf("ERROR: La matricula ya esta registrada por otro estudiante. Ingrese una matricula unica.\n");
                        return;
                    }
                    estudianteActual = estudianteActual->siguiente;
                }

                printf("Nombres: ");
                fflush(stdin);
                gets(estudiante->Nombres);

                printf("Apellidos: ");
                fflush(stdin);
                gets(estudiante->Apellidos);

                // Verificar que la carrera no tenga mas de 5 caracteres
                do
                {
                    printf("Ingrese la carrera del estudiante (maximo 5 caracteres): ");
                    fflush(stdin);
                    gets(estudiante->Carrera);
                    if (strlen(estudiante->Carrera) > 5)
                    {
                        printf("ERROR: La carrera no puede tener mas de 5 caracteres. Intente nuevamente.\n");
                    }
                } while (strlen(estudiante->Carrera) > 5);

                // Actualizar los datos del estudiante con los nuevos valores
                estudiante->ID = nuevoID;
                strcpy(estudiante->Matricula, nuevaMatricula);

                guardarEstudiantesEnArchivo(centroEducativo);

                printf("\nEstudiante modificado con exito.\n");
                return;
            }

            estudiante = estudiante->siguiente;
        }

        printf("\nERROR: No se encontro un estudiante con el ID especificado.\n");
    }
}

void inactivarEstudiante(CentroEducativo* centroEducativo)
{
    FILE* archivoEstudiantes = fopen("estudiantes.dat", "rb");

    printf("\nESTUDIANTES ACTIVOS E INACTIVOS:\n");
    mostrarEstudiantesConInactividad(archivoEstudiantes);

    int idEstudiante;

    printf("Ingrese el ID del estudiante que desea activar/desactivar (0 para salir): ");
    scanf("%d", &idEstudiante);

    if (idEstudiante != 0)
    {

        // Buscar el estudiante en la lista
        Estudiante* estudiante = centroEducativo->listaEstudiantes;
        while (estudiante != NULL)
        {

            if (estudiante->ID == idEstudiante)
            {
                estudiante->Inactivo = 1 - estudiante->Inactivo;

                // Guardar los cambios en el archivo
                guardarEstudiantesEnArchivo(centroEducativo);

                if (estudiante->Inactivo)
                {
                    printf("Estudiante con ID [%d] inactivado exitosamente.\n", idEstudiante);
                }
                else
                {
                    printf("Estudiante con ID [%d] activado exitosamente.\n", idEstudiante);
                }

                return;
            }

            estudiante = estudiante->siguiente;
        }

        printf("ERROR: No se encontro un estudiante con el ID especificado.\n");
    }

    fclose(archivoEstudiantes);
}


// ASIGNATURAS


int mostrarMenuAsignatura()
{
    int opcion;

    printf("======== MENU ASIGNATURA ========\n");
    printf("1. Crear asignatura\n");
    printf("2. Modificar asignatura\n");
    printf("3. Inactivar asignatura\n");
    printf("4. Mostrar asignaturas\n");
    printf("5. Gestionar actividades\n");
    printf("6. Volver al menu principal\n");
    printf("===================================\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int mostrarMenuActividad()
{
    int opcion;

    printf("======== GESTION DE ACTIVIDADES ========\n");
    printf("1. Crear actividad\n");
    printf("2. Modificar actividad\n");
    printf("3. Inactivar actividad\n");
    printf("4. Mostrar actividades\n");
    printf("5. Volver atras\n");
    printf("========================================\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}


void mostrarAsignaturas(Asignatura* listaAsignaturas)
{
    Asignatura* asignaturaActual = listaAsignaturas;
    int contadorAsignaturasInactivas = 0;

    // Encabezado de la tabla
    printf("\nASIGNATURAS DISPONIBLES:\n");
    printf("\n");
    printf("ID   CODIGO      NOMBRE             CREDITOS\n");
    printf("==================================================\n");

    // Recorrer la lista de asignaturas y mostrar sus datos
    while (asignaturaActual != NULL)
    {
         if (asignaturaActual->Inactivo == 0)
            printf("[%-4d] [%-11s] [%-19s] [%-11d]\n", asignaturaActual->ID, asignaturaActual->Codigo, asignaturaActual->Nombre, asignaturaActual->Creditos);
        else
            contadorAsignaturasInactivas++;

        asignaturaActual = asignaturaActual->siguiente;
    }

    printf("\n==================================================\n");

    // Mostrar el contador de asignaturas inactivas
    printf("Asignaturas inactivas: [%d]\n", contadorAsignaturasInactivas);
}

void crearAsignatura(CentroEducativo* centroEducativo)
{
    Asignatura* nuevaAsignatura = (Asignatura*)malloc(sizeof(Asignatura));
    if (nuevaAsignatura == NULL)
    {
        printf("ERROR: No se pudo asignar memoria para el nuevo estudiante.");
        return;
    }

    // Solicitar los datos de la nueva asignatura al usuario
    printf("Ingrese el ID de la asignatura: ");
    scanf("%d", &nuevaAsignatura->ID);

    // Verificar si el ID ya esta registrado
    for (Asignatura* asignaturaActual = centroEducativo->listaAsignaturas; asignaturaActual != NULL; asignaturaActual = asignaturaActual->siguiente)
    {
        if (asignaturaActual->ID == nuevaAsignatura->ID)
        {
            printf("ERROR: El ID de la asignatura ya esta registrada. Ingrese un ID unico.\n");
            free(nuevaAsignatura);
            return;
        }
    }

    printf("Ingrese el codigo de la asignatura: ");
    fflush(stdin);
    gets(nuevaAsignatura->Codigo);

    printf("Ingrese el nombre de la asignatura: ");
    fflush(stdin);
    gets(nuevaAsignatura->Nombre);

    printf("Ingrese la cantidad de creditos de la asignatura: ");
    scanf("%d", &nuevaAsignatura->Creditos);

    // Marcar la asignatura como activa
    nuevaAsignatura->Inactivo = 0;

    // Agregar la asignatura al arreglo de asignaturas en el centro educativo
    nuevaAsignatura->siguiente = centroEducativo->listaAsignaturas;
    centroEducativo->listaAsignaturas = nuevaAsignatura;

    // Incrementar el contador de asignaturas en el centro educativo
    centroEducativo->numAsignaturas++;

    // Guardar los cambios en el archivo
    guardarAsignaturasEnArchivo(centroEducativo);

    printf("Asignatura creada con exito.\n\n");
}

void modificarAsignatura(CentroEducativo* centroEducativo)
{
    int idAsignatura;
    printf("Ingrese el ID de la asignatura que desea modificar (0 para salir): ");
    scanf("%d", &idAsignatura);

    if (idAsignatura != 0)
    {
        Asignatura* asignatura = centroEducativo->listaAsignaturas;

        // Obtener la asignatura seleccionada
        while (asignatura != NULL)
        {
            if (asignatura->ID == idAsignatura)
            {
                // Guardar el ID original en una variable temporal
                int idOriginal = asignatura->ID;

                // Datos actuales de la asignatura
                printf("\nDatos actuales de la asignatura:\n");
                printf("ID: [%d]\n", asignatura->ID);
                printf("Codigo: [%s]\n", asignatura->Codigo);
                printf("Nombre: [%s]\n", asignatura->Nombre);
                printf("Creditos: [%d]\n", asignatura->Creditos);

                // Modificar los datos de la asignatura
                printf("\nIngrese los nuevos datos de la asignatura.\n");
                printf("ID: ");
                scanf("%d", &asignatura->ID);

                // Verificar si el nuevo ID ya esta registrado en otra asignatura activa
                if (idOriginal != asignatura->ID) // Se modifico el ID
                {
                    for (Asignatura* otraAsignatura = centroEducativo->listaAsignaturas; otraAsignatura != NULL; otraAsignatura = otraAsignatura->siguiente)
                    {
                        if (otraAsignatura->Inactivo == 0 && otraAsignatura->ID == asignatura->ID)
                        {
                            printf("ERROR: El ID de la asignatura ya esta registrado. Ingrese un ID unico.\n");
                            asignatura->ID = idOriginal; // Restaurar el ID original
                            return;
                        }
                    }
                }

                printf("Codigo: ");
                fflush(stdin);
                gets(asignatura->Codigo);

                printf("Nombre: ");
                fflush(stdin);
                gets(asignatura->Nombre);

                printf("Creditos: ");
                scanf("%d", &asignatura->Creditos);

                // Guardar los cambios en el archivo
                guardarAsignaturasEnArchivo(centroEducativo);

                printf("\nAsignatura modificada con exito.\n");
                return;
            }

            asignatura = asignatura->siguiente;
        }

        printf("\nERROR: no se encontro una asignatura con el ID especificado.\n");
    }
}

void inactivarAsignatura(CentroEducativo* centroEducativo)
{
    FILE* archivoAsignaturas = fopen("asignaturas.dat", "rb");

    printf("\nASIGNATURAS ACTIVAS E INACTIVAS:\n");
    mostrarAsignaturasConInactividad(archivoAsignaturas);

    int idAsignatura;

    printf("Ingrese el ID de la asignatura que desea activar/desactivar (0 para salir): ");
    scanf("%d", &idAsignatura);

    if (idAsignatura != 0)
    {
        // Buscar la asignatura en la lista
        Asignatura* asignatura = centroEducativo->listaAsignaturas;
        while (asignatura != NULL)
        {

            if (asignatura->ID == idAsignatura)
            {
                asignatura->Inactivo = 1 - asignatura->Inactivo;

                // Guardar los cambios en el archivo
                guardarAsignaturasEnArchivo(centroEducativo);

                if (asignatura->Inactivo)
                    printf("Asignatura con ID [%d] inactivada exitosamente.\n", idAsignatura);
                else
                    printf("Asignatura con ID [%d] activada exitosamente.\n", idAsignatura);

                return;
            }

            asignatura = asignatura->siguiente;
        }

        printf("ERROR: No se encontro una asignatura con el ID especificado.\n");
    }

    fclose(archivoAsignaturas);
}

void mostrarAsignaturasConInactividad(FILE* archivo)
{
    Asignatura asignatura;

    // Encabezado de la tabla
    printf("\n");
    printf("ID   CODIGO      NOMBRE             CREDITOS    INACTIVIDAD\n");
    printf("==============================================================\n");

    // Leer y mostrar los registros del archivo
    while (fread(&asignatura, sizeof(Asignatura), 1, archivo) == 1)
        printf("[%-4d] [%-11s] [%-19s] [%-11d]   [%s]\n", asignatura.ID, asignatura.Codigo, asignatura.Nombre, asignatura.Creditos, asignatura.Inactivo ? "Inactivo" : "Activo");

    printf("\n==============================================================\n");
}

void crearOcargarArchivoAsignaturas(CentroEducativo* centroEducativo)
{
    FILE* archivo = fopen("asignaturas.dat", "rb");
    if (archivo == NULL)
    {
        printf("El archivo de asignaturas no existe. Se creara un archivo nuevo.\n\n");
        archivo = fopen("asignaturas.dat", "wb");
        if (archivo == NULL)
        {
            printf("ERROR: No se pudo crear el archivo de asignaturas.\n");
            return;
        }

        fclose(archivo);
        return;
    }

    // Inicializar la lista en 0
    centroEducativo->listaAsignaturas = NULL;

    // Leer las asignaturas desde el archivo
    Asignatura asignatura;
    while (fread(&asignatura, sizeof(Asignatura), 1, archivo) == 1)
    {
        Asignatura* nuevaAsignatura = (Asignatura*)malloc(sizeof(Asignatura));
        if(nuevaAsignatura == NULL)
        {
            printf("ERROR: No se pudo asignar memoria para la nueva asignatura.");
            break;
        }

        // Mover en la lista al igual que en estudiantes
        *nuevaAsignatura = asignatura;

        nuevaAsignatura->siguiente = centroEducativo->listaAsignaturas;
        centroEducativo->listaAsignaturas = nuevaAsignatura;

        centroEducativo->numAsignaturas++;
    }


    // int numAsignaturas = fread(centroEducativo->asignaturas, sizeof(Asignatura), 20, archivo);

    // // Actualizar el numero de asignaturas en el centro educativo
    // centroEducativo->numAsignaturas = numAsignaturas;

    fclose(archivo);
}

void guardarAsignaturasEnArchivo(CentroEducativo* centroEducativo)
{
    //ordenarAsignaturasPorID(centroEducativo->listaAsignaturas, centroEducativo->numAsignaturas);

    FILE* archivo = fopen("asignaturas.dat", "wb");
    if (archivo == NULL)
    {
        printf("ERROR: No se pudo abrir el archivo de asignaturas.\n");
        return;
    }

    Asignatura *nodoActual = centroEducativo->listaAsignaturas;
    while (nodoActual != NULL)
    {
        fwrite(nodoActual, sizeof(Asignatura), 1, archivo);
        nodoActual =  nodoActual->siguiente;
    }

    //fwrite(centroEducativo->asignaturas, sizeof(Asignatura), centroEducativo->numAsignaturas, archivo);

    fclose(archivo);
}

// CALIFICACIONES

int mostrarMenuCalificacion()
{
    int opcion;

    printf("======== MENU CALIFICACION ========\n");
    printf("1. Crear calificacion\n");
    printf("2. Modificar calificacion\n");
    printf("3. Inactivar calificacion\n");
    printf("4. Mostrar calificaciones\n");
    printf("5. Volver atras\n");
    printf("=======================\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void guardarCalificacionesEnArchivo(CentroEducativo* centroEducativo)
{
    FILE* archivo = fopen("calificaciones.dat", "wb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de calificaciones.\n");
        return;
    }

    // Escribir las calificaciones en el archivo
    Calificacion* nodoActual = centroEducativo->listaCalificaciones;
    while (nodoActual != NULL)
    {
        fwrite(nodoActual, sizeof(Calificacion), 1, archivo);
        nodoActual = nodoActual->siguiente;
    }

    //fwrite(centroEducativo->calificaciones, sizeof(Calificacion), centroEducativo->numCalificaciones, archivo);

    fclose(archivo);
}


void mostrarCalificaciones(CentroEducativo *centroEducativo)
{
    int idAsignatura;
    int idActividad;
    int idEstudiante;

    mostrarAsignaturas(centroEducativo->listaAsignaturas);
    printf("Ingrese el ID de la asignatura para filtrar las calificaciones: ");
    scanf("%d", &idAsignatura);

    mostrarActividades(centroEducativo, idAsignatura);
    printf("Ingrese el ID de la actividad para filtrar las calificaciones: ");
    scanf("%d", &idActividad);

    mostrarEstudiantes(centroEducativo);
    printf("Ingrese el ID del estudiante para filtrar las calificaciones: ");
    scanf("%d", &idEstudiante);

    printf("\n===========================================\n");
    printf("ID_ACTIVIDAD   CALIFICACION\n");
    printf("===========================================\n");

    // Leer y mostrar los registros del archivo de calificaciones
    Calificacion* calificacionActual = centroEducativo->listaCalificaciones;
    while (calificacionActual != NULL)
    {
        if (calificacionActual->ID_Actividad == idActividad && calificacionActual->Inactivo == 0)
        {
            // Filtrar por actividad y estado "activo"

            // Buscar la asignatura en el archivo de asignaturas
            Asignatura* asignaturaActual = centroEducativo->listaAsignaturas;
            while (asignaturaActual != NULL)
            {
                if (asignaturaActual->ID == idAsignatura)
                {
                    // Buscar el estudiante en el archivo de estudiantes
                    Estudiante* estudianteActual = centroEducativo->listaEstudiantes;
                    while (estudianteActual != NULL)
                    {
                        if (estudianteActual->ID == idEstudiante)
                        {
                            // Mostrar la calificaci�n con los detalles de la actividad, asignatura y estudiante
                            printf("[%-13d] [%-14.2f]\n", calificacionActual->ID_Actividad, calificacionActual->Calificacion);
                            printf("Asignatura: [%s]\n", asignaturaActual->Nombre);
                            printf("Estudiante: [%s] [%s]\n", estudianteActual->Nombres, estudianteActual->Apellidos);
                            printf("-------------------------------------------\n");
                            break;
                        }

                        estudianteActual = estudianteActual->siguiente;
                    }

                    break;
                }

                asignaturaActual = asignaturaActual->siguiente;
            }
        }

        calificacionActual = calificacionActual->siguiente;
    }

    printf("\n===========================================\n");
}


void crearOcargarArchivoCalificaciones(CentroEducativo* centroEducativo)
{
    FILE* archivo = fopen("calificaciones.dat", "rb");

    if (archivo == NULL)
    {
        printf("El archivo de calificaciones no existe. Se creara un archivo nuevo.\n\n");
        archivo = fopen("calificaciones.dat", "wb");
        if (archivo == NULL)
        {
            printf("ERROR: No se pudo crear el archivo de calificaciones.\n");
            return;
        }
        fclose(archivo);
        return;
    }

    centroEducativo->listaCalificaciones = NULL;

    Calificacion calificacion;
    while (fread(&calificacion, sizeof(Calificacion), 1, archivo) == 1)
    {
        Calificacion* nuevaCalificacion = (Calificacion*)malloc(sizeof(Calificacion));
        if (nuevaCalificacion == NULL)
        {
            printf("ERROR: No se pudo asignar memoria para la nueva calificacion.\n");
            break;
        }

        *nuevaCalificacion = calificacion;

        nuevaCalificacion->siguiente = centroEducativo->listaCalificaciones;
        centroEducativo->listaCalificaciones = nuevaCalificacion;

        centroEducativo->numCalificaciones++;

    }

    fclose(archivo);
}

void crearCalificacion(CentroEducativo* centroEducativo)
{
    FILE* archivoActividades = fopen("actividades.dat", "rb");
    FILE* archivoAsignatura = fopen("asignaturas.dat", "rb");
    //FILE* archivoEstudiantes = fopen("estudiantes.dat", "rb");

    Calificacion nuevaCalificacion;

    int idAsignatura;
    mostrarAsignaturas(centroEducativo->listaAsignaturas);
    printf("Ingrese el ID de la asignatura para mostrar sus actividades: ");
    scanf("%d", &idAsignatura);
    mostrarActividades(centroEducativo, idAsignatura);

    printf("Ingrese el ID de la actividad: ");
    scanf("%d", &nuevaCalificacion.ID_Actividad);

    mostrarEstudiantes(centroEducativo);

    // Solicitar al usuario que ingrese el ID del estudiante
    int idEstudiante;
    printf("Ingrese el ID del estudiante para la calificacion: ");
    scanf("%d", &idEstudiante);

    // Buscar el estudiante en la lista de estudiantes en CentroEducativo
    Estudiante* estudianteActual = centroEducativo->listaEstudiantes;
    int indiceEstudiante = -1;
    while (estudianteActual != NULL)
    {
        if (estudianteActual->ID == idEstudiante)
        {
            indiceEstudiante = estudianteActual->ID;
            break;
        }
        estudianteActual = estudianteActual->siguiente;
    }

    if (indiceEstudiante != -1)
    {
        // Asignar el estudiante a la calificacion
        nuevaCalificacion.ID_Estudiante = idEstudiante;

        // Solicitar al usuario que ingrese la calificaci�n
        printf("Ingrese la calificacion: ");
        scanf("%f", &nuevaCalificacion.Calificacion);

        // Marcar la calificacion como activa
        nuevaCalificacion.Inactivo = 0;

        // Agregarlo a la lista de calificaciones.
        Calificacion* nuevoNodo = (Calificacion*)malloc(sizeof(Calificacion));
        if(nuevoNodo == NULL)
        {
            printf("ERROR: No se pudo asignar memoria para la nueva calificacion.\n");
            return;
        }

        *nuevoNodo = nuevaCalificacion;
        nuevoNodo->siguiente = centroEducativo->listaCalificaciones;
        centroEducativo->listaCalificaciones = nuevoNodo;

        // Agregar la calificacion al arreglo de calificaciones en el centro educativo
        // centroEducativo->calificaciones[centroEducativo->numCalificaciones] = nuevaCalificacion;

        centroEducativo->numCalificaciones++;

        // Guardar los cambios en el archivo de calificaciones
        guardarCalificacionesEnArchivo(centroEducativo);

        printf("Calificacion creada con exito.\n\n");
    } else
        printf("ERROR: No se encontro un estudiante con el ID especificado.\n");

    fclose(archivoActividades);
    fclose(archivoAsignatura);
    //fclose(archivoEstudiantes);
}


void modificarCalificacion(CentroEducativo* centroEducativo)
{
    int idCalificacion;
    printf("Ingrese el ID de la calificacion que desea modificar (0 para salir): ");
    scanf("%d", &idCalificacion);

    if (idCalificacion != 0)
    {
        int encontrado = 0;
        Calificacion* nodoActual = centroEducativo->listaCalificaciones;

        while (nodoActual != NULL)
        {
            if(nodoActual->ID_Actividad == idCalificacion)
            {
                encontrado = 1;
                break;
            }
            nodoActual = nodoActual->siguiente;
        }
        if (encontrado)
        {
            printf("\nDatos actuales de la calificacion:\n");
            printf("ID_Actividad: [%d]\n", nodoActual->ID_Actividad);
            printf("Calificacion: [%.2f]\n", nodoActual->Calificacion);

            printf("\nIngrese la nueva calificacion: ");
            scanf("%f", &nodoActual->Calificacion);

            // Guardar en el archivo de calificaciones
            guardarCalificacionesEnArchivo(centroEducativo);

            printf("\nCalificacion modificada con exito.\n");

        } else
            printf("\nERROR: No se encontro una calificacion con el ID especificado.\n");
    }
}

void inactivarCalificacion(CentroEducativo* centroEducativo)
{
    FILE* archivoCalificaciones = fopen("calificaciones.dat", "rb");

    if (archivoCalificaciones == NULL)
    {
        printf("ERROR: No se pudo abrir el archivo de calificaciones.\n");
        return;
    }

    printf("\nCALIFICACIONES ACTIVAS E INACTIVAS:\n");
    mostrarCalificacionesConInactividad(archivoCalificaciones);

    int idCalificacion;
    printf("Ingrese el ID de la calificacion que desea activar/desactivar (0 para salir): ");
    scanf("%d", &idCalificacion);

    if (idCalificacion != 0)
    {
        int encontrado = 0;
        Calificacion* nodoActual = centroEducativo->listaCalificaciones;

        while (nodoActual != NULL)
        {
            if(nodoActual->ID_Actividad == idCalificacion)
            {
                encontrado = 1;
                break;
            }

            nodoActual = nodoActual->siguiente;
        }
        if (encontrado)
        {
            nodoActual->Inactivo = 1 - nodoActual->Inactivo;
            guardarCalificacionesEnArchivo(centroEducativo);

            if (nodoActual->Inactivo)
                printf("Calificacion con ID [%d] inactivada exitosamente.\n", idCalificacion);
            else
                printf("Calificacion con ID [%d] activada exitosamente.\n", idCalificacion);

        } else
            printf("ERROR: No se encontro una calificacion con el ID especificado.\n");
    }

    fclose(archivoCalificaciones);
}

void mostrarCalificacionesConInactividad(FILE* archivo)
{
    Calificacion calificacion;
    printf("\n");
    printf("ID ACTIVIDAD   CALIFICACION   ESTADO\n");
    printf("=========================================\n");
    while (fread(&calificacion, sizeof(Calificacion), 1, archivo) == 1)
        printf("[%-13d] [%-14.2f] [%s]\n", calificacion.ID_Actividad, calificacion.Calificacion, calificacion.Inactivo ? "Inactivo" : "Activo");

    printf("=========================================\n");
}


// ACTIVIDADES


void crearActividad(CentroEducativo* centroEducativo)
{
    Actividad nuevaActividad;

    // Solicitar al usuario que ingrese el ID de la asignatura
    int idAsignatura;
    printf("Ingrese el ID de la asignatura: ");
    scanf("%d", &idAsignatura);

    // Buscar la asignatura en el arreglo de asignaturas
    Asignatura* asignaturaEncontrada = NULL;
    Asignatura* asignaturaActual = centroEducativo->listaAsignaturas;

    while (asignaturaActual != NULL)
    {
        if (asignaturaActual->ID == idAsignatura)
        {
            asignaturaEncontrada = asignaturaActual;
            break;
        }
        asignaturaActual = asignaturaActual->siguiente;
    }

    if (asignaturaEncontrada != NULL)
    {
        printf("\n [Creando actividad...] \n");
        printf("Ingrese el ID de la actividad a crear: ");
        scanf("%d", &nuevaActividad.ID);

        // Verificar si el ID ya esta registrado
        for (Actividad* actividadActual = centroEducativo->listaActividades; actividadActual != NULL; actividadActual = actividadActual->siguiente)
        {
            if (actividadActual->ID == nuevaActividad.ID)
            {
                printf("ERROR: El ID de la actividad ya esta registrado. Ingrese un ID unico.\n");
                return;
            }
        }

        printf("Ingrese el nombre de la actividad a crear: ");
        fflush(stdin);
        gets(nuevaActividad.Nombre);

        // Asignar la asignatura a la actividad
        nuevaActividad.ID_Asignatura = idAsignatura;

        // Marcar la actividad como activa
        nuevaActividad.Inactivo = 0;

        // Crear nuevo nodo para la lista enlazada de actividades
        Actividad* nuevoNodo = (Actividad*)malloc(sizeof(Actividad));
        if (nuevoNodo == NULL)
        {
            printf("ERROR: No se pudo asignar memoria para la nueva actividad.\n");
            return;
        }

        *nuevoNodo = nuevaActividad;
        nuevoNodo->siguiente = centroEducativo->listaActividades;
        centroEducativo->listaActividades = nuevoNodo;

        // Incrementar el contador de actividades en el centro educativo
        centroEducativo->numActividades++;

        // Guardar los cambios en el archivo de actividades
        guardarActividadesEnArchivo(centroEducativo);

        printf("Actividad creada con exito.\n\n");
    }
    else
    {
        printf("ERROR: El ID de la asignatura no es valido.\n");
    }
}

void modificarActividad(CentroEducativo* centroEducativo)
{
    int idActividad;

    printf("Ingrese el ID de la actividad que desea modificar (0 para salir): ");
    scanf("%d", &idActividad);

    if (idActividad != 0)
    {
        // Buscar la actividad en la lista de actividades del centro educativo
        Actividad* actividadActual = centroEducativo->listaActividades;
        while (actividadActual != NULL)
        {
            if (actividadActual->ID == idActividad)
                break;

            actividadActual = actividadActual->siguiente;
        }

        if (actividadActual != NULL)
         {
            // Mostrar los detalles de la actividad antes de modificarla
            printf("\nDetalles de la actividad seleccionada:\n");
            printf("ID: [%d]\n", actividadActual->ID);
            printf("Nombre: [%s]\n", actividadActual->Nombre);

            // Solicitar al usuario los nuevos datos de la actividad
            printf("\nIngrese los nuevos datos de la actividad.\n");
            printf("Ingrese el nuevo ID: ");
            scanf("%d", &actividadActual->ID);

            printf("\nIngrese el nuevo nombre de la actividad: ");
            fflush(stdin);
            gets(actividadActual->Nombre);

            // Guardar los cambios en el archivo de actividades
            guardarActividadesEnArchivo(centroEducativo);

            printf("\nLa actividad se ha modificado exitosamente.\n");
        } else
            printf("\nERROR: No se encontro una actividad con el ID especificado.\n");
    }
}

void mostrarActividadesConInactividad(FILE* archivo)
{
    Actividad actividad;

    // Encabezado de la tabla
    printf("\n");
    printf("ID   NOMBRE                  ESTADO\n");
    printf("========================================\n");

    // Leer y mostrar los registros del archivo
    while (fread(&actividad, sizeof(Actividad), 1, archivo) == 1)
        printf("[%-4d] [%-22s] [%s]\n", actividad.ID, actividad.Nombre, actividad.Inactivo ? "Inactivo" : "Activo");

    printf("========================================\n");
}

void inactivarActividad(CentroEducativo* centroEducativo)
{
    FILE* archivoAsignaturas = fopen("asignaturas.dat", "rb");
    FILE* archivoActividades = fopen("actividades.dat", "rb");

    mostrarAsignaturas(centroEducativo->listaAsignaturas);

    int idAsignatura;
    printf("Ingrese el ID de la asignatura para mostrar sus actividades: ");
    scanf("%d", &idAsignatura);

    // Buscar la asignatura en la lista de asignaturas
    Asignatura* asignaturaEncontrada = NULL;
    Asignatura* asignaturaActual = centroEducativo->listaAsignaturas;

    while (asignaturaActual != NULL)
    {
        if (asignaturaActual->ID == idAsignatura)
        {
            asignaturaEncontrada = asignaturaActual;
            break;
        }
        asignaturaActual = asignaturaActual->siguiente;
    }

    if (asignaturaEncontrada != NULL)
    {
        printf("\nActividades de la asignatura '%s':\n", asignaturaEncontrada->Nombre);
        printf("=============================================\n");
        printf("ID   NOMBRE                  ESTADO\n");
        printf("=============================================\n");

        // Mostrar las actividades de la asignatura
        Actividad* nodoActividad = centroEducativo->listaActividades;
        while (nodoActividad != NULL)
        {
            if (nodoActividad->ID_Asignatura == idAsignatura)
            {
                printf("[%-4d] [%-22s] [%s]\n", nodoActividad->ID, nodoActividad->Nombre,
                        nodoActividad->Inactivo ? "Inactivo" : "Activo");
            }

            nodoActividad = nodoActividad->siguiente;
        }

        printf("==============================================\n");

        int idActividad;

        printf("Ingrese el ID de la actividad que desea inactivar/activar (0 para salir): ");
        scanf("%d", &idActividad);

        if (idActividad != 0)
        {

            // Buscar actividad en la lista enlazada
            Actividad* nodoActual = centroEducativo->listaActividades;
            Actividad* nodoAnterior = NULL;
            while (nodoActual != NULL)
            {
                if (nodoActual->ID == idActividad && nodoActual->ID_Asignatura == idAsignatura)
                {
                    // Invertir estado de la inactividad
                    nodoActual->Inactivo = !nodoActual->Inactivo;

                    // Guardar los cambios en el archivo
                    guardarActividadesEnArchivo(centroEducativo);

                    if (nodoActual->Inactivo)
                        printf("Actividad con ID [%d] inactivada exitosamente.\n", idActividad);
                    else
                        printf("Actividad con ID [%d] activada exitosamente.\n", idActividad);

                    return;
                }

                nodoAnterior = nodoActual;
                nodoActual = nodoActual->siguiente;
            }

            printf("ERROR: No se encontro una actividad valida con el ID especificado.\n");
        }
    }
    else
    {
        printf("ERROR: El ID de la asignatura no es valido.\n");
    }

    fclose(archivoAsignaturas);
    fclose(archivoActividades);
}

void guardarActividadesEnArchivo(CentroEducativo* centroEducativo)
{
    //ordenarActividadesPorID(centroEducativo->listaActividades, centroEducativo->numActividades);

    FILE* archivo = fopen("actividades.dat", "wb");
    if (archivo == NULL)
    {
        printf("ERROR: No se pudo abrir el archivo de actividades.\n");
        return;
    }

    // Escribir las actividades en el archivo
    Actividad* nodoActual = centroEducativo->listaActividades;
    while (nodoActual != NULL)
    {
        fwrite(nodoActual, sizeof(Actividad), 1, archivo);
        nodoActual = nodoActual->siguiente;
    }

    fclose(archivo);
}


void mostrarActividades(CentroEducativo* centroEducativo, int idAsignatura)
{
    printf("\n==========================================\n");
    printf("ID   NOMBRE\n");
    printf("==========================================\n");

    Actividad* nodoActual = centroEducativo->listaActividades;
    while (nodoActual != NULL)
    {
        if (nodoActual->ID_Asignatura == idAsignatura && nodoActual->Inactivo == 0)
        {
            printf("[%-4d] [%-19s]\n", nodoActual->ID, nodoActual->Nombre);
        }
        nodoActual = nodoActual->siguiente;
    }

    printf("\n==================\n");
}


void crearOcargarArchivoActividades(CentroEducativo* centroEducativo)
{
    FILE* archivo = fopen("actividades.dat", "rb");
    if (archivo == NULL)
    {
        printf("El archivo de actividades no existe. Se creara un archivo nuevo.\n\n");
        archivo = fopen("actividades.dat", "wb");
        if (archivo == NULL)
        {
            printf("ERROR: No se pudo crear el archivo de actividades.\n");
            return;
        }
        fclose(archivo);

        // Inicializar todo en 0
        centroEducativo->listaActividades = NULL;
        centroEducativo->numActividades = 0;
        return;
    }

    // Leer las actividades desde el archivo
    centroEducativo->listaActividades = NULL;
    centroEducativo->numActividades = 0;
    Actividad actividad;
    while (fread(&actividad, sizeof(Actividad), 1, archivo) == 1)
    {
        // Crear nuevo nodo para la lista
        Actividad* nodoActividad = (Actividad*)malloc(sizeof(Actividad));
        if (nodoActividad == NULL)
        {
            printf("ERROR: No se pudo asignar memoria para la actividad.\n");
            break;
        }

        *nodoActividad = actividad;
        nodoActividad->siguiente = centroEducativo->listaActividades;
        centroEducativo->listaActividades = nodoActividad;

        centroEducativo->numActividades++;

    }

    fclose(archivo);
}

// void ordenarActividadesPorID(Actividad actividades[], int numActividades)
// {
//     int i, j;
//     Actividad temp;

//     for (i = 0; i < numActividades - 1; i++)
//     {
//         for (j = 0; j < numActividades - i - 1; j++)
//         {
//             if (actividades[j].ID > actividades[j + 1].ID)
//             {
//                                                         // Intercambiar actividades[j] con actividades[j + 1]
//                 temp = actividades[j];
//                 actividades[j] = actividades[j + 1];
//                 actividades[j + 1] = temp;
//             }
//         }
//     }
// }

int main()
{
    CentroEducativo centroEducativo;
    Estudiante *listaEstudiantes = NULL;
    Asignatura *listaAsignatura  = NULL;
    Actividad *listaActividad = NULL;
    EstudianteAsignatura *listaEstudianteAsignatura = NULL;
    EstudianteAsignatura *listaInscripciones = NULL;
    //CentroEducativo *listaEstudiantes = NULL;
    int opcionPrincipal;
    int opcionEstudiante;
    int opcionAsignatura;
    int opcionCalificacion;
    int opcionActividad;
    int opcionInscribirAsignatura;
    int opcionEstudianteInscrito;


    // Carga los datos desde los archivos de datos binarios
    crearOcargarArchivoEstudiantes(&centroEducativo);
    crearOcargarArchivoAsignaturas(&centroEducativo);
    crearOcargarArchivoActividades(&centroEducativo);
    crearOcargarArchivoCalificaciones(&centroEducativo);
    crearOcargarArchivoInscripciones(&centroEducativo);

    do
    {
        printf("======== MENU PRINCIPAL ========\n");
        printf("1. Menu Estudiante\n");
        printf("2. Menu Asignatura\n");
        printf("3. Inscribir asignatura\n");
        printf("4. Salir\n");
        printf("=================================\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcionPrincipal);

        switch (opcionPrincipal)
        {
        case 1:
            //system("cls");       // Limpiar la pantalla
            do
            {
                FILE* archivoEstudiantes = fopen("estudiantes.dat", "rb");

                opcionEstudiante = mostrarMenuEstudiante();

                switch (opcionEstudiante)
                {
                case 1:
                    crearEstudiante(&centroEducativo);
                    printf("Presiona enter para continuar...\n");
                    getchar();                          // Leer un caracter adicional (salto de linea)
                    //getchar();                          // Esperar una tecla antes de limpiar la pantalla
                    //system("cls");                      // Limpiar la pantalla
                    break;
                case 2:
                    mostrarEstudiantes(&centroEducativo);
                    modificarEstudiante(&centroEducativo);
                    break;
                case 3:
                    inactivarEstudiante(&centroEducativo);
                    printf("Presiona enter para continuar...\n");
                    getchar();                          // Leer un caracter adicional (salto de linea)
                    getchar();                          // Esperar una tecla antes de limpiar la pantalla
                    //system("cls");                      // Limpiar la pantalla
                    break;
                case 4:
                    mostrarEstudiantes(&centroEducativo);
                    printf("Presiona enter para continuar...\n");
                    getchar();                          // Leer un caracter adicional (salto de linea)
                    getchar();                          // Esperar una tecla antes de limpiar la pantalla
                    //system("cls");                      // Limpiar la pantalla
                    break;
                case 5:
                    do
                    {
                        //system("cls");                  // Limpiar la pantalla
                        FILE* archivoCalificaciones = fopen("calificaciones.dat", "rb");

                        opcionCalificacion = mostrarMenuCalificacion();

                        switch (opcionCalificacion)
                        {
                        case 1:
                            crearCalificacion(&centroEducativo);
                            printf("Presiona enter para continuar...\n");
                            getchar();                          // Leer un caracter adicional (salto de linea)
                            getchar();                          // Esperar una tecla antes de limpiar la pantalla
                            //system("cls");                      // Limpiar la pantalla
                            break;
                        case 2:
                            mostrarCalificaciones(&centroEducativo);
                            modificarCalificacion(&centroEducativo);
                            break;
                        case 3:
                            inactivarCalificacion(&centroEducativo);
                            printf("Presiona enter para continuar...\n");
                            getchar();                          // Leer un caracter adicional (salto de linea)
                            getchar();                          // Esperar una tecla antes de limpiar la pantalla
                            //system("cls");                      // Limpiar la pantalla
                            break;
                        case 4:
                            mostrarCalificaciones(&centroEducativo);
                            printf("Presiona enter para continuar...\n");
                            getchar();                          // Leer un caracter adicional (salto de linea)
                            getchar();                          // Esperar una tecla antes de limpiar la pantalla
                            //system("cls");                      // Limpiar la pantalla
                            break;
                        case 5:
                            //system("cls");
                            break;
                        }
                    }
                    while (opcionCalificacion != 5);

                    //system("cls");                      // Limpiar la pantalla
                    break;
                case 6:
                    opcionEstudiante = 6;
                    //system("cls");
                    break;
                default:
                    printf("Opcion invalida. Intente nuevamente.\n");
                    break;
                }

            }
            while (opcionEstudiante != 6);

            //system("cls");
            break;
        case 2:

            //system("cls");                              // Limpiar la pantalla
            do
            {

                FILE* archivoAsignatura = fopen("asignaturas.dat", "rb");

                opcionAsignatura = mostrarMenuAsignatura();

                switch (opcionAsignatura)
                {
                case 1:
                    crearAsignatura(&centroEducativo);
                    printf("Presiona enter para continuar...\n");
                    getchar();                          // Leer un caracter adicional (salto de linea)
                    getchar();                          // Esperar una tecla antes de limpiar la pantalla
                    //system("cls");                      // Limpiar la pantalla
                    break;
                case 2:
                    mostrarAsignaturas(centroEducativo.listaAsignaturas);
                    modificarAsignatura(&centroEducativo);
                    break;
                case 3:
                    inactivarAsignatura(&centroEducativo);
                    printf("Presiona enter para continuar...\n");
                    getchar();                          // Leer un caracter adicional (salto de linea)
                    getchar();                          // Esperar una tecla antes de limpiar la pantalla
                    //system("cls");                      // Limpiar la pantalla
                    break;
                case 4:
                    mostrarAsignaturas(centroEducativo.listaAsignaturas);
                    printf("Presiona enter para continuar...\n");
                    getchar();                          // Leer un caracter adicional (salto de linea)
                    getchar();                          // Esperar una tecla antes de limpiar la pantalla
                    //system("cls");                      // Limpiar la pantalla
                    break;
                case 5:
                    //system("cls");                      // Limpiar la pantalla
                    do

                    {
                        //FILE* archivoActividades = fopen("actividades.dat", "rb");
                        //FILE* archivoAsignatura = fopen("asignaturas.dat", "rb");
                        int idAsignatura;
                        opcionActividad = mostrarMenuActividad();

                        switch (opcionActividad)
                        {
                        case 1:
                            mostrarAsignaturas(centroEducativo.listaAsignaturas);

                            crearActividad(&centroEducativo);
                            printf("Presiona enter para continuar...\n");
                            getchar();                          // Leer un caracter adicional (salto de linea)
                            getchar();                          // Esperar una tecla antes de limpiar la pantalla
                            //system("cls");                      // Limpiar la pantalla
                            break;
                        case 2:
                            mostrarAsignaturas(centroEducativo.listaAsignaturas);
                            printf("Ingrese el ID de la asignatura para mostrar sus actividades: ");
                            scanf("%d", &idAsignatura);
                            mostrarActividades(&centroEducativo, idAsignatura);
                            modificarActividad(&centroEducativo);
                            break;
                        case 3:
                            inactivarActividad(&centroEducativo);
                            printf("Presiona enter para continuar...\n");
                            getchar();                          // Leer un caracter adicional (salto de linea)
                            getchar();                          // Esperar una tecla antes de limpiar la pantalla
                            //system("cls");                      // Limpiar la pantalla
                            break;
                        case 4:
                            mostrarAsignaturas(centroEducativo.listaAsignaturas);
                            printf("Ingrese el ID de la asignatura para mostrar sus actividades: ");
                            scanf("%d", &idAsignatura);
                            mostrarActividades(&centroEducativo, idAsignatura);
                            printf("Presiona enter para continuar...\n");
                            getchar();                  // Leer un caracter adicional (salto de linea)
                            getchar();                  // Esperar una tecla antes de limpiar la pantalla
                            //system("cls");              // Limpiar la pantalla
                            break;
                        case 5:
                            //system("cls");
                            break;
                        default:
                            printf("Opcion invalida. Intente nuevamente.\n");
                            break;
                        }
                    }
                    while (opcionActividad != 5);
                    //system("cls");
                    break;
                case 6:
                    opcionAsignatura = 6;
                    //system("cls");
                    break;
                default:
                    printf("Opcion invalida. Intente nuevamente.\n");
                    break;
                }
            } while (opcionAsignatura != 6);
            break;
        case 3:
            //system("cls");                              // Limpiar la pantalla
            do
            {
                opcionEstudianteInscrito = mostrarMenuEstudiantesInscritos();

                switch (opcionEstudianteInscrito)
                {
                case 1:
                    mostrarEstudiantes(&centroEducativo);
                    mostrarAsignaturas(centroEducativo.listaAsignaturas);
                    inscribirEstudiantes(&centroEducativo);
                    printf("Presiona enter para continuar...\n");
                    getchar();            // Leer un caracter adicional (salto de linea)
                    getchar();            // Esperar una tecla antes de limpiar la pantalla
                    //system("cls");      // Limpiar la pantalla
                    break;
                case 2:
                    // mostrarInscripciones(centroEducativo.listaInscripciones);

                    // modificarInscripcion(&centroEducativo);
                    break;
                case 3:
                    // inactivarInscripcion(&centroEducativo);
                    // printf("Presiona enter para continuar...\n");
                    // getchar();             // Leer un caracter adicional (salto de linea)
                    // getchar();             // Esperar una tecla antes de limpiar la pantalla
                    // system("cls");       // Limpiar la pantalla
                    break;
                case 4:
                    // mostrarInscripciones(centroEducativo.listaInscripciones);
                    printf("Presiona enter para continuar...\n");
                    getchar();             // Leer un caracter adicional (salto de linea)
                    getchar();             // Esperar una tecla antes de limpiar la pantalla
                    //system("cls");       // Limpiar la pantalla
                    break;
                case 5:
                    //system("cls");
                    break;
                default:
                    printf("Opcion invalida. Intente nuevamente.\n");
                    break;
                }

            } while (opcionEstudianteInscrito != 5);

            break;
        case 4:
            printf("�Hasta luego!\n");
            break;
        default:
            printf("Opcion invalida. Intente nuevamente.\n");
            break;
        }

        // Guardar los cambios en archivos despues de cada opci�n principal
        guardarEstudiantesEnArchivo(&centroEducativo);
        guardarAsignaturasEnArchivo(&centroEducativo);
        guardarActividadesEnArchivo(&centroEducativo);
        guardarCalificacionesEnArchivo(&centroEducativo);
        // guardarInscripcionesEnArchivo(&centroEducativo);

    }
    while (opcionPrincipal != 4);

    return 0;
}


int mostrarMenuEstudiantesInscritos()
{
    int opcion;

    printf("======== MENU INSCRIBIR ESTUDIANTE ========\n");
    printf("1. Inscribir un estudiante.\n");
    printf("2. Modificar inscripcion.\n");
    printf("3. Inactivar una inscripcion.\n");
    printf("4. Mostrar inscripciones.\n");
    printf("5. Regresar al menu principal\n");
    printf("==========================================\n");
    printf("Ingrese una opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

void crearOcargarArchivoInscripciones(CentroEducativo* centroEducativo)
{
    FILE* archivo = fopen("inscripciones.dat", "rb");

    if (archivo == NULL)
    {
        printf("El archivo de inscripciones no existe. Se creara un archivo nuevo.\n\n");
        archivo = fopen("inscripciones.dat", "wb");
        if (archivo == NULL)
        {
            printf("ERROR: No se pudo crear el archivo de inscripciones.\n");
            return;
        }
        fclose(archivo);
        return;
    }

    EstudianteAsignatura inscripcion;
    while (fread(&inscripcion, sizeof(EstudianteAsignatura), 1, archivo) == 1)
    {
        EstudianteAsignatura* nuevoNodo = (EstudianteAsignatura*)malloc(sizeof(EstudianteAsignatura));
        if (nuevoNodo == NULL)
        {
            printf("ERROR: No se pudo asignar memoria para la nueva inscripcion.\n");
            fclose(archivo);
            break;
        }

        *nuevoNodo = inscripcion;

        nuevoNodo->siguiente = centroEducativo->listaInscripciones;
        centroEducativo->listaInscripciones = nuevoNodo;

        centroEducativo->numInscripciones++;

    }

    fclose(archivo);
}

void guardarInscripcionesEnArchivo(CentroEducativo* centroEducativo)
{
    FILE* archivo = fopen("inscripciones.dat", "wb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de calificaciones.\n");
        return;
    }

    // Escribir las inscripciones en el archivo
    EstudianteAsignatura* nodoActual = centroEducativo->listaInscripciones;
    while (nodoActual != NULL)
    {
        // Crear una estructura temporal para escribir en el archivo sin incluir el puntero 'siguiente'
        EstudianteAsignatura tempInscripcion;
        tempInscripcion.ID_Estudiante = nodoActual->ID_Estudiante;
        tempInscripcion.ID_Asignatura = nodoActual->ID_Asignatura;
        tempInscripcion.Inactivo = nodoActual->Inactivo;

        fwrite(&tempInscripcion, sizeof(EstudianteAsignatura), 1, archivo);
        nodoActual = nodoActual->siguiente;
    }

    fclose(archivo);
}


void mostrarInscripciones(EstudianteAsignatura* listaInscripciones)
{
    int contadorInscripcionesInactivos = 0;

    printf("\n=================\n");
    printf("  ID_EST   ID_ASIG  \n");
    printf("===================\n");


    EstudianteAsignatura* nodoActual = listaInscripciones;
    while (nodoActual != NULL)
    {
        if (nodoActual->Inactivo == 0)
            printf("[%-6d] [%-6d] \n", nodoActual->ID_Estudiante, nodoActual->ID_Asignatura);
        else
            contadorInscripcionesInactivos++;

        nodoActual = nodoActual->siguiente;
    }

    printf("\n=================\n");

    printf("INSCRIPCIONES INACTIVAS: [%d]\n", contadorInscripcionesInactivos);
}


void inscribirEstudiantes(CentroEducativo* centroEducativo)
{
    EstudianteAsignatura nuevaInscripcion;

    // Solicitar al usuario que ingrese el ID del estudiante y la asignatura
    int idEstudiante;
    int idAsignatura;

    printf("Ingrese el ID del estudiante (0 para salir): ");
    scanf("%d", &idEstudiante);

    if (idEstudiante != 0)
    {
        printf("Ingrese el ID de la asignatura: ");
        scanf("%d", &idAsignatura);

        // Verificar si el estudiante y la asignatura existen en el centro educativo
        int indiceEstudiante = -1;
        for (int i = 0; i < centroEducativo->numEstudiantes; i++)
        {
            if (centroEducativo->estudiantes[i].ID == idEstudiante)
            {
                indiceEstudiante = i;
                break;
            }
        }

        int indiceAsignatura = -1;
        for (int i = 0; i < centroEducativo->numAsignaturas; i++)
        {
            if (centroEducativo->asignaturas[i].ID == idAsignatura)
            {
                indiceAsignatura = i;
                break;
            }
        }

        if (indiceEstudiante != -1 && indiceAsignatura != -1)
        {
            // Asignar el ID del estudiante y la asignatura a la nueva inscripcion
            nuevaInscripcion.ID_Estudiante = idEstudiante;
            nuevaInscripcion.ID_Asignatura = idAsignatura;

            // Marcar la inscripcion como activa
            nuevaInscripcion.Inactivo = 0;

            // Crear nuevo nodo para la lista enlazada de inscripciones
            EstudianteAsignatura* nuevoNodo = (EstudianteAsignatura*)malloc(sizeof(EstudianteAsignatura));
            if (nuevoNodo == NULL)
            {
                printf("ERROR: No se pudo asignar memoria para la nueva inscripcion.\n");
                return;
            }

            *nuevoNodo = nuevaInscripcion;
            nuevoNodo->siguiente = centroEducativo->listaInscripciones;
            centroEducativo->listaInscripciones = nuevoNodo;

            // Incrementar el contador de inscripciones en el centro educativo
            centroEducativo->numInscripciones++;

            // Guardar los cambios en el archivo de inscripciones
            guardarInscripcionesEnArchivo(centroEducativo);

            printf("Inscripcion creada con exito.\n\n");
        }
        else
        {
            printf("ERROR: El ID del estudiante o la asignatura no es valido.\n");
        }
    }
}
