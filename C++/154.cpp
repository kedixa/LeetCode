class Solution {
public:
    int findMin(vector<int>& nums) {
        // 本题依然可以二分，但最坏时间复杂度为O(n)，故暂略去
        return *min_element(nums.begin(), nums.end());
    }
};
