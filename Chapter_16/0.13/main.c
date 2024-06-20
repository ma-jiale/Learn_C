/*假设scores是内含1000个int类型元素的数组，要按降序排序该数组的值*/
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define SIZE 1000
int comp(const void*, const void*);
void fillarray(int *array, int size);
void showarray(const int *array, int size);

int main(void)
{
    int scores[1000];
    srand(time(NULL));// 初始化随机数生成器
    puts("random list\n");
    fillarray(scores, SIZE);
    showarray(scores, SIZE);
    qsort(&scores, SIZE, sizeof(int), comp);
    puts("\nsorted list");
    showarray(scores, SIZE);
    return 0;
}

int comp(const void* p1, const void* p2)
{
    const int* a1 = (const int*)p1;
    const int* a2 = (const int*)p2;
    if(*a1 > *a2)
        return 1;
    else if(*a1 < *a2)
        return -1;
    else
        return 0;
}

void fillarray(int *array, int size)
{
    for(int i = 0; i < size; i++) {
        array[i] = rand() % 1001;  // 生成0到1000范围内的随机数
    }
}

void showarray(const int *array, int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", array[i]);
        if ((i + 1) % 20 == 0) {  // 每20个元素换行
            printf("\n");
        }
    }
    if (size % 20 != 0) {  // 如果最后一行元素不足20个，手动换行
        printf("\n");
    }
}