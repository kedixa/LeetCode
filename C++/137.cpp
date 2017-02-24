class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // one的第i位为1表示该位出现1的次数模3余1，
        // two的第i位为1表示该位出现1的次数模3余2.
        int one = 0, two = 0;
        for(auto &x : nums)
            one = (one ^ x) & ~two,
            two = (two ^ x) & ~one;
        return one;
    }
};
