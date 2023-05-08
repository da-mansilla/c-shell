#include "main.h"
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main() {
  char *prompt = "[My Shell] $ ";
  char *full_command = NULL;
  char *copy_command = NULL;
  const char *delim = " \n";
  size_t n = 0;
  ssize_t nchars_read;
  char *token;
  int num_tokens = 0;
  int i = 0;

  char **argv;
  // (void)argc;

  while (1) {
    num_tokens = 0;
    printf("%s", prompt);
    nchars_read = getline(&full_command, &n, stdin);
    if (nchars_read == -1) {
      printf("Exiting shell...\n");
      return (-1);
    }
    // Allocate space for the copy of the input user
    copy_command = malloc(sizeof(char) * nchars_read);
    if (copy_command == NULL) {
      printf("Memory allocation error");
      return (-1);
    }
    // Copy the content into the new variable
    strcpy(copy_command, full_command);

    // Split the strings into tokens
    token = strtok(full_command, delim);

    // Count the number of tokens
    while (token != NULL) {
      num_tokens++;
      token = strtok(NULL, delim);
    }
    num_tokens++;

    // Allocate memory for a array of strings
    argv = malloc(sizeof(*argv) * num_tokens);

    // Save each token in the array
    token = strtok(copy_command, delim);
    for (i = 0; token != NULL; i++) {
      argv[i] = malloc(sizeof(**argv) * strlen(token));
      strcpy(argv[i], token);

      token = strtok(NULL, delim);
    }
    argv[i] = NULL;

    execmd(argv);

    free(argv);
    free(copy_command);
  }
  free(full_command);
  return 0;
}
