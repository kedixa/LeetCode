class Solution {
    using vi = vector<int>;
    void dfs(vector<vi> &result, vi &nums, vi &vec, vector<bool> &mark, int cur)
    {
        /*
        如果已经填满当前序列，则保存并返回
        */
        if(cur == nums.size())
        {
            result.push_back(vec);
            return;
        }
        /*
        填写vec[cur]处的数值，并递归填写下一个数值
        */
        for(int i = 0; i < nums.size(); ++i)
        {
            if(!mark[i])
            {
                mark[i] = true;
                vec[cur] = nums[i];
                dfs(result, nums, vec, mark, cur + 1);
                mark[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        /*
            递归生成所有的排列。
        */
        vector<vector<int>> result;
        vector<bool> mark(nums.size(), false); // 标记某一位是否已经用过
        vector<int> vec(nums.size()); // 保存临时结果
        sort(nums.begin(), nums.end()); // 保证按字典序排列
        dfs(result, nums, vec, mark, 0);
        return result;
    }
};