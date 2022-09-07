#include"contact.h"
cmp_char(const void* e1,const void* e2)
{
	return *((char*)e1) - *((char*)e2);
}
static int FindByName(struct Contact* pc,char name[MAX_NAME])
//找得到返回地址i，找不到返回-1
{
	int i = 0;
	for (i = 0; i < pc->size; i++)
	{
		if (0 == strcmp(pc->date[i].name, name));
		{
			return i;
		}
	}
	return -1;
}
void IntiContact(struct Contact* pc)
{
	memset(pc->date, 0, sizeof(pc->date));
	pc->size = 0;
}
void AddContact(struct Contact* pc)
{
	if (pc->size == MAX)
	{
		printf("内容已满\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", pc->date[pc->size].name);
		printf("请输入年龄:>");
		scanf("%d",&( pc->date[pc->size].age));
		printf("请输入性别:>");
		scanf("%s", pc->date[pc->size].six);
		printf("请输入电话:>");
		scanf("%s", pc->date[pc->size].tele);
		printf("请输入地址:>");
		scanf("%s", pc->date[pc->size].addr);
		pc->size++;
		printf("添加成功\n");
	}
}
void ShowContact(const struct Contact* pc)
{
	if (pc->size == 0)
	{
		printf("没有可以打印的通讯录");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "名字", "年龄", "性别", "电话", "地址");
			for (i = 0;i < pc->size; i++)
			{
				printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\n",
					pc->date[i].name,
					pc->date[i].age,
					pc->date[i].six,
					pc->date[i].tele,
					pc->date[i].addr);
			}
	}
}
void DelContact(struct Contact* pc)
{
	char name[MAX_NAME];
	//1.找到删除人的名字
	printf("请输入查找人的名字:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("查无此人\n");
	}
	//删除这个联系人的信息
	else
	{ 
		int j = 0;
		for (j = pos; j < pc->size - 1; j++)
		{
	 		pc->date[j], pc->date[j + 1];
			pc->size--;
			printf("删除成功\n");
		}
	}
}
void SearchContact(struct Contact* pc)
{
	//1.查找人
	char name[MAX_NAME];
	printf("请输入你想查找人的名字;>");
	scanf("%s", name);
	int pos = FindByName(pc, name);

	if (pos == -1)
	{
		printf("查无此人\n");
	}
	//2.打印信息
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "名字", "年龄", "性别", "电话", "地址");
		printf("%-20s\t%-4d\t%-5s\t%-12s\t%-30s\n",
			pc->date[pos].name,
			pc->date[pos].age,
			pc->date[pos].six,
			pc->date[pos].tele,
			pc->date[pos].addr);
	}
}
void ModifyContact(struct Contact* pc)
{
	char name[MAX_NAME];
	printf("请输入要修改人的名字:>");
	scanf("%s", name);
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("查无此人\n");
	}
	else
	{
		printf("请输入名字:>");
		scanf("%s", pc->date[pos].name);
		printf("请输入年龄:>");
		scanf("%d", &(pc->date[pos].age));
		printf("请输入性别:>");
		scanf("%s", pc->date[pos].six);
		printf("请输入电话:>");
		scanf("%s", pc->date[pos].tele);
		printf("请输入地址:>");
		scanf("%s", pc->date[pos].addr);
		printf("修改成功\n");
	}
}
void qsortContact(struct Contact* pc)
{
	qsort(pc->date,pc->size, sizeof(char), cmp_char);
}