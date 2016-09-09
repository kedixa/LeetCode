class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        /*
        偷个懒。
        */
        return remove(nums.begin(), nums.end(), val) - nums.begin();
    }
};