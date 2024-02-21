#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 40

FILE* open_file(char* name, char* mode);

int main(int argc, char* argv[])
{
    int ch;//use int to save EOF
    char name[40];
    FILE* in, *out;

    in = open_file(argv[1], "r");

    strncpy(name, argv[1], SIZE-6);
    name[SIZE - 6] = '\0';
    strcat(name, "_copy");
    
    out = open_file(name, "w");

    while((ch = getc(in)) != EOF)
    {
        putc(ch, out);
    }

    if(fclose(in) != 0 && fclose(out) != 0)
        printf("Error in closing file\n");
    return 0;
}

FILE* open_file(char* name, char* mode)
{
    FILE* fp;
    if((fp = fopen(name, mode)) == NULL)
    {
        printf("Can't open the file\n");
        exit(EXIT_FAILURE);
    }
    return fp;
}
