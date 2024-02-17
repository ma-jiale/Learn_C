#include<stdio.h>

void jolly(void);//函数原型
void deny(void);

int main(void)
{
	jolly();//调用函数
	jolly();
	jolly();
	deny();
	return 0;
}

void jolly(void)
{
	printf("For he's a jolly good fellow!\n");
}

void deny(void)
{
	printf("Which nobody can deny!\n");
}