class Solution {
    using vvs = vector<vector<string>>;
    using vvi = vector<vector<int>>;
    vector<string> to_vstring(vvi &vec)
    {
        vector<string> vs;
        for(int i = 0; i < vec.size(); ++i)
        {
            string tmp;
            for(int j = 0; j < vec[i].size(); ++j)
                tmp += vec[i][j] == 0 ? "Q" : ".";
            vs.push_back(tmp);
        }
        return vs;
    }
    void add(vvi &vec, int x, int y, int c)
    {
        int sz = vec.size();
        for(int i = 0; i < sz; ++i)
        {
            if(i == y) continue;
            vec[x][i] += c;
        }
        for(int i = 0; i < sz; ++i)
        {
            if(i == x) continue;
            vec[i][y] += c;
        }
        int xi, yi;
        xi = x, yi = y;
        while(--xi >= 0 && --yi >= 0) vec[xi][yi] += c;
        xi = x, yi = y;
        while(--xi >= 0 && ++yi < sz) vec[xi][yi] += c;
        xi = x, yi = y;
        while(++xi < sz && ++yi < sz) vec[xi][yi] += c;
        xi = x, yi = y;
        while(++xi < sz && --yi >= 0) vec[xi][yi] += c;
    }
    void dfs(vvs &result, vvi &vec, int cur)
    {
        /*
        若最后一行放置完，则保存结果。
        */
        if(cur == vec.size())
        {
            result.push_back(to_vstring(vec));
            return;
        }
        /*
        在当前行找一个可以放置的位置，放置并到下一行查找。
        */
        int sz = vec.size();
        for(int i = 0; i < sz; ++i)
        {
            if(vec[cur][i] == 0)
            {
                add(vec, cur, i, 1); // 去掉不能放置的位置
                dfs(result, vec, cur + 1);
                add(vec, cur, i, -1); // 找回去掉的位置
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        /*
            递归枚举每个可以放置的位置。
        */
        vvs result;
        vvi vec(n, vector<int>(n, 0));
        dfs(result, vec, 0);
        return result;
    }
};