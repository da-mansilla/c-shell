#include "main.h"
#include <stdio.h>
#include <unistd.h>
#include "main.h"

void execmd(char **argv) {
  if (argv) {
    char *command = NULL;
    char *actual_command;

    command = argv[0];
    actual_command = get_location(command);

    if (execve(actual_command, argv, NULL) == -1) {
      perror("Error.");
    }
  }
}
