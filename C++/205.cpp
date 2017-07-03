class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> vs(128, -1), vt(128, -1);
        int sz = s.length();
        for(int i = 0; i < sz; ++i) {
            if(vs[s[i]] == -1 && vt[t[i]] == -1) {
                vs[s[i]] = t[i];
                vt[t[i]] = s[i];
            }
            else if(vs[s[i]] != t[i] || vt[t[i]] != s[i])
                return false;
        }
        return true;
    }
};
