class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long n = numerator, d = denominator;
        // 先转换成正数，便于处理
        bool sign = false;
        if(n < 0) sign = !sign, n = -n;
        if(d < 0) sign = !sign, d = -d;
        if(n==0) sign = false;
        string str;
        str += to_string(n/d);
        n %= d;
        if(n==0) return (sign?"-":"") + str;
        str.push_back('.');
        unordered_map<long long, int> um; // 将余数映射到下标
        // 依次处理每一位，直到n为0或出现相同的余数
        while(n!=0) {
            auto it = um.find(n);
            if(it!=um.end()) {
                str.insert(it->second, 1, '(');
                str.push_back(')');
                break;
            }
            else {
                um.insert({n, str.size()});
                n *= 10;
                str.push_back(n/d + '0');
                n %= d;
            }
        }
        if(sign)
            str = "-" + str;
        return str;
    }
};
