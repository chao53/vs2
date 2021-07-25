#include "iostream"
using namespace std;

void swap(char* str1, char* str2)
{
	char temp = *str1;
	*str1 = *str2;
	*str2 = temp;
}
int main()
{
	char* str1 = "Data";
	char* str2 = "Structure";
	swap(str1, str2);
	cout << str1 << " " << str2;
	return 0;

}
//void swap(int* str1, int* str2)
//{
//	int temp = *str1;
//	*str1 = *str2;
//	*str2 = temp;
//}
//int main()
//{
//	int a = 11;
//	int b = 22;
//	int* str1 = &a;
//	int* str2 = &b;
//	swap(str1, str2);
//	cout << *str1 << " " << *str2;
//	return 0;
//
//}