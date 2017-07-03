class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(t < 0 || k < 1) return false;
        // 使用multiset 维护所需的区间，依次判决
        multiset<long long> ms;
        for(int i = 0; i < nums.size(); ++i) {
            auto it1 = ms.lower_bound(nums[i] - (long long)t);
            auto it2 = ms.upper_bound(nums[i] + (long long)t);
            if(it1 != it2)
                return true;
            ms.insert(nums[i]);
            if(i - k >= 0) ms.erase(ms.find(nums[i-k]));
        }
        return false;
    }
};
