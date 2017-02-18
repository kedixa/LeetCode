class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // 所有的值取异或，结果为只出现一次的值
        int res = 0;
        for(auto &x : nums)
            res ^= x;
        return res;
    }
};
