class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // 以中间位置为准，将数分成小于和大于该数的两部分
        // 则最后位于中间的数为所求
        int sz = nums.size();
        nth_element(nums.begin(), nums.begin() + sz/2, nums.end());
        return nums[sz/2];
    }
};
