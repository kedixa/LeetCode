class Solution {
    using iter = vector<int>::iterator;
    vector<vector<int>> threeSum(iter it1, iter it2, int target)
    {
        // 保证[it1, it2)已排序
        int sz = distance(it1, it2);
        vector<vector<int>> vec;
        for(auto it = it1; it != it2; advance(it, 1))
        {
            if(it != it1 && *it == *(it - 1)) continue;
            auto left = it + 1, right = it2 - 1;
            while(left < right)
            {
                int tmp = *it + *left + *right - target;
                if(tmp == 0)
                {
                    vec.push_back(vector<int>{*it, *left, *right});
                    advance(left, 1), advance(right, -1);
                }
                else if(tmp < 0) advance(left, 1);
                else advance(right, -1);
            }
        }
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        return vec;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> vec;
        int sz = nums.size();
        for(int i = 0; i < sz - 3; ++i)
        {
            if(i != 0 && nums[i] == nums[i - 1]) continue;
            auto v = threeSum(nums.begin() + i + 1, nums.end(), target - nums[i]);
            for(auto &j : v)
                vec.push_back(vector<int>{nums[i], j[0], j[1], j[2]});
        }
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        return vec;
    }
};