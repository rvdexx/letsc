#include <stdio.h>

#define BYTES_PER_LINE 20
#define LENGTH [BYTES_PER_LINE * 3 + 1]

int totalChecksum(int line[], int length)
{
  int checksum = 0;
  int i;
  for (i = 0; i < length; i++)
  {
    checksum += line[i];
  }

  return checksum;
}

int main()
{
  int ch;
  int line[BYTES_PER_LINE];
  printf("HEX ENCODED V1.0\n");

  int i = 0;
  while ((ch = getchar()) != EOF)
  {
    if (i == BYTES_PER_LINE - 1)
    {
      int checksum;
      checksum = totalChecksum(line, BYTES_PER_LINE);
      line[i] = checksum;
      printf(" %02x", checksum);
    }
    else if (i == BYTES_PER_LINE)
    {
      putchar('\n');
      i = 0;
    }

    printf(" %02x", ch);
    line[i] = ch;
    i++;
  }

  if (i != 0)
  {
    int checksum;
    checksum = totalChecksum(line, BYTES_PER_LINE);
    line[i] = checksum;
    printf(" %02x", checksum);
  }

  printf("\nEND HEX ENCODED");

  return 0;
}
