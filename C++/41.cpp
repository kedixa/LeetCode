class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        /*
            遍历nums数组，（假定下标从1开始）将数字nums[i]与nums[nums[i]]交换，
            直到发生终止条件；
            最终所有的nums[i] == i，否则第一个不匹配的位置就是缺少的值。
            保证每次操作至少有一个值归为，因此时间复杂度为O(n)
        */
        for(auto &i : nums) --i; // 在不影响复杂度的情况下简化操作
        auto len = nums.size();
        for(int i = 0; i < len; ++i)
        {
            while(nums[i] != i)
            {
                if(nums[i] < 0 || nums[i] >= len) break; // 超出范围，停止转移
                if(nums[nums[i]] == nums[i]) // 数据已有，弃掉
                {
                    nums[i] = -1;
                    break;
                }
                swap(nums[i], nums[nums[i]]);
            }
        }
        for(int i = 0; i < len; ++i)
            if(nums[i] != i) return i + 1;
        return len + 1;
    }
};