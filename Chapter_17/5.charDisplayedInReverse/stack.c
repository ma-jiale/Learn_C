#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

void InitializeStack(Stack * ps)
{
    ps->bottom = ps->top = NULL;
    ps->items = 0;
}

bool StackIsEmpty(const Stack *ps)
{
    return ps->items == 0;
}

bool StackIsFull(const Stack *ps)
{
    return ps->items == MAXSTACK;
}

unsigned int StackItemCount(const Stack *ps)
{
    return ps->items;
}

bool push(Item item, Stack * ps)
{
    if (StackIsFull(ps))
        return false;
    
    Node * newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
        return false;

    newNode->item = item;
    
    
    if (StackIsEmpty(ps))
    {
        ps->bottom = newNode;
        newNode->before = NULL;
    }
    else
    {
        newNode->before = ps->top;
    }
    ps->top = newNode;
    ps->items++;
    
    return true;
}

bool pop(Item * pitem, Stack * ps)
{
    if (StackIsEmpty(ps))
        return false;

    *pitem = ps->top->item;
    Node * temp = ps->top;
    if(ps->top->before != NULL)
        ps->top = ps->top->before;
    free(temp);

    if (StackIsEmpty(ps))
        ps->bottom = NULL;
    
    ps->items--;
    
    return true;
}

void EmptyTheStack(Stack * ps)
{
    Item dummy;
    while (!StackIsEmpty(ps))
        pop(&dummy, ps);
    free(dummy);
}
