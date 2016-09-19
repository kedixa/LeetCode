class Solution {
public:
    string countAndSay(int n) {
        /*
            简单题，每次数一下就好
        */
        string s = "1";
        if(n == 1) return s;
        while(--n)
        {
            const char * p = s.c_str();
            string tmp;
            while(*p != '\0')
            {
                char c = *p;
                int count = 1;
                while(*(p+1) == *p) ++p, ++count;
                tmp += to_string(count) + string(1, c);
                ++p;
            }
            s = tmp;
        }
        return s;
    }
};