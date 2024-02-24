/*
1.从命令行参数获取两个文件名
2.获取原始文件中数据
3.复制数据到拷贝文件中
*/
#include<stdio.h>
#include<stdlib.h>
#define BUFSIZE 4096

int main(int argc, char* argv[])
{
    FILE* origin, *copy;

    if (argc != 3)
    {
        printf("Usage: %s originfile copyfile\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if((origin = fopen(argv[1], "rb")) == NULL)
    {
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
        if((copy = fopen(argv[2], "wb")) == NULL)
    {
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    int bytes;
    static char temp[BUFSIZE];
    while ((bytes = fread(temp, sizeof(char),BUFSIZE, origin)) > 0)
    {
        fwrite(temp, sizeof(char),BUFSIZE, copy);
    }
     
    if(fclose(origin) != 0 && fclose(copy) != 0)
        printf("Error in closing file\n");
    return 0;
}