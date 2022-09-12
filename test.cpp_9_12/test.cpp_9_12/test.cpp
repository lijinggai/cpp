#include <iostream>
using namespace std;
//class B
//{
//public:
//	B(int x = 0)
//	{
//		_x = x;
//	}
//private:
//	int _x;
//};
//class A
//{
//public:
//	A(int a=1,int* p=nullptr)
//		:_a(a)
//		,_p(p)
//		{
//		}
//private:
//	//声明缺省值
//	int _a=0;
//	int* _p=nullptr;
//	int* arr = (int*)malloc(sizeof(int));
//	B _b=6;
//};
//int main()
//{
//	A a;
//	return 0;
//}
//int main()
//{
//	//new和delete和malloc和free在针对内置类型上没有差别，只是用法不同
//	//申请10int类型的数组
//	int* p1 = (int*)malloc(sizeof(int) * 10);
//	int* p2 = new int[10];//不需要强转，new是操作符
//	free(p1);
//	delete[] p2;
//
//	//申请单个int对象
//	int* p3 = (int*)malloc(sizeof(int));
//	int* p4 = new int;
//	free(p3);
//	delete p4;
//}
struct ListNode
{
public:
	ListNode(int val=0)
	:next(nullptr)
	,prev(nullptr)
	,val(val)
	{}
	~ListNode()
	{
		cout << "~ListNode()" << endl;
	}
private:
	ListNode* next;
	ListNode* prev;
	int val;
};
int main()
{
	//c  malloc只是开空间，free释放空间
	struct ListNode* n1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	free(n1);

	//cpp   new针对自定义类型，开空间+构造函数初始化
	//   delete针对自定义类型，析构函数+释放空间
	ListNode* n2 = new ListNode;
	delete n2;
	ListNode* n3 = new ListNode[4]{1,2,3,4};
	delete[] n3;
	//delete n3;//不匹配会崩溃

	//int* p1 = new int(3);
	//int* p2 = new int[3]{1,2,3};
	return 0;
}