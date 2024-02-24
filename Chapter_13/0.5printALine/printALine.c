#include<stdio.h>
#include<stdlib.h>
#define BUF 256

int have_char(char ch, const char* line ,int size);
int main(int argc, char* argv[])
{
    char ch;
    FILE* fp;
    char line[BUF];

    if((fp = fopen(argv[2], "r")) == NULL)
        {
            puts("Can't open the file.");
            exit(EXIT_FAILURE);
        }

    while (fgets(line, BUF, fp) != NULL)
    {
        if(have_char(argv[1][0], line,BUF))
            fputs(line, stdout);
    }
    
    if(fclose(fp) != 0)
        printf("Error in closing file\n");
        exit(EXIT_FAILURE);
    return 0;
}

int have_char(char ch, const char* line ,int size)
{
    for (int i = 0; i < size; i++)
    {
        if(line[i] == ch)
            return 1;
    }
    return 0;
}