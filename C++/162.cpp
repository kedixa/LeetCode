class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 0) return -1;
        if(sz == 1 || nums[0] > nums[1]) return 0;
        for(int i = 1; i < sz - 1; ++i)
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]) return i;
        return sz-1;
    }
};
