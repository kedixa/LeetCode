class Solution {
public:
    int findMin(vector<int>& nums) {
        int sz = nums.size();
        if(sz == 1 || nums[0] < nums[sz-1]) return nums[0];
        int low = 0, high = sz-1, mid;
        while(low < high) {
            mid = (low + high) / 2;
            if(nums[mid] >= nums[0]) low = mid + 1;
            else high = mid;
        }
        return nums[low];
    }
};
