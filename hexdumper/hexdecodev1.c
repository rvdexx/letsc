#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_LINE_SIZE  18
#define LENGTH (BUFFER_LINE_SIZE * 3 + 1)

int main() {

  char *str;
  char line[LENGTH];

  str = fgets(line, LENGTH, stdin);

  if (str == NULL || strncmp(str, "HEX ENCODE", 10) != 0) {
    fprintf(stderr, "Invalid HEX Encoding Format");
    exit(1);
  }

  while ((str = fgets(line, LENGTH, stdin)) != NULL) {
    
    char *r;
    int hex;

    r = strtok(line, " ");

    while (r) {
      sscanf(r, "%02x", &hex);
      printf("%c", hex);
      r = strtok(NULL, " ");
    }

  }

  return 0;

}
