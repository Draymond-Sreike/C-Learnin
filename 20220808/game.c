#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 3	//��
#define COL 3	//��

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
	printf("����������Ϸѡ��(1/0)>:");
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

void displayBoard(char board[ROW][COL])//��������
{
	int i, j, firstLineFlag = 1;
	for (i = 0; i < ROW; i++)
	{
		while (firstLineFlag)//�������̵ĵ�һ���������-----> X����X��
		{
			for (j = 0; j < COL; j++)
			{
				printf("----");//���������" %c |"��������Ϸ�
			}
			printf("> X\n");
			firstLineFlag = 0;
		}

		for (j = 0; j < COL; j++)
		{
			if (0 == j)
			{
				printf("| %c |", board[i][j]); //��ÿһ�е���������|���Դﵽ�����Y���Ч��
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
	printf("��������Ҫ����λ�õĺ�����(1-%d)>:",COL);
	while (1)
	{
		scanf("%d", &x);
		if((1 <= x) && (x <= COL))
		{
			return x;
		}
		else
		{
			printf("������ĺ����겻�Ϸ�!\n");
			printf("������������Ҫ����λ�õĺ�����(1-%d)>:", COL);
		}
	}
}

int getPlayer_Y_MoveChoice()
{
	int y;
	printf("��������Ҫ����λ�õ�������(1-%d)>:",ROW);
	while (1)
	{
		scanf("%d", &y);
		if ((1 <= y) && (y <= ROW))
		{
			return y;
		}
		else
		{
			printf("������������겻�Ϸ�!\n");
			printf("������������Ҫ����λ�õ�������(1-%d)>:", ROW);
		}
	}
}

void playerMove(char board[ROW][COL])
{
	int move_x;
	int move_y;
	printf("�����:>\n");
	while (1)
	{
		move_x = getPlayer_X_MoveChoice();
		move_y = getPlayer_Y_MoveChoice();
		if (board[move_y - 1][move_x - 1] == ' ') //����û�ѡ�е�λ��û������
		{
			board[move_y - 1][move_x - 1] = '*';
			printf("����ɹ�!\n");
			break;
		}
		else
		{
			printf("��ѡ���λ���������ӣ���ѡ����������λ��!\n");
		}
	}
}

void computerMove(char board[ROW][COL])
{
	int move_x;
	int move_y;
	printf("������:>\n");
	Sleep(2000);
	while (1)
	{
		move_x = (rand() % 3);
		move_y = (rand() % 3);
		if (board[move_y][move_x] == ' ') //����û�ѡ�е�λ��û������
		{
			board[move_y][move_x] = '#';
			printf("��������ɹ�!\n");
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
	for (i = 0; i < ROW; i++) //�ж�ÿһ���Ƿ������ɵ�*��#
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
	else								//���˻�û��һ��ʤ����������ƽ��Ҳ������Ҫ����
	{
		if (1 == board_IsFull(board))	//��������ƽ��
		{
			return 'Q';
		}
		else							//����δ����������Ϸ
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
		printf("���ʤ!\n");
	else if ('#' == winFlag)
		printf("����ʤ!\n");
	else
		printf("ƽ��!\n");
}