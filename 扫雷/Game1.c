/******************扫雷********************/

#define _CRT_SECURE_NO_WARNINGS 1
#include "Game1Base.h"

void game1(void)	//扫雷游戏主函数
{
	char soilHorizonBoard[ROWS][COLS] = { 0 };		//土壤层，用户看不见的一层，用于放置地雷
	char soilSurfaceBoard[ROWS][COLS] = { 0 };		//土表层，用户可观察的一层，用于显示探雷点周围的埋雷情况
	char userLandmineGrope_Result = 0;	 //存储用户的探雷结果
	int winCount = 0;	//记录用户已经排出无雷位置的总数量，后续用于判断是否已经扫完所有的雷
	initBoard(soilHorizonBoard, ROWS, COLS, '0');	//初始化土壤层，将该层全部填土(即'0')
	initBoard(soilSurfaceBoard, ROWS, COLS, '*');	//初始化土表层，将该层全部种草(即'*')，保持扫雷神秘感
	buryLandmine(soilHorizonBoard, ROW, COL, LANDMINE_COUNT);	//在土壤层埋放地雷
	displayBoard_Animation(soilSurfaceBoard, ROW, COL);	//展示土表层（雷盘正上方，不包括雷盘外围）
	//displayBoard_Animation(soilHorizonBoard, ROW, COL);	//展示土壤层，即雷盘，用于测试，测试后注意把改行代码注释掉
	while (1)		//进入用户交互的扫雷循环
	{
		userLandmineGrope_Result = userGropeLandmine(soilHorizonBoard, soilSurfaceBoard, ROW, COL);	//用户探雷，并返回探雷结果用于判断程序进行，若踩雷返回'F'，没有踩雷返回'C'
		if (userLandmineGrope_Result != 'C')	//如果用户探雷的结果不是"Cotinue"（继续），则跳出循环进行其他判断
			break;
		//程序执行到这里说明用户探雷的结果是Continue，即没有踩到地雷，且是对一个新的无雷位置的探雷
		winCount++;	//用户排出无雷位置的总数量增加1
		if ((ROW * COL - LANDMINE_COUNT) == winCount)	//如果已经排完全部的雷
		{
			userLandmineGrope_Result = 'W';
			break;
		}
		Sleep(1000);
		printf("该位置没有地雷，请继续扫雷!\n");
		Sleep(1000);
		displayBoard_Animation(soilSurfaceBoard, ROW, COL);	//向用户展示本次扫雷后的土表层
	}
	Sleep(1000);
	//能够跳出循环，说明用户不是踩到地雷就是完成了扫雷
	if (userLandmineGrope_Result == 'F')
	{
		printf("扫雷失败，您踩到地雷了!\n");
	}
	else		//完成扫雷
	{
		printf("扫雷成功，您已把所有地雷的位置确定了!\n");
	}
	Sleep(1000);
	printf("本次游戏的埋雷情况如下(1表示有地雷，0表示无地雷)>:\n");
	Sleep(2000);
	displayBoard_Animation(soilHorizonBoard, ROW, COL);	//不论用户扫雷成功还是踩到地雷，都向用户展示本次扫雷的土壤层埋雷情况
	Sleep(1500);
}