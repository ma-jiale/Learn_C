//#include<stdio.h>
//int main() {
//	int high = 100;
//	int low = 1;
//	int guess = 50;
//	char response;
//
//	printf("Pick an integer from 1 to 100. I will try to guess ");
//	printf("it.\nRespond with a y if mu guess is right and with");
//	printf("\nan n if it is wrong.\n");
//	printf("Uh...is your number %d?\n", guess);
//	while ((response = getchar()) != 'y') {
//
//		if (response == 'n') {
//
//			while (getchar() != '\n')
//				continue;
//			printf("Is it higher or lower than %d?(Please respond h or l)\n", guess);
//
//			if ((response = getchar()) != 'h' && response  != 'l')
//			{
//
//			}
//			if (response == 'l') {
//				high = guess - 1;
//				guess = (high + low) / 2;
//				printf("Well, then, is it %d?\n", guess);
//			}
//			else if(response == 'h') 
//			{
//				low = guess + 1;
//				guess = (high + low) / 2;
//				printf("Well, then, is it %d?\n", guess);
//			}
//		}
//		else {
//			printf("Sorry, I understand only y or n.\n");
//		}
//
//		while (getchar() != '\n')
//			continue;
//	}
//	printf("I knew i could do it!\n");
//
//	return 0;
//}