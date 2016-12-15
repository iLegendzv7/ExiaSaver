#include <stdio.h>
#include <stdlib.h> 
#include <time.h>


void fonctionStats()
{

system("clear");

int r=0;
int s=0;
int memoire=0;
int tableau[3]={0,0,0};
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

    nombreTotal = nombreStatique + nombreDynamique + nombreInteractif ;
    statStatique = ( 100 * nombreStatique / nombreTotal );
    statDynamique = ( 100 * nombreDynamique / nombreTotal );
    statInteractif = ( 100 * nombreInteractif / nombreTotal );

    tableau[0]= nombreStatique;
    tableau[1]= nombreDynamique;
    tableau[2]= nombreInteractif;
    
for (r = 0 ; r > 3; r++){
                            for ( s = 0 ; s > 3; s++){
                                 if (tableau[s]<=tableau[s+1]){
                                    memoire=tableau[s];
                                    tableau[s]=tableau[s+1];
                                    tableau[s+1]=memoire;
                                 }
                            }
    }
printf("----------------------------------------------------------------------\n");
   if (tableau[0]==nombreStatique){
	printf ("La plus grande valeur est pour le statique qui est sortie %d fois\n",nombreStatique);
	}
   if (tableau[0]==nombreDynamique){
	printf ("La plus grande valeur est pour le dynamique qui est sortie %d fois\n",nombreDynamique);
	}
   if (tableau[0]==nombreInteractif){
	printf ("La plus grande valeur est pour l'interactif qui est sortie %d fois\n",nombreInteractif);
	}

printf("----------------------------------------------------------------------\n");
   if (tableau[1]==nombreStatique){
	printf ("La valeur moyenne est pour le statique qui est sortie %d fois\n",nombreStatique);
	}
   if (tableau[1]==nombreDynamique){
	printf ("La valeur moyenne est pour le dynamique qui est sortie %d fois\n",nombreDynamique);
	}
   if (tableau[1]==nombreInteractif){
	printf ("La valeur moyenne est pour l'interactif qui est sortie %d fois\n",nombreInteractif);
	}

printf("----------------------------------------------------------------------\n");
   if (tableau[2]==nombreStatique){
	printf ("La plus petite valeur est pour le statique qui est sortie %d fois\n",nombreStatique);
	}
   if (tableau[2]==nombreDynamique){
	printf ("La plus petite valeur est pour le dynamique qui est sortie %d fois\n",nombreDynamique);
	}
   if (tableau[2]==nombreInteractif){
	printf ("La plus petite valeur est pour l'interactif qui est sortie %d fois\n",nombreInteractif);
	}
printf("----------------------------------------------------------------------\n");

    printf(" Tapper 1 pour afficher la statistique du Statique\n Tapper 2 pour afficher la statistique du Dynamique\n Tapper 3 pour afficher la statistique d'Interactif \n ");
    scanf("%d",&choix);
    printf("----------------------------------------------------------------------\n");

    switch (choix)
    {
        case 1:
        printf ("Statistique du statique = %d%c\n",statStatique,37);
        break;

        case 2:
        printf ("Statistique du Dynamique = %d%c\n",statDynamique,37);
        break;

        case 3:
        printf ("Statistique du Interactif = %d%c\n",statInteractif,37);
        break;

        default:
        printf ("Mauvaise valeur  \n");
        break;
    }

    printf("----------------------------------------------------------------------\n");

  


}
