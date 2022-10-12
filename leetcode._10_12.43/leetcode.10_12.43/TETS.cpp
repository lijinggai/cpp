class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        int n = num1.size(), m = num2.size();
        string ans(n + m, '0');
        int add = -1;
        for (int i = n - 1; i >= 0; i--) {
            int start = 0;//控制每次计算进位问题
            add++;//下一个乘法会后一位
            for (int j = m - 1; j >= 0; j--) {
                int sum = (num1[i] - '0') * (num2[j] - '0') + (ans[start + add] - '0');
                ans[start + add] = sum % 10 + '0';
                ans[++start + add] += sum / 10;//+'0'sun乘法时会减掉
            }
        }
        if (ans[n + m - 1] == '0')
            ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};