#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#define LEN_NAME 10
#define EMPTY 0
#define TAKEN 1
#define SEATS 12

struct planestats
{
    int seat_id;
    bool status;
    struct
    {
        char first[LEN_NAME];
        char last[LEN_NAME];
    };
};

char show_menu();
void eatline();
int count_empties(struct planestats ar[], int seats);
void list_empties(struct planestats ar[], int seats);

int main()
{
    char choice;
    struct planestats plane_1[SEATS], *ps[SEATS];
    size_t size = sizeof(struct planestats);
    for (int i = 0; i < SEATS; i++)
        ps[i] = &plane_1[i];
    for (int i = 0; i < SEATS; i++)
    {
        plane_1[i].status = EMPTY;
        plane_1[i].seat_id = i + 1;
    }
    while ((choice = show_menu()) != 'f')
    {
        switch (choice)
        {
        case 'a':
            printf("There are %d empty seats\n", count_empties(plane_1, SEATS));
            break;
        case 'b':
            list_empties(plane_1, SEATS);
            break;
        case 'c':
            //show_seats();
            break;
        case 'd':
            //assign_seat();
            break;
        case 'e':
            //delete_seat();
            break;       
        }
    }
    
}

char show_menu()
{
    char ans;
    puts("To choose a function, enter its letter label:");
    puts("a) Show number of empty seats");
    puts("b) Show list of empty seats");
    puts("c) Show alphabetical list of seats");
    puts("d) Assign a customer to a seat assignment");
    puts("e) Delete a seat assignment");
    puts("f) Quit");
    ans = getchar();
    ans = tolower(ans);
    eatline();
    while(strchr("abcdef", ans) == NULL)
    {
        puts("Please enter a, b, c, d, e, or f:");
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

int count_empties(struct planestats ar[], int seats)
{
    int count;
    for ( count = 0; count < seats; count++)
    {
        if(ar[count].status == EMPTY)
            count++;
    }
    return count;
}

void list_empties(struct planestats ar[], int seats)
{
    int count;
    if(count_empties(ar, seats) == 0)
        puts("There is no empty seat");
    else
    {
        puts("list of empty seats:");
        for ( count = 0; count < seats; count++)
        {
            if (ar[count].status == EMPTY)
            {
                printf("%d ", ar[count].seat_id);
            }
        }
        putchar('\n');
    }
}