#define _CRT_SECURE_NO_WARNINGS 1

//设置雷盘相关参数
#define ROW 9	//ROW*COL大小的扫雷盘
#define COL 9
#define LANDMINE_COUNT 10
#define ROWS ROW+2		//ROW*COL的扫雷盘扩大一圈外围为(ROW+2)*(COL+2)，用于探雷过程中，避免数组越界的问题
#define COLS COL+2

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

/*
* 函数功能：根据程序设计需要初始化雷盘
* 参数1：要初始化的雷盘
* 参数2：对雷盘初始化的行数（从0开始）
* 参数3：对雷盘初始化的列数（从0开始）
* 参数4：雷盘初始化的图案
*/
void initBoard(char board[ROWS][COLS], int rows, int cols, char setInitParttern);

/*
* 函数功能：展示雷盘情况
* 备注：从（1,1）开始，（以矩形形状）展示雷盘至（ROW,COL）
* 参数1：拟展示的雷盘
* 参数2：拟展示雷盘的总行数
* 参数3：拟展示雷盘的总列数
*/
void displayBoard(char board[ROWS][COLS], int row, int col);

/*
* 函数功能：展示雷盘情况（动画形式）
* 备注：从（1,1）开始，（以矩形形状）展示雷盘至（ROW,COL）
* 参数1：拟展示的雷盘
* 参数2：拟展示雷盘的总行数
* 参数3：拟展示雷盘的总列数
*/
void displayBoard_Animation(char board[ROWS][COLS], int row, int col);	//展示土表层（雷盘正上方，不包括雷盘外围）


/*
* 函数功能：埋放地雷
* 备注：从（1,1）开始，（以矩形形状）展示雷盘至（ROW,COL）
* 参数1：拟埋雷的雷盘
* 参数2：拟埋雷的总行数
* 参数3：拟埋雷的总列数
* 参数4：拟埋雷的总数量
*/
void buryLandmine(char board[ROWS][COLS], int row, int col, int landmineCount);

/*
* 函数功能：获取雷盘上指定位置坐标所在九宫格的埋雷总数（包括指定位置在内）
* 参数1：要获取信息的雷盘
* 参数2：指定位置的横坐标x
* 参数3：指定位置的纵坐标y
* 返回值：返回指定位置坐标所在九宫格的埋雷总数
*/
int get_PeripheryLandmineImformation(char soilHorizonBoard[ROWS][COLS], int gropeLandmine_X, int gropeLandmine_Y);

