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
    using vi = vector<int>;
    void dfs(TreeNode* root, int sum, vi &tmp, vector<vi> &result)
    {
        if(root == NULL) return;
        // 遇到叶结点则判断路径是否为所求
        if(root->left==NULL && root->right==NULL)
        {
            if(sum == root->val)
            {
                tmp.push_back(root->val);
                result.push_back(tmp);
                tmp.pop_back();
            }
            return;
        }
        tmp.push_back(root->val);
        dfs(root->left, sum - root->val, tmp, result);
        dfs(root->right, sum - root->val, tmp, result);
        tmp.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        // 递归查找并记录路径
        vector<vi> result;
        vi tmp;
        dfs(root, sum, tmp, result);
        return result;
    }
};
