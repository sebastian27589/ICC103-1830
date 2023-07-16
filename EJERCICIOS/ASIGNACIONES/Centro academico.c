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
    int numEstudiantes;
    int indiceEstudiantes[50];                          // �ndice de estudiantes basado en ID

    Asignatura asignaturas[20];
    int numAsignaturas;
    int indiceAsignaturas[20];                          // �ndice de asignaturas basado en ID

    Actividad actividades[30];
    int numActividades;
    int indiceActividades[30];                          // �ndice de actividades basado en ID

    Calificacion calificaciones[30];
    int numCalificaciones;
    int indiceCalificaciones[30];                          // �ndice de actividades basado en ID


} CentroEducativo;

// Funciones del estudiante
void guardarEstudiantesEnArchivo(CentroEducativo* centroEducativo);
void ordenarEstudiantesPorID(Estudiante estudiantes[], int numEstudiantes); // Función para ordenar IDs
void mostrarEstudiantes(FILE* archivo);
void crearOcargarArchivoEstudiantes(CentroEducativo* centroEducativo);
int mostrarMenuEstudiante();
void crearEstudiante(CentroEducativo* centroEducativo);
void modificarEstudiante(CentroEducativo* centroEducativo);
void inactivarEstudiante(CentroEducativo* centroEducativo);
void mostrarEstudiantesConInactividad(FILE* archivo);

// Funcionas de la asignatura
void guardarAsignaturasEnArchivo(CentroEducativo* centroEducativo);
void ordenarAsignaturasPorID(Asignatura asignaturas[], int numAsignaturas);
void mostrarAsignaturas(FILE* archivo);
void crearOcargarArchivoAsignaturas(CentroEducativo* centroEducativo);
int mostrarMenuAsignatura();
void crearAsignatura(CentroEducativo* CentroEducativo);
void modificarAsignatura(CentroEducativo* centroEducativo);
void inactivarAsignatura(CentroEducativo* centroEducativo);
void mostrarAsignaturasConInactividad(FILE* archivo);

// Funciones de la actividad
void guardarActividadesEnArchivo(CentroEducativo* centroEducativo);
void ordenarActividadesPorID(Actividad Actividades[], int numActividades);
void mostrarActividades(FILE* archivo, int idAsignatura);
void crearOcargarArchivoActividades(CentroEducativo* centroEducativo);
int mostrarMenuActividad();
void crearActividad(CentroEducativo* centroEducativo);
void modificarActividad(CentroEducativo* centroEducativo);
void inactivarActividad(CentroEducativo* centroEducativo);
void mostrarActividadesConInactividad(FILE* archivo);

// Funciones de la calificación
void guardarCalificacionesEnArchivo(CentroEducativo* centroEducativo);
void ordenarCalificacionesPorID();
void mostrarCalificaiones(FILE* archivo);
void crearOcargarArchivoCalificaciones(CentroEducativo* centroEducativo);
int mostrarMenuCalificacion();
void crearCalificacion(CentroEducativo* centroEducativo);
void modificarCalificacion(CentroEducativo* centroEducativo);
void inactivarCalificacion(CentroEducativo* centroEducativo);
void mostrarCalificacionesConInactividad(FILE* archivo);

// Funciones crear estudiante con asignatura


void mostrarEstudiantes(FILE* archivo)
{
    Estudiante estudiante;
    int contadorEstudiantesInactivos = 0;               // Variable para contar estudiantes inactivos

                                                        // Encabezado de la tabla
    printf("\n");
    printf("ID   Matricula   Nombres             Apellidos          Carrera\n");
    printf("======================================================================\n");

                                                        // Leer y mostrar los registros del archivo
    while (fread(&estudiante, sizeof(Estudiante), 1, archivo) == 1)
    {
        if (estudiante.Inactivo == 0)
        {
            printf("%-4d %-11s %-19s %-19s %-9s\n", estudiante.ID, estudiante.Matricula,
                   estudiante.Nombres, estudiante.Apellidos, estudiante.Carrera);
        }
        else
        {
            contadorEstudiantesInactivos++;
        }
    }

    printf("\n======================================================================\n");

                                                        // Mostrar el contador de estudiantes inactivos
    printf("Estudiantes inactivos: %d\n", contadorEstudiantesInactivos);
}

void mostrarEstudiantesConInactividad(FILE* archivo)
{
    Estudiante estudiante;

                                                        // Encabezado de la tabla
    printf("\n");
    printf("ID   Matricula   Nombres             Apellidos          Carrera    inactividad\n");
    printf("==================================================================================\n");

                                                        // Leer y mostrar los registros del archivo
    while (fread(&estudiante, sizeof(Estudiante), 1, archivo) == 1)
    {
        printf("%-4d %-11s %-19s %-19s %-9s   %s\n", estudiante.ID, estudiante.Matricula,
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
            printf("Error al crear el archivo de estudiantes.\n");
            return;
        }
        fclose(archivo);
        return;
    }

                                                        // Leer los estudiantes desde el archivo
    int numEstudiantes = fread(centroEducativo->estudiantes, sizeof(Estudiante), 50, archivo);

                                                        // Actualizar el numero de estudiantes en el centro educativo
    centroEducativo->numEstudiantes = numEstudiantes;

    fclose(archivo);
}

void guardarEstudiantesEnArchivo(CentroEducativo* centroEducativo)
{

    ordenarEstudiantesPorID(centroEducativo->estudiantes, centroEducativo->numEstudiantes);
    FILE* archivo = fopen("estudiantes.dat", "wb");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo de estudiantes.\n");
        return;
    }

    fwrite(centroEducativo->estudiantes, sizeof(Estudiante), centroEducativo->numEstudiantes, archivo);

    fclose(archivo);
}

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

void crearEstudiante(CentroEducativo* centroEducativo)
{

    Estudiante nuevoEstudiante;

                                                        // Solicitar los datos del nuevo estudiante al usuario
    printf("Ingrese el ID del estudiante: ");
    scanf("%d", &nuevoEstudiante.ID);
    printf("Ingrese la matricula del estudiante: ");
    scanf("%s", nuevoEstudiante.Matricula);
    printf("Ingrese el nombre del estudiante: ");
    scanf("%s", nuevoEstudiante.Nombres);
    printf("Ingrese el apellidos del estudiante: ");
    scanf("%s", nuevoEstudiante.Apellidos);
    printf("Ingrese la carrera del estudiante: ");
    scanf("%s", nuevoEstudiante.Carrera);

                                                        // Marcar al estudiante como activo
    nuevoEstudiante.Inactivo = 0;

                                                        // Agregar el estudiante al arreglo de estudiantes en el centro educativo
    centroEducativo->estudiantes[centroEducativo->numEstudiantes] = nuevoEstudiante;

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
                                                        // Buscar el estudiante en el arreglo
        int indiceEstudiante = -1;
        for (int i = 0; i < centroEducativo->numEstudiantes; i++)
        {
            if (centroEducativo->estudiantes[i].ID == indiceSeleccionado)
            {
                indiceEstudiante = i;
                break;
            }
        }

                                                        // Verificar si se encontro el estudiante
        if (indiceEstudiante != -1)
        {
                                                        // Obtener el estudiante seleccionado
            Estudiante* estudiante = &centroEducativo->estudiantes[indiceEstudiante];

            printf("\nDatos actuales del estudiante:\n");
            printf("ID: %d\n", estudiante->ID);
            printf("Matricula: %s\n", estudiante->Matricula);
            printf("Nombres: %s\n", estudiante->Nombres);
            printf("Apellidos: %s\n", estudiante->Apellidos);
            printf("Carrera: %s\n", estudiante->Carrera);

            printf("\nIngrese los nuevos datos del estudiante:\n");
            printf("ID: ");
            scanf("%d", &estudiante->ID);
            printf("Matricula: ");
            scanf("%s", estudiante->Matricula);
            printf("Nombres: ");
            scanf("%s", estudiante->Nombres);
            printf("Apellidos: ");
            scanf("%s", estudiante->Apellidos);
            printf("Carrera: ");
            scanf("%s", estudiante->Carrera);

            guardarEstudiantesEnArchivo(centroEducativo);

            printf("\nEstudiante modificado con exito.\n");
        }
        else
        {
            printf("\nError: no se encontro un estudiante con el ID especificado.\n");
        }
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
        int indiceEstudiante = -1;
        for (int i = 0; i < centroEducativo->numEstudiantes; i++)
        {
            if (centroEducativo->estudiantes[i].ID == idEstudiante)
            {
                indiceEstudiante = i;
                break;
            }
        }

        if (indiceEstudiante != -1)
        {
            Estudiante* estudiante = &centroEducativo->estudiantes[indiceEstudiante];
            estudiante->Inactivo = 1 - estudiante->Inactivo;

                                                        // Guardar los cambios en el archivo
            guardarEstudiantesEnArchivo(centroEducativo);

            if (estudiante->Inactivo)
            {
                printf("Estudiante con ID %d inactivado exitosamente.\n", idEstudiante);
            }
            else
            {
                printf("Estudiante con ID %d activado exitosamente.\n", idEstudiante);
            }
        }
        else
        {
            printf("Error: no se encontro un estudiante con el ID especificado.\n");
        }
    }

    fclose(archivoEstudiantes);
}





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

void mostrarAsignaturas(FILE* archivo)
{
    Asignatura asignatura;
    int contadorAsignaturasInactivas = 0;               // Variable para contar las asignaturas inactivas

                                                        // Encabezado de la tabla
    printf("\nASIGNATURAS DISPONIBLES:\n");
    printf("\n");
    printf("ID   Codigo      Nombre             Creditos\n");
    printf("==================================================\n");

                                                        // Leer y mostrar los registros del archivo
    while (fread(&asignatura, sizeof(Asignatura), 1, archivo) == 1)
    {
        if (asignatura.Inactivo == 0)
        {
            printf("%-4d %-11s %-19s %-11d\n", asignatura.ID, asignatura.Codigo,
                   asignatura.Nombre, asignatura.Creditos);
        }
        else
        {
            contadorAsignaturasInactivas++;
        }
    }

    printf("\n==================================================\n");

                                                        // Mostrar el contador de asignaturas inactivas
    printf("Asignaturas inactivas: %d\n", contadorAsignaturasInactivas);
}

void crearAsignatura(CentroEducativo* centroEducativo)
{
    Asignatura nuevaAsignatura;

                                                        // Solicitar los datos de la nueva asignatura al usuario
    printf("Ingrese el ID de la asignatura: ");
    scanf("%d", &nuevaAsignatura.ID);
    printf("Ingrese el codigo de la asignatura: ");
    scanf("%s", nuevaAsignatura.Codigo);
    printf("Ingrese el nombre de la asignatura: ");
    scanf("%s", nuevaAsignatura.Nombre);
    printf("Ingrese la cantidad de creditos de la asignatura: ");
    scanf("%d", &nuevaAsignatura.Creditos);

                                                        // Marcar la asignatura como activa
    nuevaAsignatura.Inactivo = 0;

                                                        // Agregar la asignatura al arreglo de asignaturas en el centro educativo
                                                        // Aqui deberas ajustar el nombre del arreglo de asignaturas en el centro educativo
    centroEducativo->asignaturas[centroEducativo->numAsignaturas] = nuevaAsignatura;

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
                                                        // Buscar la asignatura en el arreglo
        int indiceAsignatura = -1;
        for (int i = 0; i < centroEducativo->numAsignaturas; i++)
        {
            if (centroEducativo->asignaturas[i].ID == idAsignatura)
            {
                indiceAsignatura = i;
                break;
            }
        }

                                                        // Verificar si se encontro la asignatura
        if (indiceAsignatura != -1)
        {
                                                        // Obtener la asignatura seleccionada
            Asignatura* asignatura = &centroEducativo->asignaturas[indiceAsignatura];

            printf("\nDatos actuales de la asignatura:\n");
            printf("ID: %d\n", asignatura->ID);
            printf("Codigo: %s\n", asignatura->Codigo);
            printf("Nombre: %s\n", asignatura->Nombre);
            printf("Creditos: %d\n", asignatura->Creditos);

            printf("\nIngrese los nuevos datos de la asignatura:\n");
            printf("ID: ");
            scanf("%d", &asignatura->ID);
            printf("Codigo: ");
            scanf("%s", asignatura->Codigo);
            printf("Nombre: ");
            scanf("%s", asignatura->Nombre);
            printf("Creditos: ");
            scanf("%d", &asignatura->Creditos);

            guardarAsignaturasEnArchivo(centroEducativo);

            printf("\nAsignatura modificada con exito.\n");
        }
        else
        {
            printf("\nError: no se encontro una asignatura con el ID especificado.\n");
        }
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
        int indiceAsignatura = -1;
        for (int i = 0; i < centroEducativo->numAsignaturas; i++)
        {
            if (centroEducativo->asignaturas[i].ID == idAsignatura)
            {
                indiceAsignatura = i;
                break;
            }
        }

        if (indiceAsignatura != -1)
        {
            Asignatura* asignatura = &centroEducativo->asignaturas[indiceAsignatura];
            asignatura->Inactivo = 1 - asignatura->Inactivo;

                                                        // Guardar los cambios en el archivo
            guardarAsignaturasEnArchivo(centroEducativo);

            if (asignatura->Inactivo)
            {
                printf("Asignatura con ID %d inactivada exitosamente.\n", idAsignatura);
            }
            else
            {
                printf("Asignatura con ID %d activada exitosamente.\n", idAsignatura);
            }
        }
        else
        {
            printf("Error: no se encontro una asignatura con el ID especificado.\n");
        }
    }

    fclose(archivoAsignaturas);
}

void mostrarAsignaturasConInactividad(FILE* archivo)
{
    Asignatura asignatura;

                                                        // Encabezado de la tabla
    printf("\n");
    printf("ID   Codigo      Nombre             Creditos    inactividad\n");
    printf("==============================================================\n");

                                                        // Leer y mostrar los registros del archivo
    while (fread(&asignatura, sizeof(Asignatura), 1, archivo) == 1)
    {
        printf("%-4d %-11s %-19s %-11d   %s\n", asignatura.ID, asignatura.Codigo,
               asignatura.Nombre, asignatura.Creditos,
               asignatura.Inactivo ? "Inactivo" : "Activo");
    }

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
            printf("Error al crear el archivo de asignaturas.\n");
            return;
        }
        fclose(archivo);
        return;
    }

                                                        // Leer las asignaturas desde el archivo
    int numAsignaturas = fread(centroEducativo->asignaturas, sizeof(Asignatura), 20, archivo);

                                                        // Actualizar el numero de asignaturas en el centro educativo
    centroEducativo->numAsignaturas = numAsignaturas;

    fclose(archivo);
}

void guardarAsignaturasEnArchivo(CentroEducativo* centroEducativo)
{
    ordenarAsignaturasPorID(centroEducativo->asignaturas, centroEducativo->numAsignaturas);
    FILE* archivo = fopen("asignaturas.dat", "wb");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo de asignaturas.\n");
        return;
    }

    fwrite(centroEducativo->asignaturas, sizeof(Asignatura), centroEducativo->numAsignaturas, archivo);

    fclose(archivo);
}



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

void guardarCalificacionesEnArchivo(CentroEducativo* centroEducativo) {


    FILE* archivo = fopen("calificaciones.dat", "wb");
    if (archivo == NULL) {
        printf("Error al abrir el archivo de calificaciones.\n");
        return;
    }

    // Escribir las calificaciones en el archivo
    fwrite(centroEducativo->calificaciones, sizeof(Calificacion), centroEducativo->numCalificaciones, archivo);

    fclose(archivo);
}


void mostrarCalificaciones(FILE* archivo) {
    int idAsignatura;
    int idActividad;
    int idEstudiante;
    FILE* archivoAsignaturas = fopen("asignaturas.dat", "rb");
    FILE* archivoEstudiantes = fopen("estudiantes.dat", "rb");
    FILE* archivoActividades = fopen("actividades.dat", "rb");

    mostrarAsignaturas(archivoAsignaturas);
    printf("Ingrese el ID de la asignatura para filtrar las calificaciones: ");
    scanf("%d", &idAsignatura);

    mostrarActividades(archivoActividades, idAsignatura);
    printf("Ingrese el ID de la actividad para filtrar las calificaciones: ");
    scanf("%d", &idActividad);

    mostrarEstudiantes(archivoEstudiantes);
    printf("Ingrese el ID del estudiante para filtrar las calificaciones: ");
    scanf("%d", &idEstudiante);

    printf("\n===========================================\n");
    printf("ID_Actividad   Calificacion\n");
    printf("===========================================\n");

    // Leer y mostrar los registros del archivo de calificaciones
    Calificacion calificacion;
    while (fread(&calificacion, sizeof(Calificacion), 1, archivo) == 1) {
        if (calificacion.ID_Actividad == idActividad && calificacion.Inactivo == 0) {
            // Filtrar por actividad y estado "activo"

            // Buscar la asignatura en el archivo de asignaturas
            Asignatura asignatura;
            while (fread(&asignatura, sizeof(Asignatura), 1, archivoAsignaturas) == 1) {
                if (asignatura.ID == idAsignatura) {
                    // Buscar el estudiante en el archivo de estudiantes
                    Estudiante estudiante;
                    while (fread(&estudiante, sizeof(Estudiante), 1, archivoEstudiantes) == 1) {
                        if (estudiante.ID == idEstudiante) {
                            // Mostrar la calificaci�n con los detalles de la actividad, asignatura y estudiante
                            printf("%-13d %-14.2f\n", calificacion.ID_Actividad, calificacion.Calificacion);
                            printf("Asignatura: %s\n", asignatura.Nombre);
                            printf("Estudiante: %s %s\n", estudiante.Nombres, estudiante.Apellidos);
                            printf("-------------------------------------------\n");
                            break;
                        }
                    }
                    break;
                }
            }
        }
    }

    printf("\n===========================================\n");

    fclose(archivoAsignaturas);
    fclose(archivoActividades);
    fclose(archivoEstudiantes);
    fclose(archivo);
}


void crearOcargarArchivoCalificaciones(CentroEducativo* centroEducativo) {
    FILE* archivo = fopen("calificaciones.dat", "rb");
    if (archivo == NULL) {
        printf("El archivo de calificaciones no existe. Se creara un archivo nuevo.\n\n");
        archivo = fopen("calificaciones.dat", "wb");
        if (archivo == NULL) {
            printf("Error al crear el archivo de calificaciones.\n");
            return;
        }
        fclose(archivo);
        return;
    }
    int numCalificaciones = fread(centroEducativo->calificaciones, sizeof(Calificacion), 50, archivo);
    centroEducativo->numCalificaciones = numCalificaciones;
    fclose(archivo);
}

void crearCalificacion(CentroEducativo* centroEducativo) {

    FILE* archivoActividades = fopen("actividades.dat", "rb");
    FILE* archivoAsignatura = fopen("asignaturas.dat", "rb");
    FILE* archivoEstudiantes = fopen("estudiantes.dat", "rb");

    Calificacion nuevaCalificacion;

    int idAsignatura;
    mostrarAsignaturas(archivoAsignatura);
    printf("Ingrese el ID de la asignatura para mostrar sus actividades: ");
    scanf("%d", &idAsignatura);
    mostrarActividades(archivoActividades, idAsignatura);

    printf("Ingrese el ID de la actividad: ");
    scanf("%d", &nuevaCalificacion.ID_Actividad);

    mostrarEstudiantes(archivoEstudiantes);
    // Solicitar al usuario que ingrese el ID del estudiante
    int idEstudiante;
    printf("Ingrese el ID del estudiante para la calificacion: ");
    scanf("%d", &idEstudiante);

    // Buscar el estudiante en el arreglo de estudiantes
    int indiceEstudiante = -1;
    for (int i = 0; i < centroEducativo->numEstudiantes; i++) {
        if (centroEducativo->estudiantes[i].ID == idEstudiante) {
            indiceEstudiante = i;
            break;
        }
    }

    if (indiceEstudiante != -1) {
        // Asignar el estudiante a la calificacion
        nuevaCalificacion.ID_Estudiante = idEstudiante;

        // Solicitar al usuario que ingrese la calificaci�n
        printf("Ingrese la calificacion: ");
        scanf("%f", &nuevaCalificacion.Calificacion);

        // Marcar la calificacion como activa
        nuevaCalificacion.Inactivo = 0;


        // Agregar la calificacion al arreglo de calificaciones en el centro educativo
        centroEducativo->calificaciones[centroEducativo->numCalificaciones] = nuevaCalificacion;
        centroEducativo->numCalificaciones++;


        // Guardar los cambios en el archivo de calificaciones
        guardarCalificacionesEnArchivo(centroEducativo);

        printf("Calificacion creada con exito.\n\n");
    } else {
        printf("Error: no se encontro un estudiante con el ID especificado.\n");
    }
    fclose(archivoActividades);
    fclose(archivoAsignatura);
    fclose(archivoEstudiantes);
}



void modificarCalificacion(CentroEducativo* centroEducativo) {
    int idCalificacion;
    printf("Ingrese el ID de la calificacion que desea modificar (0 para salir): ");
    scanf("%d", &idCalificacion);
    if (idCalificacion != 0) {
        int indiceCalificacion = -1;
        for (int i = 0; i < centroEducativo->numCalificaciones; i++) {
            if (centroEducativo->calificaciones[i].ID_Actividad == idCalificacion) {
                indiceCalificacion = i;
                break;
            }
        }
        if (indiceCalificacion != -1) {
            Calificacion* calificacion = &centroEducativo->calificaciones[indiceCalificacion];
            printf("\nDatos actuales de la calificacion:\n");
            printf("ID_Actividad: %d\n", calificacion->ID_Actividad);
            printf("Calificacion: %.2f\n", calificacion->Calificacion);
            printf("\nIngrese la nueva calificacion: ");
            scanf("%f", &calificacion->Calificacion);
            guardarCalificacionesEnArchivo(centroEducativo);
            printf("\nCalificacion modificada con exito.\n");
        } else {
            printf("\nError: no se encontro una calificacion con el ID especificado.\n");
        }
    }
}

void inactivarCalificacion(CentroEducativo* centroEducativo) {
    FILE* archivoCalificaciones = fopen("calificaciones.dat", "rb");
    printf("\nCALIFICACIONES ACTIVAS E INACTIVAS:\n");
    mostrarCalificacionesConInactividad(archivoCalificaciones);
    int idCalificacion;
    printf("Ingrese el ID de la calificacion que desea activar/desactivar (0 para salir): ");
    scanf("%d", &idCalificacion);
    if (idCalificacion != 0) {
        int indiceCalificacion = -1;
        for (int i = 0; i < centroEducativo->numCalificaciones; i++) {
            if (centroEducativo->calificaciones[i].ID_Actividad == idCalificacion) {
                indiceCalificacion = i;
                break;
            }
        }
        if (indiceCalificacion != -1) {
            Calificacion* calificacion = &centroEducativo->calificaciones[indiceCalificacion];
            calificacion->Inactivo = 1 - calificacion->Inactivo;
            guardarCalificacionesEnArchivo(centroEducativo);
            if (calificacion->Inactivo) {
                printf("Calificacion con ID %d inactivada exitosamente.\n", idCalificacion);
            } else {
                printf("Calificacion con ID %d activada exitosamente.\n", idCalificacion);
            }
        } else {
            printf("Error: no se encontro una calificacion con el ID especificado.\n");
        }
    }
    fclose(archivoCalificaciones);
}

void mostrarCalificacionesConInactividad(FILE* archivo) {
    Calificacion calificacion;
    printf("\n");
    printf("ID_Actividad   Calificacion   Inactividad\n");
    printf("=========================================\n");
    while (fread(&calificacion, sizeof(Calificacion), 1, archivo) == 1) {
        printf("%-13d %-14.2f %s\n", calificacion.ID_Actividad, calificacion.Calificacion,
            calificacion.Inactivo ? "Inactivo" : "Activo");
    }
    printf("=========================================\n");
}



void ordenarEstudiantesPorID(Estudiante estudiantes[], int numEstudiantes)
{
    int i, j;
    Estudiante temp;

    for (i = 0; i < numEstudiantes - 1; i++)
    {
        for (j = 0; j < numEstudiantes - i - 1; j++)
        {
            if (estudiantes[j].ID > estudiantes[j + 1].ID)
            {
                temp = estudiantes[j];
                estudiantes[j] = estudiantes[j + 1];
                estudiantes[j + 1] = temp;
            }
        }
    }
}

void ordenarAsignaturasPorID(Asignatura asignaturas[], int numAsignaturas)
{
    int i, j;
    Asignatura temp;

    for (i = 0; i < numAsignaturas - 1; i++)
    {
        for (j = 0; j < numAsignaturas - i - 1; j++)
        {
            if (asignaturas[j].ID > asignaturas[j + 1].ID)
            {
                                                        // Intercambiar asignaturas[j] con asignaturas[j + 1]
                temp = asignaturas[j];
                asignaturas[j] = asignaturas[j + 1];
                asignaturas[j + 1] = temp;
            }
        }
    }
}

void ordenarActividadesPorID(Actividad actividades[], int numActividades)
{
    int i, j;
    Actividad temp;

    for (i = 0; i < numActividades - 1; i++)
    {
        for (j = 0; j < numActividades - i - 1; j++)
        {
            if (actividades[j].ID > actividades[j + 1].ID)
            {
                                                        // Intercambiar actividades[j] con actividades[j + 1]
                temp = actividades[j];
                actividades[j] = actividades[j + 1];
                actividades[j + 1] = temp;
            }
        }
    }
}



void crearActividad(CentroEducativo* centroEducativo)
{
    Actividad nuevaActividad;

    // Solicitar al usuario que ingrese el ID de la asignatura
    int idAsignatura;
    printf("Ingrese el ID de la asignatura ");
    scanf("%d", &idAsignatura);
    printf("\n creando actividad... \n");
    printf("Ingrese el ID de la actividad a crear: ");
    scanf("%d", &nuevaActividad.ID);
    printf("Ingrese el nombre de la actividad a crear: ");
    scanf("%s", nuevaActividad.Nombre);


    // Buscar la asignatura en el arreglo de asignaturas
    int indiceAsignatura = -1;
    for (int i = 0; i < centroEducativo->numAsignaturas; i++)
    {
        if (centroEducativo->asignaturas[i].ID == idAsignatura)
        {
            indiceAsignatura = i;
            break;
        }
    }

    if (indiceAsignatura != -1)
    {
        // Asignar la asignatura a la actividad
        nuevaActividad.ID_Asignatura = idAsignatura;

        // Marcar la actividad como activa
        nuevaActividad.Inactivo = 0;

        // Agregar la actividad al arreglo de actividades en el centro educativo
        centroEducativo->actividades[centroEducativo->numActividades] = nuevaActividad;

        // Incrementar el contador de actividades en el centro educativo
        centroEducativo->numActividades++;

        // Guardar los cambios en el archivo de actividades
        guardarActividadesEnArchivo(centroEducativo);

        printf("Actividad creada con exito.\n\n");
    }
    else
    {
        printf("Error: el ID de la asignatura no es v�lido.\n");
    }
}

void modificarActividad(CentroEducativo* centroEducativo)
{
    int idActividad;

    printf("Ingrese el ID de la actividad que desea modificar (0 para salir): ");
    scanf("%d", &idActividad);

    if (idActividad != 0)
    {
                                                        // Buscar la actividad en el arreglo
        int indiceActividad = -1;
        for (int i = 0; i < centroEducativo->numActividades; i++)
        {
            if (centroEducativo->actividades[i].ID == idActividad)
            {
                indiceActividad = i;
                break;
            }
        }

                                                        // Verificar si se encontro la actividad
        if (indiceActividad != -1)
        {
                                                        // Obtener la actividad seleccionada
            Actividad* actividad = &centroEducativo->actividades[indiceActividad];

            printf("\nIngrese los nuevos datos de la actividad:\n");
            printf("ID: ");
            scanf("%d", &actividad->ID);

            printf("Nombre: ");
            scanf("%s", actividad->Nombre);

            guardarActividadesEnArchivo(centroEducativo);

            printf("\nActividad modificada con exito.\n");
        }
        else
        {
            printf("\nError: no se encontro una actividad con el ID especificado.\n");
        }
    }


}

void mostrarActividadesConInactividad(FILE* archivo)
{
    Actividad actividad;

                                                        // Encabezado de la tabla
    printf("\n");
    printf("ID   Nombre                  Inactividad\n");
    printf("========================================\n");

                                                        // Leer y mostrar los registros del archivo
    while (fread(&actividad, sizeof(Actividad), 1, archivo) == 1)
    {
        printf("%-4d %-22s %s\n", actividad.ID, actividad.Nombre,
               actividad.Inactivo ? "Inactivo" : "Activo");
    }

    printf("========================================\n");
}

void inactivarActividad(CentroEducativo* centroEducativo)
{
    FILE* archivoAsignaturas = fopen("asignaturas.dat", "rb");
    FILE* archivoActividades = fopen("actividades.dat", "rb");

    mostrarAsignaturas(archivoAsignaturas);

    int idAsignatura;

    printf("Ingrese el ID de la asignatura para mostrar sus actividades: ");
    scanf("%d", &idAsignatura);

    int indiceAsignatura = -1;
    for (int i = 0; i < centroEducativo->numAsignaturas; i++)
    {
        if (centroEducativo->asignaturas[i].ID == idAsignatura)
        {
            indiceAsignatura = i;
            break;
        }
    }

    if (indiceAsignatura != -1)
    {
        printf("\nActividades de la asignatura '%s':\n", centroEducativo->asignaturas[indiceAsignatura].Nombre);
        printf("=============================================\n");
        printf("ID   Nombre                  Inactividad\n");
        printf("=============================================\n");

        for (int i = 0; i < centroEducativo->numActividades; i++)
        {
            if (centroEducativo->actividades[i].ID_Asignatura == idAsignatura)
            {
                printf("%-4d %-22s %s\n", centroEducativo->actividades[i].ID, centroEducativo->actividades[i].Nombre,
                       centroEducativo->actividades[i].Inactivo ? "Inactivo" : "Activo");
            }
        }

        printf("==============================================\n");

        int idActividad;

        printf("Ingrese el ID de la actividad que desea inactivar/activar (0 para salir): ");
        scanf("%d", &idActividad);

        if (idActividad != 0)
        {
            int indiceActividad = -1;
            for (int i = 0; i < centroEducativo->numActividades; i++)
            {
                if (centroEducativo->actividades[i].ID == idActividad && centroEducativo->actividades[i].ID_Asignatura == idAsignatura)
                {
                    indiceActividad = i;
                    break;
                }
            }

            if (indiceActividad != -1)
            {
                centroEducativo->actividades[indiceActividad].Inactivo = 1 - centroEducativo->actividades[indiceActividad].Inactivo;

                // Guardar los cambios en el archivo
                guardarActividadesEnArchivo(centroEducativo);

                if (centroEducativo->actividades[indiceActividad].Inactivo)
                {
                    printf("Actividad con ID %d inactivada exitosamente.\n", idActividad);
                }
                else
                {
                    printf("Actividad con ID %d activada exitosamente.\n", idActividad);
                }
            }
            else
            {
                printf("Error: no se encontr� una actividad v�lida con el ID especificado.\n");
            }
        }
    }
    else
    {
        printf("Error: el ID de la asignatura no es v�lido.\n");
    }

    fclose(archivoAsignaturas);
    fclose(archivoActividades);
}

void guardarActividadesEnArchivo(CentroEducativo* centroEducativo)
{
    ordenarActividadesPorID(centroEducativo->actividades, centroEducativo->numActividades);
    FILE* archivo = fopen("actividades.dat", "wb");
    if (archivo == NULL)
    {
        printf("Error al abrir el archivo de actividades.\n");
        return;
    }

    fwrite(centroEducativo->actividades, sizeof(Actividad), centroEducativo->numActividades, archivo);

    fclose(archivo);
}

void mostrarActividades(FILE* archivo, int idAsignatura)
{

    printf("\n==================\n");
    printf("ID   Nombre\n");
    printf("==================\n");
    // Leer y mostrar los registros del archivo de actividades
    Actividad actividad;
    while (fread(&actividad, sizeof(Actividad), 1, archivo) == 1)
    {
        if (actividad.ID_Asignatura == idAsignatura && actividad.Inactivo == 0)
        {
            printf("%-4d %-19s\n", actividad.ID, actividad.Nombre);
        }
    }

    printf("\n==================\n");

    fclose(archivo);
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
            printf("Error al crear el archivo de actividades.\n");
            return;
        }
        fclose(archivo);
        return;
    }

                                                        // Leer las actividades desde el archivo
    int numActividades = fread(centroEducativo->actividades, sizeof(Actividad), 30, archivo);

                                                        // Actualizar el numero de actividades en el centro educativo
    centroEducativo->numActividades = numActividades;

    fclose(archivo);
}



int main()
{
    CentroEducativo centroEducativo;
    Estudiante *listaEstudiantes = NULL;
    Asignatura *listaAsignatura  = NULL;
    Actividad *listaActividad = NULL;
    EstudianteAsignatura *listaEstudianteAsignatura = NULL;
    int opcionPrincipal;
    int opcionEstudiante;
    int opcionAsignatura;
    int opcionCalificacion;
    int opcionActividad;
    int opcionInscribirAsignatura;


                                                        // Carga los datos desde los archivos de datos binarios
    crearOcargarArchivoEstudiantes(&centroEducativo);
    crearOcargarArchivoAsignaturas(&centroEducativo);
    crearOcargarArchivoActividades(&centroEducativo);
    crearOcargarArchivoCalificaciones(&centroEducativo);

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
            system("cls");                              // Limpiar la pantalla
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
                    getchar();                          // Esperar una tecla antes de limpiar la pantalla
                    system("cls");                      // Limpiar la pantalla
                    break;
                case 2:
                    mostrarEstudiantes(archivoEstudiantes);
                    modificarEstudiante(&centroEducativo);
                    break;
                case 3:
                    inactivarEstudiante(&centroEducativo);
                    printf("Presiona enter para continuar...\n");
                    getchar();                          // Leer un caracter adicional (salto de linea)
                    getchar();                          // Esperar una tecla antes de limpiar la pantalla
                    system("cls");                      // Limpiar la pantalla
                    break;
                case 4:
                    mostrarEstudiantes(archivoEstudiantes);
                    printf("Presiona enter para continuar...\n");
                    getchar();                          // Leer un caracter adicional (salto de linea)
                    getchar();                          // Esperar una tecla antes de limpiar la pantalla
                    system("cls");                      // Limpiar la pantalla
                    break;
                case 5:
                    do
                    {
                        system("cls");                  // Limpiar la pantalla
                        FILE* archivoCalificaciones = fopen("calificaciones.dat", "rb");

                        opcionCalificacion = mostrarMenuCalificacion();

                        switch (opcionCalificacion)
                        {
                        case 1:
                            crearCalificacion(&centroEducativo);
                            printf("Presiona enter para continuar...\n");
                            getchar();                          // Leer un caracter adicional (salto de linea)
                            getchar();                          // Esperar una tecla antes de limpiar la pantalla
                            system("cls");                      // Limpiar la pantalla
                            break;
                        case 2:
                            mostrarCalificaciones(archivoCalificaciones);
                            modificarCalificacion(&centroEducativo);
                            break;
                        case 3:
                            inactivarCalificacion(&centroEducativo);
                            printf("Presiona enter para continuar...\n");
                            getchar();                          // Leer un caracter adicional (salto de linea)
                            getchar();                          // Esperar una tecla antes de limpiar la pantalla
                            system("cls");                      // Limpiar la pantalla
                            break;
                        case 4:
                            mostrarCalificaciones(archivoCalificaciones);
                            printf("Presiona enter para continuar...\n");
                            getchar();                          // Leer un caracter adicional (salto de linea)
                            getchar();                          // Esperar una tecla antes de limpiar la pantalla
                            system("cls");                      // Limpiar la pantalla
                            break;
                        case 5:
                            system("cls");
                            break;
                        }
                    }
                    while (opcionCalificacion != 5);

                    system("cls");                      // Limpiar la pantalla
                    break;
                case 6:
                    opcionEstudiante = 6;
                    system("cls");
                    break;
                default:
                    printf("Opcion invalida. Intente nuevamente.\n");
                    break;
                }

            }
            while (opcionEstudiante != 6);

            system("cls");
            break;
        case 2:

            system("cls");                              // Limpiar la pantalla
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
                    system("cls");                      // Limpiar la pantalla
                    break;
                case 2:
                    mostrarAsignaturas(archivoAsignatura);
                    modificarAsignatura(&centroEducativo);
                    break;
                case 3:
                    inactivarAsignatura(&centroEducativo);
                    printf("Presiona enter para continuar...\n");
                    getchar();                          // Leer un caracter adicional (salto de linea)
                    getchar();                          // Esperar una tecla antes de limpiar la pantalla
                    system("cls");                      // Limpiar la pantalla
                    break;
                case 4:
                    mostrarAsignaturas(archivoAsignatura);
                    printf("Presiona enter para continuar...\n");
                    getchar();                          // Leer un caracter adicional (salto de linea)
                    getchar();                          // Esperar una tecla antes de limpiar la pantalla
                    system("cls");                      // Limpiar la pantalla
                    break;
                case 5:
                    system("cls");                      // Limpiar la pantalla
                    do

                    {
                        FILE* archivoActividades = fopen("actividades.dat", "rb");
                        FILE* archivoAsignatura = fopen("asignaturas.dat", "rb");
                        int idAsignatura;


                        opcionActividad = mostrarMenuActividad();

                        switch (opcionActividad)
                        {
                        case 1:
                            mostrarAsignaturas(archivoAsignatura);

                            crearActividad(&centroEducativo);
                            printf("Presiona enter para continuar...\n");
                            getchar();                          // Leer un caracter adicional (salto de linea)
                            getchar();                          // Esperar una tecla antes de limpiar la pantalla
                            system("cls");                      // Limpiar la pantalla
                            break;
                        case 2:
                            mostrarAsignaturas(archivoAsignatura);
                            printf("Ingrese el ID de la asignatura para mostrar sus actividades: ");
                            scanf("%d", &idAsignatura);
                            mostrarActividades(archivoActividades, idAsignatura);
                            modificarActividad(&centroEducativo);
                            break;
                        case 3:
                            inactivarActividad(&centroEducativo);
                            printf("Presiona enter para continuar...\n");
                            getchar();                          // Leer un caracter adicional (salto de linea)
                            getchar();                          // Esperar una tecla antes de limpiar la pantalla
                            system("cls");                      // Limpiar la pantalla
                            break;
                        case 4:
                            mostrarAsignaturas(archivoAsignatura);
                            printf("Ingrese el ID de la asignatura para mostrar sus actividades: ");
                            scanf("%d", &idAsignatura);
                            mostrarActividades(archivoActividades, idAsignatura);
                            printf("Presiona enter para continuar...\n");
                            getchar();                  // Leer un caracter adicional (salto de linea)
                            getchar();                  // Esperar una tecla antes de limpiar la pantalla
                            system("cls");              // Limpiar la pantalla
                            break;
                        case 5:
                            system("cls");
                            break;
                        default:
                            printf("Opcion invalida. Intente nuevamente.\n");
                            break;
                        }
                    }
                    while (opcionActividad != 5);
                    system("cls");
                    break;
                case 6:
                    opcionAsignatura = 6;
                    system("cls");
                    break;
                default:
                    printf("Opcion invalida. Intente nuevamente.\n");
                    break;
                }
            }
            while (opcionAsignatura != 6);
            break;
        case 3:
            system("cls");                              // Limpiar la pantalla

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


    }
    while (opcionPrincipal != 4);

    return 0;
}
