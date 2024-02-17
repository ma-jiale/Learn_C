////power.c 
//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//double power(double, int);
//
//int main(void) {
//	double x, xpow;
//	int exp;
//
//	printf("Enter a number and the integer power to which.\n");
//	printf("q to quit.\n");
//	while (scanf("%lf%d", &x, &exp) == 2)
//	{
//		xpow = power(x, exp);
//		printf("%.3g to the power %d is %.5g\n", x, exp, xpow);
//		printf("Enter next pair of numbers or q to quit!\n");
//	}
//	printf("Jope you enjoyed this power trip -- bye!\n");
//
//	return 0;
//}
//
//double power(double n, int p) {
//	double pow = 1;
//	if (n == 0) {
//		if (p == 0) {
//			printf("0 to the power 0 is not defined,so we return \n");
//			pow = 1;
//		}
//		else
//		{
//			pow = 0;
//		}
//	}
//	else {
//		if (p > 0) {
//			pow = n * power(n, p - 1);
//		}
//		else if (p < 0) {
//			pow = (1/n) * power(n, p + 1);
//		}
//		else
//		{
//			pow = 1;
//		}
//	}
//
//
//
//	return pow;
//
//}