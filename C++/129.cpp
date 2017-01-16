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
    int sum, tmp;
    void dfs(TreeNode *root)
    {
        if(root == NULL) return;
        if(root->left==NULL && root->right==NULL)
        {
            sum += tmp + root->val;
            return;
        }
        tmp += root->val;
        tmp *= 10;
        dfs(root->left);
        dfs(root->right);
        tmp /= 10;
        tmp -= root->val;
    }
public:
    int sumNumbers(TreeNode* root) {
        // 深度优先遍历一遍，将沿途的数按要求加起来
        sum = tmp = 0;
        dfs(root);
        return sum;
    }
};
