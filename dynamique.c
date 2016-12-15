#include <stdio.h>
#include <stdlib.h>
#include <time.h>//pour les fonction temps
#include <string.h>//pour les fonctions des chaînes de caractères
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

    int a = 10;//déclaration de la variable a(globale)

    //printf("Entrez une valeur\n");//intéraction avec l'utilisateur

    //scanf("%d", &a);//demande d'entrée de l'utilsateur

    label0://déclaration de l'étiquette 0 utilisée plus tard

    system("clear");

    Temps();//utilisation de la fonciton Temps

    //printf("ce texte se rafraichira dans %d", a);//intéraction utilisateur pour la durée de rafraichissement

    refresh(a);//utilisation de la variable de l'utilisateur pour déterminer la variable de rafraichissement

    system("clear");

    goto label0;//retour à l'étiquette du dessus

}
void Temps ()//fonction Temps
{
    char aff_Time [9];//définition d'une chaîne de caractères

    time_t t = time(NULL);//setup du pointeur temps sur NULL

    struct tm tm = *localtime(&t);//définition de la structure tm tm égale à t; t égal à local time

    sprintf(aff_Time, "Il est: %d:%d:%d\n",tm.tm_hour, tm.tm_min, tm.tm_sec);//assignation t dans la chaîne de caractères

    printf("%s", aff_Time);//afichage de la chaîne de caractère
}
void refresh(int a)//fonction rafraichissement avec pour paramètre a (définie par l'utilisateur)
{
    int i = 0;//déclaration et initialisation de i

    for (i = 0; i < a; i++)//utilisation de i dans un compteur
    {
        //printf(" .");//affichage des points après la phrase

        sleep(1);//fonction de délai

	//printf("/n");
    }

    system("clear");

}
