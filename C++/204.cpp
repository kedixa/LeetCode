class Solution {
public:
    int countPrimes(int n) {
        // 先实现一个朴素筛法
        if(n < 2) return 0;
        vector<int> v(n, 1);
        v[0] = v[1] = 0;
        for(int i = 2; i < n; ++i) {
            if(!v[i] || n / i < i) continue;
            for(int j = i * i; j < n; j+=i)
                v[j] = 0;
        }
        return accumulate(v.begin(), v.end(), 0);
    }
};
