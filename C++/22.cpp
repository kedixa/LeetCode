class Solution {
    void dfs(vector<string> &vec, string &str, int index, int left_par, int right_par, int max_len)
    {
        if(index == max_len)
        {
            vec.push_back(str);
            return;
        }
        if(left_par < max_len / 2)
            str[index] = '(', dfs(vec, str, index + 1, left_par + 1, right_par, max_len);
        if(right_par < left_par)
            str[index] = ')', dfs(vec, str, index + 1, left_par, right_par + 1, max_len);
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        /*
            递归生成即可
        */
        vector<string> vec;
        string str(n * 2, '0');
        dfs(vec, str, 0, 0, 0, n * 2);
        return vec;
    }
};