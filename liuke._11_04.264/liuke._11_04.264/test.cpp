#include <iostream>
#include<map>
#include<string>
using namespace std;

int main() {
    map<string, int> m;
    string str;
    getline(cin, str);
    //±£´æÊı¾İ
    string stri;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == ' ' || str[i] == '.' || str[i] == ',')
        {
            m[stri]++;
            stri = "";
        }
        else
        {
            stri += tolower(str[i]);
        }
    }
    map<string, int>::iterator mit = m.begin();
    while (mit != m.end())
    {
        cout << mit->first << ":" << mit->second << endl;
        ++mit;
    }
}