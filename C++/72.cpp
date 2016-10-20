class Solution {
public:
    int minDistance(string word1, string word2) {
        /*
            word1[0..i]与word2[0..j]的编辑距离可以从以下几种情况转移过来：
            1. word[0..i-1]与word2[0..j]的编辑距离，再考虑去掉word2[j]
            2. word[0..i]与word2[0..j-1]的编辑距离，再考虑去掉word1[i]
            3. word[0..i-1]与word2[0..j-1]的编辑距离，再考虑匹配word1[i]与word2[j]
        */
        vector<vector<int>> vec(word1.length()+1, vector<int>(word2.length()+1,0));
        int len1=word1.length(), len2=word2.length();
        for(int i = 0; i <= len1; i++) vec[i][0] = i;
        for(int i = 0; i <= len2; i++) vec[0][i] = i;
        for(int i = 1; i <= len1; ++i)
        {
            for(int j = 1; j <= len2; ++j)
            {
                vec[i][j] = min(vec[i][j-1]+1, min(vec[i-1][j]+1, vec[i-1][j-1]+(word1[i-1]!=word2[j-1])));
            }
        }
        return vec[len1][len2];
    }
};