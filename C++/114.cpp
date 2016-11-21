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
    TreeNode** f(TreeNode* p)
    {
        // 将p->left插入到p和p->right之间
        if(p->left)
        {
            // q是指向p->left最后一个结点的right的指针
            auto q = f(p->left);
            // q连接到p->right
            *q = p->right;
            // 将p->left插入到p和p->right之间
            p->right = p->left;
            p->left = NULL;
        }
        if(p->right == NULL) return &(p->right);
        return f(p->right);
    }
public:
    void flatten(TreeNode* root) {
        if(root != NULL)
            f(root);
    }
};
