class Solution {
public:
    int jump(vector<int>& nums) {
        /*
            贪心跳法，每次跳到使得下一次跳的最远的位置上。
        */
        int step = 0;
        for(int i = 0; i < nums.size() - 1;)
        {
            ++step;
            /*
            如果这次可以跳完，则跳完。
            */
            if(i + nums[i] >= nums.size() - 1) break;
            /*
            否则寻找最好的位置，跳过去。
            */
            int ma = 0, index = 1;
            for(int j = 1; j <= nums[i] && i + j < nums.size(); ++j)
            {
                if(ma < nums[i + j] + j) ma = nums[i + j] + j, index = j;
            }
            i += index;
        }
        return step;
    }
};