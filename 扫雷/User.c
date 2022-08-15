/****************�û�����****************/

#define _CRT_SECURE_NO_WARNINGS 1
#include  <stdio.h>
#include "Game.h"

int getUserGameChoice(void)		//��ȡ�û������������Ϸѡ��
{
	int userGameChoice;							//�洢�û��Ӽ����������Ϸѡ������
	printf("������������Ϸѡ��>:");
	scanf("%d", &userGameChoice);
	while ((userGameChoice < 0) || (userGameChoice > 3))	//����û��������Ϸѡ��Ƿ�����ѭ��ֱ������Ϸ�Ϊֹ
	{
		printf("������Ϸѡ��Ƿ�������������������Ϸѡ��>:");
		scanf("%d", &userGameChoice);	//���û��ٴ�������Ϸѡ��
	}
	return userGameChoice;
}

/*
* �������ܣ��û�̽�׽��У��������û�̽�׵Ľ����������������ж�
* ��ע��	�ú��������û�ѡ���̽��λ����̽���ף��򲻻����Ϸ���̽�׽������Ҫ���û�����ѡ���µġ�û��̽���׵�λ�ý���̽�ף�����ŷ���̽�׽��
* ����1���ṩ�û�ɨ�׵�������
* ����2���ṩ�û�ɨ�׵������
* ����3���û�ɨ�����̵���
* ����4���û�ɨ�����̵���
* ����ֵ���û�ɨ�׵Ľ������̽���׷���'F'��û��̽���׷���'C'��
*/
char userGropeLandmine(char soilHorizonBoard[ROWS][COLS], char soilSurfaceBoard[ROWS][COLS], int row, int col)		//��ȡ�û���̽�׽��
{
	int gropeLandmine_X, gropeLandmine_Y;	//�洢�û�ѡ��̽�׵�λ������
	int landmineCount = 0;		//�洢�û�ѡ���̽�׵㸽�������������Ĭ��Ϊ0��ÿ�����µ��ø÷���ʱ�ñ������ᱻ��0
	printf("����������ɨ��λ�õĺ�����x(1-%d)>:", col);
	scanf("%d", &gropeLandmine_X);
	while ((gropeLandmine_X < 1) || (gropeLandmine_X > col))	//����û������̽��λ��x�Ƿ�����ѭ��ֱ������Ϸ�Ϊֹ
	{
		printf("����ɨ��λ�õĺ�����x�Ƿ�!����������(1-%d)>:", col);
		scanf("%d", &gropeLandmine_X);	//���û��ٴ�������Ϸѡ��
	}

	printf("����������ɨ��λ�õ�������y(1-%d)>:", row);
	scanf("%d", &gropeLandmine_Y);
	while ((gropeLandmine_Y < 1) || (gropeLandmine_Y > row))	//����û������̽��λ��y�Ƿ�����ѭ��ֱ������Ϸ�Ϊֹ
	{
		printf("����ɨ��λ�õ�������y�Ƿ�!����������(1-%d)>:", row);
		scanf("%d", &gropeLandmine_Y);	//���û��ٴ�������Ϸѡ��
	}
	//������ϲ��ֳ���󣬵õ��ĺ�������XY��Ϊ����ֵ
	while (1)
	{
		if (soilSurfaceBoard[gropeLandmine_Y][gropeLandmine_X] == '*')		//����û�Ҫ̽�׵�λ�û�δ̽��
		{
			if (soilHorizonBoard[gropeLandmine_Y][gropeLandmine_X] == '1')	//���̽�������򷵻�'F'
			{
				return 'F';
			}
			else		//�����û��̽���ף�Ҳû�����̽�׹���������ʾ̽�׵㸽����������������ҷ���'C'
			{
				landmineCount = get_PeripheryLandmineImformation(soilHorizonBoard, gropeLandmine_X, gropeLandmine_Y);	//��ȡ̽�׵���Χ���Ź��񣩵������������������
				soilSurfaceBoard[gropeLandmine_Y][gropeLandmine_X] = (landmineCount + '0');		//��������������ֵת��Ϊ�ַ�����������������ʾ
				return 'C';
			}
		}
		else 	//����û�Ҫ̽�׵�λ����̽��
		{
			printf("��ѡ���λ���Ѿ�ɨ�����ˣ�������ѡ��Ҫɨ�׵�λ�����꣡\n");
			printf("����������ɨ��λ�õĺ�����x(1-%d)>:", col);
			scanf("%d", &gropeLandmine_X);
			while ((gropeLandmine_X < 1) || (gropeLandmine_X > col))	//����û������̽��λ��x�Ƿ�����ѭ��ֱ������Ϸ�Ϊֹ
			{
				printf("����ɨ��λ�õĺ�����x�Ƿ�!����������(1-%d)>:", col);
				scanf("%d", &gropeLandmine_X);	//���û��ٴ�������Ϸѡ��
			}

			printf("����������ɨ��λ�õ�������y(1-%d)>:", row);
			scanf("%d", &gropeLandmine_Y);
			while ((gropeLandmine_Y < 1) || (gropeLandmine_Y > row))	//����û������̽��λ��y�Ƿ�����ѭ��ֱ������Ϸ�Ϊֹ
			{
				printf("����ɨ��λ�õ�������y�Ƿ�!����������(1-%d)>:", row);
				scanf("%d", &gropeLandmine_Y);	//���û��ٴ�������Ϸѡ��
			}
		}
	}
}