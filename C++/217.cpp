class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> us;
        for(const auto &k : nums) {
            if(us.find(k) != us.end()) return true;
            us.insert(k);
        }
        return false;
    }
};
