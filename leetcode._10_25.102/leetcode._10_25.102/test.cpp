class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        int LevelSize = 0;
        if (root)
        {
            //第一次一定为1
            q.push(root);
            LevelSize = 1;
        }
        vector<vector<int>> vv;
        while (!q.empty())
        {
            vector<int> v;
            //控制一层一层出和入
            for (int i = 0; i < LevelSize; i++)
            {
                TreeNode* front = q.front();
                if (front->left)
                {
                    q.push(front->left);
                }
                if (front->right)
                {
                    q.push(front->right);
                }
                v.push_back(q.front()->val);
                q.pop();
            }
            vv.push_back(v);
            //上一层出完，下一层入完，个数为队列的size
            LevelSize = q.size();
        }
        return vv;
    }
};