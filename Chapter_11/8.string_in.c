//#include<stdio.h>
//
//char* string_in(const char* p1, const char* p2);
//
//int main(void)
//{
//	char orig[20] = "applitation";
//	char* find;
//
//	puts(orig);
//	find = string_in(orig, "li");
//	if (find)
//		puts(find);
//	else
//		puts("Not found");
//	find = string_in(orig, "apple");
//	if (find)
//		puts(find);
//	else
//		puts("Not found");
//
//	return 0;
//}
//
//#include<string.h>
//char* string_in(const char* p1, const char* p2) {
//	const char* p2_ = p2;
//	const char* p1_ = p1;
//	_Bool match = 0;
//	while (*p1) {
//		//Ѱ�ҵ�һ���ַ�������ڶ����ַ������ַ���ͬ���ַ�
//		if (*p1 == *p2) {
//			p1_ = p1;
//			match = 1;
//			//�����ַ�������ַ��Ƿ���ڶ����ַ�����ȫ���
//			while (*p2) {
//				if (*p1++ != *p2++)
//					match = 0;
//			}
//			p2 = p2_;
//			p1 = p1_;
//			//������������ѭ��
//			if (match)
//				break;
//		}
//		p1++;
//	}
//	if (match)
//		return (char*)p1;
//	else
//		return NULL;
//}