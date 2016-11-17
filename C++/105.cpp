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
    using iterator = vector<int>::iterator;
    TreeNode* build(iterator pbegin, iterator pend, iterator ibegin, iterator iend)
    {
        // 递归实现：
        // preorder的第一个字符为当前子树的根，
        // 根据这个字符在inorder中取得两棵子树，分别构建即可
        int dist = distance(pbegin, pend);
        if(dist == 0) return NULL;
        auto root = new TreeNode(*pbegin);
        if(dist == 1) return root;
        
        auto it = find(ibegin, iend, *pbegin);
        int left = distance(ibegin, it);
        int right = distance(it + 1, iend);
        root->left = build(pbegin + 1, pbegin + 1 + left, ibegin, it);
        root->right = build(pbegin + 1 + left, pend, it + 1, iend);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        auto pbegin = preorder.begin(), pend = preorder.end();
        auto ibegin= inorder.begin(), iend = inorder.end();
        return build(pbegin, pend, ibegin, iend);
    }
};
