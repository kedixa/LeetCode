class Solution {
public:
    int numDistinct(string s, string t) {
        /*
            使用动态规划算法，v[i][j]表示s[0..i]和t[0..j]的不同子序列个数
            若s[i]==t[j]，v[i][j] = v[i][j-1]+v[i-1][j-1]
            否则，v[i][j] = v[i][j-1]
            为了代码方便，在字符串开始部分添加了虚拟字符，注意下标的变换
        */
        int slen = s.length(), tlen = t.length();
        vector<int> vec[2];
        vec[0].resize(slen + 1, 1), vec[1].resize(slen + 1, 0);
        int k = 1;
        for(int i = 0; i < tlen; ++i)
        {
            auto &v0 = vec[1-k], &v1 = vec[k];
            v1[0] = 0;
            for(int j = 0; j < slen; ++j)
            {
                v1[j+1] = v1[j];
                if(s[j] == t[i]) v1[j+1] += v0[j];
            }
            k = 1-k;
        }
        return vec[1-k].back();
    }
};
