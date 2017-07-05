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
    int val, kk;
    void dfs(TreeNode *root) {
        if(root == nullptr) return;
        dfs(root->left);
        if(kk == 0) return;
        else if(kk == 1) {
            val = root->val;
            kk = 0;
            return;
        }
        else {
            --kk;
            dfs(root->right);
        }
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        // 中序遍历直到找到第k个
        kk = k;
        dfs(root);
        return val;
    }
};
