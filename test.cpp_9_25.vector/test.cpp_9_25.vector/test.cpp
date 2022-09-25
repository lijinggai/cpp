#include <iostream>
#include <vector>
#include <string>
#include <list>
using namespace std;

void PrintVector(const vector<int>& v)
{
	//v[0] = 20;
	vector<int>::const_iterator it1 = v.begin();
	while (it1 != v.end())
	{
		//*it1 += 1;
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
}
template<class T>
void PrintVector(const vector<T>& v)
{
	vector<T>::const iterator it1 = v.cbegin();
	while (it1 != v.cend())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
}

void test_vector1()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1[0] = 10;

	// 遍历1
	for (size_t i = 0; i < v1.size(); ++i)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	// 遍历2
	vector<int>::iterator it1 = v1.begin();
	while (it1 != v1.end())
	{
		*it1 += 1;
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;

	// 遍历3 (自动判断结束，自动迭代++)->看起来很智能，
	// 实际上呢，其实就是被替换成了迭代器
	for (auto e : v1)
	{
		cout << e << " ";
	}
	cout << endl;

	PrintVector(v1);
}

void test_vector2()
{
	vector<int> v1;
	vector<int> v2(10, 0);
	vector<int> v3(v2.begin(), v2.end());

	string s("hello world");
	vector<char> v4(s.begin(), s.end());

	string s1("hello");
	string s2 = "hello";

	vector<string> v5;
	string s3("sort");
	v5.push_back(s3);
	v5.push_back(string("insert"));

	// 推荐
	v5.push_back("erase");

	PrintVector(v1);
	PrintVector(v2);
	PrintVector(v3);
	PrintVector(v4);
	PrintVector(v5);

	vector<string> copy(v5);
	PrintVector(copy);

	//vector<string>::reverse_iterator rit = copy.rbegin();
	auto rit = copy.rbegin();
	while (rit != copy.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;

	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	list<int>::iterator it = lt.begin();
	while (it != lt.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}

void test_vector3()
{
	// 验证vector的增容方式
	size_t sz;
	std::vector<int> foo;
	foo.reserve(100);

	sz = foo.capacity();
	std::cout << "making foo grow:\n";
	for (int i = 0; i < 100; ++i) {
		foo.push_back(i);
		if (sz != foo.capacity()) {
			sz = foo.capacity();
			std::cout << "capacity changed: " << sz << '\n';
		}
	}

	vector<int> v1;
	v1.reserve(10);

	vector<int> v2;
	v2.resize(10, 2);
}

void test_vector4()
{
	vector<vector<int>> vv;
	vv.resize(5);

	for (size_t i = 0; i < vv.size(); ++i)
	{
		vv[i].resize(i + 1);
	}

	for (size_t i = 0; i < vv.size(); ++i)
	{
		vv[i][0] = vv[i][vv[i].size() - 1] = 1;
	}
}

int main()
{
	test_vector4();

	return 0;
}