class Solution {
    using vb = vector<bool>;
    using vvb = vector<vb>;
public:
    bool isInterleave(string s1, string s2, string s3) {
        // 动态规划，dp[i][j]表示s1的前i个字符与s2的前j个字符
        // 是否可以构成s3的前i+j个字符
        int len1 = s1.length(), len2 = s2.length(), len3 = s3.length();
        if(len1 + len2 != len3) return false;
        if(len3 == 0) return len1 == 0 && len2 == 0;
        if(len2 == 0) return s1 == s3;
        if(len1 == 0) return s2 == s3;
        vvb dp(len1 + 1, vb(len2 + 1, false));
        dp[0][0] = true;
        for(int i = 1; i <= len2; i++)
            dp[0][i] = dp[0][i-1] && s2[i-1] == s3[i-1];
        for(int i = 1; i <= len1; i++)
            dp[i][0] = dp[i-1][0] && s1[i-1] == s3[i-1];
        for(int i = 1; i <= len1; i++)
        {
            for(int j = 1; j <= len2; j++)
            {
                // 转移方程
                dp[i][j] = (dp[i][j-1] && s2[j-1] == s3[i+j-1])
                    || (dp[i-1][j] && s1[i-1] == s3[i+j-1]);
            }
        }
        return dp[len1][len2];
    }
};