#include"Date.h"
inline int GetMonthDay(int year, int month)//判断day的合法性
{
	static int arr[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	int day = arr[month];
	if (month == 2 &&
		(year % 4 == 0
			&& year % 100 != 0
			|| year % 400 == 0))
		day = 29;
	return day;
}
Date::Date(int year, int month, int day)//构造函数
{
	if (year >= 0 &&
		0 < month&& month< 13 &&
		0 < day&& day<= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
		
	}
	else
	{
		printf("错误日期");
		cout << year << "年" << month << "月" << day << "日" << endl;
	}
}
void Date::Print()//打印
{
	cout << _year << "年" << _month << "月" << _day << "日" << endl;
}

Date& Date::operator+=(int day)//
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		int num = GetMonthDay(_year, _month);
		if (_day > num)
		{
			_day -= num;
			if (++_month > 12)
			{
				_month -= 12;
				_year++;
			}
		}
	}
	return *this;

}
Date Date::operator+(int day)//+
{
	Date ret = *this;
	ret += day;//复用
	return ret;
}
Date& Date::operator-=(int day)//-=
{
	if (_day > day)
	{
		_day -= day;
	}
	while(1)
	{
		if (_day > day)
		{
			_day -= day;
			break;
		}
		else
		{
			if (--_month == 0)
			{
				_month = 12;
				_year--;
				_day += GetMonthDay(_year, _month);
			}
			else
			{
				_day += GetMonthDay(_year, _month);
			}
		}
	}
	return *this;
}
Date Date::operator-(int day)//-
{
	Date ret(*this);
	ret -= day;//复用
	return ret;
}
bool Date::operator<(const Date& cmp)
{
	if (_year < cmp._year)
	{
		return true;
	}
	else if (_year = cmp._year)
	{
		if (_month < cmp._month)
		{
			return true;
		}
		else if (_month = cmp._month)
		{
			if (_day < cmp._day)
			{
				return true;
			}

		}
	}
	return false;
}
Date Date::operator++(int)
{
	Date ret = *this;
	*this += 1;
	return ret;
}
Date& Date::operator++()
{
	*this += 1;
	return *this;
}



