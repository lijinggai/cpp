#include<iostream>
#include<queue>
#include<deque>
using namespace std;

int main()
{
	priority_queue<int,vector<int>,greater<int>> q;//优先级队列
	q.push(2);
	q.push(5);
	q.push(1);
	q.push(4);
	q.push(6);
	q.push(3);
	int k = 6;
	while (!q.empty() && k--)
	{
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;
	return 0;
}