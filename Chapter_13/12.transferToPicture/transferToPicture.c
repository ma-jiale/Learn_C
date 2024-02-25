/*
1.获取文件名
2.打开文件
2.获取文件内容
3.将文件内容转换成对应字符
3.显示字符到屏幕上
4.关闭文件
*/
#include<stdio.h>
#include<stdlib.h>
#define ROWS 20
#define COLS 30
#define SIZE 21
#define LEVELS 10
const char trans[LEVELS + 1] = " .':~*=&%@";

void makePic(int data[][COLS], char pic[][COLS], int rows);
void init(char arr[][COLS], char ch);

int main()
{
    int picIn[ROWS][COLS];
    char picOut[ROWS][COLS];
    char name[SIZE];
    FILE* fp;
    
    puts("Enter the name of file");
    scanf("%20s", name);

    if((fp = fopen(name, "r")) == NULL)
    {
        printf("Can't open %s\n", name);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            fscanf(fp,"%d", &picIn[i][j]);
        }
    }
    fclose(fp);
    init(picOut, 'S');
    makePic(picIn, picOut, ROWS);

        for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            putchar(picOut[i][j]);
        }
        putchar('\n');
    }
    return 0;
}

void init(char arr[][COLS], char ch)
{
 int r, c;
 for (r = 0; r < ROWS; r++)
    for (c = 0; c < COLS; c++)
        arr[r][c] = ch;
}

void makePic(int data[][COLS], char pic[][COLS], int rows)
{
    int row, col;
    for (row = 0; row < rows; row++)
        for (col = 0; col < COLS; col++)
            pic[row][col] = trans[data[row][col]];
}