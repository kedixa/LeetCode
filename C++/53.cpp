class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        /*
            动态规划，依次将各个数加起来，得到一个部分和，
            若一个部分和小于零，则该部分不可能是所求SubArray的一部分，
            此时将其抛弃，置部分和为nums[i]。
        */
        int msa = nums[0];
        int tmp = -1;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(tmp <= 0) tmp = nums[i];
            else tmp += nums[i];
            msa = max(msa, tmp);
        }
        return msa;
    }
};