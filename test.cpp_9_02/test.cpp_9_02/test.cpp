#include<iostream>

#define ADD(x,y) ((x)+(y)//宏定义函数
void Swap(int& ca, int& cb)
{
	int tmp = ca;
	ca = cb;
	cb = tmp;
}
int main()
{
	const int a = 10;
	//int& ra = a;//->ra引用a属于权限放大，所以不行

	int b = 0;
	int& rb = b;
	const int& rrb = b;//->rrb引用b属于权限缩小，所以可以

	int c = 10;
	double d = 1.11;
	//double& d = c;//为什么不可以呢
	const double& d = c;//因为隐式类型转换，c产生的double的临时变量具有常性，所以可以；
	Swap(c, b);

	//内联函数
	//c语言为了小函数避免建立栈帧的消耗-》提过了宏函数支持，预处理展开
	//已经解决，那为什么还要提供inline函数？（宏函数的缺点）面试题考点
	//1.不可以调试，2.宏函数语法复杂，容易出错（写错）3.没有类型的安全检查（add（int，int）如果传double或者其他类型没有安全检查）
	return 0;
}