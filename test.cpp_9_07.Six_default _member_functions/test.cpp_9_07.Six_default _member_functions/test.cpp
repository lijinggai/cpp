
#include<iostream>
using namespace std;
//六大默认成员函数：
// 构造函数--初始化，大部分时候需要我们自己写
// 析构函数--清理对象中的资源
// 拷贝析构函数--拷贝初始化，特殊构造函数   深浅拷贝问题
// 赋值运算符重载--也是拷贝行为，但是不一样的是，拷贝构造是创造一个对象时，拿同类的对象初始化的拷贝
// 这里复制拷贝是对象已经存在了，都被初始化过，想把一个对象复制拷贝给另一个对象
//我们不写编译器会自动生成，虽然会自动生成，但是大多时候还是需要我们自己写但是生成的不一定好用
//默认构造函数：1.编译器生成2.无参的构造函数3.全缺省的构造函数
//析构函数：我们不需要写，对象内没有资源清理，编译器默认生成的就够用
//默认生成的析构函数基本上也不做什么事情，release下优化，就没了
//总结：
//构造和析构的特性是类似的，我们不写编译器会自动生成一个，内置类型不处理，自定义类型会调用它的构造和析构
//拷贝构造和赋值运算符重载是类似的，内置类型会完成浅拷贝，自定义类型会调用他们的拷贝构造和赋值重载
class Date
{
public:
	//Date()
	////{
	////	_year = 2022;
	////	_month = 9;
	////	_day = 12;
	////}
	Date(int year = 2022,int month = 9,int day = 13)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//Date(Date& d)//
	//{
	//	_year = d._year;
	//	this->_month = d._month;
	//	this->_day = d._day;
	//}
	//默认成员函数，我们不写编译器也会自动生成
	//这个拷贝构造会对内置类型完成浅拷贝或者值拷贝
	Date& operator=(Date& d)//赋值运算符重载
	{
		if(this!=&d)
		{
			_year = d._year;
			this->_month = d._month;
			this->_day = d._day;
			return *this;
		}
	}
	void Print()
	{
		cout << _year << "-" << _month << "-" << _day << endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
class Stack
{
public:
	Stack(int capacity = 4)
	{
		if (capacity == 0)
		{
			_a = nullptr;
			_size = _capacity = 0;
		}
		else
		{
			_a = (int*)malloc(sizeof(capacity));
			_size = _capacity = capacity;
		}
	}
	~Stack()
	{
		free(_a);
		_size = _capacity = 0;
		_a = nullptr;
	}

private:
	int* _a;
	int _size;
	int _capacity;
};
int main()
{
	Date d1(2021, 3, 12);
	Date d2(d1);
	Date d3;
	d3 = d1;
	d3.Print();
	return 0;
}

