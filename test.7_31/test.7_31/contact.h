#define _CRT_SECURE_NO_WARNINGS 1
#define MAX 1000
#define MAX_NAME 20
#define MAX_SIX 5
#define MAX_TELE 11
#define MAX_ADDR 30


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
struct PeoInfo//创建一个通讯录结构体
{
	char name[MAX_NAME];
	int age;
	char six[MAX_SIX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
};
struct Contact//通讯录类型
{
	struct PeoInfo date[MAX];
	int size;
};
enum Option//枚举选项让代码的可读性更高
{
	tui,
	add,
	del,
	search,
	modify,
	show,
	sort
};



void IntiContact(struct Contact* pc);//初始化通讯录
void AddContact(struct Contact* pc);//增加联系人
void ShowContact(const struct Contact* pc);//显示通讯录
void DelContact(struct Contact* pc);//删除联系人信息
void SearchContact(struct Contact* pc);//查找指定人的信息
void ModifyContact(struct Contact* pc);//修改信息
void qsortContact(struct Contact* pc);//排顺序