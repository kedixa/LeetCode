class Solution {
    vector<vector<int>> vec; // 记录结果
    vector<int> st;          // 记录中间结果
    void dfs(int s, int k, int n) {
        // 使用[s, 9]中的k个数构成n
        // 不满足条件的情况
        if(k == 0 || s > n || s > 9) return;
        // 已经满足的情况
        if(k == 1 && s == n) {
            st.push_back(n);
            vec.push_back(st);
            st.pop_back();
            return;
        }
        // 暂时未满足的情况
        // 不使用数s
        dfs(s+1, k, n);
        // 使用数s
        st.push_back(s);
        dfs(s + 1, k - 1, n - s);
        st.pop_back();
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vec.clear();
        st.clear();
        dfs(1, k, n);
        return vec;
    }
};
