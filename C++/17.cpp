class Solution {
    vector<string> dict{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    void dfs(vector<string> &ans, const string& digits, string& s, int cur, const int len)
    {
        if(cur >= len)
        {
            ans.push_back(s);
            return;
        }
        for(auto c : dict[digits[cur] - '0'])
        {
            s[cur] = c;
            dfs(ans, digits, s, cur + 1, len);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        int len = digits.length();
        vector<string> ans;
        if(len == 0) return ans;
        string s = digits;
        dfs(ans, digits, s, 0,len);
        return ans;
    }
};
