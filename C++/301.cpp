class Solution {
    int max_len;
    vector<int> front;
    vector<string> result;
    const char c = '*';
    void dfs(string &s, int p, int len) {
        if(p == s.length()) {
            string tmp = s;
            for(auto &i : front)
                tmp[i] = c;
            tmp.erase(remove(tmp.begin(), tmp.end(), c), tmp.end());
            if(tmp.length() > max_len) {
                max_len = tmp.length();
                result.clear();
                result.push_back(std::move(tmp));
            }
            else if(tmp.length() == max_len) {
                result.push_back(std::move(tmp));
            }
            return;
        }
        if(len + (s.length() - p) < max_len)
            return;
        if(s[p] == '(') {
            front.push_back(p);
            dfs(s, p+1, len+1);
            front.pop_back();
            s[p] = c;
            dfs(s, p+1, len);
            s[p] = '(';
        }
        else if(s[p] == ')') {
            if(!front.empty()) {
                int f = front.back();
                front.pop_back();
                dfs(s, p+1, len+1);
                front.push_back(f);
            }
            s[p] = c;
            dfs(s, p+1, len);
            s[p] = ')';
        }
        else {
            dfs(s, p+1, len+1);
        }
    }
public:
    vector<string> removeInvalidParentheses(string s) {
        // 效率很差，有待提高
        max_len = 0;
        front.clear();
        result.clear();
        dfs(s, 0, 0);
        sort(result.begin(), result.end());
        result.erase(unique(result.begin(), result.end()), result.end());
        return result;
    }
};
