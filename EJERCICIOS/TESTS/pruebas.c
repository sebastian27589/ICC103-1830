#include <stdio.h>

struct fecha {
    int dia;
    int mes;
    int anio;
};

int esBisiesto(int anio) {
    if ((anio % 4 == 0 && anio % 100 != 0) || anio % 400 == 0) {
        return 1; // Es bisiesto
    } else {
        return 0; // No es bisiesto
    }
}

int obtenerDiasDelMes(int mes, int anio) {
    int diasDelMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (mes == 2 && esBisiesto(anio)) {
        return 29; // Febrero en año bisiesto
    } else {
        return diasDelMes[mes - 1];
    }
}

int calcularDiferencia(struct fecha fecha1, struct fecha fecha2) {
    int dias = 0;

    // Calcula los días completos de los años completos entre las fechas
    for (int i = fecha1.anio; i < fecha2.anio; i++) {
        if (esBisiesto(i)) {
            dias += 366;
        } else {
            dias += 365;
        }
    }

    // Calcula los días de los meses completos en el año de la fecha1
    for (int i = fecha1.mes; i <= 12; i++) {
        dias += obtenerDiasDelMes(i, fecha1.anio);
    }

    // Calcula los días de los meses completos en el año de la fecha2
    for (int i = 1; i < fecha2.mes; i++) {
        dias += obtenerDiasDelMes(i, fecha2.anio);
    }

    // Resta los días de la fecha1 y fecha2
    dias += fecha2.dia - fecha1.dia;

    return dias;
}

int main() {
    struct fecha fecha1, fecha2;
    
    printf("Ingrese la primera fecha (dd mm aaaa): ");
    scanf("%d %d %d", &fecha1.dia, &fecha1.mes, &fecha1.anio);
    
    printf("Ingrese la segunda fecha (dd mm aaaa): ");
    scanf("%d %d %d", &fecha2.dia, &fecha2.mes, &fecha2.anio);
    
    int diferencia = calcularDiferencia(fecha1, fecha2);
    
    printf("La diferencia en días entre las fechas es: %d\n", diferencia);
    
    return 0;
}
