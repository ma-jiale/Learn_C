#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main() {
	const double price_artichokes = 2.05;
	const double price_beets = 1.15;
	const double price_carrots = 1.09;

	const double DISCOUNT_RATE = 0.05;

	const double under5 = 6.50;
	const double under20 = 14.00;
	const double base20 = 14.00;
	const double extralb = 0.50;

	double lb_artichokes = 0;
	double lb_beets = 0;
	double lb_carrots = 0;
	double lb_temp;
	double lb_sum = 0;
	

	char ch;
	double price_sum;
	double price_ex = 0;
	double discount = 0;
	printf("enter a to buy artichokes,b for beets,c for carrots,q to quit\n");
	while (scanf(" %c",&ch) == 1 && ch != 'q')
	{
		switch (ch)
		{
		case'a':
			printf("enter pounds of artichokes: \n");
			scanf("%lf", &lb_temp);
			lb_artichokes += lb_temp;
			break;
		case'b':
			printf("enter pounds of beets: \n");
			scanf("%lf", &lb_temp);
			lb_beets += lb_temp;
			break;
		case'c':
			printf("enter pounds of carrots: \n");
			scanf("%lf", &lb_temp);
			lb_carrots += lb_temp;
			break;
		}

		printf("enter a to buy artichokes,b for beets,c for carrots,q to quit\n");
	}
	//printf("you have bought %.2lf pounds artichokes, %.2lf pounds beets, and %.2lf pounds carrots\n", lb_artichokes, lb_beets,lb_carrots);
	lb_sum = lb_artichokes + lb_beets + lb_carrots;
	price_sum = lb_artichokes * price_artichokes + lb_beets * price_beets + lb_carrots * price_carrots;
	if (price_sum >= 100)
	{
		discount = price_sum * DISCOUNT_RATE;
		price_sum -= discount;
	}
	if (lb_sum <= 5)
	{
		price_ex = under5;
	}
	else if (lb_sum <= 20) {
		price_ex = under20;
	}
	else {
		price_ex = base20 + extralb * (lb_sum - 20);
	}

	if (lb_artichokes > 0)
	{
		printf("artichokes $%lf/pound\n", price_artichokes);
		printf("the pounds you bought: %lf\n", lb_artichokes);
	}	
	if (lb_beets > 0)
	{
		printf("beets $%lf/pound\n", price_beets);
		printf("the pounds you bought: %lf\n", lb_beets);
	}
	if (lb_carrots > 0)
	{
		printf("carrots $%lf/pound\n", price_carrots);
		printf("the pounds you bought: %lf\n", lb_carrots);
	}
	printf("Total cost of vegetables: $%lf\n", price_sum);
	
	if (discount > 0) {
		printf("your discount is $%lf\n", discount);
	}
	printf("shipping: $%lf\n", price_ex);
	printf("Total charges:$%lf\n", price_sum + price_ex);
	return 0;
}