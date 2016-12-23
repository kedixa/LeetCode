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
    /*
        递归求得每个子树的最大连续路径和，然后合并
    */
    int max_sum;
    int max_path_sum(TreeNode* root)
    {
        if(root==NULL) return numeric_limits<int>::min();
        int cur_max = max_path_sum(root->left);
        int cur_min = max_path_sum(root->right);
        if(cur_max < cur_min) swap(cur_max, cur_min);
        max_sum = max(cur_max, max_sum);
        if(cur_min >= 0) max_sum = max(cur_max + cur_min + root->val, max_sum);
        else if(cur_max <= 0) max_sum = max(root->val, max_sum);
        else max_sum = max(cur_max + root->val, max_sum);
        return root->val + ((cur_max>0)?cur_max:0);
    }
public:
    int maxPathSum(TreeNode* root) {
        max_sum = numeric_limits<int>::min();
        max_path_sum(root);
        return max_sum;
    }
};
