/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        // 可以先存到vector再构造
        vector<int> nums;
        while(head)
        {
            nums.push_back(head->val);
            head = head -> next;
        }
        return build(nums, 0, nums.size());
    }
};
