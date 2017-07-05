class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n < 1) return false;
        else return !(n&(n-1));
    }
};
