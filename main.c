#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct main
{
    char character;
    char *morese;
} kod;


void KeszletBe(char *path);

void MorzeToText(char *source, char *dest);

void TextToMorze(char *source, char *dest);

/*
        Todo:
        - Text to morse converter
        - Morse to text converter
        - Switch for the two mentioned above (Done)
        - Adding charset
        - Create a menu that offers 4 options (the previous 4 requirements) (Done)
        - When choosing the input option clear the console for better visibility
    */
int main()
{   
    int action;
    bool isTextToMorse = false;
    char *szoveg;
    char *cel;
    FILE *fp;
    int i = 0;




    printf("			___\n_-||-_		       \\   /\n|----|_--___---__I_#_--|   |\n|    |__I____|*|_______|___/\n|----|  |*|   @       |\n|_______|-|__________/\n/_______________#____\\\n\n\n");
    printf("Morze kodolo %s\nValasszon milyen muveletet szeretne vegrehajtani es irja le a sorszamat\n0. Forditas iranyanak megvaltoztatasa\n1. Bemenet megadasa\n2. Karakterkeszlet megadasa\n3. Kilépés a programból\n", isTextToMorse ? "(Szöveg -> Morze)" : "(Morze -> Szöveg)");
    
    while(scanf("%d", &action) != EOF){
        switch (action){
        case 0:
            isTextToMorse = !isTextToMorse;
            printf("\nA fordítás iránya megváltoztatva a következőre: %s\n", isTextToMorse ? "Szöveg -> Morze" : "Morze -> Szöveg");
            break;
        
        case 1:
            printf("Adja meg a %s kívánt üzenetet\n", isTextToMorse ? "kódolni" : "dekódolni");
            scanf("%s", szoveg);
            if(isTextToMorse)
                TextToMorze(szoveg, cel);
            else
                MorzeToText(szoveg, cel);
            printf("A %s üzenet a következő\n%s", isTextToMorse ? "kódólt":"visszafejtett", *cel);
            break;

        case 2:
            char *path;
            char sor[10];
            printf("Adja meg a karakterkészlet elérhetőségét\n");
            scanf("%s", path);
            fp = fopen(path, "r");
            //Reads all the lines of a txt file
            while(fgets(sor, 10, fp)){
                i++;
            }

            kod abc[i] = {};

            char be[10];
            while(i > 0){
                abc[i].character = be[0];
                i--;
            }
            fclose(fp);
            break;
        
        case 3:
            exit(1);
            break;
        
        default:
            printf("A művelet nem létezik. Adja meg a művelet sorszámát a listáról!\n");
            break;
        }
        printf("Morze kodolo %s\nValasszon milyen muveletet szeretne vegrehajtani es irja le a sorszamat\n0. Forditas iranyanak megvaltoztatasa\n1. Bemenet megadasa\n2. Karakterkeszlet megadasa\n3. Kilépés a programból\n", isTextToMorse ? "(Szöveg -> Morze)" : "(Morze -> Szöveg)");
    }

    return 0;
}

void TextToMorze(char *source, char *dest){
    //Replace chars from the beginning with their morse counterpart
        //Using two arrays for the chars and search for their encoded version
        //Creating an array of a custom type containing the letter and the coded form
    //Place the newly generated morse code to the destination pointer
};

void MorzeToText(char *source, char *dest){
    //Replace morse code from the beginning with their alphabetic counterpart
    //Place the newly generated text to the destination pointer
}

void KeszletBe(char *path){
    //Read the file at the given path and use this encoding until changed.
}
