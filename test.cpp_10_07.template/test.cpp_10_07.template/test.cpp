#include<iostream>
using namespace std;

////#define N 100
//// 模板参数
//// 类型模板参数
//// 非类型模板参数 -- 整形常量
//template<class T=int,size_t N=100>
//class Array
//{
//public:
//private:
//	T _a[N];
//};
//int main()
//{
//	Array<int, 100> a1;
//	Array<int,1000> a2;
//
//	return 0;
//}
//template<class T>
//bool IsEqual(const T& left, const T& right)
//{
//	return left == right;
//}
//bool IsEqual(const char* left, const char* right)
//{
//	return strcmp(left, right) == 0;
//}
//int main()
//{
//	const char p1[] = "hello";
//	const char p2[] = "hello";
//	cout<< IsEqual(p1,p2) << endl;
//	const char* p3 = "hello";
//	const char* p4 = "hello";
//	cout << IsEqual(p3, p4);
//	return 0;
//}

template<class T1, class T2,class T3>
class Date
{
public:
	Date() { cout << "Date<T1, T2, T3>" << endl; }
private:
	T1 _year;
	T2 _month;
	T3 _day;
};

// 假设针对T1 T2是 int int想做一些特殊化那么怎么办 ？ -- 类模板特化
// -- 全特化
template<>
class Date < int, int, int >
{
public:
	Date() { cout << "Date<int, int, int >" << endl; }
};

// 将第二个参数特化为int --偏特化
template <class T1>
class Date < T1, int, int >
{
public:
	Date() { cout << "Date<T1, int, int >" << endl; }
};

// 偏特化 指定如何模板参数是指针，就走我
template <class T1, class T2,class T3>
class Date <T1*, T2*,T3*>
{
public:
	Date() { cout << "Date<T1*, T2*, T3* >" << endl; }
};

template <class T1, class T2,class T3>
class Date < T1&, T2& , T3& >
{
public:
	Date() { cout << "Date<T1&, T2& ,T3& >" << endl; }
};

template <class T1, class T2>
class Date < T1&, T2* , int>
{
public:
	Date() { cout << "Date<T1&, T2* ,int>" << endl; }
};

int main()
{
	Date<int, int,int> d1;
	Date<int, double,char> d2;
	Date<double, int,int> d3;
	Date<double*, int*,int*> d4;
	Date<int*, int*,int*> d5;
	Date<int&, int&,int&> d6;
	Date<int&, int*,int> d7;

	return 0;
}