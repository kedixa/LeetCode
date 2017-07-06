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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int x = p->val, y = q->val;
        if(x > y) swap(x, y);
        while(root) {
            if(root->val < x) root = root->right;
            else if(root->val > y) root = root->left;
            else break;
        }
        return root;
    }
};
