class Solution {
    long long read(const char *p, int n) {
        if(*p == '\0') return -1;
        if(*p == '0' && n != 1) return -1;
        long long res = 0;
        for(int i = 0; i < n; i++) {
            if(*p == '\0') return -1;
            res *= 10;
            res += p[i] - '0';
        }
        return res;
    }
    bool check(long long x1, long long x2, const char *p) {
        while(*p != '\0') {
            long long x3 = x1 + x2;
            string tmp = to_string(x3);
            int len = tmp.length();
            const char *q = tmp.c_str();
            for(int i = 0; i < len; i++) {
                if(*p != *q) return false;
                ++p, ++q;
            }
            x1 = x2, x2 = x3;
        }
        return true;
    }
public:
    bool isAdditiveNumber(string num) {
        int len = num.length();
        if(len < 3) return false;
        const char *p = num.c_str();
        long long x1, x2;
        for(int i = 1; i <= len-2; i++) {
            for(int j = 1; i + j <= len-1; j++) {
                x1 = read(p, i);
                x2 = read(p + i, j);
                if(x1 == -1 || x2 == -1) continue;
                if(check(x1, x2, p + i + j))
                    return true;
            }
        }
        return false;
    }
};
