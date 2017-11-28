class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // 典型的动态规划
        // 删除i,j之间的气球的最大收益从以下部分转移：
        //     先删除i+1到j,再删除i
        //     先删除i到j-1,再删除j
        //     先删除i到k,再删除k+1到j,再删除k
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        vector<int> v;
        v.push_back(1);
        copy(nums.begin(), nums.end(), back_inserter(v));
        v.push_back(1);
        int n = v.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i = 1; i < n - 1; i++) {
            dp[i][i] = v[i-1] * v[i] * v[i+1];
        }
        for(int i = 1; i < n; i++) {
            for(int j = 1; i + j < n - 1; j++) {
                dp[j][i+j] = max(dp[j+1][i+j] + v[j-1] * v[j] * v[i+j+1], dp[j][i+j-1] + v[j-1] * v[i+j] * v[i+j+1]);
                for(int k = j + 1; k < i + j; k++) {
                    dp[j][i+j] = max(dp[j][i+j], dp[j][k-1] + dp[k+1][i+j] + v[j-1] * v[k] * v[i+j+1]);
                }
            }
        }
        return dp[1][n-2];
    }
};
