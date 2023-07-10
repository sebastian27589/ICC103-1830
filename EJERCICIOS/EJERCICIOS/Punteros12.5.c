#include <stdio.h>
#include <stdlib.h>

/*
12.5: En el siguiente código se accede a los elementos de una matriz. Acceder a los mismos elementos con aritmética
de punteros.

#define N 4
#define M 5
int f, c;
double mt[N][M];
. . .
for (f = 0; f<N; f++)
{
    for (c = 0; c<M; c++)
        printf("%lf  ", mt[f][c]);
    printf("\n")

}

*/

int main()
{
    const int N = 4, M = 5;
    int f, c;

    double mt[N][M];    //Establezco los mismos tipos de datos.
    double *p;          //Declaro un puntero.

    p = &mt[0][0];      //Hago que ese puntero apunte al primer elemento de ese array bidimensional.
 
    for (f = 0; f < N; f++)
    {
        for (c = 0; c < M; c++)
        {
            printf("%lf", *p);    /*Desreferencio para que me de el valor en esa posición,
                o *(p + f*M + c), lo cual es otra forma de sacar el valor.
            */
            p + 1;      //Le sumo 1 para que se mueva una dirección y apunte al sig. valor.
        }
    }
    return 0;
}