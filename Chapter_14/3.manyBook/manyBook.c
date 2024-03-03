/* manybook.c -- multiple book inventory */
#include <stdio.h>
#include <string.h>
char * s_gets(char * st, int n);
#define MAXTITL   40
#define MAXAUTL   40
#define MAXBKS   100              /* maximum number of books  */

struct book {                     /* set up book template     */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

int main(void)
{
    struct book library[MAXBKS]; /* array of book structures */
    struct book *ptrbk[100];
    int count = 0;
    int index;
    
    printf("Please enter the book title.\n");
    printf("Press [enter] at the start of a line to stop.\n");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL
           && library[count].title[0] != '\0')
    {   
        ptrbk[count] = &library[count];
        printf("Now enter the author.\n");
        s_gets(library[count].author, MAXAUTL);
        printf("Now enter the value.\n");
        scanf("%f", &library[count++].value);
        while (getchar() != '\n')
            continue;          /* clear input line         */
        if (count < MAXBKS)
            printf("Enter the next title.\n");
    }
    
    if (count > 0)
    {
        printf("Here is the list of your books:\n");
        /*按照图书输入顺序输出图书信息*/
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", library[index].title,
                   library[index].author, library[index].value);
        /*按照图书价格顺序输出图书信息*/
        struct book *temp;
        int top, seek;
        for (top = 0; top < count - 1; top++)
        {
            for(seek = top + 1; seek < count; seek++)
            {
                if(ptrbk[top]->value > ptrbk[seek]->value)
                {
                    temp = ptrbk[top];
                    ptrbk[top] = ptrbk[seek];
                    ptrbk[seek] = temp;
                }
            }
        }
        for (index = 0; index < count; index++)
            printf("%s by %s: $%.2f\n", ptrbk[index]->title,
                   ptrbk[index]->author, ptrbk[index]->value);
    }
    else
    	printf("No books? Too bad.\n");
    
    return 0;
}

char * s_gets(char * st, int n)
{
    char * ret_val;
    char * find;
    
    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n');   // look for newline
        if (find)                  // if the address is not NULL,
            *find = '\0';          // place a null character there
        else
            while (getchar() != '\n')
                continue;          // dispose of rest of line
    }
    return ret_val;
}
