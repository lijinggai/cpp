class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        //位运算
        for (int i = 0; i < 32; i++)
        {
            int total = 0;
            //一次求出一位
            for (int num : nums)
            {
                //除了想计算的位，其他位也有可能有值
                total += (num >> i) & 1;
            }
            if (total % 3)
            {
                //total可能为x乘3+1的任何数
                //total/=3;
                ret |= 1 << i;
            }
        }
        return ret;
    }
};