class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        /*
            反向查找最长的不降子序列，设其起始位置为i，将nums[i-1]与nums[i...end]中
            大于nums[i-1]的最小的数交换，并反转最长不降子序列
        */
        int size = nums.size();
        if(size == 0) return;
        int longest_desc = size - 1;
        while(longest_desc > 0 && nums[longest_desc - 1] >= nums[longest_desc])
            longest_desc--;
        if(longest_desc == 0) reverse(nums.begin(), nums.end());
        else
        {
            int &p = nums[longest_desc - 1];
            for(int i = size - 1; i >= longest_desc; --i)
                if(nums[i] > p)
                {
                    swap(nums[i], p);
                    break;
                }
            reverse(nums.begin() + longest_desc, nums.end());
        }
        return;
    }
};