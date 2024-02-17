#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define BASICSALARY1 8.75
#define BASICSALARY2 9.33
#define BASICSALARY3 10.00
#define BASICSALARY4 11.20

int getChoice();
void showMenu();

int main(void) {
	double basicsalary = 0;
	int choice;
	while ((choice = getChoice()) != 5) {
		switch (choice)
		{
		case 1:basicsalary = BASICSALARY1;
			break;
		case 2:basicsalary = BASICSALARY2;
			break;
		case 3:basicsalary = BASICSALARY3;
			break;
		case 4:basicsalary = BASICSALARY4;
			break;
		default:printf("Program error!");
			break;
		}
	}

	return 0;
}

int getChoice() {
	int i;
	showMenu();
	scanf("%d", &i);
	while ((i < 1 || i>5)) {
		printf("Please respond with 1, 2, 3, 4, or 5.\n");
		scanf("%d", &i);
	}
	return i;
}

void showMenu() {
	for (int i = 0; i < 70; i++)
	{
		putchar('*');
	}
	putchar('\n');
	printf("Enter the number corresponding to the desired pay rate or action:\n");
	printf("1) $8.75/hr      2) $9.33/hr\n");
	printf("3) $10.00/hr     4) $11.20/hr\n");
	printf("5) quit\n");
	for (int i = 0; i < 70; i++)
	{
		putchar('*');
	}
	putchar('\n');
}