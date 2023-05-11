#include "main.h"
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

void execmd(char **argv) {
  int status;
  pid_t pid;
  char *command = NULL, *actual_command = NULL;

  pid = fork();

  if (argv) {
    if (pid < 0) {
      perror("Error creating fork child");
    } else if (pid == 0) {
      command = argv[0];
      actual_command = get_location(command);
      if (execve(actual_command, argv, NULL) == -1) {
        perror("Error.");
      }
    } else {
      waitpid(pid, &status, 0);
    }
  }
}
