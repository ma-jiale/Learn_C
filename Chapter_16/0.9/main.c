/*6.编写一段代码，如果定义了PR_DATE宏，则打印预处理的日期*/
#include<stdio.h>
#define PR_DATE printf("The date is %s.\n", __DATE__)
int main()
{
    #ifdef PR_DATE
    PR_DATE;
    #endif
    return 0;
}
