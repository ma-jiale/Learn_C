#include <stdio.h>
#include <stdlib.h>    /* prototype for exit() */
#include "stack.h"      /* defines List, Item   */

int main()
{
    Item temp;
    Stack string;
    InitializeStack(&string);
    puts("Please enter a string");
    while (!StackIsFull(&string) && (temp = getchar()) != EOF)
        push(temp,&string);
    while(!StackIsEmpty(&string))
    {
        pop(&temp, &string);
        putchar(temp);
    }
    puts("Done!");
    return 0;
}