#include <stdio.h>
#include <stdlib.h>

/*

Escriba un programa para capturar el número de días que hay entre dos fechas; declarar
fecha como una estructura.

*/

typedef struct 
{
    int dia;
    int mes;
    int anyo;
}Fecha;

int Diferencia(Fecha, Fecha);

int main()
{

    Fecha fecha1, fecha2;

    printf("Especifique la primera fecha (dd/mm/yy)\n");
    printf("Escriba aquí: ");
    scanf("%d %d %d", &fecha1.dia, &fecha1.mes, &fecha1.anyo);

    printf("\nEspecifique la segunda fecha (dd/mm/yy)\n");
    printf("Escriba aquí: ");
    scanf("%d %d %d", &fecha2.dia, &fecha2.mes, &fecha2.anyo);

    int cantDias = Diferencia(fecha1, fecha2); // Cant de días será la diferencia entre ellos.

    printf("La diferencia de dias es de: %d", cantDias);

    return 0;
}

int Diferencia (Fecha fecha1, Fecha fecha2)
{
    int dif, diasFecha1, diasFecha2;

    // Fórmula para calcular los días de los meses //
    // Toma el mes y le resta 1 para sacar los meses anteriores al último mes ingresado. 
    
    diasFecha1 = (fecha1.mes - 1)*30 + fecha1.dia; 
    
    // Luego multiplica ese número de meses por 30 para transformarlo a días, y por último suma esos días con la cantidad de días restantes del último mes.

    diasFecha2 = (fecha2.mes - 1)*30 + fecha2.dia;

    // Fórmula para la diferencia //

    //Resta el último año con el primero y los transforma en días multiplicando por 365. 
    //Luego resta el primer tramo de los días de la fecha1 calculados, y suma el tramo de días de la fecha2.

    dif = (fecha2.anyo - fecha1.anyo)*365 -diasFecha1+diasFecha2;

    //Si bien, no es un método preciso, ya que no cuenta los años bisiestos ni alteraciones en los años. Pero es lo general. 

    return dif;
}