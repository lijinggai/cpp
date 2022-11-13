class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char, int> m;
        unordered_map<char, int> m1;
        int i = 0;
        for (auto ch : order)
        {
            m[ch] = i++;
        }
        for (auto ch : s)
        {
            m1[ch]++;
        }
        string ret1;
        ret1.resize(s.size());
        int index = 0;
        for (auto ch : s)
        {
            unordered_map<char, int>::iterator cur = m.find(ch);
            if (cur == m.end())
            {
                ret1[index++] = ch;
            }
        }
        for (auto ch : order)
        {
            unordered_map<char, int>::iterator cur = m1.find(ch);
            if (cur != m.end())
            {
                while (cur->second--)
                {
                    ret1[index++] = ch;
                }
            }
        }
        return ret1;
    }
};