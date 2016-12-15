#include <stdio.h>					//ajout des librairies utiles
#include <stdlib.h>
#include <time.h>
#include <signal.h>
#include <string.h>//pour les fonctions des chaînes de caractères
#include <unistd.h>//pour le sleep
#include "affichageStatique.h" 				//ajout des fichier utilisable 
#include "statistiques.h"
#include "dynamique.h"




int main() 						//fonction principale
{
FILE* stats = NULL;					//décaration des fichiers 
FILE* historique = NULL;
FILE* staticus = NULL;
FILE* dyna = NULL;

int aleatoireSaverTerm = 0;				//déclaration de variables
int a = 0;
historique = fopen("historique.txt", "a+");
printf("Entrer 0 pour générer aléatoirement un mode de veille sinon entrer la valeur 1\n");
scanf ("%d",&a);


if (a == 0)						//fonction random de 3

    {
    srand(time(NULL));					
    aleatoireSaverTerm = rand()%3+1;
    }


if (a == 1)						//fonction pour forcer louverture du fichier désirer
{
    printf(" Tapper 1 pour avoir l'affichage statique\n Tapper 2 pour avoir l'affichage dynamique\n Tapper 3 pour avoir l'affichage interactif\n Tapper 4 pour ouvrir le fichier statistiques\n ");
    scanf("%d",&aleatoireSaverTerm);
}


if (aleatoireSaverTerm == 1 )
{
 printf("Statique\n");
 staticus = fopen("affichageStatique.c", "r");
 statique();
// fonction statique
}


if (aleatoireSaverTerm == 2 )
{
	 printf("Dynamique\n");
dyna = fopen("dynamique.c","r");
dynamique();
	 // fonction dynamique
}


if (aleatoireSaverTerm == 3 )
{
	 printf("Interactif\n");
	 
	time_t t = time(NULL);
	    struct tm tm = *localtime(&t);
	    fprintf(historique, "%d-%d-%d %d:%d:%d| Interactif |[3]\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec );
	    fclose(historique); 
	// fonction interactive
}


if (aleatoireSaverTerm == 4 )
{
 printf("Statistiques\n");
 stats = fopen("statistiques.c", "r");
 fonctionStats();
 // fonction historique
}




}

