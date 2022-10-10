#include<iostream>
using namespace std;

//int main()
//{
//	int a = 1, b = 2;
//	double c = 1.1, d = 2.2;
//	//静态多态（编译时）函数重载
//	swap(a, b);
//	swap(c,d);
//	return 0;
//}

class Person {
public:
	virtual void BuyTicket() { cout << "买票-全价" << endl; }
};

class Student : public Person
{
public:
	// 子类的虚函数重写了父类的虚函数
	virtual void BuyTicket() { cout << "买票-半价" << endl; }
};

class Soldier : public Person
{
public:
	// 子类的虚函数重写了父类的虚函数
	virtual void BuyTicket() { cout << "优先-买票" << endl; }
};

void f(Person& p)
{
	// 传不同类型的对象，调用的是不同的函数，实现了调用的多种形态
	p.BuyTicket();
}

void f(Person* p)
{
	// 传不同类型的对象，调用的是不同的函数，实现了调用的多种形态
	p->BuyTicket();
}

int main()
{
	Person p; // 普通人
	Student st; // 学生
	Soldier so; // 军人

	f(p);
	f(st);
	f(so);
	cout << endl;

	f(&p);
	f(&st);
	f(&so);

	return 0;
}