#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int a, b, c, d;
	a = b = c = d = 0;	//C可以链式赋值
	printf("a = %d", a);
	printf("b = %d", b);
	printf("c = %d", c);
	printf("d = %d", d);
	return 0;
}
//void size1(int arr[])
//{
//	printf("%d\n", sizeof(arr));//4
//}
//
//void size2(int arr[])
//{
//	printf("%d\n", sizeof(arr));//4
//}
//
//int main()
//{
//	int arr[10] = { 0 };
//	printf("%d\n", sizeof(arr));//40
//	size1(arr);
//	size2(&arr);
//	printf("%p\n", arr);
//	printf("%p\n", arr+1);
//	printf("%p\n", &arr);	//取整个数组的地址去传参仍然没办法让调用函数中的sizeof算出整个数组的大小
//	printf("%p\n", &arr+1);
//	return 0;
//}

/********冒泡排序*******/
//void bubbleSort(int* arr, int size);
//
//int main()
//{
//	int arr[20], flag = 0, i, size;
//	printf("创建不超过20个元素的数组\n");
//	for (i = 0; i < 10; i++)
//	{
//		printf("请输入您数组的第%d个元素：", i);
//		scanf("%d", &arr[i]);
//		printf("您数组的第%d个元素为arr[%d]=%d\n", i, i ,arr[i]);
//		printf("请问您是否要继续存放数据？（输入1表示继续，0表示中止）：", i, i, arr[i]);
//		scanf("%d", &flag);
//		while (flag != 1 && flag != 0)
//		{
//			printf("您的输入有误，请重新输入（输入1表示继续，0表示中止）：");
//			scanf("%d", &flag);
//		}
//		if (0 == flag)
//			break;
//	}
//
//	printf("您的数组为：int arr[%d] = {", i + 1);
//	for(int n = 0; n <= i; n++)
//	{
//		printf("%d", arr[n]);
//		if(n < i)
//			printf(", ");
//	}
//	printf("}\n");
//	printf("经过冒泡排升序后您的数组为：int arr[%d] = {", i + 1);
//	bubbleSort(arr, i+1);
//	for (int n = 0; n <= i; n++)
//	{
//		printf("%d", arr[n]);
//		if (n < i)
//			printf(", ");
//	}
//	printf("}\n");
//
//	return 0;
//}
//
//void bubbleSort(int* arr, int size)
//{
//	for (int time = 1; time <= (size - 1); time++)
//	{
//		int j, flag = 1;
//		for (j = 0; j < (size - time); j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int temp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = temp;
//				flag = 0;
//			}
//		}
//		if (1 == flag)
//			break;
//	}
//}
