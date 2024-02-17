#include<stdio.h>
int main(void)
{
	int a = 2000000000;
	float b = 1.234567E42;
	int toobig_int = a*2;
	float toobig_float = b*10;
	float c;
	printf("%d\n",toobig_int);
	printf("%f\n",toobig_float);
	return 0;
}