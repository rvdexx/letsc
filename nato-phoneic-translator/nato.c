#include <stdio.h>
#include <ctype.h>

int main() {
	const char *nato[] = {
		"Alfa","Beta", "Charlie", "Delta", "Echo","Foxtrot",
		"Golf", "Hotel", "India", "Juliett", "Kilo", "Lima","Mike", 
		"November", "Oscar", "Papa", "Quebec", "Romeo", "Sierra",
		"Tango", "Uniform", "Victor", "Whiskey", "Xray","Yankkee", "Zulu" };
	char buffer[64];
	char ch;

	printf("Enter a word or phrase: ");
	fgets(buffer, 64, stdin);

	int i = 0;
	while(buffer[i] != '\0') {
		ch = toupper(buffer[i]);
		if (isalpha(ch)) {
			printf("%s ", nato[ch - 'A'] );
		}
		i++;

		if (i == 64) {
			break;
		}
	}

	fputs("\n", stdout);
	return 0;
}
