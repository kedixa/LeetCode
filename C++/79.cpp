class Solution {
    static int dir[4][2];
    bool dfs(int x, int y, int &row, int &col, int cur, string &word, vector<vector<char>> &board)
    {
        if(x < 0 || y < 0 || x >= row || y >= col) return false;
        if(board[x][y] == word[cur])
        {
            if(cur + 1 == word.length()) return true;
            board[x][y] = 0; // 走过的点要标记
            for(int i = 0; i < 4; ++i)
            {
                // 向相邻的点转移
                if(dfs(x + dir[i][0], y + dir[i][1], row, col, cur + 1, word, board))
                    return true;
            }
            board[x][y] = word[cur];
        }
        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        // 深度优先遍历board，寻找word的匹配
        if(word.length() == 0) return true;
        if(board.size() == 0) return false;
        int row = board.size(), col = board[0].size();
        for(int i = 0; i < row; ++i)
            for(int j = 0; j < col; ++j)
                if(dfs(i, j, row, col, 0, word, board)) return true;
        return false;
    }
};

int Solution::dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};