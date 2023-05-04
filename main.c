#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc, char **argv){
    char *prompt = "[My Shell] $ ";
    char *lineptr;
    size_t n = 0;

    (void)argc;(void)argv;

    while (1) {
        printf("%s",prompt);
        getline(&lineptr, &n, stdin);
        printf("%s", lineptr);

    }
    free(lineptr);
    return 0;
}
