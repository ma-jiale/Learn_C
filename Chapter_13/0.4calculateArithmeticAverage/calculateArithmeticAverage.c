#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
    FILE* fp;
    int count = 0;
    double n = 0.0;
    double sum = 0.0;
    double average = 0;
/*打开文件，或使用标准输入*/
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
/*计算算数平均数*/
    while(fscanf(fp, "%lf", &n) == 1)
    {
        sum += n;
        count++;
    }
    average = sum / count;
/*关闭文件*/
    if(fclose(fp) != 0)
        exit(EXIT_FAILURE);

    printf("the average of numbers in this file is %.2f\n", average);
    return 0;
}