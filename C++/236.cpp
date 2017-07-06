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
    TreeNode *x;
    int dfs(TreeNode *root, TreeNode *p, TreeNode *q) {
        // 遍历这棵树
        if(root == nullptr) return 0;
        int cnt = 0;
        if(root == p || root == q) {
            ++cnt;
        }
        int l = dfs(root->left, p, q);
        int r = dfs(root->right, p, q);
        if(cnt == 1) {
            // 如果该结点及其子节点为p,q，则该点为所求
            if(l + r == 1) x = root;
        }
        else if(cnt == 0) {
            // 否则左右两边恰有一个p或q的结点为所求
            if(l == 1 && r == 1) x = root;
        }
        return cnt + l + r;
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p == q) return p; // 特判
        x = nullptr;
        // 可能有更简单的方法
        dfs(root, p, q);
        return x;
    }
};
