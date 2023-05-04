#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv){
    char *prompt = "[My Shell] $ ";
    char *lineptr;
    size_t n = 0;
    ssize_t nchars_read;

    (void)argc;(void)argv;

    while (1) {
        printf("%s",prompt);
        nchars_read = getline(&lineptr, &n, stdin);
        if(nchars_read == -1){
            printf("Exiting shell...\n");
            return(-1);
        }
        printf("%s", lineptr);

    }
    free(lineptr);
    return 0;
}
