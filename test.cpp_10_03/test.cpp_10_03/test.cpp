#include<iostream>
#include<vector>
using namespace std;
int sum(int x ,int y)
{
	if (x == y)
	{
		return -1;
	}
	if (x > y)
		return x;
	else
		return y;
}
int main()
{
	int a, b;
	cin >> a;
	cin >> b;
	int max=sum(a,b);
	if(max==-1)
		cout << "相等" << endl;

	else
		cout << max;
}
