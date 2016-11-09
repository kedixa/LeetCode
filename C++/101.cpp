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
    bool isFlipSame(TreeNode *p, TreeNode *q)
    {
        if(p == NULL) return q == NULL;
        if(q == NULL) return p == NULL;
        if(q->val != p->val) return false;
        return isFlipSame(p->left, q->right) &&
            isFlipSame(p->right, q->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        // 递归解法
        if(root == NULL) return true;
        return isFlipSame(root -> left, root -> right);
    }
};