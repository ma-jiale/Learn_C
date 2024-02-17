#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#define BASICSALARY 10.00
#define BASIC_TIME 40
#define RATE1 0.15
#define RATE2 0.2
#define RATE3 0.25
#define OVERTIME 1.5
#define AMT1 300
#define AMT2 450

int main()
{
	int t = 0;
	double pre_s = 0;
	double s = 0;

	printf("enter your time\n");
	while (scanf("%d",&t) == 1)
	{
		if (t <= BASIC_TIME)
		{
			pre_s = t * BASICSALARY;
		}
		else{
			pre_s = BASIC_TIME * BASICSALARY + (t - BASIC_TIME) * OVERTIME * BASICSALARY;
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
		else if(pre_s > AMT2)
		{
			s = AMT1 * (1 - RATE1) + (pre_s - AMT1) * (1 - RATE2) + (pre_s - AMT2) * (1 - RATE3);
		}
		printf("Your salary is %.2lf\n", s);
		printf("Enter your time\n");
	}

	return 0;
}