class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        /*
            使用两个变量标记初始时第0行、第0列是否有0
            使用matrix[0][i]表示第i列是否有0，matrix[i][0]表示第i行是否有0
            最后按照这些值分别设置0即可。
        */
        int row = matrix.size();
        if(row == 0) return;
        int col = matrix[0].size();
        bool row0 = false, col0 = false;
        // 确定为0后及时退出（运行时间差别不大）
        for(int i = 0; i < col; ++i) if(matrix[0][i] == 0 && (row0 = true)) break;
        for(int i = 0; i < row; ++i) if(matrix[i][0] == 0 && (col0 = true)) break;
        for(int i = 1; i < row; ++i)
            for(int j = 1; j < col; ++j)
                if(matrix[i][j] == 0 && (matrix[i][0] = matrix[0][j] = 0)) break;
        for(int i = 1; i < row; ++i)
            if(matrix[i][0] == 0)
                for(int j = 0; j < col; ++j) matrix[i][j] = 0;
        for(int i = 1; i < col; ++i)
            if(matrix[0][i] == 0)
                for(int j = 0; j < row; ++j) matrix[j][i] = 0;
        // 第0行列最后设置
        if(row0) for(int i = 0; i < col; ++i) matrix[0][i] = 0;
        if(col0) for(int i = 0; i < row; ++i) matrix[i][0] = 0;
    }
};