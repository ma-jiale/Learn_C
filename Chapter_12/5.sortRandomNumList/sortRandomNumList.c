#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 100

void sort_int(int* ptr, int size);
void print(const int array[], int limit);

int main()
{
    srand((unsigned int)time(0));
    
    int num[SIZE];
    for (int  i = 0; i < SIZE; i++)
    {
        num[i] = rand() % 10 + 1;
        //printf("%d\n", num[i]);
    }
    puts("the initial array");
    print(num, SIZE);
    sort_int(num, SIZE);
    puts("\nthe sorted array");
    print(num, SIZE);
    return 0;
}

//selection sort algorithm
//sorts an integer array in decreasing order
void sort_int(int* ptr, int size)
{
    int temp;
    int top, seek;
    for(top = 0; top < size - 1; top++)
    {
        for(seek = top + 1; seek < size; seek++)
        {
            if(ptr[top] > ptr[seek])
            {
                temp = ptr[top];
                ptr[top] = ptr[seek];
                ptr[seek] = temp;
            }
        }
    }
}

void print(const int array[], int limit)
{
 int index;
 for (index = 0; index < limit; index++)
 {
    printf("%2d ", array[index]);
    if (index % 10 == 9)
    putchar('\n');
 }
 if (index % 10 != 0) // if last line not complete
    putchar('\n');
}