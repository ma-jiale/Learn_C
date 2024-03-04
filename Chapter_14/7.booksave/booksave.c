/*待改进的地方：
    1.应通过查找书名来修改或删除书籍
    2.将展示书籍封装成函数
    3.更友好的交互
    4.从文件中读取数据的方式待改进
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10 /* maximum number of books */

struct book
{ /* set up book template    */
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
    bool state;
};
char show_menu();
void eatline();
int delete_books(struct book ar[], int size);
void update_books(struct book ar[], int size);
int add_books(struct book ar[], int size);
char *s_gets(char *st, int n);
int main(void)
{
    struct book library[MAXBKS]; /* array of structures     */
    int count = 0;
    int index, filecount;
    char choice;
    FILE *pbooks;
    int size = sizeof(struct book);
    for (int i = 0; i < MAXBKS; i++)
    {
        library[i].state = false;
    }
    

    if ((pbooks = fopen("book.dat", "r+b")) == NULL)
    {
        fputs("Can't open book.dat file\n", stderr);
        exit(EXIT_FAILURE);
    }
    /*显示储存在文件中的书本记录*/
    rewind(pbooks); /* go to start of file     */
    index = 0;
    while (index < MAXBKS && fread(&library[index], size,
                                   1, pbooks) == 1)
    {
        if (count == 0)
            puts("Current contents of book.dat:");
        if(library[index].state == true)
        {
            printf("%d. %s by %s: $%.2f\n", count + 1, library[index].title,
                library[index].author, library[index].value);
            count++;
        }
        index++;
    }

    filecount = count;
    if (count == MAXBKS)
    {
        fputs("The book.dat file is full.", stderr);
        exit(2);
    }
    while ((choice = show_menu()) != 'e')
    {
        switch (choice)
        {
        case 'a':
            count += add_books(library, MAXBKS);
            break;
        case 'm':
            update_books(library, MAXBKS);
            break;
        case 'd':
            count -= delete_books(library, MAXBKS);
            break;           
        }
    }

        /*显示所有的书本记录*/
    if (count > 0)
    {
        puts("Here is the list of your books:");
        for (index = 0; index < MAXBKS; index++)
        {
            if (library[index].state == true)
            {
                printf("%d. %s by %s: $%.2f\n", index + 1, library[index].title,
                    library[index].author, library[index].value);
                
            }
            
        }
        rewind(pbooks);
        fwrite(library, size, MAXBKS, pbooks);
    }
    else
        puts("No books? Too bad.\n");
    puts("Bye.\n");
    fclose(pbooks);
    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val)
    {
        find = strchr(st, '\n'); // look for newline
        if (find)                // if the address is not NULL,
            *find = '\0';        // place a null character there
        else
            while (getchar() != '\n')
                continue; // dispose of rest of line
    }
    return ret_val;
}

char show_menu()
{
    char ans;
    puts("Enter menu choice:");
    puts("a) add new books      m) modify books");
    puts("d) delete books       e) exit");
    ans = getchar();
    ans = tolower(ans);
    eatline();
    while(strchr("amde", ans) == NULL)
    {
        puts("Please enter a, m, d, or e:");
        ans = getchar();
        ans = tolower(ans);
        eatline();
    }
    return ans;
}

void eatline()
{
    while(getchar() != '\n')
        continue;
}

int delete_books(struct book ar[], int size)
{
    int num;
    int count = 0;
    puts("Enter the number of book you want to delete:");
    puts("Press [enter] at the start of a line to stop.");
    while (scanf("%d", &num) == 1 && num != 0)
    {
        if (num <= size && num > 0)
        {
            ar[num-1].state = false;
            printf("delete %s successfully!",ar[num-1].title);
            count++;
        }
        else
        {
            puts("Can't find this book!");
        }
        puts("Enter the number of book you want to delete:");
        puts("Press [enter] at the start of a line to stop.");
    }
    return count;
}

void update_books(struct book ar[], int size)
{
    int num;
    puts("Enter the number of book you want to modify:");
    puts("Press [enter] at the start of a line to stop.");
    while (scanf("%d", &num) == 1 && num != 0)
    {
        eatline();
        if (num <= size)
        {
            puts("Please enter new book titles.");
            s_gets(ar[num - 1].title, MAXTITL);
            puts("Now enter the author.");
            s_gets(ar[num - 1].author, MAXAUTL);
            puts("Now enter the value.");
            scanf("%f", &ar[num - 1].value);
            while (getchar() != '\n')
                continue; /* clear input line  */
        }
        else
        {
            puts("Can't find this book!");
        }
        puts("Enter the number of book you want to modify:");
        puts("Press [enter] at the start of a line to stop.");
    }
    eatline();
}

int add_books(struct book ar[], int size)
{
    int num = 0;
    int count = 0;
    for (num = 0; num < size; num++)
    {
        if(ar[num].state == false)
        {
            puts("Please add new book titles.");
            puts("Press [enter] at the start of a line to stop.");
            if (s_gets(ar[num].title, MAXTITL) && ar[num].title[0] != '\0' )
            {
                puts("Now enter the author.");
                s_gets(ar[num].author, MAXAUTL);
                puts("Now enter the value.");
                scanf("%f", &ar[num].value);
                while (getchar() != '\n')
                    continue; /* clear input line  */
                ar[num].state = true;
                count++;
            }
            else
                break;
        }
        
    }
    return count;
}
