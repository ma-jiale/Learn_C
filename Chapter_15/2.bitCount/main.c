/*通过命令行参数读取两个二进制字符串，对两个二进制数
使用~运算符、&运算符、|运算符和^运算符，并以二进制字符串形式打印结果*/
#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
int bstr_to_dec(const char *str);
char *itobs(int n, char *ps);
int main(int argc, char *argv[])
{
    char value[CHAR_BIT * sizeof(int) + 1];
    int value1, value2;
    if (argc != 3)
    {
        fprintf(stderr, "Usage: %s binarynum1 binarynum2\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    value1 = bstr_to_dec(argv[1]);
    value2 = bstr_to_dec(argv[2]);
    printf("~%s = %s\n", argv[1], itobs(~value1, value));
    printf("~%s = %s\n", argv[2], itobs(~value2, value));
    printf("%s & %s = %s\n", argv[1], argv[2],
           itobs(value1 & value2, value));
    printf("%s | %s = %s\n", argv[1], argv[2],
           itobs(value1 | value2, value));
    printf("%s ^ %s = %s\n", argv[1], argv[2],
           itobs(value1 ^ value2, value));
    puts("Done");
    return 0;
}

int bstr_to_dec(const char *str)
{
    int val = 0;

    while (*str != '\0')
        val = 2 * val + (*str++ - '0');
    return val;
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