#include "singleton.h"


int Count = 0;
//GetInformation GetInformation::instance(10);//定义，静态成员可以用类名+::访问
GetInformation* GetInformation::instance=nullptr;//定义，静态成员可以用类名+::访问
GetInformation::CGarbo _CGarbo;//垃圾回收

void func()
{
	for (int i = 10; i > 0; i--)
	{
		++Count;
		GetInformation::GetInstance().Add(1);
		;
	}
}