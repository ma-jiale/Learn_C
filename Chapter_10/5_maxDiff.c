//#include<stdio.h>
//#define SIZE 5
//double diff_max(const double arr[], int size);
//
//int main() {
//	double test[SIZE] = { 5,3,1,6,9 };
//	printf("%f", diff_max(test, SIZE));
//	return 0;
//}
//
////���β�ʹ��const,���������е�����
//double diff_max(const double arr[], int size) {
//	double max = arr[0];
//	double min = arr[0];
//	for (int i = 1; i < size; i++) {
//		if (arr[i] > max) {
//			max = arr[i];
//		}
//		else if (arr[i] < min) {
//			min = arr[i];
//		}
//	}
//	return max - min;
//}