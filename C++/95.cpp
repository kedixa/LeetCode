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
    using vt = vector<TreeNode*>;
    TreeNode* deepcopy(TreeNode *root)
    {
        // 复制一棵树
        if(root == NULL) return NULL;
        TreeNode* p = new TreeNode(root -> val);
        p -> left = deepcopy(root -> left);
        p -> right = deepcopy(root -> right);
        return p;
    }
    void del(TreeNode *root)
    {
        // 释放一棵树
        if(root == NULL) return;
        del(root -> left);
        del(root -> right);
        delete root;
    }
    vt tree(int s, int t)
    {
        // 生成[s, t]对应的所有二叉树
        vt vec;
        if(s > t) vec.push_back(NULL);
        else if(s == t) vec.push_back(new TreeNode(s));
        else
        {
            // 枚举以s..t为根的树
            for(int i = s; i <= t; i++)
            {
                // 获取左右子树
                auto v1 = tree(s, i-1), v2 = tree(i+1, t);
                // 复制一份左右子树，构造这棵树
                for(auto &left : v1)
                {
                    for(auto &right : v2)
                    {
                        auto root = new TreeNode(i);
                        root -> left = deepcopy(left);
                        root -> right = deepcopy(right);
                        vec.push_back(root);
                    }
                }
                // 释放未返回的内存
                for(auto &left : v1) del(left);
                for(auto &right : v2) del(right);
            }
        }
        return vec;
    }
public:
    vector<TreeNode*> generateTrees(int n) {
        if(n == 0) return {};
        return tree(1, n); // 好像返回的指针不需要手动释放
    }
};