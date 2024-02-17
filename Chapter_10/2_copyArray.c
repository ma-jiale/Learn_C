//#include<stdio.h>
//#define SIZE 5
//
//void copy_arr(double [], double [], int);
//void copy_ptr(double* ptr1, double* ptr2, int size);
//void copy_ptrs(double* ptr1, double* ptr2, double* ptr3);
//
//int main() {
//	double source[SIZE] = { 1.1,2.2,3.3,4.4,5.5 };
//	double target1[SIZE];
//	double target2[SIZE];
//	double target3[SIZE];
//
//	copy_arr(target1, source, SIZE);
//	copy_ptr(target2, source, SIZE);
//	copy_ptrs(target3, source, source + SIZE);
//
//	printf("source target1 target2 target3\n");
//	for (int i = 0; i < SIZE; i++)
//	{
//		printf("%.1f%8.1f%8.1f%8.1f\n", source[i], target1[i], target2[i], target3[i]);
//	}
//
//	return 0;
//}
////使用带数组表示法的函数
//void copy_arr(double ar1[], double ar2[], int size) {
//	for (int i = 0; i < size; i++) {
//		ar1[i] = ar2[i];
//	}
//}
//
////使用带指针表示法的函数
//void copy_ptr(double* ptr1, double* ptr2, int size) {
//	for (int i = 0; i < size; i++)
//	{
//		*(ptr1 + i) = *(ptr2 + i);
//	}
//}
//
////使用带指针表示法的函数
//void copy_ptrs(double* ptr1, double* ptr2, double* ptr3) {
//	for (int i = 0; i < ptr3 - ptr2; i++)
//	{
//		*(ptr1 + i) = *(ptr2 + i);
//	}
//}