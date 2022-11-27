#pragma once
#include<iostream>
using namespace std;

extern int Count ;
void func();

////饿汉模式
//class GetInformation
//{
//public:
//	static GetInformation& GetInstance()
//	{
//		return instance;
//	}
//	void Add(const int n)
//	{
//		instance._count += n;
//	}
//	int GetConut()
//	{
//		return instance._count;
//	}
//	GetInformation(const GetInformation& instance)=delete;
//private:
//	GetInformation(int n=0)
//		:_count(n)
//	{}
//	int _count;
//	static GetInformation instance;//声明
//};


//懒汉模式
class GetInformation
{
public:
	static GetInformation& GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new GetInformation;
		}
		return *instance;
	}
	//static GetInformation& GetInformation()
	//{
	//	// C++98 中多线程调用时，static sInst对象构造初始化并不能保证下线程安全
	//	// C++11 优化了这个问题，C++11中static sInst对象构造初始化是线程安全的
	//	static GetInformation instance;

	//	return instance;
	//}
	void Add(const int n)
	{
		instance->_count += n;
	}
	int GetConut()
	{
		return instance->_count;
	}
	GetInformation(const GetInformation& instance) = delete;
	GetInformation(int n = 0)
		:_count(n)
	{}
	// 实现一个内嵌垃圾回收类 
	// 一般懒汉的单例对象，不需要回收，因为进程正常结束，资源都会还给系统，这个对象只有一个系统自动回收也没什么问题
	// 但是如果你在单例对象释放析构时，有一些要完成的动作，比如要记录日志等等。那么可以考虑搞一个类似下面的回收类帮助去完成这个事情
	class CGarbo
	{
		~CGarbo()
		{
			if (instance != nullptr)
			{
				delete instance;
			}
		}
	private:
	};
private:
	static CGarbo _CGarbo;

	int _count;
	static GetInformation* instance;//声明
};
