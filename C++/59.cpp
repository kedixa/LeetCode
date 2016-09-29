class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        /*
            每次处理矩阵的最外面一层，直到矩阵为空为止。
        */
        vector<vector<int>> result(n, vector<int>(n));
        int index = 1;
        if(n == 0) return result;
        /*
            用四个数表示矩阵的边界位置。
        */
        int u = 0, d = n, l = 0, r = n;
        while(u < d && l < r)
        {
            for(int i = l; i < r; ++i)
                result[u][i] = index++;
            ++u;
            if(u == d) break;
            
            --r;
            for(int i = u; i < d; ++i)
                result[i][r] = index++;
            if(l == r) break;
            
            --d;
            for(int i = r - 1; i >= l; --i)
                result[d][i] = index++;
            if(u == d) break;
            
            for(int i = d - 1; i >= u; --i)
                result[i][l] = index++;
            ++l;
        }
        return result;
    }
};