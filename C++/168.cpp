class Solution {
public:
    string convertToTitle(int n) {
        // 注意到每个数位都是每26次循环，故每次对n取模可得一个数位
        string str;
        while(n) {
            int t = n % 26;
            if(t == 0) {
                t = 26;
            }
            n = (n-t)/26;
            str.push_back('A' - 1 + t);
        }
        reverse(str.begin(), str.end());
        return str;
    }
};
