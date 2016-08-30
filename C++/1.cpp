class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size(), s;
        vector<int>::iterator it;
        for(s = 0; s < len - 1; ++s)
        {
            it = find(nums.begin() + s + 1, nums.end(), target - nums[s]);
            if(it != nums.end()) break;
        }
        return vector<int>{s, it - nums.begin()};
    }
};
