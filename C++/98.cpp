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
    bool valid(TreeNode* root, long long ma, long long mi) {
        // 按照二叉排序树规则判断即可，注意使用int时可能会溢出
        if(root == NULL) return true;
        return root -> val >= mi && root -> val <= ma &&
            valid(root->left, root -> val - 1LL, mi) &&
            valid(root -> right, ma, root -> val + 1LL);
    }
public:
    bool isValidBST(TreeNode* root) {
        return valid(root, numeric_limits<long long>::max(),
            numeric_limits<long long>::min());
    }
};
