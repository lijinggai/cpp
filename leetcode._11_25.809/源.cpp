class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int ret = words.size();
        for (auto& word : words)
        {
            int i = 0, j = 0;
            while (i < s.size() || j < word.size())
            {
                //其中有一个结束了，另一个没结束
                if (i == s.size() || j == word.size())
                {
                    ret--;
                    break;
                }
                //元素不同
                if (s[i] != word[j])
                {
                    ret--;
                    break;
                }
                int counti = 0;
                char chi = s[i];
                while (i < s.size() && s[i] == chi)
                {
                    counti++; i++;
                }
                int countj = 0;
                char chj = word[j];
                while (word[j] == chj)
                {
                    countj++; j++;
                }
                //不能缩容
                if (countj > counti)
                {
                    ret--;
                    break;
                }
                //不相同且s的某一个元素数量小于3
                if (counti != countj && counti < 3)
                {
                    ret--;
                    break;
                }
            }
        }
        return ret;
    }
};