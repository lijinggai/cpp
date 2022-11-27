//#include<iostream>
//using namespace std;
//// 请设计一个类，只能在堆上创建对象
//class HeapOnly
//{
//public:
//	static HeapOnly* CreateObj()
//	{
//		return new HeapOnly;
//	}
//
//	HeapOnly(const HeapOnly& ho) = delete;
//private:
//	HeapOnly()
//		:_a(0)
//	{}
//private:
//	int _a;
//};
//
//class StackOnly
//{
//public:
//	static StackOnly CreateObj()
//	{
//		return StackOnly();
//	}
//
//	void* operator new(size_t size) = delete;
//	void operator delete(void* p) = delete;
//private:
//	StackOnly()
//		:_a(0)
//	{}
//
//private:
//	int _a;
//};

//int main()
//{
//	//HeapOnly ho1;
//	//HeapOnly* pho = new HeapOnly;
//	HeapOnly* ptr1 = HeapOnly::CreateObj();
//	//HeapOnly copy(*ptr);
//
//	//StackOnly* ptr2 = new StackOnly;
//	StackOnly obj = StackOnly::CreateObj();
//	//StackOnly* ptr3 = new StackOnly(obj);
//


//class A
//{
//public:
//	A(const int& a=0)
//		:_a(a)
//	{}
//	A(const A& a);
//private:
//	int _a;
//};
//A::A(const A& a)
//{
//	_a = a._a;
//}
//int main()
//{
//	A a1;
//	A a2=a1;
//	return 0;
//}


#include "singleton.h"


int main()
{
	
	func();
	cout << "count:" << Count << endl;
	cout << "getcount:" << GetInformation::GetInstance().GetConut() << endl;
	return 0;
}