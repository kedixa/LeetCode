class Solution {
public:
    int numSquares(int n) {
        // 动态规划解法
        vector<int> v;
        v.resize(n+1, n+1);
        v[0] = 0;
        for(int i = 1; i <= n; ++i) {
            int mi = v[i];
            for(int j = 1; j * j <= i; ++j) {
                mi = min(mi, v[i-j*j]);
            }
            v[i] = mi + 1;
        }
        return v[n];
    }
};
