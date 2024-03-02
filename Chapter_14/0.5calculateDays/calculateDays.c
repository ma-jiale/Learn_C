#include<stdio.h>

struct month{
    char name[10];
    char abb[4];
    int days;
    int num;
};
struct month year[12] = {
    {"January", "Jan", 31, 1},
    {"February", "Feb", 28, 2},
    {"March", "Mar", 31, 3},
    {"April", "Apr", 30, 4},
    {"May", "May", 31, 5},
    {"June", "Jun", 30, 6},
    {"July", "Jul", 31, 7},
    {"Augest", "Aug", 31, 8},
    {"September", "Sep", 30, 9},
    {"October", "Oct", 31, 10},
    {"November", "Nov", 30, 11},
    {"December", "Dec", 31, 12}
};
int calculate_days(int num);

int main()
{
    int num = 0;
    puts("please enter a  number of a month");
    while (scanf("%d", &num) != NULL)
    {
        printf("Total number of days in the year to %s is %d\n", 
            year[num-1].name, calculate_days(num));
        puts("please enter a  number of a month");
    }
    return 0;
}

int calculate_days(int num)
{
    int ans = 0;
    for (int i = 0; i < num; i++)
    {
        ans += year[i].days;
    }
    return ans;
}