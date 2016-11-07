class Solution {
    using vi = vector<int>;
    void dfs(int cur, vi &nums, vi &v, vector<bool> &flag, vector<vi> &result)
    {
        result.push_back(v);
        for(int i = cur; i < nums.size(); i++)
        {
            // 为了防止重复，需要使用flag标记已经使用过的数，若满足以下条件，则跳过
            if(i > 0 && nums[i] == nums[i-1] && !flag[i-1])continue;
            v.push_back(nums[i]);
            flag[i] = 1;
            dfs(i + 1, nums, v, flag, result);
            flag[i] = 0;
            v.pop_back();
        }
        return;
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // 首先排序，使相同大小的数相邻， 然后递归挨个找
        sort(nums.begin(), nums.end());
        vector<vi> result;
        vector<bool> flag(nums.size(), 0);
        vi v;
        dfs(0, nums, v, flag, result);
        return result;
    }
};