/*
1.使用命令行参数获取文件名
2.打开所有文件
3.将所有文件显示在屏幕上
4.关闭所有文件
*/
#include<stdio.h>
#include<stdlib.h>
#define SIZE 20

void showFile(char* name,FILE* fp);

int main(int argc, char* argv[])
{   
    FILE* fp[SIZE];

    for (int i = 0; i < argc - 1; i++)
    {
        if((fp[i] = fopen(argv[i+1], "rb")) == NULL)
        {
            printf("Can't open %s\n", argv[i+1]);
            exit(EXIT_FAILURE);
        }
    }
    for(int i = 0; i < argc - 1; i++)
    {
        showFile(argv[i+1],fp[i]);
    }

    for (int i = 0; i < argc - 1; i++)
    {
        fclose(fp[i]);
    }
    return 0;    
}

void showFile(char* name,FILE* fp)
{
    char ch;
    puts(name);
    while ((ch = getc(fp)) != EOF)
    {
        putchar(ch);
    }
    putchar('\n');
}