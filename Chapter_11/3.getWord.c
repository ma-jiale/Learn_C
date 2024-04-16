#include<stdio.h>
#include<ctype.h>
char* getWord(char* ps);

int main(void)
{
	char input[20];

	while (getWord(input) != NULL)
		puts(input);
	puts("Done.\n");

	return 0;
}

char* getWord(char* ps) {
	char ch;
	char* save = ps;
	while ((ch = getchar()) != EOF && isspace(ch))
		continue;
	if (ch == EOF)
		return NULL;
	else
		*save++ = ch;
	while ((ch = getchar()) != EOF && !isspace(ch))
		*save++ = ch;
	*save = '\0';
	if (ch == EOF)
		return NULL;
	else
		while (getchar() != '\n')
			continue;
		return ps;
}