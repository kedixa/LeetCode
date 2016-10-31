class Solution {
public:
    bool isScramble(string s1, string s2) {
        // 小数据特判
        int len = s1.length();
        if(len < 2) return s1==s2;
        else if(len == 2) return (s1==s2)||(s1 == string(s2.rbegin(), s2.rend()));
        // 若两个字符串对应字符个数不同，则一定不scramble
        auto t1 = s1, t2 = s2;
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        if(t1 != t2) return false;
        // 对每个切片分别判断
        for(int i = 1; i < len; ++i)
        {
            auto s11 = s1.substr(0, i), s12 = s1.substr(i);
            auto s21 = s2.substr(0, i), s22 = s2.substr(i);
            auto s32 = s2.substr(0, len - i), s31 = s2.substr(len - i);
            if(
                (isScramble(s11, s21) && (isScramble(s12, s22)) ||
                (isScramble(s11, s31) && (isScramble(s12, s32)))))
                return true;
        }
        return false;
    }
};