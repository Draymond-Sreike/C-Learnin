/****************用户交互****************/

#define _CRT_SECURE_NO_WARNINGS 1
#include  <stdio.h>
#include "Game.h"

int getUserGameChoice(void)		//获取用户键盘输入的游戏选择
{
	int userGameChoice;							//存储用户从键盘输入的游戏选择数字
	printf("请输入您的游戏选择>:");
	scanf("%d", &userGameChoice);
	while ((userGameChoice < 0) || (userGameChoice > 3))	//如果用户输入的游戏选择非法，则循环直至输入合法为止
	{
		printf("您的游戏选择非法！请重新输入您的游戏选择>:");
		scanf("%d", &userGameChoice);	//供用户再次输入游戏选择
	}
	return userGameChoice;
}

/*
* 函数功能：用户探雷进行，并返回用户探雷的结果用于其他程序的判断
* 备注：	该函数中若用户选择的探雷位置已探过雷，则不会马上返回探雷结果，会要求用户重新选择新的、没有探过雷的位置进行探雷，而后才返回探雷结果
* 参数1：提供用户扫雷的土壤层
* 参数2：提供用户扫雷的土表层
* 参数3：用户扫雷雷盘的行
* 参数4：用户扫雷雷盘的列
* 返回值：用户扫雷的结果（若探到雷返回'F'，没有探到雷返回'C'）
*/
char userGropeLandmine(char soilHorizonBoard[ROWS][COLS], char soilSurfaceBoard[ROWS][COLS], int row, int col)		//获取用户的探雷结果
{
	int gropeLandmine_X, gropeLandmine_Y;	//存储用户选择探雷点位置坐标
	int landmineCount = 0;		//存储用户选择的探雷点附近的埋雷情况，默认为0，每次重新调用该方法时该变量都会被置0
	printf("请输入您拟扫雷位置的横坐标x(1-%d)>:", col);
	scanf("%d", &gropeLandmine_X);
	while ((gropeLandmine_X < 1) || (gropeLandmine_X > col))	//如果用户输入的探雷位置x非法，则循环直至输入合法为止
	{
		printf("您拟扫雷位置的横坐标x非法!请重新输入(1-%d)>:", col);
		scanf("%d", &gropeLandmine_X);	//供用户再次输入游戏选择
	}

	printf("请输入您拟扫雷位置的纵坐标y(1-%d)>:", row);
	scanf("%d", &gropeLandmine_Y);
	while ((gropeLandmine_Y < 1) || (gropeLandmine_Y > row))	//如果用户输入的探雷位置y非法，则循环直至输入合法为止
	{
		printf("您拟扫雷位置的纵坐标y非法!请重新输入(1-%d)>:", row);
		scanf("%d", &gropeLandmine_Y);	//供用户再次输入游戏选择
	}
	//完成以上部分程序后，得到的横纵坐标XY即为合理值
	while (1)
	{
		if (soilSurfaceBoard[gropeLandmine_Y][gropeLandmine_X] == '*')		//如果用户要探雷的位置还未探过
		{
			if (soilHorizonBoard[gropeLandmine_Y][gropeLandmine_X] == '1')	//如果探到地雷则返回'F'
			{
				return 'F';
			}
			else		//如果即没有探到雷，也没有完成探雷工作，则显示探雷点附近的埋雷情况，并且返回'C'
			{
				landmineCount = get_PeripheryLandmineImformation(soilHorizonBoard, gropeLandmine_X, gropeLandmine_Y);	//获取探雷点周围（九宫格）的埋雷情况（即数量）
				soilSurfaceBoard[gropeLandmine_Y][gropeLandmine_X] = (landmineCount + '0');		//将埋雷数量从数值转换为字符并存入土表层进行显示
				return 'C';
			}
		}
		else 	//如果用户要探雷的位置已探过
		{
			printf("您选择的位置已经扫过雷了，进重新选择要扫雷的位置坐标！\n");
			printf("请输入您拟扫雷位置的横坐标x(1-%d)>:", col);
			scanf("%d", &gropeLandmine_X);
			while ((gropeLandmine_X < 1) || (gropeLandmine_X > col))	//如果用户输入的探雷位置x非法，则循环直至输入合法为止
			{
				printf("您拟扫雷位置的横坐标x非法!请重新输入(1-%d)>:", col);
				scanf("%d", &gropeLandmine_X);	//供用户再次输入游戏选择
			}

			printf("请输入您拟扫雷位置的纵坐标y(1-%d)>:", row);
			scanf("%d", &gropeLandmine_Y);
			while ((gropeLandmine_Y < 1) || (gropeLandmine_Y > row))	//如果用户输入的探雷位置y非法，则循环直至输入合法为止
			{
				printf("您拟扫雷位置的纵坐标y非法!请重新输入(1-%d)>:", row);
				scanf("%d", &gropeLandmine_Y);	//供用户再次输入游戏选择
			}
		}
	}
}