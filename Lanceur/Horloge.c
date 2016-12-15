#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#define TAILLE_MAX 80
#define centrer(x,y) printf("\033[%d;%dH", (x), (y))


int initialisationHeure()
{
    time_t secondes;
    struct tm instant;
    time(&secondes);
    instant=*localtime(&secondes);
    //on associe chaque variable tm à une variable entière
    int timeSeconde1 = (instant.tm_sec)/10;
    int timeSeconde2 = (instant.tm_sec)-(timeSeconde1*10);
    int timeMinute1 = (instant.tm_min)/10;
    int timeMinute2 = (instant.tm_min)-(timeMinute1*10);
    int timeHeure1 = (instant.tm_hour)/10;
    int timeHeure2 = (instant.tm_hour)-(timeHeure1*10);


    //On met les variables dans un tableau
    int Heure[8];
    Heure[0] = timeHeure1;
    Heure[1] = timeHeure2;
    Heure[2] = 25;
    Heure[3] = timeMinute1;
    Heure[4] = timeMinute2;
    Heure[5] = 25;
    Heure[6] = timeSeconde1;
    Heure[7] = timeSeconde2;

    int z = 0;
    int tailleFichier = 1;

    int y=40-((4+tailleFichier*2)*3+5), x = 6;
    int i = 0, j = 0; //Variable pour les boucles
    FILE* fichier = NULL; //On met le pointeur à null
    char chaine[TAILLE_MAX];
    int chaine2[2];
    int a,b;

    //Boucle pour récuperer les images PBM de l'heure
    for (z = 0; z < 8; z++)
    {
        switch(Heure[z])
        {
            case 0 :
                fichier = fopen("Numero/Zéro.pbm", "r");
            break;


            case 1 :
                fichier = fopen("Numero/Un.pbm", "r");
            break;


            case 2 :
                fichier = fopen("Numero/Deux.pbm", "r");
            break;


            case 3 :
                fichier = fopen("Numero/Trois.pbm", "r");
            break;


            case 4 :
                fichier = fopen("Numero/Quatre.pbm", "r");
            break;


            case 5 :
                fichier = fopen("Numero/Cinq.pbm", "r");
            break;


            case 6 :
                fichier = fopen("Numero/Six.pbm", "r");
            break;


            case 7 :
                fichier = fopen("Numero/Sept.pbm", "r");
            break;


            case 8 :
                fichier = fopen("Numero/Huit.pbm", "r");
            break;


            case 9 :
                fichier = fopen("Numero/Neuf.pbm", "r");
            break;


            case 25 :
                fichier = fopen("Numero/Point.pbm", "r");
            break;


            default:

                printf("error in switch");

        }

        if(fichier != NULL)//On vérifie que le fichier est ouvert
        {
            fseek(fichier, 3, SEEK_SET);
            fscanf(fichier, "%d %d", &chaine2[0], &chaine2[1]);
            a = chaine2[0];
            b = chaine2[1];
            a = (a*2)-1;

            fseek(fichier, 1, SEEK_CUR);

            for(i = 0; i < b; i++)//boucle qui parcourt la ligne
            {
                centrer(x,y);
                fgets(chaine, TAILLE_MAX, fichier); //on récupère une ligne du fichier PBM lu

                for(j = 0; j < a; j++) //boucle qui lit caractère par caractère
                {
                    centrer(x,y);
                    if(chaine[j] == '0')
                        chaine[j] = ' ';//On remplace les 0 par  des espaces
                    else if(chaine[j] == '1')
                        chaine[j] = 'X' ;//On change les 1 par des X

                }
                x = x + 1;
                printf("%s", chaine);
            }
            fclose(fichier);//On ferme le fichier
            fichier = NULL;
        }
        x = x - 5;
        y = y + 7;
    }
    return 0;
}
void HorlogeJuan()
{
    //Variable pour le rafraichissement des images et le centrage de l'image
    int rafraichissement = 0;
    int ctrlc = 0;
    int i;
    int a = 20; int b = 15, c = 3, d = 25;
    system("clear");
    printf("entrez votre valeur \n");
    scanf ("%d\n", &rafraichissement);


    while(ctrlc != 1)
    {
        int x = 20;
        int y = 62;

        centrer(c,d);
        initialisationHeure();
        centrer(a,b);

        //Texte afficher pour indiquer comment l'heure ce rafraichis
        if(rafraichissement == 1)
        {
            centrer(a,b+10);
            printf("L'ecran est actualise toute les secondes\n");
        }
        else
        {
            printf("L'ecran sera actualisé dans quelques secondes");
        }

        //Boucle pour rafraichir l'heure
        for(i = 0; i < rafraichissement; i++)
        {
            sleep(1);
            centrer(x,y);
            printf(".\n");
            y++;
        }

        y = y - rafraichissement;
        centrer(x,y);
        printf("                             ");
    }
}
