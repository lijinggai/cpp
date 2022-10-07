#include"template.h"

void func(int a, int b);

template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}

void func(int a, int b)
{
	cout << a << endl;
	cout << b << endl;
}

//template
//int Add<int>(const int& left, const int& right);
//template
//double Add<double>(const double& left, const double& right);