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
        // postorder的最后一个字符为当前子树的根，
        // 根据这个字符在inorder中取得两棵子树，分别构建即可
        int dist = distance(pbegin, pend);
        if(dist == 0) return NULL;
        auto root = new TreeNode(*(pend - 1));
        if(dist == 1) return root;
        
        auto it = find(ibegin, iend, *(pend - 1));
        int left = distance(ibegin, it);
        int right = distance(it + 1, iend);
        root->left = build(pbegin, pbegin + left, ibegin, it);
        root->right = build(pbegin + left, pend - 1, it + 1, iend);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        auto ibegin= inorder.begin(), iend = inorder.end();
        auto pbegin = postorder.begin(), pend = postorder.end();
        return build(pbegin, pend, ibegin, iend);
    }
};
