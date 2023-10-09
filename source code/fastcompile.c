#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#ifdef _WIN32
    #define device "nt"
#else
    #define device "nonNT"
#endif

int clearscr();

int main() {
    printf("\033[38;5;33m-> GCC\n\033[0m   G++");
    int current = 1;
    int c;
    while(1){
        //printf("%d", current);
        c = getch();
        clearscr();
        if (c == 13) {
            char filename[256];
            char otherargs[100];
            printf("\033[38;5;33mFile:\033[0m ");
            scanf("%259s", filename);

            printf("\033[38;5;33mOther arguments (optional):\033[0m ");
            getchar();
            fgets(otherargs, sizeof(otherargs), stdin);

            if (strlen(otherargs) > 0 && otherargs[strlen(otherargs) - 1] == '\n') {
                otherargs[strlen(otherargs) - 1] = '\0';
            }

            char* cmd = NULL;

            if (current == 1) {
                int totalLen = snprintf(NULL, 0, "gcc %s %s", filename, otherargs);
                cmd = (char*)malloc(totalLen + 1);
                snprintf(cmd, totalLen + 1, "gcc %s %s", filename, otherargs);
            } else if (current == 2) {
                int totalLen = snprintf(NULL, 0, "g++ %s %s", filename, otherargs);
                cmd = (char*)malloc(totalLen + 1);
                snprintf(cmd, totalLen + 1, "g++ %s %s", filename, otherargs);
            } else {
                return printf("goodbye.");
            }

            if (cmd != NULL) {
                printf("\n\n\033[0mExecuting \"%s\"\n==========================\n", cmd);
                system(cmd);
                free(cmd);
            }

            return 0;
        }
        if (c == 3) { return 0; }
        if (c == 0 || c == 224) {
            c = getch();

            switch(c) {
                case 80:
                    if(current < 2) {current++;}

                    break;
                case 72:
                    if(current > 1) { current--; }
                    break;
            }

        }
    if (current == 1) {
        printf("\033[38;5;33m-> GCC\n\033[0m   G++\033[0m");
    } else if (current == 2) {
        printf("\033[0m   GCC\n\033[38;5;33m-> G++");
    } else {
        printf("you dirty hacker...\n  3 File(s) moved.");
    }
    }
}

int clearscr() {
    if (device == "nt") {
        system("cls");
    } else {
        system("clear");
    }
}