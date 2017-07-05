class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // Majority Vote algorithm
        int k1 = 0, k2 = 0, n1 = 0, n2 = 0;
        for(const auto &c : nums) {
            if(n1 != 0 && k1 == c) ++n1;
            else if(n2 != 0 && k2 == c) ++n2;
            else if(n1 == 0) k1 = c, n1 = 1;
            else if(n2 == 0) k2 = c, n2 = 1;
            else --n1, --n2;
        }
        vector<int> result;
        if(n1 > 0 && count(nums.begin(), nums.end(), k1) > nums.size() / 3)
            result.push_back(k1);
        if(n2 > 0 && count(nums.begin(), nums.end(), k2) > nums.size() / 3)
            result.push_back(k2);
        return result;
    }
};
