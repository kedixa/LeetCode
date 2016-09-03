class Solution {
    using si = string::iterator;
    bool _match(const char *s, const char *p)
    {
        /*
            如果p已经为空，则只有s为空才能匹配
        */
        if(*p == '\0') return (*s == '\0');

        /*
            根据下一个字符是否为‘*’分为两种情况
        */
        if(*(p+1) == '*')
        {
            /*
            这里又有x*和.*两种情况
            */
            while(*p == *s || (*p == '.' && *s != '\0'))
            {
                if(_match(s, p + 2)) return true;
                ++s;
            }
            return _match(s, p + 2);
        }
        else
        {
            if(*p == *s || (*p == '.' && *s != '\0'))
                return _match(s + 1, p + 1);
            return false;
        }

    }
public:
    bool isMatch(string s, string p) {
        /*
            使用C类型的字符串指针而不是string::iterator 似乎更加方便
        */
        return _match(s.c_str(), p.c_str());
    }
};
