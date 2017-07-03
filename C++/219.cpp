class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> us;
        for(int i = 0; i < nums.size(); ++i) {
            auto it = us.find(nums[i]);
            if(it != us.end()) return true;
            us.insert(nums[i]);
            if(i - k >= 0) us.erase(nums[i-k]);
        }
        return false;
    }
};
