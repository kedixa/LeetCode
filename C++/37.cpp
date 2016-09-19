class Solution {
    using Node = pair<int,int>;
    bool dfs(vector<vector<char>> &board, stack<Node> &st)
    {
        if(st.empty()) return true;
        Node p = st.top();
        st.pop();
        int &x = p.first, &y = p.second;
        bool mark[10] = {0};
        for(int i = 0; i < 9; ++i)
            if(board[i][y] != '.') mark[board[i][y] - '0'] = 1;
        for(int i = 0; i < 9; ++i)
            if(board[x][i] != '.') mark[board[x][i] - '0'] = 1;
        for(int i = (x/3)*3; i < (x/3)*3 + 3; ++i)
            for(int j = (y/3)*3; j < (y/3)*3 + 3; ++j)
                if(board[i][j] != '.') mark[board[i][j] - '0'] = 1;
        for(int i = 1; i < 10; ++i)
        {
            if(mark[i]) continue;
            board[x][y] = i + '0';
            if(dfs(board, st)) return true;
            board[x][y] = '.';
        }
        st.push(p);
        return false;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        /*
            本题的测试样例比较少，采用dfs直接对每个空位置枚举可以填写的值即可
        */
        stack<Node> st;
        for(int i = 0; i < 9; ++i)
            for(int j = 0; j < 9; ++j)
                if(board[i][j] == '.') st.push(Node(i, j));
        dfs(board, st);
        return;
    }
};