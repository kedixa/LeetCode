class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int sz = nums.size();
        if(sz <= 1) return nums[0];
        // 这两个数组也可以省
        vector<int> a(sz, 0), b(sz, 0);
        if(nums[0] >= 0) a[0] = nums[0], b[0] = 0;
        else a[0] = 0, b[0] = nums[0];
        for(int i = 1; i < sz; ++i) {
            if(nums[i] >= 0)
                a[i] = max(a[i-1] * nums[i], nums[i]), b[i] = b[i-1] * nums[i];
            else a[i] = b[i-1] * nums[i], b[i] = min(a[i-1] * nums[i], nums[i]);
        }
        return *max_element(a.begin(), a.end());
    }
};
