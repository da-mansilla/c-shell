#include "main.h"
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

char *get_location(char *command) {
  char *path, *path_copy, *path_token, *file_path;
  int command_length, directory_length;
  struct stat buffer;

  path = getenv("PATH");
  if (path) {
    // Duplicate path string to use strtok later
    path_copy = strdup(path);
    command_length = strlen(command);

    // Cut the path variable per :
    path_token = strtok(path_copy, ":");
    while (path_token != NULL) {
      directory_length = strlen(path_token);
      // Allocate memory to storing de command length, the directory lenght and
      // 2 bites more to '/' caracters
      file_path = malloc(command_length + directory_length + 2);

      // Build the path to the command
      strcpy(file_path, path_token);
      strcat(file_path, "/");
      strcat(file_path, command);
      strcat(file_path, "\0");

      // Check if the file path exists
      if (stat(file_path, &buffer) == 0) {
        free(path_copy);
        return (file_path);
      }
      // Check for other path directory
      else {
        free(file_path);
        path_token = strtok(NULL, ":");
      }
    }
    free(path_copy);

    // Check if the command itself is a file_path that one that exists
    if (stat(command, &buffer) == 0) {
      return (command);
    }

    return NULL;
  }
  return NULL;
}
