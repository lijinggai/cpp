#pragma once
#include <iostream>
#include <assert.h>
using namespace std;

namespace lj
{
	class string
	{
	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		const_iterator begin()const
		{
			return _str;
		}
		const_iterator end()const
		{
			return _str + _size;
		}
		iterator begin()
		{
			return _str;
		}
		iterator end()
		{
			return _str + _size;
		}
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_capacity, s._capacity);
			::swap(_size, s._size);
		}
		string(const char* str = "")//构造函数
		{
			_size = strlen(str);
			_capacity = _size;
			_str = new char[_capacity + 1];//capacity为容量不包括‘\0’
			strcpy(_str, str);
		}
		~string()//析构函数
		{
			delete[] _str;
			_str = nullptr;
			_capacity = _size = 0;
		}
		//string(const string& s)//拷贝构造函数
		//	:_str(new char[strlen(s._str) + 1])
		//{
		//	strcpy(_str, s._str);
		//}
		//string& operator=(const string& s)//赋值运算符重载
		//{
		//	if(_str!=s._str)
		//	{
		//		delete[] _str;
		//		_str = new char[strlen(s._str) + 1];
		//		strcpy(_str, s._str);
		//	}
		//	return *this;
		//}

		//现代写法
		string(const string& s)//拷贝构造函数
			:_str(nullptr)//交换后，如果一开始不初始化this,tmp指向随机空间，不属于它不能析构
			, _size(0)
			, _capacity(0)
		{
			string tmp(s._str);
			//swap(_str, tmp._str);
			//swap(_capacity, tmp._capacity);
			//swap(_size, tmp._size);

		}
		//s3=s1
		string& operator=(string s)//赋值运算法重载,传值传参，拷贝构造的深拷贝
		{
			//swap(_str, s._str);
			//swap(_capacity, s._capacity);
			//swap(_size, s._size);
			return *this;
		}
		const char& operator[](size_t i)const//只读
		{
			assert(i < _size);//防止越界
			return _str[i];
		}
		char& operator[](size_t i)//可读可写
		{
			assert(i < _size);//防止越界
			return _str[i];
		}
		void reserve(size_t n)//reserve
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];//+1'\0'需要
				strncpy(tmp, _str, _size + 1);
				delete[] _str;
				_str = tmp;
				_capacity = n;
			}
		}
		void resize(size_t n, char val = '\0')//resize
		{
			if (n < _size)
			{
				_size = n;
				_str[_size] = '\0';
			}
			else
			{
				if (n > _capacity)
				{
					reserve(n);
				}

				for (size_t i = _size; i < n; ++i)
				{
					_str[i] = val;
				}
				_str[n] = '\0';
				_size = n;
			}
		}
		void push_back(char ch)//尾插字符
		{
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			_str[_size] = ch;
			_size++;
			_str[_size] = '\0';
		}
		void append(const char* str)//尾插字符串
		{
			size_t len = _size + strlen(str);
			if (len > _capacity)
			{
				reserve(len);
			}
			strcpy(_str, str);
		}

		string& operator+=(char ch)//+=字符
		{
			push_back(ch);
			return *this;
		}

		// s1 += "xxxxx"
		string& operator+=(const char* str)//+=字符串
		{
			append(str);
			return *this;
		}
		string& insert(size_t pos, char ch)//插入字符
		{
			assert(pos <= _size);
			if (_size == _capacity)
			{
				reserve(_capacity == 0 ? 4 : _capacity * 2);
			}
			char* end = _str+_size;
			while (end >= _str + pos)
			{
				*(end + 1) = *end;
				--end;
			}
			_str[pos] = ch;
			_size++;
			return *this;
		}
		size_t size()//size
		{
			return _size;
		}
		char* c_str()const
		{
			return _str;
		}
		string& insert(size_t pos, const char* str)
		{
			assert(pos <= _size);
			size_t len = _size + strlen(str);
			if (len > _capacity)
			{
				reserve(len);
			}
			char* end = _str + _size;
			while (end >= _str + pos)
			{
				*(end + strlen(str)) = *(end);
				end--;
			}
			strncpy(_str + pos, str, strlen(str));
			_size += strlen(str);
			return *this;
		}
		string& erase(size_t pos, size_t len = npos)
		{
			assert(pos < _size);
			size_t leftLen = _size - pos;
			if (len >= leftLen)
			{
				_str[pos] = '\0';
				_size = pos;
			}
			else
			{
				char* start = _str + pos + len;
				strcpy(_str + pos, start);
				_size -= len;
			}
			return *this;
		}
		size_t find(char ch, size_t pos=0)
		{
			assert(pos < _size);
			for (size_t i = pos; i < _size; i++)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return npos;
		}
		size_t find(const char* str, size_t pos = 0)
		{
			assert(_size+pos < _size);

			char* ret=strstr(_str + pos, str);
			if (ret)
			{
				return ret-_str;
			}
			else
			{
				return npos;
			}
		}
		void clear()
		{
			_size = 0;
			_str[0] = '\0';
		}

	private:
		size_t _size;
		size_t _capacity;
		char* _str;
		static const size_t npos;
	};
	const size_t string::npos = -1;

	inline bool operator<(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) < 0;
	}

	inline bool operator==(const string& s1, const string& s2)
	{
		return strcmp(s1.c_str(), s2.c_str()) == 0;
	}

	inline bool operator<=(const string& s1, const string& s2)
	{
		return s1 < s2 || s1 == s2;
	}

	inline bool operator>(const string& s1, const string& s2)
	{
		return !(s1 <= s2);
	}

	inline bool operator>=(const string& s1, const string& s2)
	{
		return !(s1 < s2);
	}

	inline bool operator!=(const string& s1, const string& s2)
	{
		return !(s1 == s2);
	}
	ostream& operator<<(ostream& out, const string& s)
	{
		for (auto ch : s)
		{
			out << ch;
		}
		return out;
	}
	istream& operator>>(istream& in, string& s)
	{
		s.clear();
		char ch;
		ch = in.get();
		while (ch != ' ' && ch != '\n')
		{
			s += ch;
			ch = in.get();
		}
		return in;
	}
	istream& getlline(istream& in, string& s)
	{
		s.clear();
		char ch;
		ch = in.get();
		while ( ch != '\n')
		{
			s += ch;
			ch = in.get();
		}
		return in;
	}
	void func(const string& s)//只读
	{

		string::const_iterator it = s.begin();
		while (it != s.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

	}

	void Test1()
	{
		string s1("hello wrold");
		cout << s1.c_str() << endl;
		string s2(s1);
		string s3;
		s3 = s1;
	}
	void Test2()
	{
		string s1("hello wrold");
		cout << s1[2] << endl;
		s1[0] = 'f';
		for (size_t i = 0; i < s1.size(); i++)
		{
			cout << s1[i] << " ";
		}
		cout << endl;
	}
	void Test3()
	{
		string s1("hello wrold");
		string::iterator it = s1.begin();
		while (it != s1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
		//范围for，由迭代器支持
		for (auto ch : s1)
		{
			cout << ch << " ";
		}
		cout << endl;
	}
	void Test4()
	{
		string s1("hello wrold");
		/*s1 += '*';
		for (auto ch : s1)
		{
			cout << ch << " ";
		}
		cout << endl;
		s1 += "abcde";
		for (auto ch : s1)
		{
			cout << ch << " ";

		}
		cout << endl;
		s1.resize(30, 'x');
		for (auto ch : s1)
		{
			cout << ch << " ";
		}
		cout << endl;*/
		func(s1);//迭代器只读
	}
	void Test5()
	{
		string s1("hello wrold");
		cout << s1.c_str() << endl;
		s1.insert(5, 'a');
		cout << s1.c_str() << endl;
		s1.insert(3, "hehehe");
		cout << s1.c_str() << endl;
		s1.insert(3, "hehehe");
		cout << s1.c_str() << endl;
		s1.erase(2, 5);
		cout << s1.c_str() << endl;
		s1.erase(3);
		cout << s1.c_str() << endl;
	}
	void Test6()
	{
		string s1("hello wrold");
		cout << s1.find('x') << endl;
		cout << s1.find('w', 1) << endl;
		cout << s1.find("wrold", 0) << endl;
		cout<<s1.find("wrolr", 1) << endl;
	}
}

int main()
{
	//lj::Test1();
	//lj::Test2();
	//lj::Test3();
	//lj::Test4();
	//lj::Test5();
	lj::Test6();
	return 0;
}