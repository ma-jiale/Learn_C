/*
1.通过两个命令行参数获取目标字符串和待查找文件
2.以只读形式打开文件
3.读取文件的每一行并查找当前行是否有字符串。
4.关闭文件
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define BUF 256

int main(int argc, char* argv[])
{
    FILE* fp;
    char* line;
    line = malloc(sizeof(char)*BUF);
    if(argc != 3)
    {
        printf("Usage:%s string file_name", argv[0]);
        exit(EXIT_FAILURE);
    }
    if((fp = fopen(argv[2], "r")) == NULL)
    {
        printf("Can't open %s\n", argv[2]);
        exit(EXIT_FAILURE);
    }
    while (fgets(line, BUF, fp) != NULL)
    {
        if(strstr(line, argv[1]) != NULL)
            fputs(line, stdout);
    }
    fclose(fp);
    free(line);
    return 0;
}