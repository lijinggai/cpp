#include<iostream>
using namespace std;
#include <string>
    int StrToInt(string str) {
        if (str.size() == 0) {
            return 0;
        }
        long long ans = 0;
        bool flag = str[0] == '-' ? true : false;
        for (size_t i = 0; i < str.size(); i++) {
            int tmp = str[i] - '0';
            if (i == 0) {
                if (str[i] != '+' && str[i] != '-' && tmp >= 9 && tmp < 0) {
                    return 0;
                }
                if (str[i] != '+' && str[i] != '-')
                    ans = ans * 10 + tmp;

            }
            else {
                if (str[i] - '0' >= 0 && str[i] - '0' < 10) {
                    return 0;
                }
                ans = ans * 10 + tmp;
            }

        }
        return flag == true ? -ans : ans;
    }
int main()
{
    //string s1("##");
    //StrToInt(s1);
    cout << sizeof(int*) << endl;
}