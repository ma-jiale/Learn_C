//#include<stdio.h>
//#define LEN 10
//char* getNChar(char*,int);
//
//int main(void) {
//	char input[LEN];
//	char* check;
//
//	check = getNChar(input, LEN - 1);
//	if (check == NULL)
//		puts("Input failed.");
//	else
//		puts(input);
//	puts("Done.\n");
//
//	return 0;
//}
//char* getNChar(char* ps,int n) {
//	int ch = 0;
//	int i;
//
//	for (i = 0; i < n; i++)
//	{
//		ch = getchar();
//		if (ch != EOF) {
//			ps[i] = ch;
//		}
//		else {
//			break;
//		}
//	}
//	if (ch == EOF) {
//		return NULL;
//	}
//	else {
//		ps[i] = '\0';
//		return ps;
//	}
//}