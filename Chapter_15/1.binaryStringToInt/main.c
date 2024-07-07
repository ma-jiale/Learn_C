/*编写一个把二进制字符串转换为一个数值的函数*/
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h> // C99 -- otherwise use int
#include <limits.h> // for CHAR_BIT

int bstoi(const char *pt);
int main(void)
{
    printf("%d\n", bstoi("00010101"));
    return 0;
}

int bstoi(const char *pt)
{
    int res = 0;
    int size = strlen(pt);
    for (int i = size; i > 0; i--)
    {
        if (pt[i - 1] == '1')
            res += pow(2, size - i);
    }
    return res;
}

/*答案示例*/
int bstr_to_dec(const char *str)
{
    int val = 0;

    while (*str != '\0')
        val = 2 * val + (*str++ - '0');
    return val;
}