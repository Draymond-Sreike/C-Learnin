/****************�û�����****************/
#define _CRT_SECURE_NO_WARNINGS 1

#include "Game.h"

int getUserGameChoice(void);		//��ȡ�û�����Ϸѡ��
int getUserGame1BoardChoice(void);		//��ȡ�û����̴�Сѡ��

/*
* �������ܣ��û�̽�׽��У��������û�̽�׵Ľ����������������ж�
* ��ע��	�ú��������û�ѡ���̽��λ����̽���ף��򲻻����Ϸ���̽�׽������Ҫ���û�����ѡ���µġ�û��̽���׵�λ�ý���̽�ף�����ŷ���̽�׽��
* ����1���ṩ�û�ɨ�׵�������
* ����2���ṩ�û�ɨ�׵������
* ����3���û�ɨ�����̵���
* ����4���û�ɨ�����̵���
* ����ֵ���û�ɨ�׵Ľ������̽���׷���'F'��û��̽���׷���'C'��
*/
char userGropeLandmine(char soilHorizonBoard[ROWS][COLS], char soilSurfaceBoard[ROWS][COLS], int row, int col);		//��ȡ�û���̽�׽��