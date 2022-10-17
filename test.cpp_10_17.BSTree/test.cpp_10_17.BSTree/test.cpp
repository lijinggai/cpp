#include"BSTree.h"

int main()
{
	BSTree<int> t;
	int arr[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	for (auto e : arr)
	{
		t.InsertR(e);
	}
	t.InOrder();
	t.EraseR(7);
	t.EraseR(3);
	t.EraseR(2);
	t.EraseR(0);
	t.EraseR(4);
	t.EraseR(5);
	t.EraseR(6);
	t.EraseR(9);
	t.EraseR(1);
	t.EraseR(8);
	t.InOrder();
	return 0;
}