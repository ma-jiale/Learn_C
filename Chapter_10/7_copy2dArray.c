//#include<stdio.h>
//
//void copy_arr(double[], double[], int);
//void show_arr(double arr1[][4], int size);
//int main() {
//	double arr[5][4] = { {1,2,3,4},{2,2,2,2},{3,3,3,3},{4,4,4,4},{5,5,5,5}};
//	double target[5][4];
//	for (int i = 0; i < 5; i++) {
//		copy_arr(target[i], arr[i], 5);
//	}
//	show_arr(arr, 5);
//	show_arr(target, 5);
//	return 0;
//}
//
//void copy_arr(double ar1[], double ar2[], int size) {
//	for (int i = 0; i < size; i++) {
//		ar1[i] = ar2[i];
//	}
//}
//
//void show_arr(double arr1[][4], int size) {
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < 4; j++) {
//			printf("%g ", arr1[i][j]);
//		}
//		putchar('\n');
//	}
//	putchar('\n');
//}