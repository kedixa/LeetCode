class Solution {
public:
    bool isPalindrome(string s) {
        /*
            从两端分别找alphanumeric，并判断是否相等
        */
        int i = 0, j = s.length() - 1;
        if(i == j) return true;
        do
        {
            while(i<j && !isalnum(s[i])) ++i;
            while(i<j && !isalnum(s[j])) --j;
            if(tolower(s[i]) != tolower(s[j])) return false;
            ++i, --j;
        }while(i<j);
        return true;
    }
};
