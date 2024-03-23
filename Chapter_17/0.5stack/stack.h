/*
栈ADT

类型名：    栈
类型属性：  可以存储一系列项  
类型操作：  初始化栈为空
            确定栈为空
            确定栈已满
            确定栈中的项数
            在栈的末尾添加项
            在栈的末尾删除项
            清空栈
*/

#ifndef _STACK_H_
#define _STACK_H_
#include<stdbool.h>

typedef SONETHING Item;

#define MAXSTACK 10

typedef struct node
{
    Item item;
    struct node * next;
}Node;

typedef struct stack
{
    Node * front;
    Node * rear;
    int items;
}Stack;

/*操作：    初始化栈        */
/*前提条件  ps指向一个栈    */
/*后置条件  栈被初始化为空*/
void InitializeStack(Stack * ps);

/* operation:        determine if stack is empty                 */
/*                   pstack points to an initialized stack        */
/* postconditions:   function returns True if stack is empty     */
/*                   and returns False otherwise                */
bool StackIsEmpty(const Stack *ps);

/* operation:        determine if stack is full                  */
/*                   pstack points to an initialized stack        */
/* postconditions:   function returns True if stack is full      */
/*                   and returns False otherwise                */
bool StackIsFull(const Stack *ps);

/* operation:        determine number of items in stack          */
/*                   pstack points to an initialized stack        */
/* postconditions:   function returns number of items in stack   */
unsigned int StackItemCount(const Stack *ps);

/*操作：    在栈的末尾添加项                    */
/*前提条件  ps指向被初始化的栈                  */
/*         item是要被添加在末尾的项            */
/*后置条件  如果栈不为满，item将被添加到栈的末尾*/
bool AddItem(Item item, Stack * ps);

/*操作：    在栈的末尾删除项                    */
/*前提条件  ps指向被初始化的栈                  */
/*后置条件  如果栈不为空，栈末尾的item将被复制到*pitem
            中并删除，且函数返回true;           
            如果该操作使得栈为空，则重置栈为空
            如果栈在操作前为空，该函数返回false   */
bool DeItem(Item * pitem, Stack * ps);

/* operation:        free allocated memory, if any              */
/*                   pstack points to an initialized stack        */
/* postconditions:   any memory allocated for the stack is freed */
/*                   and the stack is set to empty               */
void EmptyTheStack(Stack * ps);

#endif