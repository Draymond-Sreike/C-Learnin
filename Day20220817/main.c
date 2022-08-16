#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int a = -1;
	a = a / 2;
	printf("%d", a);		//0
	//int a = 2147483646;
	//int b = 2147483645;
	//printf("交换前a = %d, b = %d\n", a, b);
	//a = a + b;
	//b = a - b;
	//a = a - b;
	//printf("交换后a = %d, b = %d\n", a, b);
	return 0;
}
