#include <iostream>
using namespace std;
//struct ListNode
//{
//public:
//	ListNode(int val=0)
//	:_next(nullptr)
//	,_prev(nullptr)
//	,_val(val)
//	{}
//private:
//	ListNode* _next;
//	ListNode* _prev;
//	int _val=5;
//};
//int main()
//{
//	//operator new该函数实际通过malloc申请空间,当malloc申请成功时直接返回，申请失败，尝试执行空间不足应对措施，
//	//如果用户改应对措施了，则继续申请，否则抛异常
//	struct ListNode* p1 = (struct ListNode*)malloc(sizeof(struct ListNode));
//	free(p1);
//
//	struct ListNode* p2 = (struct ListNode*)operator new(sizeof(struct ListNode));
//	operator delete(p2);
//	return 0;
//}

//void Swap(int& x1, int& x2)//如果2个都满足，会先调用我们写的
//{
//	int tmp = x1;
//	x1 = x2;
//	x2 = tmp;
//}
//template <class T>//定义模板参数T可以用class或者typename
////泛型编程--模板
////函数模板
////template <typename T>
//void Swap(T& x1, T& x2)
//{
//	T tmp = x1;
//	x1 = x2;
//	x2 = tmp;
//}
//int main()
//{
//	int a = 1, b = 2;
//	Swap(a, b);
//	double c = 1.1, d = 2.2;
//	Swap(c, d);
//
//	//编译器会通过实参推形参的类型t非标为int和double
//	//这种方式是隐式实例化
//
//	//Add<int>(a, c);
//	//不让编译器推演类型，显示指定类型
//	//这种方式叫做显示实例化
//	return 0;
//}

//int Add(int left, int right)
//{
//	return left + right;
//}
//template<class T>
//T Add(T left, T right)
//{
//	return left + right;
//}
////模板调用，有现成匹配函数，绝对不实例化模板
////有更匹配的，优先匹配类型最合适的
//int main()
//{
//	int a = 1;
//	int b = 2;
//	double c = 2.2;
//	Add(a, b);
//	Add(a, c);
//	return 0;
//}

// 类模板
namespace Lj
{
	template<class T>
	class vector
	{
	public:
		vector()
			:_a(nullptr)
			, _size(0)
			, _capacity(0)
		{}

		// 拷贝构造和operator= 这里涉及深浅拷贝问题，还挺复杂，后面具体再讲

		~vector()
		{
			delete[] _a;
			_a = nullptr;
			_size = _capacity = 0;
		}

		void push_back(const T& x)
		{
			if (_size == _capacity)
			{
				int newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				T* tmp = new T[newcapacity];
				if (_a)
				{
					memcpy(tmp, _a, sizeof(T) * _size);
					delete[] _a;
				}
				_a = tmp;
				_capacity = newcapacity;
			}

			_a[_size] = x;
			++_size;
		}

		// 读+写
		T& operator[](size_t pos);
		size_t size();
	private:
		T* _a;
		size_t _size;
		size_t _capacity;
	};

	// 模板不支持分离编译，也就是声明在.h ,定义在.cpp，原因后面再讲
	// 建议就是定义在一个文件 xxx.h  xxx.hpp
	// 在类外面定义
	template<class T>
	T& vector<T>::operator[](size_t pos)
	{
		assert(pos < _size);

		return _a[pos];
	}

	template<class T>
	size_t vector<T>::size()
	{
		return _size;
	}
}

int main()
{
	zj::vector<int> v1;		// int
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	// v1.operator[](3);
	//cout << v1[3] << endl;
	//cout << v1[5] << endl;
	for (size_t i = 0; i < v1.size(); ++i)
	{
		v1[i] *= 2;
	}
	cout << endl;

	for (size_t i = 0; i < v1.size(); ++i)
	{
		cout << v1[i] << " ";
	}
	cout << endl;


	zj::vector<double> v2;   // double
	v2.push_back(1.1);
	v2.push_back(2.2);
	v2.push_back(3.3);
	v2.push_back(4.4);

	for (size_t i = 0; i < v2.size(); ++i)
	{
		cout << v2[i] << " ";
	}
	cout << endl;

	return 0;
}