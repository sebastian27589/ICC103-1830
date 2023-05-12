#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 5, b = 10;

    //Apunta a la dirección de la variable a
    int *p_a = &a; 

    //Muestra el tamaño de p_a y de a
    printf("Bytes de p_a: %d\t  Bytes de a: %d\n", sizeof(p_a), sizeof(a));

    //Imprime el valor de p_a y abajo imprime su dirección de memoria
    printf("Valor de p_a: %x\n", p_a);
    printf("Valor de a: %d\n", *p_a);

    //Apunta a la variable B, solo se cambia la variable p_a
    p_a = &b; 

    //Imprime el nuevo valor de p_a y abajo imprime su dirección de memoria
    printf("Valor de p_a: %x\n", p_a);
    printf("Valor de b: %d\n", *p_a);


    char cadena[] = "Hola Mundo Cruel.";
    char *p_cadena = cadena; //Apunta a la dirección de la primera posición de CADENA   
    printf("\n%c\n", *cadena);
    printf("%x\n", cadena);
    printf("%x\n", cadena+1); //Aritmetica de punteros, le sumo N cantidad de bytes al puntero.
    printf("%c\n\n", *(cadena+1)); //Se imprime el carácter en la siguiente posición de la "H" (Desreferencia).
    

    char c;
    char *pc;
    pc = &c;
    for(c = 'A'; c <= 'Z'; c++)
        printf("%c\t\n", *pc); //Imprimo la desreferencia a la variable "c"
    

    int v[10];
    int *p;
    p = v;

    *p = 5;
    printf("%d\n", v[0]); //5

    *(p+4) = 50;
    printf("\n%d\n", v[4]); //50

    p += 6; // p = p + 6
    *p = 100;
    printf("%d\n", v[6]);

    return 0;
}