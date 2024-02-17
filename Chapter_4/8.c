#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#define GAL_Lit 3.785
int main(void)
{
	double len;
	double gas;
	const double m_km = 1.609;
	printf("Please the length of your travel\n");
	scanf("%lf", &len);
	printf("Please the gas you have used\n");
	scanf("%lf", &gas);
	printf("%.1fmile/gal\n", len / gas);
	printf("%.1fkm/L", len * m_km / (gas * GAL_Lit));
	return 0;
}