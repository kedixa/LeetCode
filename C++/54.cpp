class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        /*
            每次取出矩阵的最外面一层，直到矩阵为空为止。
        */
        vector<int> result;
        if(matrix.size() == 0) return result;
        /*
            用四个数表示矩阵的边界位置。
        */
        int u = 0, d = matrix.size(), l = 0, r = matrix[0].size();
        result.reserve(d * r);
        while(u < d && l < r)
        {
            for(int i = l; i < r; ++i)
                result.push_back(matrix[u][i]);
            ++u;
            if(u == d) break;
            
            --r;
            for(int i = u; i < d; ++i)
                result.push_back(matrix[i][r]);
            if(l == r) break;
            
            --d;
            for(int i = r - 1; i >= l; --i)
                result.push_back(matrix[d][i]);
            if(u == d) break;
            
            for(int i = d - 1; i >= u; --i)
                result.push_back(matrix[i][l]);
            ++l;
        }
        return result;
    }
};