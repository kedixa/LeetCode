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
public:
    vector<int> inorderTraversal(TreeNode* root) {
        // 非递归遍历二叉树，用栈保存路径信息即可
        vector<int> v;
        stack<TreeNode*> st;
        while(root) st.push(root), root = root -> left;
        while(!st.empty())
        {
            auto p = st.top();
            st.pop();
            v.push_back(p -> val);
            p = p -> right;
            if(p) while(p) st.push(p), p = p -> left;
        }
        return v;
    }
};