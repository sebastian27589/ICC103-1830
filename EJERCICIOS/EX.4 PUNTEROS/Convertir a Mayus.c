#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXCHAR 30

void convertirCapitales(char *p_Frase);

int main()
{
    //char *arreglo; 
    char arreglo[MAXCHAR];

    printf("Digite su frase: ");
    gets(arreglo);

    convertirCapitales(arreglo);
    puts(arreglo);
    return 0;
}

void convertirCapitales(char *p_Frase)
{
    int ind;

    for (ind = 0; *(p_Frase+ind); ind++)
    {
        if ( *(p_Frase+ind) >= 'a' && *(p_Frase+ind) <= 'z')
        {
            *(p_Frase+ind) -= 32;
        }
            
        else if ( *(p_Frase+ind) >= 'A' && *(p_Frase+ind) <= 'Z' )
        {
            *(p_Frase+ind) += 32;
        }
    }
}