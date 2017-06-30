class Solution {
public:
    int rob(vector<int>& nums) {
        // 好像还可以优化
        int sz = nums.size();
        if(sz == 0) return 0;
        if(sz == 1) return nums[0];
        // dp1[i] 表示偷第i家时得到的最多的钱
        // dp2[i] 表示到第i家但不偷得到的最多的钱
        vector<int> dp1(sz, 0), dp2(sz, 0);
        dp1[0] = nums[0];
        for(int i = 1; i < sz; ++i) {
            dp1[i] = dp2[i-1] + nums[i];
            dp2[i] = max(dp1[i-1], dp2[i-1]);
        }
        return max(dp1.back(), dp2.back());
    }
};
