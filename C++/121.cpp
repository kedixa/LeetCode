class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = 0, ma = 0;
        for(auto it = prices.rbegin(); it!=prices.rend(); ++it)
        {
            int tmp = ma - *it;
            if(m < tmp) m = tmp;
            if(ma < *it) ma = *it;
        }
        return m;
    }
};
