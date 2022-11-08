class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        for (auto str : words)
        {
            int length = 0;
            for (char ch : str)
            {
                for (char cha : allowed)
                {
                    if (ch == cha)
                    {
                        length++;
                        break;
                    }
                }
            }
            if (length == str.size())
            {
                count++;
            }
        }
        return count;
    }
};