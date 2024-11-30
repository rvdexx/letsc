#include <stdio.h>

#define OUT 0
#define IN 1

int main() {
  char word[50];
  int wc;
  char *ptr;
  int position;

  wc = 0;
  fgets(word, 50, stdin);
  ptr = word;
  position = OUT;
  while(*ptr != '\0') {
    if (*ptr == ' ' || *ptr == '\t' || *ptr == '\n') {
      position = OUT;
    } else if ( position == OUT) {
      wc++;
      position = IN;
    }
    ptr++;
  }
  printf("Total words: %d", wc);
  return 1;
}
