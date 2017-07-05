class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int row = matrix.size();
        if(row == 0) return 0;
        int col = matrix[0].size();
        // 正方形边长
        // side[i][j] 表示以i,j为右下角的方形的最大边长
        vector<vector<int>> side(row, vector<int>(col, 0));
        int max_side = 0;
        side[0][0] = (matrix[0][0] == '1');
        max_side = max(max_side, side[0][0]);
        for(int i = 1; i < row; ++i) {
            side[i][0] = (matrix[i][0] == '1');
            max_side = max(max_side, side[i][0]);
        }
        for(int j = 1; j < col; ++j) {
            side[0][j] = (matrix[0][j] == '1');
            max_side = max(max_side, side[0][j]);
        }
        for(int i = 1; i < row; ++i) {
            for(int j = 1; j < col; ++j) {
                if(matrix[i][j] == '1') {
                    // 若为1，则边长可由该方程转移得到
                    side[i][j] = min(side[i][j-1], min(side[i-1][j], side[i-1][j-1])) + 1;
                    max_side = max(max_side, side[i][j]);
                }
            }
        }
        return max_side * max_side;
    }
};
