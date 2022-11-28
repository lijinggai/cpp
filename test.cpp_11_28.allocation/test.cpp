#include<iostream>
using namespace std;

//volatile int a = 0;//常量区不能写入
//int main()
//{
//	//int i = 12;
//	//int* p = &i;
//	//// 显示的强制类型转换
//	//int address = (int)p;
//	//printf("%x, %d\n", p, address);
//
//
//	////c++
//	//double a = 10.12;
//	//double b = 20.12;
//	//int c = static_cast<int>(a+b);//相近类型的显示类型转换
//	//cout << c << endl;
//	//printf("%d\n", c);
//
//
//	//int d = 0;
//	//int* p = &d;
//	//int address = reinterpret_cast<int>(p);//不相近类型的显示类型转换
//	//printf("%x, %d\n", p, address);
//
//
//	//const int a = 5;//优化：看到const直接取常量，不去使用地址取值
//	volatile const int a = 5;//禁止编译器优化volatile
//	int* p = const_cast<int*>(&a);
//	*p = 10;
//	cout << a << endl;
//	cout << *p << endl;
//
//	return 0;
//}


//class A
//{
//	virtual void f() {}
//public:
//};
//
//class B : public A
//{
//public:
//	int _b = 0;
//};
//
//// 1、pa指向父类对象
//// 2、pa指向子类对象
//void func(A* pa)
//{
//	// 如果pa是指向父类对象，那么不做任何处理
//	// 如果pa是指向子类对象，那么请转回子类，并访问子类对象中_b成员
//	// dynamic_cast--如果pa指向的父类对象，那么则转换不成功，返回nullptr
//	//               如果pa指向的子类对象，那么则转换成功，返回对象指针
//	B* pb1 = dynamic_cast<B*>(pa);
//	if (pb1 == nullptr)
//	{
//		cout << "转换失败" << endl;
//	}
//	else
//	{
//		cout << "pb1:" << pb1 << endl;
//		pb1->_b++;
//	}
//
//	// dynamic_cast会先检查是否能转换成功，能成功则转换，不能则返回
//	B* pb1 = static_cast<B*>(pa);
//	B* pb2 = dynamic_cast<B*>(pa);
//
//	cout << "pb1:" << pb1 << endl;
//	cout << "pb2:" << pb2 << endl;
//}
//
//int main()
//{
//	A aa;
//	B bb;
//	func(&aa);
//	func(&bb);
//
//	//aa = bb;
//	//bb = reinterpret_cast<B>(aa); // 不允许
//}