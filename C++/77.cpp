class Solution {
    void dfs(int num, int cur, int ma, int k, vector<vector<int>>& vec, vector<int> &v)
    {
        if(num == k)
        {
            vec.push_back(v);
            return;
        }
        for(int i = cur; i <= ma - k + num + 1; ++i)
        {
            v[num] = i;
            dfs(num + 1, i + 1, ma, k, vec, v);
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        // 逐个生成即可
        vector<vector<int>> result;
        vector<int> v(k);
        dfs(0, 1, n, k, result, v);
        return result;
    }
};