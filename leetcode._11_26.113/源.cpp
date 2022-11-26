/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void _pathSum(TreeNode* root, int targetSum, vector<vector<int>>& ret, vector<int>& cur)
    {
        if (root == nullptr)
            return;
        cur.push_back(root->val);
        targetSum -= root->val;
        _pathSum(root->left, targetSum, ret, cur);
        _pathSum(root->right, targetSum, ret, cur);
        //后序遍历,直到到叶子结点，才执行后面的代码
        if (root->left == nullptr && root->right == nullptr && targetSum == 0)
            ret.push_back(cur);
        //
        cur.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ret;
        vector<int> cur;
        _pathSum(root, targetSum, ret, cur);
        return ret;
    }
};