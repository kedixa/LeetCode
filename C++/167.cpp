class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size(), s, t;
        vector<int>::iterator it;
        for(s = 0; s < len - 1; ++s)
        {
            if(binary_search(nums.begin() + s + 1, nums.end(), target - nums[s]))
            {
                it = lower_bound(nums.begin() + s + 1, nums.end(), target - nums[s]);
                break;
            }
        }
        return vector<int>{s + 1, it - nums.begin() + 1};
    }
};
