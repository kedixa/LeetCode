class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        // 对每个操作符的两边分别求值，然后合并
        vector<int> result;
        int i = 0, sz = input.length();
        while(i != sz) {
            if(input[i] == '+' || input[i] == '-' || input[i] == '*') {
                auto v1 = diffWaysToCompute(input.substr(0, i));
                auto v2 = diffWaysToCompute(input.substr(i+1));
                if(input[i] == '+') {
                    for(const auto &a1 : v1)
                        for(const auto &a2 : v2)
                            result.push_back(a1 + a2);
                }
                if(input[i] == '-') {
                    for(const auto &a1 : v1)
                        for(const auto &a2 : v2)
                            result.push_back(a1 - a2);
                }
                if(input[i] == '*') {
                    for(const auto &a1 : v1)
                        for(const auto &a2 : v2)
                            result.push_back(a1 * a2);
                }
            }
            ++i;
        }
        if(result.empty()) {
            result.push_back(stoi(input));
        }
        return result;
    }
};
