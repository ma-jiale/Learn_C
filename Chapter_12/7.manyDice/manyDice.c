#include <stdio.h>
#include <stdlib.h> /* for srand() */
#include <time.h> /* for time() */
int rollem(int);
int main(void)
{
    int dice, count, roll;
    int sides;
    int set, sets;
 
    srand((unsigned int) time(0)); /* randomize rand() */
 
    printf("Enter the number of sets; enter q to stop: ");
    while (scanf("%d", &sets) == 1)
    {
        printf("How many sides and how many dice? ");
        if (scanf("%d %d", &sides, &dice) != 2)
        {
            puts("not integers -- terminating input loop.");
            break;
        }
        printf("Here are %d sets of %d %d-sided throws.\n", sets, dice, sides);
        for (int i = 0; i < sets; i++)
        {
            int sum = 0;
            for (int i = 0; i < dice; i++)
            {
                sum += rollem(sides);
            }
            printf("%4d", sum);
        }
        putchar('\n');
        printf("How many sets? Enter q to stop: ");
    }
    puts("GOOD FORTUNE TO YOU!\n");
    return 0;
}

int rollem(int sides)
{
 int roll;
 roll = rand() % sides + 1;
 return roll;
}