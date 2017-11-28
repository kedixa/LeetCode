class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 状态v0: 可以购买, v1: 已经购买, v2: 已经卖出
        // 操作三种状态之间的转移
        int len = prices.size();
        if(len < 2) return 0;
        vector<int> v0(len, 0), v1(len, 0), v2(len, 0);
        v0[0] = 0;
        v1[0] = -prices[0];
        v2[0] = -999999999;
        for(int i = 1; i < len; i++) {
            v0[i] = max(v0[i-1], v2[i-1]);
            v1[i] = max(v0[i-1] - prices[i], v1[i-1]);
            v2[i] = v1[i-1] + prices[i];
        }
        return max(v0[len-1], v2[len-1]);
    }
};
