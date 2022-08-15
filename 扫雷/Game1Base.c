#define _CRT_SECURE_NO_WARNINGS 1

#include <Windows.h>
#include "Game1Base.h"
/*
* �������ܣ����ݳ��������Ҫ��ʼ�����̼�����Χ
* ����1��Ҫ��ʼ��������
* ����2�������̳�ʼ������������0��ʼ��
* ����3�������̳�ʼ������������0��ʼ��
* ����4�����̳�ʼ����ͼ��
*/
void initBoard(char board[ROWS][COLS], int rows, int cols, char setInitParttern)
{
	int i, j;
	for (i = 0; i < rows; i++)	//���̵���
	{
		for (j = 0; j < cols; j++)		//���̵���	
			board[i][j] = setInitParttern;	//��ʼ�����̵�ͼ��
	}
}

/*
* �������ܣ�չʾ�������
* ��ע���ӣ�1,1����ʼ�����Ծ�����״��չʾ��������ROW,COL��
* ����1����չʾ������
* ����2����չʾ���̵�����
* ����3����չʾ���̵�����
*/
void displayBoard(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	for (j = 0; j <= col; j++)	//��ÿһ�����Ϸ���ӡ�кţ������û����ٶ�λ̽�׵���У�ϸ�ڣ���0��ʼ��ӡ��
	{
		printf("%d ", j);
	}
	printf("\n");	//�кŴ�ӡ��֮����һ�½������̴�ӡ
	for (i = 1; i <= row; i++)	//�У�չʾ���̴�1��ROW
	{
		printf("%d ", i);	//ÿһ���ͷ��ӡ�кţ�����кţ������û����ٶ�λ̽�׵����
		for (j = 1; j <= col; j++)			//�У�չʾ���̴�1��COL
			printf("%c ", board[i][j]);
		printf("\n");		//ÿһ������չʾ����У�������һ�����̵�չʾ
	}
}

/*
* �������ܣ�չʾ���������������ʽ��
* ��ע���ӣ�1,1����ʼ�����Ծ�����״��չʾ��������ROW,COL��
* ����1����չʾ������
* ����2����չʾ���̵�����
* ����3����չʾ���̵�����
*/
void displayBoard_Animation(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	for (j = 0; j <= col; j++)	//��ÿһ�����Ϸ���ӡ�кţ������û����ٶ�λ̽�׵���У�ϸ�ڣ���0��ʼ��ӡ��
	{
		printf("%d ", j);
	}
	printf("\n");	//�кŴ�ӡ��֮����һ�½������̴�ӡ
	for (i = 1; i <= row; i++)	//�У�չʾ���̴�1��ROW
	{
		Sleep(100);	//��ӡÿһ��ͣ��100ms
		printf("%d ", i);	//ÿһ���ͷ��ӡ�кţ�����кţ������û����ٶ�λ̽�׵����
		for (j = 1; j <= col; j++)			//�У�չʾ���̴�1��COL
			printf("%c ", board[i][j]);
		printf("\n");		//ÿһ������չʾ����У�������һ�����̵�չʾ
	}
	Sleep(1000);	//���̴�ӡ��ɺ�ͣ��1s
}

/*
* �������ܣ���ŵ���
* ��ע���ӣ�1,1����ʼ�����Ծ�����״��չʾ��������ROW,COL��
* ����1�������׵�����
* ����2�������׵�������
* ����3�������׵�������
* ����4�������׵�������
*/
void buryLandmine(char board[ROWS][COLS], int row, int col, int landmineCount)
{
	printf("���ν���%d������Ҫ���\n", landmineCount);
	Sleep(1000);
	while (landmineCount)
	{
		int x = ((rand() % col) + 1);	//���ѡȡҪ����λ�õ�x���꣨1~col�����˴���1��ʼ����Ϊ���̴ӣ�1,1����ʼ
		int y = ((rand() % row) + 1);	//���ѡȡҪ����λ�õ�y���꣨1~row�����˴���1��ʼ����Ϊ���̴ӣ�1,1����ʼ
		if ('0' == board[y][x])	//���������λ��û���ף�������
		{
			board[y][x] = '1';	//����
			landmineCount--;	//���óɹ�������Ҫ�����������1
		}
	}
	
	//ģ����صȴ��Ľ�������
	printf("�����У���ȴ�");
	for (int i = 0; i < 6; i++)		//��"��ȴ�"�������6��"."
	{
		Sleep(500);	//ÿ���һ��"."���ȴ�500ms
		printf(".");
	}
	Sleep(1000);//"......"�����Ϻ�ȴ�1s
	printf("\n������ϣ��뿪ʼɨ��!\n");
	Sleep(1250);	//����ٵȴ�1250ms��������һ��
}

/*
* �������ܣ���ȡ������ָ��λ���������ھŹ������������������ָ��λ�����ڣ�
* ����1��Ҫ��ȡ��Ϣ������
* ����2��ָ��λ�õĺ�����x
* ����3��ָ��λ�õ�������y
* ����ֵ������ָ��λ���������ھŹ������������
*/
int get_PeripheryLandmineImformation(char soilHorizonBoard[ROWS][COLS], int gropeLandmine_X, int gropeLandmine_Y)
{
	int landmineCount = 0;
	for (int y = (gropeLandmine_Y - 1); y <= (gropeLandmine_Y + 1); y++)		//�û�̽�׵����һ�С���ǰ�С���һ��
	{
		for (int x = (gropeLandmine_X - 1); x <= (gropeLandmine_X + 1); x++)		//�û�̽�׵��ǰһ�С���ǰ�С���һ��
		{
			if ('1' == soilHorizonBoard[y][x])		//���̽�׵����ڵľŹ����ڵ�ÿһ���е��ף�����׼�����1���������������û�ѡ��̽�׵㣬��û�й�ϵ�������ִ�е�����û�ѡ���̽�׵�һ����û�е��׵ģ�
			{
				landmineCount++;
			}
		}
	}
	return landmineCount;
}
