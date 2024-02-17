#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define BASICSALARY1 8.75
#define BASICSALARY2 9.33
#define BASICSALARY3 10.00
#define BASICSALARY4 11.20
#define BASIC_TIME 40
#define RATE1 0.15
#define RATE2 0.2
#define RATE3 0.25
#define OVERTIME 1.5
#define AMT1 300
#define AMT2 450

char getChoice();
void showMenu();
char getFirst();
int main(void) {
	double basicsalary = 0;
	char choice;
	while ((choice = getChoice()) != 'q') {
		switch (choice)
		{
		case 'a':
		case 'A':basicsalary = BASICSALARY1;
			break;
		case 'b':
		case 'B':basicsalary = BASICSALARY2;
			break;
		case 'c':
		case 'C':basicsalary = BASICSALARY3;
			break;
		case 'd':
		case 'D':basicsalary = BASICSALARY4;
			break;
		default:printf("Program error!");
			break;
		}

		int t = 0;
		double pre_s = 0;
		double s = 0;

		printf("Enter the number of hours worked this week:\n");
		scanf("%d", &t);
			if (t <= BASIC_TIME)
			{
				pre_s = t * basicsalary;
			}
			else {
				pre_s = BASIC_TIME * basicsalary + (t - BASIC_TIME) * OVERTIME * basicsalary;
				//printf("%f\n", pre_s);
			}

			if (pre_s <= AMT1)
			{
				s = pre_s * (1 - RATE1);
			}
			else if (pre_s > AMT1 && pre_s <= AMT2)
			{
				s = AMT1 * (1 - RATE1) + (pre_s - AMT1) * (1 - RATE2);
			}
			else if (pre_s > AMT2)
			{
				s = AMT1 * (1 - RATE1) + (pre_s - AMT1) * (1 - RATE2) + (pre_s - AMT2) * (1 - RATE3);
			}
			printf("Your salary is %.2lf\n", s);
			while (getchar() != '\n');
			continue;
	}
	printf("Done.\n");
	return 0;
}

char getChoice() {
	char ch;
	showMenu();
	ch = getFirst();
	while (((ch < 'A' || ch > 'd') || (ch > 'D' && ch < 'a')) && (ch != 'q')) {
		printf("Please respond with a, b, c, d, or q.\n");
		ch = getFirst();
	}
	return ch;
}

void showMenu() {
	for (int i = 0; i < 70; i++)
	{
		putchar('*');
	}
	putchar('\n');
	printf("Enter the number corresponding to the desired pay rate or action:\n");
	printf("a) $8.75/hr      b) $9.33/hr\n");
	printf("c) $10.00/hr     d) $11.20/hr\n");
	printf("q) quit\n");
	for (int i = 0; i < 70; i++)
	{
		putchar('*');
	}
	putchar('\n');
}

char getFirst() {
	char ch;
	ch = getchar();
	while (getchar() != '\n')/* skip over newlines */
		continue;
	return ch;
}