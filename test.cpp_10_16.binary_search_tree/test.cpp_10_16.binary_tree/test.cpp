#include"binary_search.h"

int main()
{
	BSTree<int> t;
	int arr[] = { 5, 3, 4, 1, 7, 8, 2, 6, 0, 9 };
	for (auto e : arr)
	{
		t.Insert(e);
	}
	t.InOrder();
	t.Erase(7);
	t.Erase(3);
	t.Erase(2);
	t.Erase(0);
	t.Erase(4);
	t.Erase(5);
	t.Erase(6);
	t.Erase(9);
	t.Erase(1);
	t.Erase(8);
	t.InOrder();
	return 0;
}