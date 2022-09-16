#include <iostream>
#include <string>
using namespace std;

//int main()
//{
//	string s1("hello wrold");
//	cout << s1 << endl;
//	s1.clear();
//	cout << s1 << endl;
//	return 0;
//}
 

//int main()
//{
//	string s2("hello wrold");
//	cout << "size:" << s2.size() << endl;
//	cout << "capacity:" << s2.capacity() << endl;
//	cout << s2 << endl;
//	
//	//没有pos默认'\0'
//	s2.resize(20);//改变size，如果容量不够会扩容
//	cout << "size:" << s2.size() << endl;
//	cout << "capacity:" << s2.capacity() << endl;
//	cout << s2 << endl;
//
//	s2.resize(5,'x');//缩小，不会改变容量，也不会把‘x’填入
//	cout << "size:" << s2.size() << endl;
//	cout << "capacity:" << s2.capacity() << endl;
//	cout << s2 << endl;
//
//	string s3("hello world");
//	s3.reserve(50);
//	cout << "size:" << s3.size() << endl;
//	cout << "capacity:" << s3.capacity() << endl;
//	cout << s3 << endl;
//
//	string s4;
//	s4.reserve(127);//先增容解决
//	//s4.resize(127);//改变容量的同是也改变size，后续还是会增容
//	size_t chOld = s4.capacity();
//	for (int ch = 0; ch < 127; ch++)
//	{
//		//多次增容效率低
//		if (chOld != s4.capacity())
//		{
//			cout << "增容" << chOld << "->" << s4.capacity()<<endl;
//			chOld = s4.capacity();
//		}
//		s4 += ch;
//	}
//	cout << s4 << endl;
//	return 0;
//}


//int main()
//{
//	string s1("hello world");
//	cout << s1 << endl;//调用operator(cout,s1)
//	cout << s1.c_str() << endl;//调用operator<<(cout,char*)
//	s1.resize(30);
//	s1 += "!!!";
//	cout << s1 << endl;//调用operator(cout,s1)
//	cout << s1.c_str() << endl;//调用operator<<(cout,char*)
//
//	cout << s1.size() << endl;
//	cout << strlen(s1.c_str()) << endl;//可以配合一些C语言函数使用
//	return 0;
//}


//int main()
//{
//	string s1("test.cpp");
//	size_t pos = s1.find('.');
//	if (pos != -1)
//	{
//		//string suff(s1, pos);
//		//cout << suff << endl;
//		string suff = s1.substr(pos);
//		cout << suff << endl;
//	}
//
//	return 0;
//}

string GetDomain(const string& url)
{
	size_t pos = url.find("://");
	if (pos != string::npos)
	{
		size_t start = pos + 3;
		size_t end = url.find('/', start);
		if (end != string::npos)
		{
			return url.substr(start, end - start);
		}
		else
		{
			return string();
		}
	}
	else
	{
		return string();
	}
}

string GetProtocol(const string& url)
{
	size_t pos = url.find("://");
	if (pos != string::npos)
	{
		return url.substr(0, pos - 0);
	}
	else
	{
		//string s;
		//return s;
		return string();
	}
}
int main()
{
		// 要求写一个程序分别取出域名和协议名
	string url1 = "http://www.cplusplus.com/reference/string/string/rfind/";
	string url2 = "https://tower.im/users/sign_in";
	string url3 = "tower.im/users/sign_in";

	cout << GetDomain(url1) << endl;
	cout << GetProtocol(url1) << endl;

	cout << GetDomain(url2) << endl;
	cout << GetProtocol(url2) << endl;

	//cout << GetProtocol(url3) << endl;
	return 0;
}