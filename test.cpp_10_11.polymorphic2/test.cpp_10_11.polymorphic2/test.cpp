#include <iostream>
using namespace std;

////抽象类--无法实例化对象
////1、可以更好的去表示现实世界中，没有实例对象对应的抽象类型  比如：植物、人、动物
////2、体现接口继承，强制子类去重写虚函数(不重写，子类也是抽象类)
//// 要注意跟override区分，override检查子类虚函数是否完成重写。
//class Person
//{
//public:
//	//纯虚函数
//	virtual void jog() = 0;
//};
//class Student:public Person
//{
//public:
//	virtual void jog()
//	{
//		cout << "void jog" << endl;
//	}
//};
//int main()
//{
//	//Person p;
//	Student s;
//	Person* ps = &s;
//	ps->jog();
//	return 0;
//}

//// 这里常考一道笔试题：sizeof(Base)是多少？
//class Base
//{
//public:
//	virtual void Func1()
//	{
//		cout << "Func1()" << endl;
//	}
//
//	virtual void Func2()
//	{
//		cout << "Func2()" << endl;
//	}
//
//	void Func3()
//	{
//		cout << "Func3()" << endl;
//	}
//
//private:
//	int _b = 1;
//	char _ch = '\0';
//};
//
//int main()
//{
//	Base bs;
//	cout << sizeof(Base) << endl;
//	return 0;
//}