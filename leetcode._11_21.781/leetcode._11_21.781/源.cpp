class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> m;
        //计数
        for (auto e : answers)
        {
            m[e]++;
        }
        int answer = 0;
        for (auto e : m)
        {
            //为0没有相同
            if (e.first == 0)
                answer += e.second;
            else
            {
                int i = e.second - e.first - 1;
                cout << i << ":" << e.first << ":" << e.second << endl;
                answer = answer + e.first + 1;
                //说相同1的可能有多个，互相相同1每队只有2个
                while (i > 0)
                {
                    answer = answer + e.first + 1;
                    i = i - e.first - 1;
                }
            }
        }
        return answer;
    }
};