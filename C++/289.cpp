class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        // 使用两个比特保存状态信息，可完成原地转换
        int row = board.size(), col;
        if(row == 0) return;
        col = board[0].size();
        auto g = [&](int i, int j)->int {
            if(i < 0 || i >= row || j < 0 || j >= col) return 0;
            else return board[i][j] & 1;
        };
        auto f = [&](int i, int j)->int {
            int s = g(i-1, j-1) + g(i-1, j) + g(i-1, j+1)
                  + g(i, j-1) + g(i, j+1)
                  + g(i+1, j-1) + g(i+1, j) + g(i+1, j+1);
            return s;
        };
        for(int i = 0; i < row; ++i)
            for(int j = 0; j < col; ++j) {
                int k = f(i, j);
                if(board[i][j] & 1) {
                    if(k ==2 || k == 3) board[i][j] |= 2;
                }
                else if(k == 3) board[i][j] |= 2;
            }
        for(int i = 0; i < row; ++i)
            for(int j = 0; j < col; ++j)
                board[i][j] >>= 1;
    }
};
