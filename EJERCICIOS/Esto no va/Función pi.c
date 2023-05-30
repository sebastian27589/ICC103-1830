#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <stdlib.h>
#define CANTMINTERM  500
#define MAXLINEAIMP  20
#define ENTER        13
#define CONTINUAR    83
#define STOP         78

float pi(int);

int main()
{
   int liminf, limsup, nterm, cantcolimp,cantlineasimp, cantcol;
   char tecla;
   do{
      do{
         system("cls");
         printf("Evaluaci%cn serie PI.\n",162);
         printf("Ingrese rango de t%crminos a evaluar:\n",130);
         do{
            printf("Ingrese l%cmite inferior: ",161);
            scanf("%d",&liminf);

            if (liminf <= CANTMINTERM)
               printf("Cantidad de t%crminos debe ser mayor a %d\n",130,CANTMINTERM);

         }while ( liminf <= CANTMINTERM);

         do{
            printf("Ingrese l%cmite superior: ",161);
            scanf("%d",&limsup);

            if (limsup <= CANTMINTERM)
               printf("Cantidad de t%crminos debe ser mayor a %d\n",130,CANTMINTERM);

         }while (limsup <= CANTMINTERM);

         if ( liminf >= limsup )
         printf("Rango de t%crminos es incorrecto!\n",130);

      }while ( liminf >= limsup );

      do{
         system("cls");
         printf("Ingrese la cantidad de columnas deseada: ");
         scanf("%d", &cantcol);

         if(cantcol < 3 && cantcol > 5)
            printf("la cantidad de columas debe estar entre 3 y 5");

      }while(cantcol < 3 && cantcol > 5);
printf("Serie pi evaluada en: [%d,%d] t%crminos\n",liminf,limsup,130);

      for ( nterm = liminf,cantlineasimp = 0,cantcolimp = 0; nterm <= limsup; nterm++ )
      {
         printf("Pi(%d)= %.4f    ",nterm,pi(nterm));
         cantcolimp++;

      //Columnas settings
         if ( cantcolimp % cantcol == 0 )
         {
            printf("\n");
            cantlineasimp++;
         }

         if ( cantlineasimp == MAXLINEAIMP )
         {
            printf("Presione [Enter] para continuar...");
            do{
               tecla = getch();
            }while (tecla != ENTER );
            system("cls");
            printf("Serie pi evaluada en: [%d,%d] t%crminos\n",liminf,limsup,130);
            cantlineasimp = 0;
         }

      }

      printf("\n\n %cQuiere hacerlo nuevamente%c Presione S/N \n", 168, 63);

      do{
         tecla = getch();
         tecla = toupper(tecla);
         if (tecla == STOP)
            break;
      }while(tecla != CONTINUAR);

   }while(tecla == CONTINUAR);
return 0;
}

/* Función: pi
   Argumento: (int) nterm, cantidad de términos a evaluar de la serie
   Pi
   Objetivo: Evaluar "nterm" terminos de la serie pi.
   Retorno: (float) Resultado de la evaluación de la serie pi para "nterm".
*/
float pi( int nterm)
{
   float numterm, prod1, prod2, prod3;
   int cont, denominador, sumatoria = 0;

   prod1 = 2;
   for ( cont = 2, numterm = 1; numterm <= nterm; numterm++, cont++)
   {
      prod2 = ++prod1;
      prod3 = ++prod2;

      denominador = prod1 * prod2 * prod3;

      if (cont % 2 == 0)
         sumatoria += 4/denominador;
      else
         sumatoria -= 4/denominador;

      prod1 =  prod3;
   }

   return 3 + sumatoria;
}