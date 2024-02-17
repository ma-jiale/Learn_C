//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//	char current = 'A';
//	char enterchar;
//	int row;
//	scanf("%c", &enterchar);
//	row = (int)enterchar - 64;
//	for (int i = 1; i  <= row ; i ++)
//	{
//		for (int j = 26; j >= i; j--)
//		{
//			printf(" ");
//		}
//		current = 'A';
//		for (int j = 0; j < i; j++)
//		{
//			printf("%c", current++);
//		}
//
//		for (int j = 0; j < i-1; j++)
//		{
//			printf("%c", --current);
//		}
//
//		printf("\n");
//	}
//	return 0;
//}