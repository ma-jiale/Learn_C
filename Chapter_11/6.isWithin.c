//#include<stdio.h>
//
//int is_within(char ch, char* ps);
//char* s_gets(char* st, int n);
//
//int main() {
//	char input[20];
//	char ch;
//	int found;
//	printf("Enter a string: ");
//	while (s_gets(input, 20) && input[0] != '\0') {
//		printf("Enter a character: ");
//		ch = getchar();
//		while (getchar() != '\n')
//			continue;
//		found = is_within(ch,input);
//		if (found == 0)
//			printf("%c not found in string.\n", ch);
//		else
//			printf("%c found in string %s\n", ch, input);
//		printf("Next string: ");
//	}
//	puts("Done.\n");
//	return 0;
//}
//
//int is_within(char ch, char* ps) {
//	int i = 0;
//	while (*ps) {
//		if (ch == *ps) {
//			i = 1;
//			break;
//		}
//		ps++;
//	}
//	return i;
//}
//
//char* s_gets(char* st, int n) {
//	char* ret_val;
//
//	ret_val = fgets(st, n, stdin);
//	if (ret_val) {
//		while (*st != '\n' && *st != '\0')
//			st++;
//		if (*st == '\n')
//			*st = '\0';
//		else
//			while (getchar() != '\n')
//				continue;
//	}
//	return ret_val;
//}