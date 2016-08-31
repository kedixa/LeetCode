class Solution {
public:
    int reverse(int x) {
        /*
            将复杂的事情交给了ostream
        */
        bool neg = false;
        long long y = x;
        if(y < 0) y = -y, neg = true;
        ostringstream oss;
        oss << y;
        string s = oss.str();
        std::reverse(s.begin(), s.end());
        y = stoll(s);
        if(y > numeric_limits<int>::max()) return 0;
        return neg==true ? -y : y;
    }
};
