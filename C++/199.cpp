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
    vector<int> v;
    void dfs(TreeNode *p, int dep) {
        // 中-右-左遍历，第一次到达某层时，记录该结点的值
        if(!p) return;
        if(v.size() <= dep) v.push_back(p->val);
        dfs(p->right, dep+1);
        dfs(p->left, dep+1);
    }
public:
    vector<int> rightSideView(TreeNode* root) {
        v.clear();
        v.reserve(100);
        dfs(root, 0);
        return v;
    }
};
