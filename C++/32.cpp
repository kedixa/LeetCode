class Solution {
public:
    int longestValidParentheses(string s) {
        /*
        定义数组v，若s[i]为'('则v[i]表示以s[i-1]结尾的最长的合法括号序列，
        若s[i]为')'，则v[i]表示以s[i]结尾的最长的合法括号序列；
        数组v中最大的数字即为所求。
        */
        s = "#" + s;
        int len = s.length();
        vector<int> v(len, 0);
        for(int i = 2; i < len; i++)
        {
            if(s[i] == '(') v[i] = (s[i-1]==')')?v[i-1]:0;
            else
            {
                int &k = v[i-1];
                if(s[i-1] == '(') v[i] = k + 2;
                else
                {
                    int tmp = i - k - 1;
                    if(s[tmp] == '(') v[i] = v[tmp] + k + 2;
                    else v[i] = 0;
                }
            }
        }
        return *max_element(v.begin(), v.end());
    }
};