/*两个数的调和平均数这样计算：先得到两数的倒数，然后计算两个倒数的 平均值，最后取计算结果的倒数。
使用#define指令定义一个宏“函数”，执行该运算。编写一个简单的程序测试该宏*/
#include<stdio.h>
#define HARMONIC_MEAN(X, Y) (2.0 * (X) * (Y) / ((Y) + (X)))

int main()
{
    double x = 1.0;
    double y = 2.0;
    printf("the harmonic mean of x and y is %f", HARMONIC_MEAN(x, y));
    return 0;
}