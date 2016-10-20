class Solution {
public:
    void sortColors(vector<int>& nums) {
        /*
            先数个数再赋值。
        */
        if(nums.empty()) return;
        int n[3] = {0, 0, 0};
        for(auto &i : nums) n[i]++;
        auto it = fill_n(nums.begin(), n[0], 0);
        it = fill_n(it, n[1], 1);
        fill_n(it, n[2], 2);
    }
};