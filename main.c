#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LINE_LENGTH 256

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

kod* abc_realloc(int meret, kod* alphabet){
    kod temp[meret] = {};
    for(int i = 0; i < meret-1; i++){
            temp[i] = alphabet[i];
    }

    meret++;
    free(alphabet);
    alphabet = (kod*) malloc(meret * sizeof(kod));

    for(int i = 0; i < meret-1; i++){
            alphabet[i] = temp[i];
    }

    return alphabet;
}

char** splitString(const char* str, char split_char) {
    char** result = (char**)malloc(2 * sizeof(char*));

    if (result == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    // Find the position of the split character
    const char* split_position = strchr(str, split_char);

    if (split_position == NULL) {
        // If the split character is not found, return the whole string as the first part
        result[0] = strdup(str);
        result[1] = NULL; // The second part is NULL
    } else {
        // Calculate the lengths of the two parts
        size_t first_part_length = split_position - str;
        size_t second_part_length = strlen(split_position + 1);

        // Allocate memory for the first part
        result[0] = (char*)malloc((first_part_length + 1) * sizeof(char));

        if (result[0] == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }

        // Copy the first part to the allocated memory
        strncpy(result[0], str, first_part_length);
        result[0][first_part_length] = '\0'; // Null-terminate the string

        // Allocate memory for the second part
        result[1] = (char*)malloc((second_part_length + 1) * sizeof(char));

        if (result[1] == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }

        // Copy the second part to the allocated memory
        strcpy(result[1], split_position + 1);
    }

    return result;
}

char* Encode(kod* source, char input, int size);
char* Convert(kod* source, int size, char* input, bool isTextToMorse);
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
            char* output = Convert(abc, *mp, input, isTextToMorse);
            printf("A kiemenet: %s", output);
            free(output);
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
               printf("%c\t%s\n",abc[i].character, abc[i].morse);
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
    char* sor;
    sor = (char*) malloc(sizeof(char) * MAX_LINE_LENGTH);

    fp = fopen(path,"r");
    while(fgets(sor, MAX_LINE_LENGTH,fp) != NULL){
        kod temp[meret];

        meret++;
        alphabet = (meret, alphabet);

        alphabet[meret-1].morse = (char*) malloc(sizeof(char) * MAX_LINE_LENGTH);
        sscanf("%c\t%s", &(alphabet[meret-1].character), alphabet[meret-1].morse);
    }
    free(sor);
    fclose(fp);
    *size = meret;
    return alphabet;
}

char* Encode(kod *source, char input, int size){
    for(int i = 0; i < size; i++){
        if(source[i].character == input)
            return source[i].morse;
    }
    return NULL;
}

char* Convert(kod *source, int size, char *input, bool isTextToMorse){
    char* output;
    if(isTextToMorse){
        for(int i = 0; input[i] != '\0'; i++){
            char* encoded_char = Encode(source, input[i], size);
            output = (char*) malloc((sizeof(output) + sizeof(encoded_char) + 2) * sizeof(char));
            strcpy(output, encoded_char);
            if(input[i+1] != '\0')
                strcat(output,"/");
        }
    }else{

    }
    return output;
    //Replace chars from the beginning with their morse counterpart
        //Using two arrays for the chars and search for their encoded version
        //Creating an array of a custom type containing the letter and the coded form
    //Place the newly generated morse code to the destination pointer
    //Replace morse code from the beginning with their alphabetic counterpart
    //Place the newly generated text to the destination pointer
}