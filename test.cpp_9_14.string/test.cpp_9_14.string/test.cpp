#include <iostream>
#include <string>
using namespace std;

//int main()
//{
//	//ascall编码
//	char ah1 = 'a';
//	char ah2 = 97;
//	cout << ah1 << endl;
//	cout << ah1 << endl;
//	char str[] = "中国";
//	str[3] = -6;
//
//	cout << str << endl;
//	return 0;
//}

int main()
{
	string s1;
	string s2("hello wrold");
	string s3(s2);
	//3种遍历方式
	//1.下标+[]
	for (size_t i = 0; i < s2.size(); ++i)
	{
		cout << s2[i] << " ";
	}
	cout << endl;
	//2.迭代器
	//[begin(),end())end()返回的不是最后一个数据位置的迭代器，返回的是最后一个位置下一个位置
	//也要注意的是，c++中凡是给迭代器一般都是给的{)左闭右开的区间
	//迭代器是类似指针一样的东西
	string::iterator it = s2.begin();
	while (it != s2.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	//const修饰只读
	string s4 = "123456";
	//class Solution {
	//public:
	//	int firstUniqChar(const string s)
	//	{
	//		int count[26] = { 0 };
	//		string::const_iterator it = s.begin();
	//		while(it!=s.end())
	//		{
	//			count[*it - 'a']++;
	//		}
	//		for (int i = 0; i < s.size(); i++)
	//		{
	//			if (count[s[i] - 'a'] == 1)
	//				return i;
	//		}
	//		return -1;
	//	}
	//};
	//反向迭代器
	string::reverse_iterator rit = s4.rbegin();
	while (rit != s4.rend())
	{
		*rit += 1;
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
	//迭代器意义：像string，vector支持[]遍历，但是list，map等等容器不支持{
	//我们就要用迭代器遍历，所以迭代器是一种统一使用的方式

	//c++11,3.范围for
	//依次取容器的值赋给e，自动判断结束
	for (auto e : s4)
	{
		//e+=1;//需要引用
		cout << e << " ";
	}
	cout << endl;
	return 0;
}