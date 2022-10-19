class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> st;
        vector<int> v;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        while (cur || !st.empty())
        {
            while (cur)
            {
                st.push(cur);
                cur = cur->left;
            }
            TreeNode* top;
            top = st.top();
            if (top->right == nullptr || top->right == prev)
            {
                v.push_back(top->val);
                st.pop();
                prev = top;
            }
            else
            {
                cur = top->right;
            }
        }
        return v;
    }
};