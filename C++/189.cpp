class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        // 参考std::rotate，这个题有很多办法可以做
        // O(1)空间，O(n)时间
        int sz = nums.size();
        k = (sz - k%sz) % sz;
        int first = 0, last = sz, next = k;
        while(first != next) {
            swap(nums[first++], nums[next++]);
            if(next==last) next = k;
            else if(first == k) k = next;
        }
    }
};
