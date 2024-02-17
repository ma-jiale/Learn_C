//#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//#define ROWS 3
//#define COLS 5
//
//void saveIn2dArray(double arr[][COLS],int size);
//double averArray(double arr[], int size);
//double aver2dAray(double arr[][COLS], int size);
//double maxInArray(double arr[][COLS], int size);
//void show(double arr[][COLS], int size);
//
//int main() {
//	double source[ROWS][COLS];
//	printf("Please enter 3 group of numbers,every group contain 5 double\n");
//	saveIn2dArray(source, ROWS);
//	show(source, ROWS);
//	return 0;
//}
//
//void saveIn2dArray(double arr[][COLS], int size) {
//	for (int i = 0; i < size; i++)
//	{
//		printf("Please enter the %d group of numbers\n",i+1);
//		for (int j = 0; j < COLS; j++)
//		{
//			scanf("%lf", &arr[i][j]);
//		}
//	}
//}
//
//double averArray(double arr[], int size) {
//	double subTot = 0;
//	for (int i = 0; i < size; i++)
//	{
//		subTot += arr[i];
//	}
//	return subTot / size;
//}
//
//double aver2dAray(double arr[][COLS], int size) {
//	double total = 0;
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			total += arr[i][j];
//		}
//	}
//	return total / (COLS * size);
//}
//
//double maxInArray(double arr[][COLS], int size) {
//	double max = arr[0][0];
//	for (int i = 0; i < 3; i++)
//	{
//		for (int j = 0; j < 5; j++)
//		{
//			if (arr[i][j] > max)
//				max = arr[i][j];
//		}
//	}
//	return max;
//}
//
//void show(double arr[][COLS], int size) {
//	for (int i = 0; i < ROWS; i++)
//	{
//		printf("The average of %d group is %2.1lf\n", i + 1, averArray(arr[i], COLS));
//	}
//	printf("The average of the all group is %2.1lf\n", aver2dAray(arr, ROWS));
//	printf("The max number of the all group is %2.1lf\n", maxInArray(arr, ROWS));
//}