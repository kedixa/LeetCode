class NumArray {
    vector<int> v;
public:
    NumArray(vector<int> nums) {
        v.resize(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); ++i)
            v[i+1] = v[i] + nums[i];
    }
    
    int sumRange(int i, int j) {
        return v[j+1] - v[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
