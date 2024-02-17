//#include<stdio.h>
//#include<ctype.h>
//#include <stdbool.h> 
//
//int main() {
//	int num_upper = 0;
//	int num_lower = 0;
//	int num_word = 0;
//	int num_punct = 0;
//	int num_digit = 0;
//	char ch;
//	bool inword = false;
//	printf("Enter text to be analyzed (EOF to terminate):\n");
//	while ((ch = getchar()) != EOF) {
//		if (isupper(ch))
//			num_upper++;
//		if (islower(ch))
//			num_lower++;
//		if (ispunct(ch))
//			num_punct++;
//		if (isdigit(ch))
//			num_digit++;
//		if (!isspace(ch) && !inword)
//		{
//			inword = true; // starting a new word 
//			num_word++; // count word 
//		}
//		if (isspace(ch) && inword)
//			inword = false; // reached end of word
//	}
//	printf("The input has %d words, %d upper letters, %d lower letters, %d punctions, %d digits\n", num_word, num_upper, num_lower, num_punct, num_digit);
//	return 0;
//}