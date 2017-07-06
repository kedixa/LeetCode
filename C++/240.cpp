class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        if(row == 0) return false;
        int col = matrix[0].size();
        if(col == 0) return false;
        int r = 0, c = col - 1;
        while(r < row && c >= 0) {
            if(matrix[r][c] == target) return true;
            if(matrix[r][c] > target) --c;
            else if(matrix[r][c] < target) ++r;
        }
        return false;
    }
};
