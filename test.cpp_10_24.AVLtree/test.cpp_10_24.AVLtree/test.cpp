#include"AVLtree.h"

int main()
{
	int arr[] = { 1,3,5,2,9,6 };
	AVLtree<int, int> at;
	for (auto e : arr)
	{
		at.Insert(pair<int,int>(e,e));
	}

	return 0;
}