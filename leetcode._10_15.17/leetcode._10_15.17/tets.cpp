const char* num_str[] = { "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
class Solution {
public:
    void _letterCombinations(string& digits, int i, string str, vector<string>& ret)
    {
        if (i == digits.size())
        {
            ret.push_back(str);
            return;
        }
        int num = digits[i] - '0';
        const string letters = num_str[num];
        for (auto e : letters)
        {
            _letterCombinations(digits, i + 1, str + e, ret);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        if (digits.empty())//Îª¿Õ
        {
            return ret;
        }
        int i = 0;//µÝ¹é²ãÊý
        string str;//´«letters
        _letterCombinations(digits, i, str, ret);
        return ret;

    }
};