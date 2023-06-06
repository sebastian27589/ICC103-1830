#include <stdio.h>
#include <stdlib.h>

int cantfactabun (int);
int sumadivisores (int);

int main()
{
   int ranginf, rangsup, varaux, sumdiv, sumfactabun;
   float promedio = 0, sumaexitoso = 0, cantexitoso = 0;

   do{
      do{
         printf("Ingrese el l%cmite inferior:\n", 161);
         scanf("%d", &ranginf);

         if(ranginf <= 0)
            printf("El l%cmite debe ser mayor que 0.\n", 161);

      }while(ranginf <= 0);

      do{
         printf("Ingrese el l%cmite superior:\n", 161);
         scanf("%d", &rangsup);
if(rangsup <= 0)
            printf("El l%cmite debe ser mayor que 0.\n", 161);

      }while(rangsup <= 0);

      if(ranginf >= rangsup)
         printf("El rango es incoherente.\n");

   }while(ranginf >= rangsup);

   printf("\n");

   for(varaux = ranginf; varaux <= rangsup; varaux++)
   {
      sumdiv = sumadivisores(varaux);
      if(sumdiv > varaux)//si el número es abundante.
      {
         sumfactabun = cantfactabun (varaux);

         if(sumfactabun >= 3 || sumfactabun <= 8)//No estoy segura de si debo usar un and o un or.
         {
            printf("%d es un n%cmero exitoso.\n", varaux, 163);
            cantexitoso += 1;
            sumaexitoso += varaux;
         }
      }
   }
   printf("\n");

   promedio = sumaexitoso / cantexitoso;
   if (promedio > 0)
   {
      printf("El promedio de los n%cmeros exitosos dentro del rango [%d,%d] es: %.2f.\n", 163, ranginf, rangsup, promedio );
   }
   else
      printf("No hay n%cmeros exitosos dentro del rango [%d,%d]\n", 163, ranginf, rangsup);

return 0;
}

/*
   Función: sumadivisores
   Argumento: int num.
   Objetivo: Obtener la suma de los divisores de "num".
   Retorno: (int sumdiv) indica la suma de los divisores de "num".
/

int sumadivisores(int num)
{
   int div, sumdiv = 0;

   for ( div = 1; div <= num/2; div++ )
      if (num % div == 0)
         sumdiv += div;
   return sumdiv;
}

/
Función: cantfactabun.
Argumento: int num.
Objetivo: Obtener la cantidad de factores abundantes de un número.
Retorno: (int cantabun) indica la cantidad de factores abundantes.
*/

int cantfactabun (int num)
{
   int factor, div, cantabun = 0;

   for ( div = 1; div <= num/2; div++ )

      if (num % div == 0){

         factor = sumadivisores (div);
         if (factor > div){
            cantabun += 1;
         }
      }
   return cantabun;
}
