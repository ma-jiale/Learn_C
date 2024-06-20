/*编写一个函数接受这些参数：内含int类型元素的数组名、数组的大小和一个代表选取次数的值。
该函数从数组中随机选择指定数量的元素，并打印他们，每个元素只能选择一次*/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10
#define PICKS 5
void random_pick(int* pt, int size, int picks);

int main()
{
    int lottery[SIZE];
    int orginal[SIZE];
    char ch;
    for (int i = 0; i < SIZE; i++)
    {
        lottery[i] = i + 1;
        orginal[i] = i + 1;
    }
    do
    {
        random_pick(lottery, SIZE, PICKS);
        puts("Again? >y");
        for (int i = 0; i < SIZE; i++)
        {
            lottery[i] = orginal[i];
        }
        ch = getchar();
        while(getchar() != '\n')
            continue;      
    } while (ch == 'y' || ch == 'Y');
    return 0;
}

void random_pick(int pt[], int size, int picks)
{
    int index, temp;
    srand((unsigned int) time(0));
    if (picks > size)
    {
        fputs("Number of picks > array size\n", stderr);
        fputs("Setting picks = array size\n", stderr);
        picks = size;
    }
    for (int i = 0; i < picks; i++)
    {
        index = rand() % size;
        temp = pt[index];
        printf("%2d ", temp);
        pt[index] = pt[size - 1];
        size--;
    }
    putchar('\n');
}