#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>

void menu();
void game();

int main()
{
	srand((unsigned int)time(NULL));//拿时间戳来生成随机数起点
	int chose;
	do 
	{
		menu();
		scanf("%d", &chose);
		switch(chose)
		{
		case 1:
			printf("开始游戏！\n");
			game();
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("选择有误，请重新输入！\n");
			break;
		}
	} while (chose);

	return 0;
}

void menu()
{
	printf("*************************************\n");
	printf("***********1.Play  0.Exit************\n");
	printf("*************************************\n");
	printf("输入“1”开始游戏，输入“0”退出游戏\n");
	printf("您的选择是>:");
}

void game()
{
	int randomNum, guess;
	randomNum = ((rand()%100)+1);//使得这个随机数在0-100之间，并再每次游戏时产生一个赋给randomNum;
	//printf("%d\n", randomNum);
	printf("请猜一个数（0-100）>:");
	while (1)
	{	
		scanf("%d", &guess);
		if (guess > randomNum)
		{
			printf("您猜大了\n");
			printf("请再猜一个数>:");
		}
		else if (guess < randomNum)
		{
			printf("您猜小了\n");
			printf("请再猜一个数>:");
		}
		else
		{
			printf("您猜对了，这个数就是：randomNum = %d\n", randomNum);
			break;
		}
	}
}
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <windows.h>
///*************深南牌智能关机程序*****************/
//int main()
//{
//	char judgeString[20] = { 0 };
//	printf("欢迎您使用深南牌“智能关机程序”！\n");
//	printf("您的电脑将在3s后执行定时定时关机！\n");
//	Sleep(3000);
//	system("shutdown -s -t 60");
//	printf("输入：“我是猪！”，可取消定时关机！\n");
//	while (1)
//	{
//		printf("请输入：");
//		scanf("%s", judgeString);
//		if (strcmp("我是猪！", judgeString) == 0)
//		{
//			system("shutdown -a");
//			printf("自动关机程序已关闭！\n");
//			printf("感谢您使用深南牌“智能关机程序”！\n");
//			break;
//		}
//		else
//		{
//			printf("您的输入有误！请输入“我是猪！”,否则电脑将要关机！\n");
//		}
//	}
//}

/***********九九乘法表*************/
//int main()
//{
//	int i, j;
//	for (i = 1; i <= 9; i++)
//	{
//		for (j = 1; j <= i; j++)
//		{
//			printf("%d*%d=%d ", i, j,i*j);//代码呈现存在参差不齐的现象，因为乘积结果是2位数时候会多占1格
//			printf("%d*%d=%2d ", i, j, i * j);//优化将乘积结果设置为2位，不足时右对齐
//			printf("%d*%d=%-2d ", i, j, i * j);//进一步优化为左对齐
//		}
//		printf("\n");
//	}
//	return 0;
//}
