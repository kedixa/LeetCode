class Solution {
    bool is_pal(const string& str, int s, int t) {
        while(s < t) {
            if(str[s] != str[t]) return false;
            ++s, --t;
        }
        return true;
    }
public:
    string shortestPalindrome(string s) {
        // 本题有O(n)解法
    	int len = s.length();
        if(len == 0) return "";
        int a = len - 1;
        while(a > 0) {
            if(is_pal(s, 0, a)) break;
            --a;
        }
        string p = s.substr(a+1);
        reverse(p.begin(), p.end());
        return p + s;
    }
};
