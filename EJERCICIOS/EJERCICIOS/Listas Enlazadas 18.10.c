#include <stdio.h>
#include <stdlib.h>

/*
    Se tiene una lista de simple enlace, el campo dato es una estructura con los campos de un alumno:

    - Nombre
    - Edad
    - Sexo

    Escribir una función para transformar la lista de tal forma que si el primer nodo es de un alumno
    de sexo masculino, el siguiente sea de sexo femenino.
*/

typedef struct sAlumno
{
    char nombre[30];
    int edad;
    char sexo;
    struct sAlumno *link;
}Alumno;

void TransformarLista(Alumno **ListaEnlazada);

int main()
{
    Alumno *ListaEnlazada = NULL;

    TransformarLista(&ListaEnlazada);

    return 0;
}

void TransformarLista(Alumno **ListaEnlazada)
{
    if (*ListaEnlazada == NULL)
        return ListaEnlazada;
    
    Alumno *Actual = *ListaEnlazada;
    Alumno *Sig = (*ListaEnlazada)->link;

    while (Actual != NULL && Sig != NULL)
    {
        // Si el primer enlace es Masculino -> Femenino, no hay cambios
        if (Actual->sexo == 'M' && Sig->sexo == 'F')
        {
            Actual = Sig->link;
            if (Actual == NULL)
            {
                Sig = Actual->link;
            }

        // Si es Femenino -> Masculino, se intercambian los nodos
        } else if (Actual->sexo == 'F' && Sig->sexo == "M") {

            Alumno *Temp = Actual->link;
            Actual->link = Sig->link;
            Sig->link = Actual;
            
            if(*ListaEnlazada == Actual)
            {
                *ListaEnlazada = Sig;
            }

            Actual = Temp;
            if (Actual != NULL)
            {
                Sig = Actual->link;
            }
        } else {

            // Si no se cumple el patrón esperado, se avanza al siguiente
            Actual = Sig;
            Sig = (Actual != NULL) ? Actual->link : NULL;

        }
    }
}