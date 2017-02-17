class Solution {
    bool pal(string &s, int a, int b)
    {
        while(a < b)
        {
            if(s[a++] != s[--b])
                return false;
        }
        return true;
    }
public:
// 动态规划
// dp[i]表示以s[i]结尾的字符串需要的最少切割数
// 则dp[i]为s[k~i]为回文时dp[k-1]+1的最小值
// 为了书写方便，可以在dp[]前面空余出一个位置表示空串
    int minCut(string s) {
        vector<int> dp(s.length() + 1);
        for(int i = 0; i < dp.size(); ++i)
            dp[i] = i - 1;
        for(int i = 1; i < dp.size(); ++i)
        {
            for(int j = i; j >= 1; --j)
            {
                if(dp[i] > dp[j-1]+1 && pal(s, j - 1, i))
                {
                    dp[i] = min(dp[i], dp[j-1] + 1);
                }
            }
        }
        if(dp.back()==-1) dp.back()=0;
        return dp.back();
    }
};
