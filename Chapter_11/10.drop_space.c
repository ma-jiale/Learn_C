//#include<stdio.h>
//#include<string.h>
//#define LEN 81
//
//void drop_space(char* ps);
//char* s_gets(char* st, int n);
//
//int main(void)
//{
//	char orig[LEN];
//
//	puts("Enter a string of 80 characters or less:");
//	while (s_gets(orig, LEN) && orig[0] != '\0')
//	{
//		drop_space(orig);
//		puts(orig);
//		puts("Enter next string (or just Enter to quit):");
//	}
//	puts("Bye!");
//	return 0;
//}
//
//void drop_space(char* ps) {
//	char* find;
//	while (*ps) {
//		if (*ps == ' ') {
//			find = ps;
//
//			while (*find) {
//				*find = *(find + 1);
//				find++;
//			}
//		}
//		ps++;
//	}
//}
//
//char* s_gets(char* st, int n)
//{
//	char* ret_val;
//	char* find;
//
//	ret_val = fgets(st, n, stdin);
//	if (ret_val)
//	{
//		find = strchr(st, '\n'); // look for newline
//		if (find) // if the address is not NULL,
//			*find = '\0'; // place a null character there
//		else
//			while (getchar() != '\n')
//				continue;
//	}
//	return ret_val;
//}