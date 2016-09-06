class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
            有待改进，暂时还没相通
        */
        sort(nums.begin(), nums.end());
        int sz = nums.size(), left, right;
        vector<vector<int>> vec;
        for(int i = 0; i < sz - 2; ++i)
        {
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            left = i + 1, right = sz - 1;
            while(left < right)
            {
                int tmp = nums[i] + nums[left] + nums[right];
                if(tmp == 0)
                {
                    vec.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    ++left, --right;
                }
                else if(tmp < 0) ++left;
                else --right;
            }
        }
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        return vec;
    }
};
