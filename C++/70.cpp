class Solution {
    vector<int> vec;
public:
    Solution()
    {
        vec.resize(46, 1);
        for(int i = 2; i < 46; ++i)
            vec[i] = vec[i-1] + vec[i-2];
    }
    int climbStairs(int n) {
        /*
            打表。
        */
        return vec[n];
    }
};