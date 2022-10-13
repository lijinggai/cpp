void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void ADJustDown(int* a, int n, int root)//调整
{
	int parent = root;
	int child = parent * 2 + 1;
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
int* sortArray(int* nums, int numsSize, int* returnSize)
{
	//排升序建大堆
	for (int end = (numsSize - 1 - 1) / 2; end >= 0; end--)
	{
		ADJustDown(nums, numsSize, end);//调整
	}

	for (int n = numsSize - 1; n > 0; n--)
	{
		Swap(&nums[0], &nums[n]);
		ADJustDown(nums, n, 0);//调整
	}
	*returnSize = numsSize;
	return nums;
}