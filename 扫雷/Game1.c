/******************ɨ��********************/

#define _CRT_SECURE_NO_WARNINGS 1
#include "Game1Base.h"

void game1(void)	//ɨ����Ϸ������
{
	char soilHorizonBoard[ROWS][COLS] = { 0 };		//�����㣬�û���������һ�㣬���ڷ��õ���
	char soilSurfaceBoard[ROWS][COLS] = { 0 };		//����㣬�û��ɹ۲��һ�㣬������ʾ̽�׵���Χ���������
	char userLandmineGrope_Result = 0;	 //�洢�û���̽�׽��
	int winCount = 0;	//��¼�û��Ѿ��ų�����λ�õ������������������ж��Ƿ��Ѿ�ɨ�����е���
	initBoard(soilHorizonBoard, ROWS, COLS, '0');	//��ʼ�������㣬���ò�ȫ������(��'0')
	initBoard(soilSurfaceBoard, ROWS, COLS, '*');	//��ʼ������㣬���ò�ȫ���ֲ�(��'*')������ɨ�����ظ�
	buryLandmine(soilHorizonBoard, ROW, COL, LANDMINE_COUNT);	//����������ŵ���
	displayBoard_Animation(soilSurfaceBoard, ROW, COL);	//չʾ����㣨�������Ϸ���������������Χ��
	//displayBoard_Animation(soilHorizonBoard, ROW, COL);	//չʾ�����㣬�����̣����ڲ��ԣ����Ժ�ע��Ѹ��д���ע�͵�
	while (1)		//�����û�������ɨ��ѭ��
	{
		userLandmineGrope_Result = userGropeLandmine(soilHorizonBoard, soilSurfaceBoard, ROW, COL);	//�û�̽�ף�������̽�׽�������жϳ�����У������׷���'F'��û�в��׷���'C'
		if (userLandmineGrope_Result != 'C')	//����û�̽�׵Ľ������"Cotinue"����������������ѭ�����������ж�
			break;
		//����ִ�е�����˵���û�̽�׵Ľ����Continue����û�вȵ����ף����Ƕ�һ���µ�����λ�õ�̽��
		winCount++;	//�û��ų�����λ�õ�����������1
		if ((ROW * COL - LANDMINE_COUNT) == winCount)	//����Ѿ�����ȫ������
		{
			userLandmineGrope_Result = 'W';
			break;
		}
		Sleep(1000);
		printf("��λ��û�е��ף������ɨ��!\n");
		Sleep(1000);
		displayBoard_Animation(soilSurfaceBoard, ROW, COL);	//���û�չʾ����ɨ�׺�������
	}
	Sleep(1000);
	//�ܹ�����ѭ����˵���û����ǲȵ����׾��������ɨ��
	if (userLandmineGrope_Result == 'F')
	{
		printf("ɨ��ʧ�ܣ����ȵ�������!\n");
	}
	else		//���ɨ��
	{
		printf("ɨ�׳ɹ������Ѱ����е��׵�λ��ȷ����!\n");
	}
	Sleep(1000);
	printf("������Ϸ�������������(1��ʾ�е��ף�0��ʾ�޵���)>:\n");
	Sleep(2000);
	displayBoard_Animation(soilHorizonBoard, ROW, COL);	//�����û�ɨ�׳ɹ����ǲȵ����ף������û�չʾ����ɨ�׵��������������
	Sleep(1500);
}