class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size(), s;
        /*
            遍历nums，当遍历到nums[i]时，如果在nums[0...i-1]中包含数字(target - nums[i]),
            则问题解决。
        */
        unordered_set<int> se; // 使用hash表判断某个数字是否出现过
        se.insert(nums[0]); // 题目保证有且只有一个解，所以此处不会越界
        vector<int>::iterator it;
        for(s = 1; s < len; ++s)
        {
            if(se.find(target - nums[s]) != se.end())
            {
                // 使用unordered_map则此处不需要进行线性查找
                it = find(nums.begin(), nums.begin() + s, target - nums[s]);
                break;
            }
            se.insert(nums[s]);
        }
        return vector<int>{it - nums.begin(), s};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size(), s;
        /*
            不使用额外存储空间，但复杂度为O(n^2)的方法。
        */
        vector<int>::iterator it;
        for(s = 0; s < len - 1; ++s)
        {
            it = find(nums.begin() + s + 1, nums.end(), target - nums[s]);
            if(it != nums.end()) break;
        }
        return vector<int>{s, it - nums.begin()};
    }
};
