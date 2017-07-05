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
    int depth;
    int cnt;
    bool done;
    void dfs(TreeNode *root, int cur_dpt) {
        if(root == nullptr) return;
        int dpt = cur_dpt;
        TreeNode *p = root->left;
        while(p) ++dpt, p = p->right;
        if(dpt == depth) {
            // 若该子树（满的）深度与depth相同
            // 说明root->right中不存在最后一层不满的结点
            dfs(root->left, cur_dpt + 1);
        }
        else {
            // 否则root->left 最后（比depth多出的）一层结点都应加到cnt
            // 并且root->right中还可能有最后一层的结点
            cnt += (1 << (depth - cur_dpt));
            dfs(root->right, cur_dpt + 1);
        }
    }
public:
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;
        // 先计算结点满的最大层数
        TreeNode *p = root;
        while(p) ++depth, p = p->right;
        // 再计算（不满的）最后一层的结点数
        cnt = 0;
        dfs(root, 1);
        return (1 << depth) - 1 + cnt;
    }
};
