class Solution {
    void dfs(int cur, vector<int>& nums, vector<int> &v, vector<vector<int>>& vec)
    {
        vec.push_back(v);
        for(int i = cur; i < nums.size(); i++)
        {
            v.push_back(nums[i]);
            dfs(i + 1, nums, v, vec);
            v.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        // 逐个生成即可
        vector<vector<int>> result;
        vector<int> v; // 此时不能提前分配空间
        dfs(0, nums, v, result);
        return result;
    }
};