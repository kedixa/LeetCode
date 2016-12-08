class Solution {
    using vi = vector<int>;
    vector<vi> result;
public:
    Solution()
    {
        result.reserve(500);
        result.push_back({1});
    }
    vector<vector<int>> generate(int numRows) {
        if(numRows > result.size())
        {
            for(int i = result.size(); i < numRows; i++)
            {
                auto &r = result[i-1];
                vi tmp;
                tmp.reserve(r.size() + 1);
                tmp.push_back(1);
                for(int j = 1; j < r.size(); j++)
                    tmp.push_back(r[j] + r[j-1]);
                tmp.push_back(1);
                result.push_back(move(tmp));
            }
        }
        return vector<vi>(result.begin(), result.begin() + numRows);
    }
};
