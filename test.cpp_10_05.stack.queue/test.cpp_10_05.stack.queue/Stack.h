#pragma once
#include<iostream>
#include<vector>
#include<deque>
using namespace std;
//namespace lj
//{
//	常规方法
//	template<class T>
//	class stack
//	{
//	public:
//
//	private:
//		T* _a;
//		size_t _size;
//		size_t _capacity;
//	};
//}
namespace lj
{
	template<class T, class Container = deque<T>>
	class stack
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}
		void pop()
		{
			_con.pop_back();
		}
		T top()
		{
			return _con.back();
		}
	private:
		Container _con;
	};
}