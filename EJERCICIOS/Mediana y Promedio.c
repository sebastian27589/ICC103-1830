#include<stdio.h>

int calcularMediana(int cont, int valores[]);

int main()
{
    const int MAX = 90000, PARADA = 99999;
    int valores[MAX];
    int valorActual, valorAnterior = 0;
    long sumatoria = 0;
    short cant = 0, flag = 0;

    //printf("%ld\n", sizeof(sumatoria));

    do
    {
        do
        {
            flag = 0;
            printf("\n D%cgame los n%cmeros: ", 161, 163);
            scanf("%d", &valorActual);

            if ( valorActual < 0 )
                        flag = 1;
            else if ( valorActual < valorAnterior )
                        flag = 1;
            if (flag == 1)
                        printf("ERROR: No puede escribir n%cmeros negativos o menores al n%cmero anterior.", 163, 163);

        } while (flag == 1);
            
        if (valorActual == PARADA)
            break;

        valores[cant] = valorActual;
        valorAnterior = valorActual;

        sumatoria += valorActual;
        cant++;
        
    } while (valorActual != PARADA);

    
    printf("\n El promedio de los n%cmeros es: %.2f", 163, (float)(sumatoria)/cant);
    printf("\n La mediana es: %d \n", calcularMediana(cant, valores));

    return 0;
}

int calcularMediana(int cant, int valores[])
{
    if (cant % 2 == 0)
        return (valores[cant/2-1] + valores[cant/2]) / 2;
    else
        return valores[cant/2];

}