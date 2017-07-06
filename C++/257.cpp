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
    vector<string> result;
    vector<string> v;
    string to_str() {
        string tmp;
        if(v.size() == 0) return tmp;
        tmp.reserve(v.size() * 5);
        tmp += v[0];
        for(int i = 1; i < v.size(); ++i) {
            tmp += "->";
            tmp += v[i];
        }
        return tmp;
    }
    void dfs(TreeNode *p) {
        v.push_back(to_string(p->val));
        if(p->right == nullptr && p->left == nullptr)
            result.push_back(to_str());
        else {
            if(p->left)
                dfs(p->left);
            if(p->right)
                dfs(p->right);
        }
        v.pop_back();
    }
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        result.clear();
        v.clear();
        if(root == nullptr) return result;
        dfs(root);
        return result;
    }
};
