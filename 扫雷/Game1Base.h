#define _CRT_SECURE_NO_WARNINGS 1

//����������ز���
#define ROW 9	//ROW*COL��С��ɨ����
#define COL 9
#define LANDMINE_COUNT 10
#define ROWS ROW+2		//ROW*COL��ɨ��������һȦ��ΧΪ(ROW+2)*(COL+2)������̽�׹����У���������Խ�������
#define COLS COL+2

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

/*
* �������ܣ����ݳ��������Ҫ��ʼ������
* ����1��Ҫ��ʼ��������
* ����2�������̳�ʼ������������0��ʼ��
* ����3�������̳�ʼ������������0��ʼ��
* ����4�����̳�ʼ����ͼ��
*/
void initBoard(char board[ROWS][COLS], int rows, int cols, char setInitParttern);

/*
* �������ܣ�չʾ�������
* ��ע���ӣ�1,1����ʼ�����Ծ�����״��չʾ��������ROW,COL��
* ����1����չʾ������
* ����2����չʾ���̵�������
* ����3����չʾ���̵�������
*/
void displayBoard(char board[ROWS][COLS], int row, int col);

/*
* �������ܣ�չʾ���������������ʽ��
* ��ע���ӣ�1,1����ʼ�����Ծ�����״��չʾ��������ROW,COL��
* ����1����չʾ������
* ����2����չʾ���̵�������
* ����3����չʾ���̵�������
*/
void displayBoard_Animation(char board[ROWS][COLS], int row, int col);	//չʾ����㣨�������Ϸ���������������Χ��


/*
* �������ܣ���ŵ���
* ��ע���ӣ�1,1����ʼ�����Ծ�����״��չʾ��������ROW,COL��
* ����1�������׵�����
* ����2�������׵�������
* ����3�������׵�������
* ����4�������׵�������
*/
void buryLandmine(char board[ROWS][COLS], int row, int col, int landmineCount);

/*
* �������ܣ���ȡ������ָ��λ���������ھŹ������������������ָ��λ�����ڣ�
* ����1��Ҫ��ȡ��Ϣ������
* ����2��ָ��λ�õĺ�����x
* ����3��ָ��λ�õ�������y
* ����ֵ������ָ��λ���������ھŹ������������
*/
int get_PeripheryLandmineImformation(char soilHorizonBoard[ROWS][COLS], int gropeLandmine_X, int gropeLandmine_Y);

