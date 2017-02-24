class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // dp[i] 表示以s[i]结尾的字符串是否符合题意
        // 则其可以从dp[k]=true且s[k+1~i]在字典中转移过来
        // 为了便于处理，在dp前面添加一个1，实际下标可能有偏移
        unordered_set<string> us(wordDict.begin(), wordDict.end());
        int max_len = 0;
        for(auto &x : wordDict) max_len = max(max_len, (int)x.length());
        vector<int> dp(s.length()+1, 0);
        dp[0] = 1;
        for(int i = 1; i <= s.length(); ++i)
        {
            int j = i - 1;
            for(j; j >=0 && i-j <= max_len; --j)
                if(dp[j] == 1 && us.find(s.substr(j, i-j)) != us.end())
                {
                    dp[i] = 1;
                    break;
                }
        }
        return dp.back();
    }
};
