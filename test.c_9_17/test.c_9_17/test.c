#include<stdio.h>
#include<string.h>
int cmp_int(const void* e1, const void* e2)
{
    return *((int*)e1) - *((int*)e2);
}
void Swap(char* bf1, char* bf2, int width)//交换
{
    int i = 0;
    for (i = 0; i < width; i++)
    {
        int tmp = *bf1;
        *bf1 = *bf2;
        *bf2 = tmp;
        bf1++;
        bf2++;
    }

}
void Bubble_sort(void* base, int sz, int width,
    int (*cmp)(void* e1, void* e2))//算法实现
{
    int i = 0;
    for (i = 0; i < sz - 1; i++)
    {
        int j = 0;
        for (j = 0; j < sz - 1 - i; j++)
        {
            if (cmp((char*)base + j * width, (char*)base + (j
                + 1) * width) > 0)
            {
                Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
            }

        }
    }
}
void print(int arr[], int sz)//打印第一个数组
{
    int i = 0;
    for (i = 0; i < sz; i++)
    {
        printf("%d ", arr[i]);
    }
}
int main()
{
    int arr[] = { 9,8,7,6,5,4,3,2,1 };
    int sz = sizeof(arr) / sizeof(arr[0]);
    Bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);//算法
    print(arr, sz);
    return 0;
}
