#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <math.h>

/*********用函数实现判断一个数是不是素数***********/
int isPrimeNum(int num);//函数声明时，形参变量名可以省，即这里形参列表可以写成（int）
						//但函数定义时，形参变量名不可省

int main()
{
	int num,count = 0;
  //printf("输入一个数>:");
	//scanf("%d", &num);
	for (num = 2; num <= 100; num++)
	{
		if (isPrimeNum(num) == 1)
		{
			printf("%d ", num);
			count++;
		}
	}
	printf("count:%d", count);
	return 0;
}

int isPrimeNum(int num)//函数定义时，形参变量名不可省
{
	int i;
	for (i = 2; i <= sqrt(num); i++)
	{
		if (num % i == 0)
			return 0;
	}
	return 1;
}
