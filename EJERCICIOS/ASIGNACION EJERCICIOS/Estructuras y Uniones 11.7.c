#include <stdio.h>
#include <stdlib.h>

/*

Declare un tipo de dato estructura para representar a un alumno; los campos que debe 
tener son los siguientes:

- Nombre
- Curso
- Edad
- Dirección
- Notas de las 10 asignaturas.

Declare otro tipo estructura para representar a un profesor; los campos que debe
tener son:

- Nombre
- Asignaturas que imparte
- Dirección

Por último, declare una estructura que pueda representar a un profesor o un alumno

*/


typedef struct 
{
    char nombre[30];
    int curso;
    int edad;
    char direccion[20];
    char notas[10];
}Alumno;

typedef struct 
{
    char nombre[30];
    int asignaturas;
    char direccion[20];
}Profesor;

typedef struct 
{
    Alumno alumno;
    Profesor profesor;
}Persona;


int main()
{
    return 0;
}