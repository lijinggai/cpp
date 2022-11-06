#include<iostream>
#include<unordered_set>
#include<unordered_map>
using namespace std;

void test1()
{
	unordered_set<int> us;
	us.insert(5);
	us.insert(7);
	us.insert(9);
	us.insert(3);
	us.insert(2);
	us.insert(2);
	us.insert(6);
	unordered_set<int>::iterator it = us.begin();
	while (it != us.end())
	{
		cout << *it << " ";
		it++;
	}
}
int main()
{
	test1();
}
