#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "tree.h"
void showMenu();
char getChoice();
char getFirst();
char *getWordInFile(char *ps, FILE *fp);
void showItem(Item item);
void findWord(const Tree *ptree);
int main()
{
	Tree words;
	InitializeTree(&words);
	FILE *fp;
	Item temp;
	temp.num = 1;
	char choice;
	if ((fp = fopen("song.txt", "r")) == NULL)
	{
		puts("Can't open the file.");
		exit(EXIT_FAILURE);
	}
	while (getWordInFile(temp.word, fp) != NULL && !TreeIsFull(&words))
		AddItem(&temp, &words);
	while ((choice = getChoice()) != 'q')
	{
		switch (choice)
		{
		case 'a':
		case 'A':
			Traverse(&words, showItem);
			break;
		case 'b':
		case 'B':
			findWord(&words);
			break;
		default:
			printf("Program error!");
			break;
		}
	}
	puts("Bye!");
	return 0;
}

char getChoice()
{
	char ch;
	showMenu();
	ch = getFirst();
	while (((ch < 'A' || ch > 'b') || (ch > 'B' && ch < 'a')) && (ch != 'q'))
	{
		printf("Please respond with a, b, or q.\n");
		ch = getFirst();
	}
	return ch;
}

void showMenu()
{
	for (int i = 0; i < 70; i++)
	{
		putchar('*');
	}
	putchar('\n');
	printf("Enter the number corresponding to the action:\n");
	printf("a) show all words     b) look a word\n");
	printf("q) quit\n");
	for (int i = 0; i < 70; i++)
	{
		putchar('*');
	}
	putchar('\n');
}

char getFirst()
{
	char ch;
	ch = getchar();
	while (getchar() != '\n') /* skip over newlines */
		continue;
	return ch;
}

void showItem(Item item)
{
	printf("%s  %d times\n", item.word, item.num);
}

void findWord(const Tree *ptree)
{	
	Item temp;
	puts("please enter the word you what to find in this file");
	scanf("%s", temp.word);
	if(InTree(&temp, ptree))
		printf("%s is found in this text %d times\n",temp.word,temp.num);
	else
		printf("Can't find %s in this text\n",temp.word);
	
}

char *getWordInFile(char *ps, FILE *fp)
{
	char ch;
	char *save = ps;
	while ((ch = getc(fp)) != EOF && isspace(ch))
		continue;
	if (ch == EOF)
		return NULL;
	else
		*save++ = ch;
	while ((ch = getc(fp)) != EOF && !isspace(ch) && !ispunct(ch))
		*save++ = ch;
	*save = '\0';
	if (ch == EOF)
		return NULL;
	return ps;
}