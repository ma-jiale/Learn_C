//#include<stdio.h>
//
//void double_arr(int arr[][5], int size);
//void show_arr(int arr1[][5], int size);
//int main() {
//	int source[3][5] = { {1,1,1,1,1},{2,2,2,2,2},{3,3,3,3,3} };
//	show_arr(source, 3);
//	double_arr(source, 3);
//	show_arr(source, 3);
//	return 0;
//}
//void double_arr(int arr[][5], int size) {
//	for (int i = 0; i < size; i++) {
//		for (int j = 0; j < 5; j++) {
//			arr[i][j] *= 2;
//		}
//	}
//}
//
//void show_arr(int arr1[][5], int size) {
//	for (int i = 0; i < size; i++)
//	{
//		for (int j = 0; j < 5; j++) {
//			printf("%d ", arr1[i][j]);
//		}
//		putchar('\n');
//	}
//	putchar('\n');
//}