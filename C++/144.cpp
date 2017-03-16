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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> st;
        TreeNode *p = root;
        while(p != nullptr)
        {
            result.push_back(p -> val);
            if(p -> right) st.push(p -> right);
            p = p -> left;
            while(p == nullptr && !st.empty())
            {
                p = st.top();
                st.pop();
            }
        }
        return result;
    }
};
