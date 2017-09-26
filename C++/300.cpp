class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i] 表示长度为i的LIS的最小结束位置，则nums[dp[i]]必然是一个上升序列
        // 对于每个新的nums[i]，根据dp[i]查找其在nums[dp[i]]中的位置，并维护dp
        using Node = pair<int, int>;
        int sz = nums.size();
        if(sz == 0) return 0;
        vector<int> dp(sz + 1, -1);
        dp[0] = -1;
        dp[1] = 0;
        int dpsz = 1;
        for(int i = 1; i < sz; ++i) {
            auto it = lower_bound(dp.begin() + 1, dp.begin() + dpsz + 1, i, [&](int a, int b){
                return nums[a] < nums[b];
            });
            int pos = it - dp.begin();
            if(pos == dpsz + 1) dp[++dpsz] = i;
            else if(nums[dp[pos]] > nums[i]) {
                dp[pos] = i;
            }
        }
        return dpsz;
    }
};
