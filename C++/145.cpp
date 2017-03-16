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
    vector<int> postorderTraversal(TreeNode* root) {
        // 使用栈解决，把root当作一个结点入栈，root->right当作一棵子树入栈，
        // 处理root->left，然后从栈中取出(root->right, true)当作子树处理，
        // 从栈中取出(root, false)，把root->val放入结果中。
        // 应当有更好的不需要布尔变量的解法。
        vector<int> result;
        stack<pair<TreeNode*, bool>> st;
        TreeNode *p = root;
        while(p != nullptr)
        {
            st.push(make_pair(p, false));
            if(p -> right) st.push(make_pair(p->right, true));
            p = p -> left;
            while(p == nullptr && !st.empty())
            {
                auto &s = st.top();
                if(s.second == false) // treat it as a node
                    result.push_back(s.first->val);
                else p = s.first; // treat it as a subtree
                st.pop();
            }
        }
        return result;
    }
};
