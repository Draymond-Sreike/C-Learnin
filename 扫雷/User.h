/****************用户交互****************/
#define _CRT_SECURE_NO_WARNINGS 1

#include "Game.h"

int getUserGameChoice(void);		//获取用户的游戏选择
int getUserGame1BoardChoice(void);		//获取用户雷盘大小选择

/*
* 函数功能：用户探雷进行，并返回用户探雷的结果用于其他程序的判断
* 备注：	该函数中若用户选择的探雷位置已探过雷，则不会马上返回探雷结果，会要求用户重新选择新的、没有探过雷的位置进行探雷，而后才返回探雷结果
* 参数1：提供用户扫雷的土壤层
* 参数2：提供用户扫雷的土表层
* 参数3：用户扫雷雷盘的行
* 参数4：用户扫雷雷盘的列
* 返回值：用户扫雷的结果（若探到雷返回'F'，没有探到雷返回'C'）
*/
char userGropeLandmine(char soilHorizonBoard[ROWS][COLS], char soilSurfaceBoard[ROWS][COLS], int row, int col);		//获取用户的探雷结果