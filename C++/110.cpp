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
    bool flag; // 记录是否平衡的标记
    int depth(TreeNode *l, TreeNode *r)
    {
        // 若已经不平衡则立刻返回
        if(!flag) return 0;
        if(l == NULL && r == NULL) return 0;
        int dl, dr;
        if(l == NULL)
        {
            dr = depth(r->left, r->right) + 1;
            if(dr > 1) flag = false;
            return dr;
        }
        if(r == NULL)
        {
            dl = depth(l->left, l->right) + 1;
            if(dl > 1) flag = false;
            return dl;
        }
        dl = depth(l->left, l->right), dr = depth(r->left, r->right);
        if(abs(dl - dr) > 1) flag = false;
        return max(dl, dr) + 1;
    }
public:
    bool isBalanced(TreeNode* root) {
        // 按照题意判断即可
        if(root == NULL) return true;
        flag = true;
        depth(root->left, root->right);
        return flag;
    }
};
