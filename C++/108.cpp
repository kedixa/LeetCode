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
    TreeNode* build(vector<int>& nums, int s, int t)
    {
        // 以位于中间的元素为根，两侧元素为子树，递归构建即可
        if(s == t) return NULL;
        int mid = s + (t - s) / 2;
        auto root = new TreeNode(nums[mid]);
        if(s == t - 1) return root;
        root -> left = build(nums, s, mid);
        root -> right = build(nums, mid + 1, t);
        return root;
    }
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int sz = nums.size();
        return build(nums, 0, sz);
    }
};
