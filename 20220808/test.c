#define _CRT_SECURE_NO_WARNINGS 1

#include <time.h>
#include <stdlib.h>
#include "game.h"

void test();

int main()
{
	srand((unsigned int)time(NULL));
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
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("����������������������(1/0)>:");
			break;
		}
	} while (gameChoice);
}