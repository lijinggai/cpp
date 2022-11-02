long long Factorial(long long x)//½×³Ë
{
    long long factorial = 0;
    for (long long i = 0; i < x; i++)
    {
        factorial += (i + 1);
    }
    return factorial;
}
long long zeroFilledSubarray(int* nums, int numsSize)
{
    int* prev = nums;
    int* cur = nums;
    long long i = 0;
    long long j = 0;
    long long n = numsSize;
    long long m = 0;
    long long ret = 0;
    while (i < n)
    {
        if (cur[i] != 0)
        {
            i++;
        }
        else
        {
            j = i;
            while (cur[i] == 0)
            {
                if (i == n - 1)
                {
                    i++;
                    break;
                }
                i++;
            }
            m = i - j;
            j = i;
            ret += Factorial(m);
        }
    }
    return ret;
}