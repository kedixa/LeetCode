class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // 假设两个数为a, b，则将全部数异或的结果为a^b
        // 若a^b中的某个比特为1，则a和b在该比特上必定不同
        // 根据该比特将数据分成两组，转化成每组只有一个只出现依次的数的问题
        int x = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        x &= -x;
        int a = 0, b = 0;
        for(const auto &y : nums) {
            if(x & y) a ^= y;
            else b ^= y;
        }
        return {a, b};
    }
};
