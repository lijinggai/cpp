char* findLongestWord(char* s, char** dictionary, int dictionarySize)
{
    int m = strlen(s);//s字符串长度
    int n = dictionarySize;

    int count = 0;
    int ri = 0;

    char* cur1 = s;
    char** cur2 = dictionary;
    for (int i = 0; i < n; i++)
    {

        int c = 0;//需要dictionary的列
        int count1 = 0;
        for (int j = 0; j < m; j++)
        {
            if (cur2[i][c] == cur1[j])//比较相同，相同++
            {
                c++;
                count1++;
            }
            if (cur2[i][c] == '\0')//dictionary走完了
            {
                break;
            }
        }
        //2种可能，1dictionary走完了，2j不小于m了
        if (cur2[i][c] != '\0')
        {
            count1 = 0;
        }

        if (count == count1)
        {
            for (int j = 0; cur2[i][j] != '\0'; j++)//有多个相同的字符串，取字母序小的
            {
                if (cur2[ri][j] > cur2[i][j])
                {
                    ri = i;
                    count = count1;
                    break;
                }
                else if (cur2[ri][j] < cur2[i][j])
                {
                    break;
                }
            }
        }
        else if (count < count1)//判断现在的dictionary【i】是否更短
        {
            ri = i;
            count = count1;
        }
    }
    char* cnums = "";
    if (count == 0)//没有符合的返回空字符串
    {
        return cnums;
    }
    return dictionary[ri];
}