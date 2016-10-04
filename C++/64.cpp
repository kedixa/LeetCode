class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        /*
            一个点的最短路径从左边或上方的最小值中转移过来。
        */
        int n = grid.size(), m = grid[0].size();
        for(int i = 1; i < m; ++i) grid[0][i] += grid[0][i-1];
        for(int i = 1; i < n; ++i) grid[i][0] += grid[i-1][0];
        for(int i = 1; i < n; ++i)
            for(int j = 1; j < m; ++j)
                grid[i][j] += min(grid[i][j-1], grid[i-1][j]);
        return grid[n-1][m-1];
    }
};