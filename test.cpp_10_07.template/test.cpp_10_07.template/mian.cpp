#include"template.h"

int main()
{
	// 函数模板不支持分离编译，报链接错误，为什么？
	Add(1, 2);
	Add(1.0, 2.0);

	// 普通函数支持分离编译
	func(1, 2);

	return 0;
}