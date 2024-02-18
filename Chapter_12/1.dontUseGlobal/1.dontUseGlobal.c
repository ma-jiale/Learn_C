#include<stdio.h>
void critic(int*);
int main()
{
    int units = 0;//use local variable56
    printf("How many pounds to a firkin of butter?\n");
    scanf("%d", &units);
    while (units != 56)
    {
        critic(&units);
    }
    printf("You must have looked it up!\n");
    return 0;
}

void critic(int* ptr)
{
    printf("No luck, my friend. Try again.\n");
    scanf("%d",ptr);
}