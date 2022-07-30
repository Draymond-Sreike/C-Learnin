#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void main()
{
	char password[20] = { 0 };
	scanf("%s", password);
	//int arr[10] = { 1,2,3,4,5,6,8,9,10 };
	//int sz = (sizeof(arr) / sizeof(arr[0]));
	//int left = 0, right = sz - 1;
	//int k = 7;
	//int mid;
	//while (left <= right)
	//{
	//	mid = (left + right) / 2;
	//	if(arr[mid] < k)
	//	{
	//		left = mid + 1;
	//	}
	//	else if (arr[mid] > k)
	//	{
	//		right = mid - 1;
	//	}
	//	else
	//	{
	//		printf("找到了，下标为：%d\n", mid);
	//		break;
	//	}
	//	if (left > right)
	//	{
	//		printf("找不到\n");
	//	}
	//}
	//int ret = 1, sum = 0, i, n;
	//scanf("%d", &n);
	//for (i = 1; i <= n; i++)
	//{
	//	ret *= i;
	//	sum += ret;
	//}
	//printf("sum = %d", sum);
	//char ch = 0;
	//while ((ch = getchar()) != EOF)
	//{
	//	if (ch < '0' || ch > '9')
	//		continue;
	//	putchar(ch);
	//}
	//char password[20] = { 0 };
	//printf("请输入密码：");
	//scanf("%s", password);
	//while (getchar() != '\n');//直到把缓存区中的由于上次输入敲入的'\n'读走，便于下次getchar等待用户输入并读取新的输入
	//printf("请确认您的密码（Y/N）：");
	//if (getchar() ==  'Y')
	//{
	//	printf("您的密码已确认\n");
	//}
	//else
	//{
	//	printf("您取消了密码确认");
	//}
}
