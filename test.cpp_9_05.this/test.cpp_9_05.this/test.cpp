
#include<iostream>
using namespace std;
//class Date{
//public:
//	void Init(int year, int month, int day)
//	//编译器会增加一个隐含的this指针，void Init(Date* this(隐含),int year, int month, int day)
//	//1.this指针是隐含的，是编译器在编译阶段加的，我们不能显示在调用和在函数定义加
//	//2.可以在成员函数加
//	//this指针存在栈上
//	{
//		this->_year = year;
//		this->_month = month;
//		_day = day;
//	}
//
//private:
//	//
//	int _year;
//	int _month;
//	int _day;
//};
//int main()
//{
//	Date d1;
//	cout << "d1:" << &d1 << endl;
//	d1.Init(2022, 9, 5);
//	Date d2;
//	d2.Init(2022, 9, 17);
//	cout << "d2:" << &d2 << endl;
//	return 0;
//}

class A{
public:
	void Print()
	{
		cout << _a << endl;
	}
	void Show()
	{
		cout << "show" << endl;
	}

private:
	int _a;
};
int main()
{
	A* pa = nullptr;
	//pa->Print();
	//pa->Show();
	return 0;
}