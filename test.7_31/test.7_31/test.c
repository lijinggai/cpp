#include"contact.h"
void menu()
{
	printf("###########################\n");
	printf("#####1.add    2.del    ####\n");
	printf("#####3.search 4.modify ###\n");
	printf("#####5.show   6.sort ####\n");
	printf("#####0.exit       ######\n");
	printf("###########################\n");
}

int main()
{
	int input = 0;
	struct  Contact con;//	创建1000个大小的数组
	IntiContact(&con);//初始化通讯录
	do
	{
		menu();
		printf("请输入:>");
		scanf("%d", &input);
		switch (input)
		{
		case add:
			AddContact(&con);
			break;
		case del:
			DelContact(&con);
			break;
		case search:
			SearchContact(&con);
			break;
		case modify:
			ModifyContact(&con);
			break;
		case show:
			ShowContact(&con);
			break;
		case sort:
			qsortContact(&con);
			break;
		case tui:
			printf("退出成功\n");
			break;
		default:
			printf("选择错误\n");
			break;
		};
	} while (input);
	return 0;
	
}