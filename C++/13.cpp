class Solution {
public:
    int romanToInt(string s) {
        /*
            反向处理字符串
            如果出现了比之前的数字更小的数，则减去，
            否则加上
        */
        unordered_map<char, int> c2i = {
            {'I', 1}, {'V', 5}, {'X', 10},
            {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int cur_max = 0, ans = 0;
        auto it = s.rbegin();
        while(it != s.rend())
        {
            auto p = c2i[*it++];
            if(p < cur_max) ans -= p;
            else ans += p, cur_max = p;
        }
        return ans;
    }
};
