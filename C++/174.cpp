class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        auto &d = dungeon;
        int m = d.size();
        int n = d[0].size();
        // 构造一个新的vector<vector> v，其中v[i][j]保存的是走到该位置时，
        // 需要保留的最少体力是多少
        // 这样反向求出每个v[i][j]，则v[0][0]为所求
        // 在边界设很大的值，保证一定从出口走出
        vector<vector<long long>> v(m + 1, vector<long long>(n + 1, 2147483647));
        v[m-1][n] = 1; // 从出口走出去至少需要1体力
        for(int i = m-1; i >= 0; --i) {
            for(int j = n-1; j >= 0; --j) {
                // 每个位置需要经过下方或右方中最优的位置走出去
                v[i][j] = max(min(v[i+1][j], v[i][j+1]) - d[i][j], 1LL);
            }
        }
        return v[0][0];
    }
};
