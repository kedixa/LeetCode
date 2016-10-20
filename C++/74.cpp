class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        /*
            二分查找target可能所在行，再二分查找target是否在这一行
        */
        int left = 0, right = matrix.size(), mid;
        while(left < right)
        {
            mid = (left + right) / 2;
            if(matrix[mid][0] <= target) left = mid + 1;
            else right = mid;
        }
        --left;
        if(left == -1) return false;
        return binary_search(matrix[left].begin(), matrix[left].end(), target);
    }
};