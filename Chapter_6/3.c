//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//	int i;
//	char ch;
//	for ( i = 1; i <=6; i++)
//	{
//		for (ch = 70; ch > 70-i; ch--)
//		{
//			printf("%c", ch);
//		}
//		printf("\n");
//	}
//	return 0;
//}

///* pe6-3.c */
///* this implementation assumes the character codes */
///* are sequential, as they are in ASCII. */
//#include <stdio.h>
//int main(void)
//{
//	char let = 'F';
//	char start;
//	char end;
//
//	for (end = let; end >= 'A'; end--)
//	{
//		for (start = let; start >= end; start--)
//			printf("%c", start);
//		printf("\n");
//	}
//
//	return 0;
//}