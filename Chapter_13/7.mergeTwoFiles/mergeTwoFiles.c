/*
1.使用命令行参数获取文件名
2.打开两个文件
3.依次交叉打印文件的每一行
4.关闭文件
*/
#include<stdio.h>
#include<stdlib.h>
#define BUF 256

int main(int argc, char* argv[])
{
    char line1[BUF];
    char line2[BUF];
    FILE *fp1, *fp2;
    char* get1,*get2;
    if((fp1 = fopen(argv[1], "r")) == NULL)
        {
            puts("Can't open the file.");
            exit(EXIT_FAILURE);
        }
    if((fp2 = fopen(argv[2], "r")) == NULL)
        {
            puts("Can't open the file.");
            exit(EXIT_FAILURE);
        }
    while(1)
    {
        if(fgets(line1, BUF, fp1) != NULL)
            fputs(line1, stdout);
        if(fgets(line2, BUF, fp2) != NULL)
            fputs(line2, stdout);
        if (feof(fp1) && feof(fp2))
        {
            break;
        }
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}