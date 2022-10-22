class Solution {
public:
    TreeNode* _buildTree(vector<int>& postorder, int postBegin, int postEnd,
        vector<int>& inorder, int inBegin, int inEnd)
    {
        if (inBegin > inEnd)
            return nullptr;

        //后序最后一个元素为根
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int cur = inBegin;
        while (cur <= inEnd && inorder[cur] != root->val)
        {
            cur++;
        }

        int dif = cur - inBegin;
        //中序根的左子树有n个，那么后序前n个就是左子树
        root->left = _buildTree(postorder, postBegin, postBegin + dif - 1, inorder, inBegin, cur - 1);
        root->right = _buildTree(postorder, postBegin + dif, postEnd - 1, inorder, cur + 1, inEnd);
        return root;

    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return _buildTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1);
    }
};