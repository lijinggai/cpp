#include<stdio.h>
#include<string.h>
#pragma once
//鼠、牛、虎、兔、蛇、马、羊、猴、鸡、狗、猪以及传说中的龙
void Zodiac(int x)//switch判断生肖
{
	switch (x)
	{
	case 1:
		printf("你的生肖是鼠");
		break;
	case 2:
		printf("你的生肖是牛");
		break;
	case 3:
		printf("你的生肖是虎");
		break;
	case 4:
		printf("你的生肖是兔");
		break;
	case 5:
		printf("你的生肖是蛇");
		break;
	case 6:
		printf("你的生肖是马");
		break;
	case 7:
		printf("你的生肖是羊");
		break;
	case 8:
		printf("你的生肖是猴");
		break;
	case 9:
		printf("你的生肖是鸡");
		break;
	case 10:
		printf("你的生肖是狗");
		break;
	case 11:
		printf("你的生肖是猪");
		break;
	case 12:
		printf("你的生肖是龙");
		break;
	}
	printf("\n");
}
void Constellation(month, day)//switch判断星座
{
	switch (month)
	{
	case 1:
		if(day<=19)
			printf("你的星座是摩羯座");
		else
			printf("你的星座是水瓶座");
		break;
	case 2:
		if (day <= 18)
			printf("你的星座是水瓶座");
		else
			printf("你的星座是双鱼座");
		break;
	case 3:
		if (day <= 20)
			printf("你的星座是双鱼座");
		else
			printf("你的星座是白羊座");
		break;
	case 4:
		if (day <= 20)
			printf("你的星座是白羊座");
		else
			printf("你的星座是金牛座");
		break;
	case 5:
		if (day <= 20)
			printf("你的星座是金牛座");
		else
			printf("你的星座是双子座");
		break;
	case 6:
		if (day <= 21)
			printf("你的星座是双子座");
		else
			printf("你的星座是巨蟹座");
		break;
	case 7:
		if (day <= 22)
			printf("你的星座是巨蟹座");
		else
			printf("你的星座是狮子座");
		break;
	case 8:
		if (day <= 22)
			printf("你的星座是狮子座");
		else
			printf("你的星座是处女座");
		break;
	case 9:
		if (day <= 22)
			printf("你的星座是处女座");
		else
			printf("你的星座是天秤座");
		break;
	case 10:
		if (day <= 22)
			printf("你的星座是天秤座");
		else
			printf("你的星座是天蝎座");
		break;
	case 11:
		if (day <= 21)
			printf("你的星座是天蝎座");
		else
			printf("你的星座是射手座");
		break;
	case 12:
		if (day <= 2)
			printf("你的星座是射手座");
		else
			printf("你的星座是摩羯座");
		break;
	}
	printf("\n");
}

int main()
{
	//50024220030512
	char name[10];
	char ID[19];
	printf("请输入你的名字：");
	scanf("%s", name);
	printf("请输入你的身份证号码：");
	scanf("%s", ID);
	//char* pID = ID;
	//char year[5];
	//char* pyear=year;
	//strncpy(year, pID + 6, 4);
	//year[4] = '\0';
	int year=0,month=0,day=0;
	int index = 1;
	for (int i = 0; i < 4; i++)//取出日期
	{
		
		year +=(ID[9 - i] - '0') * index;
		if (i < 2)
		{
			month += (ID[11 - i] - '0')*index;
			day += (ID[13 - i] - '0') * index;

		}
		index *= 10;
	}
	if ((ID[16] - '0') % 2 == 0)//即奇偶数判断男女
		printf("%s女士\n",name);
	else
		printf("%s男士\n", name);
	printf("你的出生在\%d年，", year);
	Zodiac(year % 12);//switch判断生肖
	printf("你的生日是%d月%d日，",month,day);
	Constellation(month,day);//switch判断星座
	return 0;
}