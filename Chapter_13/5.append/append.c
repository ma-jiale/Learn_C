/* append.c -- appends files to a file */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFSIZE 4096
#define SLEN 81
void append(FILE *source, FILE *dest);
char * s_gets(char * st, int n);

int main(int argc, char* argv[])
{
    FILE *fa, *fs;	// fa for append file, fs for source file
    int files = 0;  // number of files appended
    int ch;
    
    if ((fa = fopen(argv[1], "a+")) == NULL)
    {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if (setvbuf(fa, NULL, _IOFBF, BUFSIZE) != 0)
    {
        fputs("Can't create output buffer\n", stderr);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < argc - 2; i++)
    {
        if (argv[i + 2][0] != '\0')
        {
            if (strcmp(argv[i + 2], argv[1]) == 0)
                fputs("Can't append file to itself\n",stderr);
            else if ((fs = fopen(argv[i + 2], "r")) == NULL)
                fprintf(stderr, "Can't open %s\n", argv[i + 2]);
            else
            {
                if (setvbuf(fs, NULL, _IOFBF, BUFSIZE) != 0)
                {
                    fputs("Can't create input buffer\n",stderr);
                    continue;
                }
                append(fs, fa);
                if (ferror(fs) != 0)
                    fprintf(stderr,"Error in reading file %s.\n",
                        argv[i + 2]);
                if (ferror(fa) != 0)
                    fprintf(stderr,"Error in writing file %s.\n",
                        argv[1]);
                fclose(fs);
                files++;
                printf("File %s appended.\n", argv[i + 2]);
            }
        }
    }
    printf("Done appending. %d files appended.\n", files);
    rewind(fa);
    printf("%s contents:\n", argv[1]);
    while ((ch = getc(fa)) != EOF)
        putchar(ch);
    puts("Done displaying.");
    fclose(fa);
    
    return 0;
}

void append(FILE *source, FILE *dest)
{
    size_t bytes;
    static char temp[BUFSIZE]; // allocate once
    
    while ((bytes = fread(temp,sizeof(char),BUFSIZE,source)) > 0)
        fwrite(temp, sizeof (char), bytes, dest);
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');   // look for newline
        if (find)                  // if the address is not NULL,
            *find = '\0';          // place a null character there
        else
            while (getchar() != '\n')
                continue;
    }
    return ret_val;
}