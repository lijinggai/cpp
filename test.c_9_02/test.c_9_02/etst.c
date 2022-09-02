#include<stdio.h>
int Findnum(int arr[3][3], int* px, int* py, int k)
{
    int x = 0;
    int y = *py - 1;
    while (x <= *px - 1 && y >= 0)
    {
        if (arr[x][y] > k)
        {
            y--;
        }
        else if (arr[x][y] < k)
        {
            x++;
        }
        else
        {
            *px = x;
            *py = y;
            return 1;
        }
    }
    return 0;
}
int main()
{
    int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
    int k = 7;
    int x = 3;
    int y = 3;
    int ret = Findnum(arr, &x, &y, k);
    if (ret == 1)
    {
        printf("找到了");
        printf("下标是%d %d", x, y);
    }
    else
        printf("找不到");
    return 0;
}
