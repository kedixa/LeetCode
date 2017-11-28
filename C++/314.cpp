class Solution {
    vector<int> arrsum;
    int lowbit(int x) {
        return x&(-x);
    }
    void add(int x, int y) {
        for(int i = x; i < arrsum.size(); i+=lowbit(i)) {
            arrsum[i] += y;
        }
    }
    int get(int x) {
        int sum = 0;
        for(int i = x; i > 0; i -= lowbit(i)) {
            sum += arrsum[i];
        }
        return sum;
    }
public:
    vector<int> countSmaller(vector<int>& nums) {
        // 将nums排序离散化，用树状数组维护前缀和
        // 从后往前依次取nums中的元素，找到其在离散化后的数组的下标，该下标之前的和为所求
        // 将该元素对应的计数增加1
        if(nums.size() == 0) return {};
        vector<int> result(nums.size(), 0);
        vector<int> arr = nums;
        sort(arr.begin(), arr.end());
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        arrsum.clear();
        arrsum.resize(arr.size() + 1, 0);
        for(int i = nums.size() - 1; i >= 0; i--) {
            int pos = lower_bound(arr.begin(), arr.end(), nums[i]) - arr.begin();
            result[i] = get(pos);
            add(pos + 1, 1);
        }
        return result;
    }
};
