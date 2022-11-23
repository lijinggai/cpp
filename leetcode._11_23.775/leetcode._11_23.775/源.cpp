class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        int compare = nums[0];
        for (int i = 0; i + 2 < nums.size(); i++)
        {
            if (compare > nums[i + 2])
            {
                return false;
            }
            compare = max(compare, nums[i + 1]);
        }
        return true;
    }
};