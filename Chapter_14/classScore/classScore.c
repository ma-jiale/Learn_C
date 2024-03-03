#include<stdio.h>
#include<string.h>
#define SCORES 3
#define SIZE 4
#define NAMELEN 10
struct name
{
    char first_name[NAMELEN];
    char last_name[NAMELEN];
};
struct student
{
    struct name person;
    double grade[SCORES];
    double average;
};

void get_scores(struct student *pst, int size);
void find_mean(struct student ar[], int size);
void show_class(struct student ar[], int size);
void show_ave(struct student ar[], int size);
int main()
{
    struct student CSIZE[SIZE] = {
        {"Flip", "Snide"},
        { "Clare", "Voyans"},
        {"Bingo", "Higgs"},
        { "Fawn", "Hunter"}
    };
    get_scores(CSIZE, SIZE);
    find_mean(CSIZE, SIZE);
    show_class(CSIZE, SIZE);
    show_ave(CSIZE, SIZE);
    return 0;
}

void get_scores(struct student ar[], int size)
{
    char name[NAMELEN];
    int count;
        for (count  = 0; count < size; count++)
        {
            printf("Please enter %d scores for %s %s\n", SCORES, ar[count].person.first_name, 
            ar[count].person.last_name);
                for (int i = 0; i < SCORES; i++)
                {
                    printf("Enter %d score: ", i+1);
                    scanf("%lf", &(ar[count].grade[i]));
                }
        }
}

void find_mean(struct student ar[], int size)
{
    int count;
    double sum;
    for (count  = 0; count < size; count++)
    {
        sum = 0;
        for (int i = 0; i < SCORES; i++)
        {
            sum += ar[count].grade[i];
        }
        ar[count].average = sum / SCORES;
    }
}

void show_class(struct student ar[], int size)
{
    int count;
    puts("    name    grade1  grade2  grade3  average grade");
    for (count  = 0; count < size; count++)
    {
        printf("%s %-6s  %.2f  %.2f  %.2f     %.2f\n", ar[count].person.first_name, 
        ar[count].person.last_name, ar[count].grade[0], ar[count].grade[1], 
        ar[count].grade[2], ar[count].average);
    }
}

void show_ave(struct student ar[], int size)
{
    double classSum = 0;
    int count;
    for (count  = 0; count < size; count++)
    {
        classSum += ar[count].average;
    }
    printf("class average grade: %.2f\n", classSum / size);
}