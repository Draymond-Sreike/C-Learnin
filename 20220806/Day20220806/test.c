#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void test();

int main()
{
	test();
	return 0;
}

void test()
{
	int gameChoice = 0;
	gameMenu();
	do
	{
		gameChoice = getGameChoice();
		switch (gameChoice)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("您的输入有误，请重新输入(1/0)>:");
			break;
		}
	} while (gameChoice);
}
