/*编写一个函数，接受一个int类型的参数，并返回该参数中打开位的数量。*/
#include <stdio.h>
#include <limits.h>

char *itobs(int n, char *ps);
int onbits(int x);
int main()
{
    char bstr[CHAR_BIT*sizeof(int)+1];
    int value;
    puts("Please enter a integer");
    while (scanf("%d", &value) == 1)
    {
        printf("%d(%s) has %d bits which is 1\n", value, itobs(value, bstr), onbits(value));
        puts("next integer:");
    }
    puts("Done!");
    return 0;
}

int onbits(int x)
{
    static const int size = CHAR_BIT * sizeof(int);
    int n;
    for (int i = 0; i < size; i++)
    {
        if (x & 01)
            n++;
        x >>= 1;
    }
    return n;
}

char *itobs(int n, char *ps)
{
    const static int size = CHAR_BIT * sizeof(int);
    for (int i = size - 1; i >= 0; i--, n >>= 1)
    {
        ps[i] = (01 & n) + '0';
    }
    ps[size] = '\0';
    return ps;
}