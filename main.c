#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct
{
    char character;
    char *morse;
} kod;

char* hosszu_sort_olvas(){
    char *tomb;
    int meret = 1;
    char c = '0';
    tomb = (char*) malloc(meret * sizeof(char));
    scanf("%c", &c);

    while(scanf("%c", &c) != EOF){
        meret++;
        if(c == '\n')
            break;

        char temp[meret] = {};

        for(int i = 0; i < meret-2; i++){
            temp[i] = tomb[i];
        }

        free(tomb);
        tomb = (char*) malloc(meret * sizeof(char));
        
        for(int i = 0; i < meret-2; i++){
            tomb[i] = temp[i];
        }
        tomb[meret-2] = c;
        if(meret > 2) tomb[meret-1] = '\0';
    }

    return tomb;
}

char* Encode(kod* source, int size, char input);
char* Convert(kod* source, int size,char* input, bool isTextToMorse);
kod* ReadCharset(char *path, int* size);
/*
        Todo:
        - Text to morse converter
        - Morse to text converter
        - Switch for the two mentioned above (Done)
        - Adding charset(Done)
        - Create a menu that offers 4 options (the previous 4 requirements) (Done)
    */
int main()
{
    bool isTextToMorse = false;
    int action;
    char *input;
    char *path;
    kod *abc = NULL;
    int meret = 0;
    int *mp = &meret;

    printf("			___\n_-||-_		       \\   /\n|----|_--___---__I_#_--|   |\n|    |__I____|*|_______|___/\n|----|  |*|   @       |\n|_______|-|__________/\n/_______________#____\\\n\n\n");
    printf("Morze kodolo %s\nValasszon milyen muveletet szeretne vegrehajtani es irja le a sorszamat\n0. Forditas iranyanak megvaltoztatasa\n1. Bemenet megadasa\n2. Karakterkeszlet megadasa\n3. Kilépés a programból\n", isTextToMorse ? "(Szöveg -> Morze)" : "(Morze -> Szöveg)");

    while(scanf("%d", &action) != EOF){
        switch (action)
        {
        case 0:
            isTextToMorse = !isTextToMorse;
            printf("A forditas iranya megvaltozott: %s", isTextToMorse ? "Szoveg -> Morze" : "Morze -> Szoveg");
            break;
        case 1:
            printf("Adja meg a %s szoveget:\n", isTextToMorse ? "kodolando" : "dekodolando");
            input = hosszu_sort_olvas();
            printf("\nA bemenet:%s\n", input);
            Convert(abc, *mp, input, isTextToMorse);
            free(input);
            break;
        case 2:
            if(abc != NULL){
                for(int i = 0; i < *(mp)-1; i++)
                    free(abc[i].morse);
                free(abc);
            }
            path = hosszu_sort_olvas();
            
            abc = ReadCharset(path, mp);
            free(path);
            for(int i = 0; i < *mp-1; i++)
                printf("%c\t%s",abc[i].character, abc[i].morse);
            break;
        case 3:
            for(int i = 0; i < *mp-1; i++)
                free(abc[i].morse);
            free(abc);
            exit(1);
            break;
        
        default:
            break;
        }
        printf("Morze kodolo %s\nValasszon milyen muveletet szeretne vegrehajtani es irja le a sorszamat\n0. Forditas iranyanak megvaltoztatasa\n1. Bemenet megadasa\n2. Karakterkeszlet megadasa\n3. Kilépés a programból\n", isTextToMorse ? "(Szöveg -> Morze)" : "(Morze -> Szöveg)");
    }
    return 0;
}

kod* ReadCharset(char *path, int* size){
    FILE* fp;
    kod *alphabet;
    int meret = 0;
    alphabet = (kod*) malloc(meret * sizeof(kod));
    char sor[101];

    fp = fopen(path,"r");
    while(fgets(sor,101,fp)){
        if(sor != ""){
            printf("%s", sor);
            if(meret > 0){
                kod temp[meret] = {};

                for(int i = 0; i < meret-1; i++){
                    temp[i] = alphabet[i];
                }

                free(alphabet);
                alphabet = (kod*) malloc(meret * sizeof(kod));

                for(int i = 0; i < meret; i++){
                    alphabet[i] = temp[i];
                }

                alphabet[meret-1].morse = (char*) malloc(sizeof(char) * (strlen(sor) - strlen("A\t")));

                sscanf(sor,"%c\t%s", alphabet[meret - 1].character, alphabet[meret - 1].morse);
            }
            meret++;
        }
    }
    fclose(fp);
    *size = meret;
    return alphabet;
}

char* Encode(kod *source, int size, char input){
    for(int i = 0; i < size; i++){
        if(source[i].character == input)
            return source[i].morse;
    }
}

char* Convert(kod *source, char *input, bool isTextToMorse){
    char* output;
    if(isTextToMorse){
        for(int i = 0; input[i] != '\0'; i++){

        }
    }else{

    }
    //Replace chars from the beginning with their morse counterpart
        //Using two arrays for the chars and search for their encoded version
        //Creating an array of a custom type containing the letter and the coded form
    //Place the newly generated morse code to the destination pointer
    //Replace morse code from the beginning with their alphabetic counterpart
    //Place the newly generated text to the destination pointer
}