class Solution {
public:
    int numDecodings(string s) {
        // 设以s[i]结尾的串的解码方法数为v[i]
        int len = s.length();
        if(len == 0) return 0;
        vector<int> vec(len, 0);
        vec[0] = s[0] != '0'; // 若s[0]为'0'则v[0]为0，否则为1
        for(int i = 1; i < len; ++i)
        {
            int p = s[i-1] - '0', q = s[i] - '0';
            if(q == 0)
            {
                // 若s[i]为'0'，则s[i-1]只能是'1'或'2'
                if(p == 0) vec[i] = 0;
                else if(p < 3) vec[i] = i>1 ? vec[i-2] : 1;
            }
            // 若两位数s[i-1,i]<27，则这两位数有两种解码方案
            else if(p == 1 || (p == 2 && q < 7)) vec[i] = vec[i-1] + (i > 1 ? vec[i-2] : 1);
            // 否则只有一种
            else vec[i] = vec[i-1];
        }
        return vec[len-1];
    }
};