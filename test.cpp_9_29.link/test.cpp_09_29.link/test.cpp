#include<iostream>
#include<list>
#include<vector>
#include<algorithm>
#include<functional>

using namespace std;

void test_list1()
{
	//list<int> lt;
	//lt.push_back(1);
	//lt.push_back(2);
	//lt.push_back(3);
	//lt.push_back(4);
	////遍历方式1
	//list<int>::iterator it = lt.begin();
	//while (it != lt.end())
	//{
	//	cout << *it << " ";
	//	it++;
	//}
	//cout << endl;
	////遍历方式2
	//for (auto e : lt)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;
	int a[] = { 13,2,32,41 };
	list<int> lt1(a, a + 4);
	//原生指针可以当做天然的迭代器使用，其实vector/string的的迭代器也是原生指针
	list<int>::iterator it = lt1.begin();//InputIterator first, InputIterator last
	while (it != lt1.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
	vector<int> v(a, a + 4);
	sort(v.begin(), v.end());
	sort(v.begin(), v.end(), greater<int>());
}
void test_list2()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
	list<int>::iterator pos = find(lt.begin(), lt.end(), 3);
	if (pos == lt.end())
	{
		exit(-1);
		cout << "find fail";
	}
	//list因为底层结构insert不会导致pos迭代器失效
	lt.insert(pos, 30);
	//list因为底层结构erase会导致pos迭代器失效，野指针
	lt.erase(pos);
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;
}
int main()
{
	//test_list1();
	test_list2();
	return 0;
}