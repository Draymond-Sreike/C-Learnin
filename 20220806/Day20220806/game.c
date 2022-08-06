#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3
#define COL 3

#include <stdio.h>

void gameMenu()
{
	printf("**********************************\n");
	printf("*********1.Play    0.Exit*********\n");
	printf("**********************************\n");
}

int getGameChoice()
{
	int gameChoice;
	printf("输入您的游戏选择(1/0)>:");
	scanf("%d", &gameChoice);
	return gameChoice;
}
void gameBoard_Init(char board[ROW][COL])
{
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void disPlayBoard(char board[ROW][COL])
{
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf(" %c |", board[i][j]);
			if ((COL - 1) == j)
			{
				printf("\b \n");
			}
		}
		if (i < (ROW - 1))
		{
			for (j = 0; j < COL; j++)
			{
				printf("---|");
				if ((COL - 1) == j)
				{
					printf("\b \n");
				}
			}
		}
	}
}

void game()
{
	char board[ROW][COL] = {'a','b','c','d','e','f','g','h','i'};
	printf("Game Begin!\n");
	gameBoard_Init(board);
	disPlayBoard(board);
}
