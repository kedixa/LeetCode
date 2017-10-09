class NumMatrix {
    vector<vector<int>> v;
public:
    NumMatrix(vector<vector<int>> matrix) {
        int r = matrix.size();
        if(r == 0) return;
        int c = matrix[0].size();
        v.resize(r + 1, vector<int>(c + 1, 0));
        for(int i = 0; i < r; ++i) {
            for(int j = 0; j < c; ++j) {
                v[i+1][j+1] = v[i][j+1] + v[i+1][j] - v[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return v[row2+1][col2+1] - v[row2+1][col1] - v[row1][col2+1] + v[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
