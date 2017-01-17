class Solution {
    void bfs(vector<vector<char>> &board, int x, int y)
    {
        int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
        queue<pair<int,int>> que;
        que.push(pair<int,int>(x,y));
        board[x][y] = 'A';
        while(!que.empty())
        {
            auto q = que.front();
            que.pop();
            for(int i = 0; i < 4; ++i)
            {
                auto xx = q.first + dir[i][0], yy = q.second + dir[i][1];
                if(xx < 0 || xx >= board.size() || yy < 0 || yy >= board[0].size())
                    continue;
                if(board[xx][yy]=='O')
                    board[xx][yy]='A', que.push(pair<int,int>(xx,yy));
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        // 除以边缘的'O'开始搜索出的连通区域外，其余的'O'都修改为'X'
        int row = board.size();
        if(row == 0) return;
        int col = board[0].size();
        for(int i = 0; i < row; ++i)
        {
            if(board[i][0]=='O') bfs(board, i, 0);
            if(board[i][col-1]=='O') bfs(board, i, col-1);
        }
        for(int i = 1; i < col - 1; ++i)
        {
            if(board[0][i]=='O') bfs(board, 0, i);
            if(board[row-1][i]=='O') bfs(board, row-1, i);
        }
        for(auto &r : board)
            for(auto &c : r)
                if(c=='O') c='X';
        for(auto &r : board)
            for(auto &c : r)
                if(c=='A') c='O';
        return;
    }
};
