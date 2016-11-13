/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        // 使用广度优先遍历的方法遍历这棵树即可
        vector<vector<int>> vec;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty())
        {
            int sz = que.size();
            vec.push_back(vector<int>());
            for(int i = 0; i < sz; ++i)
            {
                auto p = que.front();
                que.pop();
                if(!p) continue;
                vec.back().push_back(p->val);
                que.push(p->left);
                que.push(p->right);
            }
        }
        if(vec.size() && vec.back().size()==0) vec.pop_back();
        return vec;
    }
};