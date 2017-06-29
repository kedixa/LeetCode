class Solution {
public:
    int titleToNumber(string s) {
        // 按照上一个题目的相反的思路即可
        int res = 0;
        for(const char &c : s) {
            res *= 26;
            res += (c - 'A' + 1);
        }
        return res;
    }
};
