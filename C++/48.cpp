class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        /*
            题目要求inplace交换，由于是旋转90度，故使用“十”字将矩阵等分成四块，
            每次将四块中的对应元素归位即可，此处采用对角十字，其中一个块如“*”所示。
            ***·
            ·*··
            ····
            ····
        */
        int n = matrix.size(), tmp, m = n - 1;
        for(int i = 0; i < n/2; ++i)
        {
            for(int j = i; j < n - i - 1; ++j)
            {
                /*
                对每个“*”，找到其它几个块中的对应位置，顺时针交换即可。
                */
                tmp = matrix[i][j];
                matrix[i][j] = matrix[m - j][i];
                matrix[m - j][i] = matrix[m - i][m - j];
                matrix[m - i][m - j] = matrix[j][m - i];
                matrix[j][m - i] = tmp;
            }
        }
    }
};