class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 0..n的和减去nums的和
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        return static_cast<int>((0LL + nums.size()) * (nums.size() + 1) / 2 - sum);
    }
};
