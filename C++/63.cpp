class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        /*
            如果一个位置是1，那么到达它的方法有0个，否则有g[i-1][j]+g[i][j-1]个。
        */
        auto &g = obstacleGrid;
        int n = g.size(), m = g[0].size();
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < m; ++j)
            {
                if(g[i][j] == 1) g[i][j] = 0;
                else if(i==0 && j==0) g[i][j] = 1;
                else g[i][j] = ((i==0)?0:g[i-1][j]) + ((j==0)?0:g[i][j-1]);
            }
        }
        return g[n-1][m-1];
    }
};