class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // 这个题目思路很奇特啊，没有想到跟带一个环的链表查找循环起始位置是一个思路
        int slow = nums[0], fast = nums[nums[0]];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
