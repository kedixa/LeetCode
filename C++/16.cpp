class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int sz = nums.size(), left, right;
        int ans, min_close = numeric_limits<int>::max();
        for(int i = 0; i < sz - 2; ++i)
        {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            left = i + 1, right = sz - 1;
            while(left < right)
            {
                int tmp = nums[i] + nums[left] + nums[right];
                int diff = abs(tmp - target);
                if(diff < min_close) min_close = diff, ans = tmp;
                if(tmp < target) ++left;
                else --right;
            }
        }
        return ans;
    }
};
