class Solution {
    bool Find(TreeNode* root, TreeNode* x)
    {
        if (root == nullptr)
        {
            return false;
        }
        if (root == x)
            return true;
        return Find(root->left, x) || Find(root->right, x);
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (q == root || p == root)
            return root;
        bool ispInLeft, ispInRight, isqInLeft, isqInRight;
        ispInLeft = Find(root->left, p);
        ispInRight = !ispInLeft;
        isqInLeft = Find(root->left, q);
        isqInRight = !isqInLeft;
        //全在左子树
        if (ispInLeft && isqInLeft)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        //全在右子树
        else if (ispInRight && isqInRight)
        {
            return lowestCommonAncestor(root->right, p, q);
        }
        else
        {
            return root;
        }
    }
};