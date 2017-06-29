class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        v.reserve(nums.size());
        for(const auto &i : nums) v.push_back(to_string(i));
        // 按照下面的规则排序，在拼成字符串即可
        // 原理是对于任意两个数x, y，若"xy" 更大，则x无论如何都应该在y前面
        sort(v.begin(), v.end(), [](const string& x, const string& y){
            return x+y < y+x;
        });
        while(v.size() > 1 && v.back() == "0") v.pop_back();
        string str;
        for(auto it = v.rbegin(); it != v.rend(); ++it) {
            str += *it;
        }
        return str;
    }
};
