#define _CRT_SECURE_NO_WARNINGS 1

#include <Windows.h>
#include "Game1Base.h"
/*
* 函数功能：根据程序设计需要初始化雷盘及其外围
* 参数1：要初始化的雷盘
* 参数2：对雷盘初始化的行数（从0开始）
* 参数3：对雷盘初始化的列数（从0开始）
* 参数4：雷盘初始化的图案
*/
void initBoard(char board[ROWS][COLS], int rows, int cols, char setInitParttern)
{
	int i, j;
	for (i = 0; i < rows; i++)	//雷盘的行
	{
		for (j = 0; j < cols; j++)		//雷盘的列	
			board[i][j] = setInitParttern;	//初始化雷盘的图案
	}
}

/*
* 函数功能：展示雷盘情况
* 备注：从（1,1）开始，（以矩形形状）展示雷盘至（ROW,COL）
* 参数1：拟展示的雷盘
* 参数2：拟展示雷盘的行数
* 参数3：拟展示雷盘的列数
*/
void displayBoard(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	for (j = 0; j <= col; j++)	//在每一列正上方打印列号，便于用户快速定位探雷点的列（细节：从0开始打印）
	{
		printf("%d ", j);
	}
	printf("\n");	//列号打印完之后换行一下进行雷盘打印
	for (i = 1; i <= row; i++)	//行，展示雷盘从1到ROW
	{
		printf("%d ", i);	//每一行最开头打印行号，结合列号，便于用户快速定位探雷点的行
		for (j = 1; j <= col; j++)			//列，展示雷盘从1到COL
			printf("%c ", board[i][j]);
		printf("\n");		//每一行雷盘展示完后换行，便于下一行雷盘的展示
	}
}

/*
* 函数功能：展示雷盘情况（动画形式）
* 备注：从（1,1）开始，（以矩形形状）展示雷盘至（ROW,COL）
* 参数1：拟展示的雷盘
* 参数2：拟展示雷盘的行数
* 参数3：拟展示雷盘的列数
*/
void displayBoard_Animation(char board[ROWS][COLS], int row, int col)
{
	int i, j;
	for (j = 0; j <= col; j++)	//在每一列正上方打印列号，便于用户快速定位探雷点的列（细节：从0开始打印）
	{
		printf("%d ", j);
	}
	printf("\n");	//列号打印完之后换行一下进行雷盘打印
	for (i = 1; i <= row; i++)	//行，展示雷盘从1到ROW
	{
		Sleep(100);	//打印每一行停留100ms
		printf("%d ", i);	//每一行最开头打印行号，结合列号，便于用户快速定位探雷点的行
		for (j = 1; j <= col; j++)			//列，展示雷盘从1到COL
			printf("%c ", board[i][j]);
		printf("\n");		//每一行雷盘展示完后换行，便于下一行雷盘的展示
	}
	Sleep(1000);	//雷盘打印完成后停留1s
}

/*
* 函数功能：埋放地雷
* 备注：从（1,1）开始，（以矩形形状）展示雷盘至（ROW,COL）
* 参数1：拟埋雷的雷盘
* 参数2：拟埋雷的总行数
* 参数3：拟埋雷的总列数
* 参数4：拟埋雷的总数量
*/
void buryLandmine(char board[ROWS][COLS], int row, int col, int landmineCount)
{
	printf("本次将有%d个地雷要埋放\n", landmineCount);
	Sleep(1000);
	while (landmineCount)
	{
		int x = ((rand() % col) + 1);	//随机选取要埋雷位置的x坐标（1~col），此处从1开始是因为雷盘从（1,1）开始
		int y = ((rand() % row) + 1);	//随机选取要埋雷位置的y坐标（1~row），此处从1开始是因为雷盘从（1,1）开始
		if ('0' == board[y][x])	//如果拟埋雷位置没有雷，则埋雷
		{
			board[y][x] = '1';	//埋雷
			landmineCount--;	//放置成功，手上要埋的雷数量减1
		}
	}
	
	//模拟加载等待的交互界面
	printf("埋雷中，请等待");
	for (int i = 0; i < 6; i++)		//在"请等待"后面输出6个"."
	{
		Sleep(500);	//每输出一个"."，等待500ms
		printf(".");
	}
	Sleep(1000);//"......"输出完毕后等待1s
	printf("\n埋雷完毕，请开始扫雷!\n");
	Sleep(1250);	//最后再等待1250ms，进入下一步
}

/*
* 函数功能：获取雷盘上指定位置坐标所在九宫格的埋雷总数（包括指定位置在内）
* 参数1：要获取信息的雷盘
* 参数2：指定位置的横坐标x
* 参数3：指定位置的纵坐标y
* 返回值：返回指定位置坐标所在九宫格的埋雷总数
*/
int get_PeripheryLandmineImformation(char soilHorizonBoard[ROWS][COLS], int gropeLandmine_X, int gropeLandmine_Y)
{
	int landmineCount = 0;
	for (int y = (gropeLandmine_Y - 1); y <= (gropeLandmine_Y + 1); y++)		//用户探雷点的上一行、当前行、下一列
	{
		for (int x = (gropeLandmine_X - 1); x <= (gropeLandmine_X + 1); x++)		//用户探雷点的前一列、当前列、下一列
		{
			if ('1' == soilHorizonBoard[y][x])		//如果探雷点所在的九宫格内的每一格有地雷，则地雷计数加1（程序这里会包含用户选择探雷点，但没有关系，程序会执行到这里，用户选择的探雷点一定是没有地雷的）
			{
				landmineCount++;
			}
		}
	}
	return landmineCount;
}
