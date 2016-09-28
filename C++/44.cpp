class Solution {
public:
    bool isMatch(string s, string p) {
        /*
            使用了动态规划，但此题还有更好的做法，故暂不解释
        */
        if(p.size() == 0) return s.size() == 0;
        s = "aa" + s, p = "aa" + p;
        vector<vector<int>> vec(2, vector<int>(p.size()));
        vec[0][0] = 1;
        for(int i = 1; i < s.size(); ++i)
        {
            for(int j = 1; j < p.size(); ++j)
            {
                if(s[i] == p[j] || p[j] == '?') vec[1][j] = vec[0][j - 1];
                else if(p[j] == '*') vec[1][j] = vec[0][j - 1] || vec[0][j] || vec[1][j - 1];
                else vec[1][j] = 0;
            }
            vec[0].swap(vec[1]);
            vec[0][0] = 0;
        }
        return vec[0][p.size() - 1];
    }
};