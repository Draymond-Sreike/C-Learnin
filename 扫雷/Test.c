#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"
#include "user.h"
#include "time.h"

void test()
{
	int userGameChoice;			//�洢�û�����Ϸѡ������
	do											//ѭ����������û�����Ϸѡ��(һ����Ϸ���֮�����������Ϸѡ��)
	{
		gameMenu();															//��ʾ��Ϸѡ��˵�
		userGameChoice = getUserGameChoice();		//��ȡ�û�����Ϸѡ��
		switch (userGameChoice)										//�ж��û�����Ϸѡ�񲢽�����Ӧ����Ϸ
		{
		case 1:		//������Ϸ1
			game1();	//ɨ��
			break;
		case 0:		//�˳���Ϸ
			break;	
		}
	} while (userGameChoice);	//���������Ϸѡ��Ϊ'0'���˳���Ϸ������ѡ���������Ϸ�������ٴ����û�������Ϸѡ��
}

int main()
{
	srand((unsigned int)time(NULL));	//���֣������������ʼ��
    test();
	return 0;
}