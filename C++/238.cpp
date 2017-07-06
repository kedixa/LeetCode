class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // 正向反向各一遍，用一个数记录nums[i]之前和之后的乘积即可
        int sz = nums.size();
        vector<int> output(sz, 1);
        int mul = 1;
        for(int i = 0; i < sz; ++i) {
            output[i] = mul;
            mul *= nums[i];
        }
        mul = 1;
        for(int i = sz - 1; i >= 0; --i) {
            output[i] *= mul;
            mul *= nums[i];
        }
        return output;
    }
};
