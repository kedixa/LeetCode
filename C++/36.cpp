class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        /*
            按行、列、宫分别检测即可
        */
        for(int i = 0; i < 9; ++i)
        {
            unsigned int mark = 0;
            for(int j = 0; j < 9; ++j)
            {
                char &c = board[i][j];
                if(c == '.') continue;
                int k = c - '0';
                if(mark & (1<<k)) return false;
                mark |= (1<<k);
            }
        }
        for(int i = 0; i < 9; ++i)
        {
            unsigned int mark = 0;
            for(int j = 0; j < 9; ++j)
            {
                char &c = board[j][i];
                if(c == '.') continue;
                int k = c - '0';
                if(mark & (1<<k)) return false;
                mark |= (1<<k);
            }
        }
        for(int i = 0; i < 3; ++i)
        {
            for(int j = 0; j < 3; ++j)
            {
                unsigned int mark = 0;
                for(int m = 0; m < 3; ++m)
                {
                    for(int n = 0; n < 3; ++n)
                    {
                        char &c = board[i * 3 + m][j * 3 + n];
                        if(c == '.') continue;
                        int k = c - '0';
                        if(mark & (1<<k)) return false;
                        mark |= (1<<k);
                    }
                }
            }
        }
        return true;
    }
};