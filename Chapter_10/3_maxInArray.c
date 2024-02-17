//#include <stdio.h>
//#define SIZE 10
//int MaxInArr(int* ptr, int size);
//
//int main() {
//	int arr[SIZE] = { 1,5,3,2,0};
//	printf("the max number is %d\n", MaxInArr(arr, SIZE));
//	return 0;
//}
//int MaxInArr(int* ptr, int size) {
//	int max = *ptr;  /* don't use 0 as initial max value -- fails if all array values are neg */
//	for (int i = 1; i < size; i++) {
//		if (*(ptr + i) > max)
//			max = *(ptr + i);
//	}
//	return max;
//}