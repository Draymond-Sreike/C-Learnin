#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3	//行
#define COL 3	//列

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

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

void displayBoard(char board[ROW][COL])//陈列棋盘
{
	int i, j, firstLineFlag = 1;
	for (i = 0; i < ROW; i++)
	{
		while (firstLineFlag)//陈列棋盘的第一行用来输出-----> X，即X轴
		{
			for (j = 0; j < COL; j++)
			{
				printf("----");//跟随后续的" %c |"输出在其上方
			}
			printf("> X\n");
			firstLineFlag = 0;
		}

		for (j = 0; j < COL; j++)
		{
			if (0 == j)
			{
				printf("| %c |", board[i][j]); //在每一行的最左边输出|，以达到最后有Y轴的效果
			}
			else
			{
				printf(" %c |", board[i][j]);
			}
			if ((COL - 1) == j)
			{
				printf("\b \n");
			}
		}

		if (i < (ROW - 1))
		{
			for (j = 0; j < COL; j++)
			{
				if (0 == j)
				{
					printf("|---|", board[i][j]);
				}
				else
				{
					printf("---|", board[i][j]);
				}
				if ((COL - 1) == j)
				{
					printf("\b \n");
				}
			}
		}
	}
	printf("|\nY\n");
}

int getPlayer_X_MoveChoice()
{
	int x;
	printf("请输入您要下棋位置的横坐标(1-%d)>:",COL);
	while (1)
	{
		scanf("%d", &x);
		if((1 <= x) && (x <= COL))
		{
			return x;
		}
		else
		{
			printf("您输入的横坐标不合法!\n");
			printf("请重新输入您要下棋位置的横坐标(1-%d)>:", COL);
		}
	}
}

int getPlayer_Y_MoveChoice()
{
	int y;
	printf("请输入您要下棋位置的纵坐标(1-%d)>:",ROW);
	while (1)
	{
		scanf("%d", &y);
		if ((1 <= y) && (y <= ROW))
		{
			return y;
		}
		else
		{
			printf("您输入的纵坐标不合法!\n");
			printf("请重新输入您要下棋位置的纵坐标(1-%d)>:", ROW);
		}
	}
}

void playerMove(char board[ROW][COL])
{
	int move_x;
	int move_y;
	printf("玩家下:>\n");
	while (1)
	{
		move_x = getPlayer_X_MoveChoice();
		move_y = getPlayer_Y_MoveChoice();
		if (board[move_y - 1][move_x - 1] == ' ') //如果用户选中的位置没有棋子
		{
			board[move_y - 1][move_x - 1] = '*';
			printf("下棋成功!\n");
			break;
		}
		else
		{
			printf("您选择的位置已有棋子，请选择其他下棋位置!\n");
		}
	}
}

void computerMove(char board[ROW][COL])
{
	int move_x;
	int move_y;
	printf("电脑下:>\n");
	Sleep(2000);
	while (1)
	{
		move_x = (rand() % 3);
		move_y = (rand() % 3);
		if (board[move_y][move_x] == ' ') //如果用户选中的位置没有棋子
		{
			board[move_y][move_x] = '#';
			printf("电脑下棋成功!\n");
			break;
		}
	}
}
int board_IsFull(char board[ROW][COL])
{
	int i, j;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char isWin(char board[ROW][COL])
{
	int i;
	for (i = 0; i < ROW; i++) //判断每一行是否有连成的*或#
	{
		if ((board[i][1] != ' ') && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))
		{
			return board[i][1];
		}
	}
	for (i = 0; i < COL; i++)
	{
		if ((board[1][i] != ' ') && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i]))
		{
			return board[1][i];
		}
	}
	if ((board[1][1] != ' ') && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))
		return board[1][1];
	else if ((board[1][1] != ' ') && (board[2][0] == board[1][1]) && (board[1][1] == board[0][2]))
		return board[1][1];
	else								//至此还没有一方胜出，可能是平局也可能需要继续
	{
		if (1 == board_IsFull(board))	//棋盘满，平局
		{
			return 'Q';
		}
		else							//棋盘未满，继续游戏
			return 'C';
	}
}

void game()
{
	char winFlag = 0;
	char board[ROW][COL] = {'a','b','c','d','e','f','g','h','i'};
	printf("Game Begin!\n");
	gameBoard_Init(board);
	displayBoard(board);
	while (1)
	{
		playerMove(board);
		displayBoard(board);
		winFlag = isWin(board);
		if ('C' != winFlag)
			break;
		computerMove(board);
		displayBoard(board);
		winFlag = isWin(board);
		if ('C' != winFlag)
			break;
	}
	if ('*' == winFlag)
		printf("玩家胜!\n");
	else if ('#' == winFlag)
		printf("电脑胜!\n");
	else
		printf("平局!\n");
}