
class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        int last1 = -1, ret = 0, last2 = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= left && nums[i] <= right)
            {
                last1 = i;
            }
            else if (nums[i] > right)
            {
                last1 = -1;
                last2 = i;
            }
            if (last1 != -1)
            {
                ret += last1 - last2;
            }
        }
        return ret;
    }
};