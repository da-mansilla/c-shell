#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

int main (int arg, char **argv){
    char *prompt = "[My Shell] $";
    char *lineptr;
    size_t n = 0;

    printf("%s\n",prompt);
    getline(&lineptr, &n, stdin);

    free(lineptr);
    return 0;
}
