#include <stdio.h>


int tohex(int c)
{
  if (c >= '0' && c <= '9') {
    return c - '0';
  }

  if ( c >= 'A' && c <= 'F') {
    return c - 'A' + 0xA;
  }
  
  return -1;
}


int main() {

  int ch, a,b;

  while (1){

    ch = getchar();
    a = tohex(ch);
    if (a < 0) break;
    a <<= 4;

    ch = getchar();
    b = tohex(ch);
    if (b < 0) break;
    putchar(a + b);
  }

  return 0;
}
