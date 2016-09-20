class Solution {
    using vii = vector<int>::iterator;
    void dfs(vector<vector<int>> &result, vector<int> &tmp, vii it1, vii it2, int target)
    {
        /*
        递归结束条件
        */
        if(target < 0) return;
        if(target == 0)
        {
            result.push_back(tmp);
            return;
        }
        if(it1 == it2) return;

        /*
        若当前元素可以放
        */
        if(target >= *it1)
        {
            tmp.push_back(*it1);
            dfs(result, tmp, it1 + 1, it2, target - *it1);
            tmp.pop_back();
        }
        /*
        尝试放下一个元素
        */
        while(it1 + 1 != it2 && *(it1 + 1) == *it1) ++it1;
        dfs(result, tmp, it1 + 1, it2, target);
        return;
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        /*
            直接dfs即可
        */
        auto it1 = candidates.begin(), it2 = candidates.end();
        sort(it1, it2, std::greater<int>());
        vector<vector<int>> result;
        vector<int> tmp; // 在dfs过程中保存已经取到的元素
        dfs(result, tmp, it1, it2, target);
        return result;
    }
};