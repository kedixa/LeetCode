class Solution {
public:
    string addBinary(string a, string b) {
        /*
            与十进制加法大同小异。
        */
        string ans;
        int carry = 0;
        auto it1 = a.rbegin(), it2 = b.rbegin();
        while(it1 != a.rend() || it2 != b.rend())
        {
            carry += (it1==a.rend()?0:(*it1++ - '0')) + (it2==b.rend()?0:(*it2++ - '0'));
            if(carry&1) ans.push_back('1');
            else ans.push_back('0');
            carry >>= 1;
        }
        if(carry&1) ans.push_back('1');
        reverse(ans.begin(), ans.end());
        return ans;
    }
};