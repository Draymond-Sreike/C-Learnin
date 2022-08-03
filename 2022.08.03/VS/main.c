#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <string.h>

int main()
{
	int arr[3][5] = { {1,2,3,4},{5,6,7,8} };
	printf("%d", sizeof(arr));//3*5*4=60
	printf("%d", sizeof(arr[0]));//5*4=20
	return 0;
}
//int main()
//{
//	100;
//	char ch = 'n';
//	printf("%c", ch);
//	return 0;
//}
