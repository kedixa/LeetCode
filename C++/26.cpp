class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        /*
        偷个懒。
        */
        return unique(nums.begin(), nums.end()) - nums.begin();
    }
};