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
    using nl = numeric_limits<long long>;
    TreeNode *t1, *t2;
    void recover(TreeNode *root, long long min, long long max)
    {
        if(root == NULL) return;
        auto& v = root -> val;
        recover(root -> left, min, v);
        TreeNode *p;
        long long left = min, right = max;
        if(p = root -> left) {
            while(p -> right) p = p -> right;
            left = p -> val;
        }
        if(p = root -> right) {
            while(p -> left) p = p -> left;
            right = p -> val;
        }
        // 此处t1为比两边都大的数，且取第一个，而t2取最后一个
        if(left < v && right < v && t1 == NULL)
            t1 = root;
        if((left > v || left == nl::min()) && right > v) t2 = root;
        recover(root -> right, v, max);
    }
public:
    void recoverTree(TreeNode* root) {
        // 暂时只会O(depth of tree) space的解法，O(1)的方法尚未理解
        // 思路：一个严格有序序列中两个数错位，
        // 必有一个数比两边都大、一个数比两边都小
        // 找到第一个比两边都大的数和最后一个比两边都小的数，交换即可
        t1 = t2 = NULL;
        recover(root, nl::min(), nl::max());
        swap(t1 -> val, t2 -> val);
        return;
    }
};
