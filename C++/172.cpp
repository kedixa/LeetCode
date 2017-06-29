class Solution {
public:
    int trailingZeroes(int n) {
        // 只有2和5相乘才能出现末尾的0
        // 所以数有多少个因子5即可
        int res = 0;
        while(n) {
            res += n/5;
            n /= 5;
        }
        return res;
    }
};
