class Solution {
public:

    void GetOperator(stack<long long>& st, long long& left, long long& right)
    {
        right = st.top();
        st.pop();
        left = st.top();
        st.pop();
    }
    int evalRPN(vector<string>& tokens) {
        stack<long long> st;
        long long left, right;
        for (auto& e : tokens)
        {
            switch (e[0])
            {
            case '+':
                GetOperator(st, left, right);
                st.push(left + right);
                break;
            case '-':
                if (e.size() == 1) {
                    GetOperator(st, left, right);
                    st.push(left - right);
                }
                else {
                    st.push(stoi(e));
                }
                break;
            case '*':
                GetOperator(st, left, right);
                st.push(left * right);
                break;
            case '/':
                GetOperator(st, left, right);
                st.push(left / right);
                break;
            default:
                st.push(stoi(e));
                break;
            }
        }
        return st.top();
    }
};