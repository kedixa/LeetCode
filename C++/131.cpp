class Solution {
    vector<vector<string>> result;
    vector<string> tmp;
    bool pal(string &s, int a, int b)
    {
        while(a < b)
            if(s[a++] != s[--b]) return false;
        return true;
    }
    void dfs(string &s, int a, int b)
    {
        if(a==b)
        {
            result.push_back(tmp);
            return;
        }
        for(int i = a + 1; i <= b; ++i)
        {
            if(pal(s, a, i))
            {
                tmp.push_back(s.substr(a, i-a));
                dfs(s, i, b);
                tmp.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        result.clear();
        tmp.clear();
        int len = s.length();
        dfs(s, 0, len);
        return result;
    }
};
