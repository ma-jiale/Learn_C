//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//int main(void)
//{
//	char let = 'A';
//	char start;
//	char end;
//	int i;
//	
//	for (i = 1,end = let,start = let;end <= 'U'; end = end + (++i))
//	{
//		for (; start <= end; start++)
//		{
//			printf("%c", start);
//		}
//		printf("\n");
//	}
//	return 0;
//}

//chatgpt的答案
//#include <stdio.h>
//
//int main() {
//    int rows = 6;  // 指定行数
//    int currentChar = 65;  // ASCII码中 'A' 的值
//
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; j <= i; j++) {
//            printf("%c", currentChar);
//            currentChar++;
//        }
//        printf("\n");
//    }
//
//    return 0;
//}
