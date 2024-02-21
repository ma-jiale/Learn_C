#include<stdio.h>
#include<stdlib.h>
#define SIZE 10
int main(int argc, char* argv[])
{
    double num[SIZE];
    FILE* fp;
    size_t count = 0;
    double sum = 0;
    double average = 0;

    if(argc != 2)
    {
        puts("use stdin");
        fp = stdin;
    }
    else if((fp = fopen(argv[1], "r")) == NULL)
    {
        puts("can't open the file.");
        exit(EXIT_FAILURE);
    }

    count = fread(num, sizeof(double), SIZE, fp);

    if(fclose(fp) != 0)
        exit(EXIT_FAILURE);

    for (int i = 0; i < SIZE; i++)
    {
        sum += num[i];
    }
    average = sum / count;
    printf("the average of numbers in this file is %f\n", average);
    return 0;
}