#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 40

int main(int argc, char* argv[])
{
    int ch;//use int to save EOF
    char name[40];
    FILE* in, *out;

    if((in = fopen(argv[1], "r")) == NULL)
    {
        printf("Can't open the file\n");
        exit(EXIT_FAILURE);
    }

    strncpy(name, argv[1], SIZE-6);
    name[SIZE - 6] = '\0';
    strcat(name, "_copy");
    if((out = fopen(name, "w")) == NULL)
    {
        printf("Can't create the file\n");
        exit(EXIT_FAILURE);
    }

    while((ch = getc(in)) != EOF)
    {
        putc(ch, out);
    }

    if(fclose(in) != 0 && fclose(out) != 0)
        printf("Error in closing file\n");
    return 0;
}