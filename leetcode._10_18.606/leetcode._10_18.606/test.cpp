class Solution {
public:
    string tree2str(TreeNode* root) {
        if (root == nullptr)
            return string();
        string str;
        str += to_string(root->val);

        if (root->left || root->right)
        {
            str += "(";
            str += tree2str(root->left);
            str += ")";
        }

        if (root->right)
        {
            str += "(";
            str += tree2str(root->right);
            str += ")";
        }

        return str;
    }
};