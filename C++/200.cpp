class Solution {
    using Node=pair<int,int>;
    int row, col;
    void bfs(int r, int c, vector<vector<char>>& g) {
        static const int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
        queue<Node> que;
        que.push(Node(r,c));
        g[r][c] = '0';
        while(!que.empty()) {
            auto q = que.front();
            que.pop();
            Node p;
            for(int i = 0; i < 4; ++i) {
                p = {q.first + dir[i][0], q.second + dir[i][1]};
                if(p.first >= 0 && p.first < row && p.second >= 0 &&
                   p.second < col && g[p.first][p.second] == '1') {
                    que.push(p);
                    g[p.first][p.second] = '0';
                }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        // bfs寻找连通块
        row = grid.size();
        if(row==0) return 0;
        col = grid[0].size();
        int ans = 0;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(grid[i][j] == '1') {
                    ++ans;
                    bfs(i, j, grid);
                }
            }
        }
        return ans;
    }
};
