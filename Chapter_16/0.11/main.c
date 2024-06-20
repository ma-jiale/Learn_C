/*11.创建一个使用泛型选择表达式的宏，如果宏的参数是_Bool类型，对"boolean"求值，否则对"not boolean"求值。*/
#include<stdio.h>
#include<stdbool.h>
#define ISBOOL(X) _Generic((X), _Bool: #X" is boolean", default: #X" is not boolean")
int main()
{
    _Bool d = true;
    int x = 23;
    printf("%s\n", ISBOOL(d));
    printf("%s\n", ISBOOL(x));
    return 0;
}