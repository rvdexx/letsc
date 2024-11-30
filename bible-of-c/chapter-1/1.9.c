#include <stdio.h>

int main() {
  int ch;

 while ((ch = getchar()) != EOF) {
    putchar(ch);

    if (ch == ' ') {
      while ((ch=getchar()) == ' ');
      putchar(ch);
    }
  }
  
  return 0;
}
