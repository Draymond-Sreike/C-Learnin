#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
#include "user.h"
#include "time.h"

void test()
{
	int userGameChoice;			//存储用户的游戏选择数字
	do											//循环用来获得用户的游戏选择(一把游戏完成之后继续进行游戏选择)
	{
		gameMenu();															//显示游戏选择菜单
		userGameChoice = getUserGameChoice();		//获取用户的游戏选择
		switch (userGameChoice)										//判断用户的游戏选择并进入相应的游戏
		{
		case 1:		//进行游戏1
			game1();	//扫雷
			break;
		case 0:		//退出游戏
			break;	
		}
	} while (userGameChoice);	//若输入的游戏选择为'0'则退出游戏，其他选择则会在游戏结束后再次让用户输入游戏选择
}

int main()
{
	srand((unsigned int)time(NULL));	//播种（设置随机数起始）
    test();
	return 0;
}