/****************游戏主模块****************/

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include "Game1.h"

int gameMenu(void)	//显示游戏选择菜单
{
	printf("****************************************\n");
	Sleep(125);
	printf("***********    《游戏菜单》  ***********\n");
	Sleep(125);
	printf("***********      1.扫雷      ***********\n");
	Sleep(125);
	printf("***********      0.退出      ***********\n");
	Sleep(125);
	printf("****************************************\n");
	Sleep(500);
}