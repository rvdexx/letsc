#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

int moon_function(int, int, int);

int main(int argc, char *argv[]) {
   if (argc < 2) {
	puts("Hello, you handsome beast!");
   } else {
	printf("Hello %s\n", argv[1]);
   }

   char buffer[256];
   char *entry;
   FILE *fp;
   char **entries;
   int items, saying;

   fp = fopen("/Users/dex/Desktop/letsc/greetings/quotes.txt", "r");
   
   if (fp == NULL) {
      fprintf(stderr, "Unable to open file");
      exit(1);
   }
   items = 0;
   entries = (char **) malloc(sizeof(char *) * 100);
   if (entries == NULL) {
	fprintf(stderr, "Unable to allocate memory");
	exit(1);
   }
   while(!feof(fp) ) {
     if(! fgets(buffer,256, fp)) {
       break;
     }
     entry = (char *) malloc(sizeof(char) * strlen(buffer) + 1);
     strcpy(entry, buffer);
     *(entries+items) = entry;
      
      items++;
   } 
   fclose(fp);

   

   time_t now;
   struct tm *clock;
   char time_string[64];
   char *moon_phases[8] = {
       "waxing crescent", "at first quarter", "waxing gibbous",
       "full", "waning gibbous", "at last quarter", "waning crescent", "new"};   
   int mp_num;

   time(&now);
   clock = localtime(&now);
   strftime(time_string, 64, "Today is %A, %B %d, %Y%nIt is %r%n", clock); 
   mp_num = moon_function(clock->tm_year + 1900, clock->tm_mon, clock->tm_mday);
   printf("%s", time_string);
   printf("Moon is %s", moon_phases[mp_num]);

   srand((unsigned)time(NULL));
   saying = rand() % (items-1);
   printf("\n%s", *(entries+saying));

   free(entry);
   free(entries);
   return 0;
}

int moon_function(int year, int month, int day) {
    int d,g,e;
 
    d = day;
    if(month == 2)
        d += 31;
    else if(month > 2)
        d += 59+(month-3)*30.6+0.5;
    g = (year-1900)%19;
    e = (11*g + 29) % 30;
    if(e == 25 || e == 24)
        ++e;
    return ((((e + d)*6+5)%177)/22 & 7);
}
