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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 简单题
        if(p == NULL) return q == NULL;
        if(q == NULL) return p == NULL;
        if(p -> val != q -> val) return false;
        return isSameTree(p -> left, q -> left) &&
            isSameTree(p -> right, q -> right);
    }
};