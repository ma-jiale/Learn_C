#include<stdio.h>
#define SIZE 11
#include<string.h>
char* s_gets(char* st, int n);
int main()
{
    char st[SIZE];
    s_gets(st, SIZE);
    puts(st);
    return 0;
}

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');    // look for newline
		if (find)                   // if the address is not NULL,
			*find = '\0';           // place a null character there
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}