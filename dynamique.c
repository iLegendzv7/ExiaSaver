#include <stdio.h>
#include <stdlib.h>
#include <time.h>//pour les fonction temps
#include <string.h>//pour les fonctions des cha�nes de caract�res
#include <unistd.h>//pour le sleep
void Temps ();//prototype de la fonction Temps
void refresh(int a);//prototype de la fonciton de rafraichissement

void dynamique()//boucle principale
{
    system("clear");
    
    FILE* historique = NULL;

    time_t t = time(NULL);		//set up du pointeur time

    struct tm tm = *localtime(&t);		//definition de la structure

    historique = fopen("historique.txt", "a+");		//Ouvre le fichier historique et on peur lire et ecrire dedans

    fprintf(historique, "%d-%d-%d %d:%d:%d| Dynamique |[2]\n", tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday, tm.tm_hour, tm.tm_min, tm.tm_sec );        //ecriture dans historique

    fclose(historique);  

    int a = 10;//d�claration de la variable a(globale)

    //printf("Entrez une valeur\n");//int�raction avec l'utilisateur

    //scanf("%d", &a);//demande d'entr�e de l'utilsateur

    label0://d�claration de l'�tiquette 0 utilis�e plus tard

    system("clear");

    Temps();//utilisation de la fonciton Temps

    //printf("ce texte se rafraichira dans %d", a);//int�raction utilisateur pour la dur�e de rafraichissement

    refresh(a);//utilisation de la variable de l'utilisateur pour d�terminer la variable de rafraichissement

    system("clear");

    goto label0;//retour � l'�tiquette du dessus

}
void Temps ()//fonction Temps
{
    char aff_Time [9];//d�finition d'une cha�ne de caract�res

    time_t t = time(NULL);//setup du pointeur temps sur NULL

    struct tm tm = *localtime(&t);//d�finition de la structure tm tm �gale � t; t �gal � local time

    sprintf(aff_Time, "Il est: %d:%d:%d\n",tm.tm_hour, tm.tm_min, tm.tm_sec);//assignation t dans la cha�ne de caract�res

    printf("%s", aff_Time);//afichage de la cha�ne de caract�re
}
void refresh(int a)//fonction rafraichissement avec pour param�tre a (d�finie par l'utilisateur)
{
    int i = 0;//d�claration et initialisation de i

    for (i = 0; i < a; i++)//utilisation de i dans un compteur
    {
        //printf(" .");//affichage des points apr�s la phrase

        sleep(1);//fonction de d�lai

	//printf("/n");
    }

    system("clear");

}
