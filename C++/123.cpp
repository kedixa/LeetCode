class Solution {
public:
    int maxProfit(vector<int>& prices) {
        /*
        dp[][0]: 购买一个的最大收益
        dp[][1]: 买一个并卖一个的最大收益
        dp[][2]: 买两个并卖一个的最大收益
        dp[][3]: 买两个并卖两个的最大收益
        */
        int MIN = numeric_limits<int>::min();
        int dp[2][4]{MIN, 0, MIN, 0};
        int p = 1;
        for(int i = 0; i < prices.size(); ++i)
        {
            auto &cur = dp[1-p], &next = dp[p];
            p = 1-p;
            next[0] = max(cur[0], -prices[i]);
            next[1] = max(cur[1], next[0]+prices[i]);
            next[2] = max(cur[2], next[1]-prices[i]);
            next[3] = max(cur[3], next[2]+prices[i]);
        }
        return max(dp[1-p][1], dp[1-p][3]);
    }
};
