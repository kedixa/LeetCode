class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        // 这个题理解不深刻，还需进一步理解
        int sz = prices.size(), p = 1;
        if(k==0) return 0;
        if(k>sz/2) {
            // 简单情况
            int ans = 0;
            for (int i=1; i<sz; ++i){
                ans += max(prices[i] - prices[i-1], 0);
            }
            return ans;
        }
        vector<vector<int>> v(2, vector<int>(2*k, 0));
        const int MIN = numeric_limits<int>::min();
        for(int i = 0; i < v[0].size(); i+=2) v[0][i] = MIN;
        for(int i = 0; i < sz; ++i) {
            auto &cur = v[1-p], &next = v[p];
            p = 1-p;
            next[0] = max(cur[0], -prices[i]);
            for(int j = 1; j < 2*k; ++j)
                next[j] = max(cur[j], next[j-1]+prices[i]*(j%2?1:-1));
        }
        int ans = 0;
        for(int i = 1; i < 2*k; i+=2)
            ans = max(v[1-p][i], ans);
        return ans;
    }
};
