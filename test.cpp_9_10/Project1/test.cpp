#include <iostream>

using std::cout;
using std::cin;
using std::ostream;
using std::istream;
using std::endl;
//class Date
//{
//public:
//	friend ostream& operator<<(ostream& out, Date& d);
//	friend istream& operator>>(istream& in, Date& d);
//
//	Date(int year=2022, int month=2, int day=2)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& out,Date& d)
//{
//	out << d._year << "-" << d._month << "-" << d._day << endl;
//	return out;//为什么有返回值，用于连续访问
//}
//istream& operator>>(istream& in, Date& d)
//{
//	in >> d._year >> d._month >> d._day ;
//	return in;//用于连续访问
//}
//int main()
//{
//	Date d;
//	cin >> d;
//	cout << d;
//	return 0;
//}
class A
{
public:
	A(int a)
	{
		cout << "A" << endl;
		_a = a;
	}
private:
	int _a;

};
class Date
{
public:
	//可以理解成，一个对象的成员变量在初始化列表是
	//这个可以算是初始化列表和函数体内初始化不同的地方，也是它价值的体现
	Date(int year = 2022, int month = 2, int day = 2)
		//有三种必须在初始化列表初始化
		:_year(year)
		, _c(year)//引用成员变量
		, _n(10)//const成员变量
		, _a(20)//自定义类型成员（类没有默认构造函数）
	{
		_year = year;//函数结构体内初始化
		_month = month;
		_day = day;
		//不能在函数体内初始化，必须使用初始化列表初始化
		_c = year;
		_n = 10;
		/*_a = 10;*/
	}


private:
	//成员变量声明
	int _year;
	int _month;
	int _day;
	//必须在定义时候初始化
	const int _n;
	int& _c;
	A _a;
};
int main()
{
	Date d1;
	return 0;
}