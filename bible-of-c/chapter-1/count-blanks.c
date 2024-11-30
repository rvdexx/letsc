#include <stdio.h>

int main() {
  int ch, tabsCount, newLineCount, spaceCount;

  tabsCount = newLineCount = spaceCount = 0;
  while((ch = getchar()) != EOF) {
         switch(ch) {
           case '\n':
              newLineCount++;
              break;
           case '\t':
              tabsCount++;
              break;
           case ' ':
              spaceCount++;
              break;
         }
  }


  printf("\n\n Tabs\t New Line \t Space\n");
  printf("%4d\t %4d \t %4d", tabsCount, newLineCount, spaceCount);

  return 1;
}
