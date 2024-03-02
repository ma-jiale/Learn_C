#include<stdio.h>
#include<string.h>
#include<stdbool.h>

#define MONTH_NUM 12
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
char* s_gets(char* st, int n);

int main()
{
    char line[10];
    bool month_is_found = false;
    int month;
    puts("Please enter a month");
    while (s_gets(line, 10) != NULL && line[0] != '\0')
    {
        for (month = 1; month <= MONTH_NUM; month++)
        {
            if (strcmp(line, year[month-1].name) == 0)
            {
                month_is_found = true;
                break;
            }
        }
        if(month_is_found)
        {
            printf("Total number of days in the year to %s is %d\n", 
                year[month-1].name, calculate_days(month));
        }
        else
            printf("Can't find this month\n");
        puts("Please enter next month");
    }
    puts("Goodbye!");
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

char* s_gets(char* st, int n)
{
	char* ret_val;
	char* find;

	ret_val = fgets(st, n, stdin);
	if (ret_val)
	{
		find = strchr(st, '\n');    // look for newline
		if (find)                   // if the address is not NULL,
			*find = '\0';           // place a null character there
		else
			while (getchar() != '\n')
				continue;
	}
	return ret_val;
}