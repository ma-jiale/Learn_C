#include <stdio.h>
#include <string.h>
#include <ctype.h>
char Toupper(char);
char Tolower(char);
char show_menu();
void eatline();
int main()
{
    char choice;
    char demo;
    char (*pf)(char);
    puts("Enter a letter");
    demo = getchar();
    eatline();
    while ((choice = show_menu()) != 'q')
    {
        switch (choice)
        {
        case 'a':
            pf = Toupper;
            break;
        case 'b':
            pf = Tolower;
            break;
        }
        demo = (*pf)(demo);
        putchar(demo);
        putchar('\n');
    }

    return 0;
}

char show_menu()
{
    char ans;
    puts("Enter menu choice:");
    puts("a) Toupper      b) Tolower");
    puts("q) quit");
    ans = getchar();
    ans = tolower(ans);
    eatline();
    while (strchr("abq", ans) == NULL)
    {
        puts("Please enter a, b or q:");
        ans = getchar();
        ans = tolower(ans);
        eatline();
    }
    return ans;
}

void eatline()
{
    while (getchar() != '\n')
        continue;
}

char Toupper(char ch) 
{
    ch = toupper(ch);
    return ch;
}

char Tolower(char ch) 
{
    ch = tolower(ch);
    return ch;
}