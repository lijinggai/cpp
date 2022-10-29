void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void ADJustDown(int* a, int n, int root)//调整
{
	int parent = root;
	int child = parent * 2 + 1;//左孩子
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])//可能没有右孩子
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else//不交换跳出循环，以免死循环
		{
			break;
		}
	}
}
void HeapSort(int* a, int n)//堆排序
{
	//升序，建大堆
	for (int end = (n - 1 - 1) / 2; end >= 0; end--)
	{
		ADJustDown(a, n, end);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		ADJustDown(a, end, 0);
		end--;
	}
}

int maximumBags(int* capacity, int capacitySize, int* rocks, int rocksSize, int additionalRocks) {
	int* nums = (int*)malloc(sizeof(int) * capacitySize);
	for (int i = 0; i < capacitySize; i++)
	{
		nums[i] = capacity[i] - rocks[i];
	}
	HeapSort(nums, capacitySize);//堆排序
	int i = 0;
	while (i < capacitySize)
	{
		if (additionalRocks - nums[i] >= 0)
		{
			additionalRocks -= nums[i];
			i++;
		}
		else
		{
			break;
		}
	}
	return i;
}