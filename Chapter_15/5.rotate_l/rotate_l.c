/*编写一个函数，把一个unsigned int类型值中的所有位向左旋转指定数量的位*/
#include <stdio.h>
#include <limits.h>
char *itobs(unsigned int n, char *ps);
unsigned int rotate_l(unsigned int n, unsigned int bits);

int main()
{
    char bstr[CHAR_BIT * sizeof(int) + 1];
    char res_bstr[CHAR_BIT * sizeof(int) + 1];
    unsigned int value, res;
    unsigned int bits;
    puts("Please enter a unsigned integer and the bits you want to rotate");
    while (scanf("%u %u", &value, &bits) == 2)
    {
        res = rotate_l(value, bits);
        printf("%u(%s) has been rotated is %u(%s)\n", value, itobs(value, bstr), res, itobs(res, res_bstr));
        puts("Please enter next unsigned integer and the bits you want to rotate");
    }
    puts("Done!");
    return 0;
}

unsigned int rotate_l(unsigned int n, unsigned int bits)
{
    const static int size = CHAR_BIT * sizeof(int);
    unsigned int mask, n_copy;
    unsigned int bitval = 1;
    n_copy = n;
    unsigned int bits_copy = bits;
    while (bits-- > 0)
    {
        mask |= bitval;
        bitval <<= 1;
    }
    for (int i = size; i > 0; i--, n_copy >>= 1)
    {
        if (i == bits_copy)
        {
            mask &= n_copy;
            break;
        }
    }
    n <<= bits_copy;
    n |= mask;
    return n;
}

/*答案示例*/
unsigned int rotate_l(unsigned int n, unsigned int b)
{
 static const int size = CHAR_BIT * sizeof(int);
 unsigned int overflow;
 
 b %= size; /* keep b a valid value */
 
 overflow = n >> (size - b); /* save bits that are shifted out */
 return (n << b) | overflow;
}

char *itobs(unsigned int n, char *ps)
{
    const static int size = CHAR_BIT * sizeof(int);
    for (int i = size - 1; i >= 0; i--, n >>= 1)
    {
        ps[i] = (01 & n) + '0';
    }
    ps[size] = '\0';
    return ps;
}