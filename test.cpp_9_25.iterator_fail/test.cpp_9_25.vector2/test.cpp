#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void vector_test()
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
		it++;
	}
	cout << endl;
	vector<int>::iterator pos=find(v.begin(), v.end(), 3);
	if (pos != v.end())//如果没有找到会返回v.end()的位置
	{
		v.insert(pos, 30);
	}
	for (auto ch : v)
	{
		cout << ch << " ";
	}
	cout << endl;
	pos = find(v.begin(), v.end(), 3);
	v.erase(pos);
	for (auto e : v)
	{
		cout << e << " ";
	}
}
void vector_test1()
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
		it++;
	}
	cout << endl;
	vector<int>::iterator it1 = v.begin();
	while (it1 != v.end())
	{
		if (*it1 % 2 == 0)
		{
			v.erase(it1);
		}
		else
		{
			it1++;
		}
	}
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	
}
void vector_test2()
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
		it++;
	}
	cout << endl;
	vector<int>::iterator pos = find(v.begin(), v.end(), 4);
	if (pos != v.end())//找不到返回end（）
	{
		v.insert(pos, 40);
	}
	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
	pos = find(v.begin(), v.end(), 4);
	v.insert(pos,400);
}
int main()
{
	//vector_test();
	//vector_test1();
	vector_test2();
	return 0;
}