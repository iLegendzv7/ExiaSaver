#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void fonctionStats()
{


int choix = 0 ;
int nombreTotal = 0 ;
int nombreStatique = 0;
int statStatique = 0;
int nombreDynamique = 0;
int statDynamique = 0 ;
int nombreInteractif = 0;
int statInteractif = 0 ;
int c = 0;
FILE* historique = NULL;
historique = fopen("historique.txt","r");




   do {
              c = fgetc (historique);
                if (c == '[')
                {
                 c = fgetc (historique);
                    if (c == '1')
                    {
                        nombreStatique++;
                    }
                    else if (c == '2')
                    {
                        nombreDynamique++; //
                    }
                    if (c == '3')
                    {
                        nombreInteractif++;
                    }

                }
            } while (c != EOF);

    nombreTotal = nombreStatique + nombreInteractif + nombreDynamique;
    printf(" Tapper 1 pour afficher la statistique du Statique\n Tapper 2 pour afficher la statistique du Dynamique\n Tapper 3 pour afficher la statistique d'Interactif \n ");
    scanf("%d",&choix);
    printf("----------------------------------------------------------------------\n");

    switch (choix)
    {
        case 1:
        statStatique = ( 100 * nombreStatique / nombreTotal );
        printf ("Statistique du statique = %d%c\n",statStatique,37);
        break;

        case 2:
        statDynamique = ( 100 * nombreDynamique / nombreTotal );
        printf ("Statistique du Dynamique = %d%c\n",statDynamique,37);
        break;

        case 3:
        statInteractif = ( 100 * nombreInteractif / nombreTotal );
        printf ("Statistique du Interactif = %d%c\n",statInteractif,37);
        break;

        default:
        printf ("Mauvaise valeur  ");
        break;
    }

    printf("----------------------------------------------------------------------\n");



}
