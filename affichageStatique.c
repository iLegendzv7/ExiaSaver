#include <stdio.h> 		//Ajout des deux bibliothèques
#include <stdlib.h>		//de base
#include <signal.h>		//Permet de recuperer un signal de l'utilisateur par exemple
#include <time.h>		//Permet de convertir différent format d'heure



#define LARGEUR_CONSOLE 80




void statique()			//Fonction principale
{
    int pid = 0;		//Déclaration d'entier qui serviront dans le programme
    int touche = 0;		
    int imput = 0;
    int etat =0;
    char caractereActuel = 0;
    FILE* fichier = NULL;	//Initialise le fichier "fichier"
    FILE* historique = NULL;
    historique = fopen("historique.txt", "a+");		//Ouvre le fichier historique et on peur lire et ecrire dedans

    srand(time(NULL));			//Fonction ramdom
    int random=rand()%5+1;		//qui va de 5 à 1




    time_t t = time(NULL);		//set up du pointeur time
    struct tm tm = *localtime(&t);		//definition de la structure
    fprintf(historique, "%d-%d-%d %d:%d:%d| Statique | image numero %d|[1]\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec ,random);	    //ecriture dans historique
    fclose(historique);



    if (random == 1)
    {
        fichier = fopen("exiapau.pbm", "r");
    }
    if (random == 2)
    {
        fichier = fopen("Sapin.pbm", "r");
    }
    if (random == 3)
    {
        fichier = fopen("quadrillage.pbm", "r");
    }
    if (random == 4)
    {
        fichier = fopen("lignes.pbm", "r");
    }
    if (random == 5)
    {
        fichier = fopen("oeil.pbm", "r");
    }

		//Plusieurs boucle if qui sont selectionné aléatoirement en fonction du résultat du random, ce qui permet d'ouvrir les différent .pbm


    if (fichier != NULL)		//On vérifie que la selection du fichier a bien était faite
    {

    do
    {
           caractereActuel = fgetc(fichier); // On lit le caractère dans le fichier


            if (etat < 30)

            {

                if (caractereActuel == 48)		// 48 correspond a 0 en ASCII
                    {
                        printf(" ");
                    }


                else if (caractereActuel == 49)		// 49 correspond a 1 en ASCII
                    {
                        printf("\u2587");		//Correspond au symbole carré blanc dans la console
                    }


                else if (caractereActuel == 10)		// 10 correspond a un retour a la ligne, \n
                    {
                        printf("\n");
                    }
            }

            if(caractereActuel == 10)			//Permet de compter le nombre de ligne grace au \n, pour pouvoir éviter de les lire

            {
                etat++;
            }

    } while (caractereActuel != EOF);			// La boucle s'éxecute tant que le fichier texte n'a pas finit d'être lu, sinon on obtient EOF (End Of File)





        }

imput = scanf("%d", &touche);				// Permet de quitter le programme avec n'importe quelle touche
if (touche != 68)					// Si la touche est différent de null on execute la suite
{
    system("clear");					// Efface la console
    kill(pid, SIGKILL);					// Kill le programme

}


        fclose(fichier);
}
