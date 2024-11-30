#include <stdio.h>


int getLine(char *, int);
void copy(char *, char *);

int main() {
  
  int MAX_LINE = 1000;
  char lines[MAX_LINE];
  char maxLine[MAX_LINE];
  int max,len;

  max = 0;
 while ((len = getLine(lines, MAX_LINE)) > 0) {
   if (len > max) {
     max = len;
     copy(maxLine, lines);
   }
 }
  printf("Max line is: %s", maxLine);

  return 1;
}

void copy(char *to, char *from) {
  while ((*to = *from) != '\0') {
    to++;
    from++;
  }
}

int getLine(char *input, int max) {
  int i;
  char ch;
  for(i=0; i < max && (ch = getchar()) != EOF && ch != '\n'; i++) {
      input[i] = ch;
  }
  return i;
}
