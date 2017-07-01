class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int k = 0;
        while(m!=n) ++k, m >>= 1, n >>= 1;
        return m<<k;
    }
};
