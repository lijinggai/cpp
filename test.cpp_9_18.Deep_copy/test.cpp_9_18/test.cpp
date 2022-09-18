#include <iostream>
using namespace std;
//
//namespace lj
//{
//	class string
//	{
//	public:
//		string(const char* str)
//		{
//			_str = new char[strlen(str) + 1];
//			strcpy(_str, str);
//		}
//		char& operator[](size_t i)
//		{
//			return _str[i];
//		}
//		size_t size()
//		{
//			return strlen(_str);
//		}
//	private:
//		char* _str;
//	};
//}
//
//int main()
//{
//	lj::string s("hello world");
//	cout << s[2] << endl;
//	cout << s.operator[](2) << endl;
//	//s[2] += 1;
//
//	for (size_t i = 0; i < s.size(); ++i)
//	{
//		cout << s[i] << " ";
//	}
//	cout << endl;
//
//	for (size_t i = 0; i < s.size(); ++i)
//	{
//		s[i] += 1;
//	}
//
//	for (size_t i = 0; i < s.size(); ++i)
//	{
//		cout << s[i] << " ";
//	}
//	cout << endl;
//
//	return 0;
//}
namespace lj
{
	class string
	{
	public:
		string(const char* str = "")
			:_str(new char[strlen(str) + 1])
		{
			strcpy(_str, str);
		}

		// s2(s1)
		string(const string& s)
			:_str(new char[strlen(s._str) + 1])
		{
			strcpy(_str, s._str);
		}

		// s1 = s3
		string& operator=(const string& s)
		{
			if (this != &s)
			{
				delete[] _str;
				_str = new char[strlen(s._str) + 1];
				strcpy(_str, s._str);
			}

			return *this;
		}

		char& operator[](size_t i)
		{
			return _str[i];
		}

		size_t size()
		{
			return strlen(_str);
		}

		~string()
		{
			cout << "~string()" << endl;
			delete[] _str;
			_str = nullptr;
		}
	private:
		char* _str;
	};
}
int main()
{
	lj::string s1("hello world");
	lj::string s2(s1);
	lj::string s3("hello bit");

	s1 = s3;

	return 0;
}