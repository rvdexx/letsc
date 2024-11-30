#include <stdio.h>
#include "nato.h"

int streq(char *, char *);
int strlength(char *);

int main(int argc, char *argv[]) {
  char nwords[64];
  char *match;
  char letter;
  printf("Enter Nato Words to convert to actual word:");
  fgets(nwords, 64, stdin);

  match = strtok(nwords, " !,%=$#@");

  while (match != NULL) {
    for (int i=0; i<26; i++) {
      char *term;
      term = nato[i];

      if (streq(term, match)) {
        fputs(term, stdout);
        fputs(match, stdout);
        printf("%s \n\n", term);
      }
    }
    match = strtok(NULL, " ");
  }



  return 1;

}

int strlength(char *str) {
  int count = 0;
  while(*str != '\0') {
    str++;
    count++;
  }

  return count;
}

int streq(char *str1, char *str2) {
  if (strlength(str1) != strlength(str2)) {
    return 0;
  }
  int equal = 1;
  while(*str1 == '\0') {
    if (*str1 != *str2) {
      equal = 0;
      break;
    }
    str1++;
    str2++;
  }
  return equal;
}

