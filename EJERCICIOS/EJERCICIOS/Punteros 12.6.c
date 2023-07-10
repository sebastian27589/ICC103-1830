#include <stdio.h>
#include <stdlib.h>

/*
Escribir una función con un argumento de tipo puntero a double y otro argumento de tipo int.
El primer argumento se debe de corresponder con un array y el segundo con el núm de elementos de un array.
La función ha de ser de tipo puntero a double para devolver la dirección del elemento menor. 

*/

double* ElementoMenor(double*, int);

int main()
{

    double array[] = {4.3, 4.5, 7.5, 8.4};              //Declaro mi arreglo tipo double
    int elementos = sizeof(array) / sizeof(array[0]);   //Saco el tamaño del arreglo

    /*Debe retornar una dirección de memoria así que como los elementos
    del array son tipo double, declaro un puntero del mismo tipo que reciba la dirección de memoria
    del menor valor*/
                                                                    
    double* direcciónMenor = ElementoMenor(array, elementos);       

    printf("\nElemento menor es: %p", direcciónMenor);                  //Imprimo la dirección del elemento menor
    printf("\nDirección del elemento menor: %.2f\n", *direcciónMenor);  //Desreferencio al elemento menor

    return 0;
}

double *ElementoMenor(double *array, int nElementos)
{
    double *menor = array; //Puntero que apunte al primer elemento (trabajamos con doubles, así que también debe ser double).

    for (int ind = 1; ind < nElementos; ind++)
    {
        if ( array[ind] < *menor);
        {
            menor = &array[ind];
        }
    }

    return menor;
}
