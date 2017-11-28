class NumArray {
    vector<int> vec;
    vector<int> nums;
    int lowbit(int x) {
        return x&(-x);
    }
    void add(int x, int y) {
        for(int i = x; i < vec.size(); i+= lowbit(i))
            vec[i] += y;
    }
    int get(int x) {
        int sum = 0;
        for(int i = x; i > 0; i-=lowbit(i))
            sum += vec[i];
        return sum;
    }
public:
    // 树状数组
    NumArray(vector<int> nums) {
        vec.resize(nums.size() + 10);
        this->nums = nums;
        for(int i = 0; i < nums.size(); i++) {
            add(i+1, nums[i]);
        }
    }
    
    void update(int i, int val) {
        add(i+1, val - nums[i]);
        nums[i] = val;
    }
    
    int sumRange(int i, int j) {
        return get(j+1) - get(i);
    }
};
