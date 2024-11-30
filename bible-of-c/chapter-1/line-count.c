#include <stdio.h>

int main() {
  int c,lc;
  lc = 0;
  while ((c = getchar()) != EOF) {
   if (c == '\n') {
      lc++;
   }
  }

  printf("Total Line: %d", lc);
  
  return 0;

}
