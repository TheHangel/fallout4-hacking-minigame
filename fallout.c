#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

#include "util/words.c"
#include "util/likeness.c"
#include "util/char.c"

#include "display/colors.c"
#include "display/print.c"

#define NB_LINES 16

int main() {
    srand(time(NULL));

    const char* word_to_find = randomWord();
    //printf("WORD TO FIND : %s\n", word_to_find);

    char list_game_word [NB_WORDS][MAX_STRING_SIZE] = {
    };

    for(int i=0; i<NB_WORDS; i++) {
        strcpy(list_game_word[i], randomWord());
    }

    int found = 0;
    for(int i = 0; i < NB_WORDS; ++i)
    {
        if(!strcmp(list_game_word[i], word_to_find))
        {
            found++;
        }
    }

    if(found == 0) {
        int r = rand() % NB_WORDS + 0;
        strcpy(list_game_word[r], word_to_find);
    }

    /*for(int i=0; i<NB_WORDS; i++) {
        printf("%s\n", list_game_word[i]);
    }*/

    green();
    delay_print("ROBCO INDUSTRIES (TM) TERMLINK PROTOCOL");
    wait(WAIT_TIME*8);
    printf("\n");
    delay_print("PASSWORD REQUIRED");
    wait(WAIT_TIME*12);
    printf("\n");
    printf("\n");
    
    for (int j = 0; j < NB_LINES; j++) {
        printBloc(list_game_word);
        printf("\t  ");
        printBloc(list_game_word);
        printf("\n");
    }
    int lives = 4;
    int like = 0;
    //int attempts = 0;

    // GAME LOOP
    while(like != 4 && lives > 0) {
        printf("\tAttempts Remaining : ");
        for(int i=0; i<lives; i++) {
            printf("\u25A0 ");
        }
        printf("\n>");
        char wordchosen[4];
        scanf("%s", wordchosen);
        uppercase(wordchosen);
        like = likeness(word_to_find, wordchosen);
        /*if(attempts > 0) {
            for(int i=0; i<6; i++) {
                resetScreen();
            }
            printf("ICI");
        }*/
        if(like == -1) {
            printf(">Incorrect.\n");
        }
        else if(like != 4) {
            printf(">Entry denied.\n");
            printf(">Likeness=%d\n", like);
            lives--;
        }
        if(like == 4) {
            printf(">Exact match!\nPlease wait while system is accessed.\n");
            wait(WAIT_TIME*20);
        }
        if(lives == 1) {
            printf(">!!! WARNING: LOCKOUT IMINENT !!!\n");
        }
        if(lives == 0) {
            printf(">TERMINAL LOCKED.\n");
        }
        //attempts++;
    }

    reset();
    return 0;
}