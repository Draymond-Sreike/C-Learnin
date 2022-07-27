#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void main()
{
	int day;
	scanf("%d", &day);

	//switch语句的执行逻辑一定是按照case从上到下的顺序
	//于其中找到对应的变量值后作为入口，然后有串联趋势地去执行入口及入口以下部分的代码

	switch (day)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("工作日\n");
		break;
	case 6:
	case 7:
		printf("休息日\n");
		break;
	default:
		printf("您的输入有误\n");
		break;
	}
	//short i;
	//for (i = 1; i <= 100; i++)
	//{
	//	if (i % 2 == 1)
	//	{
	//		printf("%d ", i);
	//	}
	//}
	//short age = 18;
	//if (age >= 18)
	//{
	//	printf("已经成年\n");
	//	printf("可以谈恋爱\n");
	//}
	////printf("可以谈恋爱\n");
	////if与其他同分支的判断语句之间不能有其他的语句
	////否则回导致上面的if与下面的else或else if匹配不了
	//else
	//{
	//	printf("未成年\n");
	//}
}
