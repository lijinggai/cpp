#include<iostream>
#include<algorithm>
#include<assert.h>
#include<string>
using namespace std;

namespace lj
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		const_iterator begin()const
		{
			return _start;
		}
		const_iterator end()const
		{
			return _finish;
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		vector()
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{}
		// 类模板的成员函数，还可以再是函数模板
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
			: _start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}
		vector(const vector<T>& v)//拷贝构造
			:_start(nullptr)
			,_finish(nullptr)
			,_endofstorage(nullptr)
		{
			_start = new T[v.capacity()];
			/*memcpy(_start, v._start, sizeof(T) * v.capacity());*/
			for (size_t i = 0; i < v.size(); i++)//解决深层次的深浅拷贝
			{
				
				_start[i] = v._start[i];
			}
			_endofstorage = _start + v.capacity();
			_finish = _start + v.size();
		}
		vector<T>& operator=(vector<T> v)
		{
			swap(_start, v._start);
			swap(_finish, v._finish);
			swap(_endofstorage, v._endofstorage);
			return *this;
		}
		/*vector<T>& operator=(const vector<T>& v)
		{
			if(_start!=v._start)
			{
				delete[] _start;
				_start = new T[v.capacity()];
				memcpy(_start, v._start, sizeof(T) * v.capacity());
				_endofstorage = _start + v.capacity();
				_finish = _start + v.size();
			}
			return *this;
		}*/
		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity()const
		{
			return _endofstorage - _start;
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				iterator tmp = new T[n];
				if (_start)//start不为为空
				{
					//memcpy(tmp, _start, sz*sizeof(T));
					for (size_t i = 0; i << sz; i++)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = _start+sz;//finish还为0，start新空间，size()会返回很大的负值
				_endofstorage=_start+n;//endofstorage还为0，start新空间，capacity()会返回很大的负值
			}
		}
		void resize(size_t n, T val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);

				}
				for (size_t i = size(); i < n; i++)
				{
					*_finish = val;
					_finish++;
				}
			}
		}
		bool empty()
		{
			return _start == _finish;
		}
		void push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);
			}
			*_finish = x;
			_finish++;
		}
		void pop_back()
		{
			assert(!empty());
			--_finish;
		}
		void insert(iterator pos, const T& x)
		{
			size_t sz = pos - _start;
			if (_finish == _endofstorage)//判断增容
			{
				size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
				reserve(newCapacity);
				//更新pos，防止迭代器失效
				pos = _start + sz;
			}
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*end = x;
			++_finish;
		}
		iterator erase(iterator pos)
		{
			iterator it = pos + 1;
			while (it != end())
			{
				*(it - 1) = *it;
				++it;
			}
			_finish--; 
			return pos;
		}
		void PrintVector()const
		{
			vector<T>::const_iterator it = this->begin();
			while (it != this->end())
			{
				//*it += 1;//只能读，不能写
				cout << *it << " ";
				++it;
			}
			cout << endl;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
		v.PrintVector();
	}
	void test_vector2()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		//v.pop_back();
		v.resize(3);
		v.resize(6,1);
		v.resize(12,2);
		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
	}
	void test_vector3()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		vector<int>::iterator pos = find(v.begin(), v.end(), 3);
		v.insert(pos, 30);
		v.PrintVector();
	}
	void test_vector4()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);
		vector<int>::iterator pos = find(v.begin(), v.end(), 3);
		v.erase(pos);
		v.PrintVector();
	}
	void test_vector5()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		vector<int> v1(v);
		vector<int> v2;
		v1=v2=v;

		v.PrintVector();
		v1.PrintVector();
		v2.PrintVector();
	}
	void test_vector6()
	{
		vector<string> v;
		v.push_back("111111111111111111");
		v.push_back("2222");
		v.push_back("3333");
		v.push_back("4444");
		v.push_back("5555");
		vector<string> v1(v);


		v.PrintVector();
		v1.PrintVector();
	}
}
int main()
{
	//lj::test_vector1();
	//lj::test_vector2();
	//lj::test_vector3();
	lj::test_vector6();
	return 0;
}
