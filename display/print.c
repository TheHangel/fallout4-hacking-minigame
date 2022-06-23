#define WAIT_TIME 80000
#define NB_WORDS 12

int count_wrd_print = 0;

void waiting(int time) {
    fflush(stdout);
    usleep(time);
}

void resetScreen() {
    /*
     \33[2K erases the entire line your cursor is currently on
     \033[A moves your cursor up one line, but in the same column i.e. not to the start of the line
    */
   printf("\033[A");
   printf("\33[2K");
}

void delay_print(char *str) {
    for (char *p = str; *p; p++) {
        putchar(*p);
        fflush(stdout);
        usleep(20000);
    }
}

char randomChar() {
    int r = rand() % 48 + 33;
    return r;
}

int randomNumber() {
    int r = rand() % 10 + 0;
    return r;
}

void printAddress() {

    printf("0x");

    for(int i=0; i<4; i++) {
        printf("%d", randomNumber());
    }

}

char* randomWord() {
    int r = rand() % NUMBER_OF_STRING + 0;
    return list_of_words[r];
}

void printRandomChars(char list_words[][5]) {
    int ran = 1;
    if(count_wrd_print < NB_WORDS) {
        ran = rand() % 2 + 0;
    }
    if(ran == 0) {
        int r = rand() % 3 + 1;
        switch (r)
        {
        case 1:
            for (int i = 0; i < 8; i++) {
                printf("%c", randomChar());
            }
            light_green();
            printf("%s", list_words[count_wrd_print]);
            green();
            break;
        case 2:
            light_green();
            printf("%s", list_words[count_wrd_print]);
            green();
            for (int i = 0; i < 8; i++) {
                printf("%c", randomChar());
            }
            break;
        case 3:
            for (int i = 0; i < 4; i++) {
                printf("%c", randomChar());
            }
            light_green();
            printf("%s", list_words[count_wrd_print]);
            green();
            for (int i = 0; i < 4; i++) {
                printf("%c", randomChar());
            }
            break;
        }
        count_wrd_print++;
    }
    else {
        for (int i = 0; i < 12; i++) {
            printf("%c", randomChar());
        }
    }
}

void printBloc(char list_words[][5]) {
    waiting(WAIT_TIME);
    printAddress();
    printf("  ");
    waiting(WAIT_TIME);
    printRandomChars(list_words);
    waiting(WAIT_TIME);
}
