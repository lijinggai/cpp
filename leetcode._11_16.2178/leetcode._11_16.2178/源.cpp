class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> v;
        if (finalSum % 2 == 1)
        {
            return v;
        }
        long long tatol = 0;
        long long num = 0;
        while (finalSum > num)
        {
            num += 2;
            v.push_back(num);
            finalSum -= num;
        }
        if (finalSum != 0)
        {
            finalSum /= 2;
            for (int i = v.size() - finalSum; i < v.size(); i++)
            {

                v[i] += 2;
            }
        }
        return v;
    }
};