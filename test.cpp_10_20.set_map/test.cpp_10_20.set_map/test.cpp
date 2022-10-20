#include <iostream>
#include<string>
#include <set>
using namespace std;

void test_set1()
{
	set<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(2);
	s.insert(14);
	s.insert(36);
	s.insert(4);
	s.insert(3);
	s.insert(3);

	// 1、排序+去重
	// 遍历方式1：
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		// 不能修改已经插入的值
		// *it += 1;

		cout << *it << " ";
		++it;
	}
	cout << endl;

	set<int>::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	// 遍历方式2：
	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;

	// 检查单词拼写是否正确
	// 思路：词库中单词都放进set的对象中，把每个写出来的单词
	// 去set中查一下，在不在，在就是正确的，不在就是错误的拼写
	set<string> strSet;
	strSet.insert("sort");
	strSet.insert("left");
	strSet.insert("right");
	strSet.insert("insert");

	for (const auto& e : strSet)
	{
		cout << e << " ";
	}
	cout << endl;

	// ...
	set<string>::iterator ret = strSet.find("sort");
	if (ret != strSet.end())
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没有找到" << endl;
	}

	ret = strSet.find("map");
	if (ret != strSet.end())
	{
		cout << "找到了" << endl;
	}
	else
	{
		cout << "没有找到" << endl;
	}
}

void test_set2()
{
	set<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(2);
	s.insert(14);
	s.insert(36);
	s.insert(4);
	s.insert(3);
	s.insert(3);

	// 先查找，找到了再删。没找到，也去删会报错
	auto pos = s.find(4);
	if (pos != s.end())
	{
		s.erase(pos);
	}

	pos = s.find(40);
	//s.erase(pos);
	if (pos != s.end())
	{
		s.erase(pos);
	}

	// 在就删除，不在就不处理也报错
	s.erase(3);
	s.erase(30);

	for (auto e : s)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test_set3()
{
	// multiset允许键值冗余，使用方法基本跟set一致
	// 就下面几个地方有一些差异
	multiset<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(2);
	s.insert(14);
	s.insert(36);
	s.insert(4);
	s.insert(3);
	s.insert(3);
	s.insert(3);

	// 排序
	multiset<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	// find查找的val有多个的时候，那么他找到的是中序的第一个
	multiset<int>::iterator pos = s.find(3);
	while (*pos == 3)
	{
		cout << *pos << endl;
		++pos;
	}
	cout << s.count(3) << endl;
	cout << s.count(4) << endl;

	s.erase(3);
	it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

int main()
{

	return 0;
}