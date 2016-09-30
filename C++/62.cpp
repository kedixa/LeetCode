class Solution {
    vector<vector<int>> vec;
public:
    Solution()
    {
        vec.resize(101, vector<int>(101));
        for(int i = 0; i < 101; ++i) vec[0][i] = vec[i][0] = 1;
        for(int i = 1; i < 101; ++i)
            for(int j = 1; j < 101; ++j)
                vec[i][j] = vec[i][j-1] + vec[i-1][j];
    }
    int uniquePaths(int m, int n) {
        /*
            有更好的方法。
        */
        return vec[m-1][n-1];
    }
};