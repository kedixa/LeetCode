class Solution {
    using vii = vector<int>::iterator;
    void dfs(vector<vector<int>> &result, vector<int> &tmp, vii it1, vii it2, int target)
    {
        /*
        递归结束条件
        */
        if(it1 == it2) return;
        if(target < 0) return;
        if(target == 0)
        {
            result.push_back(tmp);
            return;
        }
        /*
        若当前元素还可以放
        */
        if(target >= *it1)
        {
            tmp.push_back(*it1);
            dfs(result, tmp, it1, it2, target - *it1);
            tmp.pop_back();
        }
        /*
        放下一个元素
        */
        dfs(result, tmp, it1 + 1, it2, target);
        return;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        /*
            为了防止结果重复，首先去掉candidates中重复的元素，然后dfs即可
        */
        auto it1 = candidates.begin(), it2 = candidates.end();
        sort(it1, it2);
        it2 = unique(it1, it2);
        candidates.erase(it2, candidates.end());
        it1 = candidates.begin(), it2 = candidates.end();
        vector<vector<int>> result;
        vector<int> tmp; // 在dfs过程中保存已经取到的元素
        dfs(result, tmp, it1, it2, target);
        return result;
    }
};