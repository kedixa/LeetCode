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
        填写vec[cur]处的数值，并递归填写下一个数值，
        为了不重复，同一个位置已经填过的数字不能再填
        */
        int last = 0x80000000;
        for(int i = 0; i < nums.size(); ++i)
        {
            if(!mark[i] && nums[i] != last)
            {
                mark[i] = true;
                vec[cur] = nums[i];
                dfs(result, nums, vec, mark, cur + 1);
                mark[i] = false;
                last = nums[i];
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
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