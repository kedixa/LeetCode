class Solution {
public:
    bool search(vector<int>& nums, int target) {
        // 最坏时间复杂度为O(n)，例如在[1, 1, ..., 1, 0, 1, ..., 1]中找0
         return find(nums.begin(), nums.end(), target) != nums.end();
    }
};